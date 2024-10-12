#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define WORD_SIZE 100

void upperToLower(char arr[], int _size);
bool detectCaesarCipher(int _size_, char encryptMessage[], int _counter);
int detectSizeOfWord(char arr[]);

int main() {
	bool detected = false;
	char encryptMessage[WORD_SIZE], *word_s;
	int counter;

	printf("\tWarning! Maximum value is 100 letters.\nEnter a Ciphertext message: ");
	fgets(encryptMessage, sizeof(encryptMessage), stdin);
	
	counter = detectSizeOfWord(encryptMessage);
	// Stage control starts from 4 and decreases to 2
	if (!detected) {
		for (int i = 4; i > 1; i--)
		{
			detected = detectCaesarCipher(i, encryptMessage, counter);
			if (detected) break;
		}
	}
	if(!detected) {
		printf("\nThe password could not be deciphered and the key is unknown!\n");
	}
	
	return 0;
}
// converting uppercase letters to lowercase letters
void upperToLower(char arr[], int _size)
{
	for (int i = 0; i < _size; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			arr[i] += 32;
		}
	}
}

bool detectCaesarCipher(int _size_, char encryptMessage[], int _counter)
{
	char word[WORD_SIZE], tryEncryptMessage[WORD_SIZE], lowerEncryptMessage[WORD_SIZE], * word_s;
	int key = 1, counter, truth = 0;
	bool detected = false;

	FILE* word_file = fopen("words.txt", "r");
	if (word_file == NULL) { printf("The file isn't opened. The program will now exit.\n"); exit(0); }
	else { printf("\nThe file is opened and reading Successfully.\n"); }
	// copy encryptMessage to lowerEncryptMessage
	strncpy(lowerEncryptMessage, encryptMessage, strlen(encryptMessage - 1));
	// Convert all input to lowercase
	upperToLower(lowerEncryptMessage, strlen(encryptMessage));

	printf("\nAnalysis of words with letters %d and higher than %d begins...\n", _size_, _size_);

	while (key <= 26) {
		counter = 0;
		for (int i = 0; lowerEncryptMessage[i] != '\n'; i++)
		{
			if (lowerEncryptMessage[i] != ' ') {
				tryEncryptMessage[i] = ((lowerEncryptMessage[i] - 'a' - key + 26) % 26) + 'a';
			}
			else {
				tryEncryptMessage[i] = ' ';
			}
			counter++;
		}
		tryEncryptMessage[counter] = '\0';
		printf("The key is: %d - ", key);
		for (int i = 0; tryEncryptMessage[i] != '\0'; i++)
		{
			printf("%c", tryEncryptMessage[i]);
		}

		word_s = strtok(tryEncryptMessage, " ");

		while (word_s != NULL)
		{
			while (fscanf(word_file, "%s", word) != EOF) {
				if (strcmp(word, word_s) == 0 && strlen(word_s) >= _size_) {
					truth++;
					// word quantity control
					if (_counter >= 2) {
						// matching word quantity condition
						if (truth >= 2) {
							printf("\n\nKey detected: %d - Minimum %d word match - Last word detected: ", key, truth);
							for (int i = 0; i < strlen(word); i++)
							{
								printf("%c", word[i]);
							}
							detected = true;
							break;
						}
					}
					else {
						printf("\n\nKey detected: %d - Minimum %d word match - Last word detected: ", key, truth);
						for (int i = 0; i < strlen(word); i++)
						{
							printf("%c", word[i]);
						}
						detected = true;
						break;
					}
				}
			}
			if (detected) {
				break;
			}
			word_s = strtok(NULL, " ");
			rewind(word_file);
		}
		if (detected) {
			break;
		}
		printf("\n");
		key++;
	}
	fclose(word_file);

	return detected;
}
// determining the number of words in a sentence
int detectSizeOfWord(char arr[])
{
	int counter = 0;
	bool inside = false;

	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t') {
			
			if (inside) {
				counter++;
				inside = false;
			}
		}
		else {
			inside = true; 
		}
	}

	if (inside) counter++;

	return counter;
}
