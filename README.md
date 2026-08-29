# RC4 File Encryptor

A simple C++ program that encrypts and decrypts the contents of `file.txt`
using the RC4 stream cipher.

## Files

- `rc4_encryptor.cpp` - Encrypts `file.txt` using RC4.
- `rc4_decryptor.cpp` - Decrypts `file.txt` using the same RC4 key.
- `file.txt` - Sample text file used for testing.

## How it works

The encryptor reads `file.txt` in binary mode, encrypts its contents using
RC4, and writes the encrypted bytes back to the file.

The decryptor uses the same key and RC4 process to restore the original
contents.

## Testing

1. Create the original `file.txt`.
2. Run the encryptor.
3. Verify that the file contains unreadable encrypted data.
4. Run the decryptor.
5. Verify that the original contents are restored.
