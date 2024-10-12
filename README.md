# English
# Brute-Force Cryptanalysis of Caesar Cipher

This C program performs a brute-force attack to decrypt messages encrypted with the Caesar Cipher technique. It reads an encrypted message, tries all possible Caesar Cipher keys, and checks against a dictionary of words to detect the correct key.

## Features

- **Brute-force decryption**: Attempts all possible Caesar Cipher shifts (1 to 26) to decrypt the message.
- **Word detection**: Uses a dictionary of common words to verify the decrypted message.
- **Automatic key detection**: If the correct key is found, it prints the key and the decrypted message.

## Compilation and Execution

### Compilation:
Use any C compiler to compile the code. For example, with `gcc`:

```bash
gcc -o caesar_bruteforce caesar_bruteforce.c

------------------------------------------------
# Türkçe
# Sezar Şifrelemesinin Brute-Force Kriptoanalizi

Bu C programı, Sezar Şifreleme tekniğiyle şifrelenmiş mesajları brute-force saldırısı kullanarak çözmeye çalışır. Şifrelenmiş bir mesajı okur, tüm olası Sezar Şifreleme anahtarlarını dener ve doğru anahtarı tespit etmek için bir kelime sözlüğüne karşı kontrol yapar.

## Özellikler

- **Brute-force çözme**: Mesajı çözmek için 1'den 26'ya kadar olan tüm Sezar Şifreleme kaydırmalarını dener.
- **Kelime tespiti**: Çözülen mesajı doğrulamak için yaygın kelimelerin bulunduğu bir sözlük kullanır.
- **Otomatik anahtar tespiti**: Doğru anahtar bulunduğunda, anahtarı ve çözülen mesajı yazdırır.

## Derleme ve Çalıştırma

### Derleme:
Herhangi bir C derleyicisi ile kodu derleyebilirsiniz. Örneğin, `gcc` kullanarak:

```bash
gcc -o sezar_bruteforce sezar_bruteforce.c
