# Encryption / Decryption Tool

## Approach and Requirements

1. _Project Overview_:

   Objective: Develop a file encryption tool using the AES encryption algorithm.
   Main Components: Key generation, encryption, and decryption functions.

2. _Requirements_:

   User Interface:
   Command-line interface for simplicity.
   Options for encryption and decryption.
   Input: File path to encrypt/decrypt.
   Encryption Algorithm:
   Use AES encryption.
   Choose a key size (128, 192, or 256 bits).
   Key Management:
   Implement a secure key generation mechanism.
   Allow the user to input or generate a key.
   File Handling:
   Read the file to encrypt/decrypt.
   Write the encrypted/decrypted content to a new file.
   Error Handling:
   Gracefully handle errors such as file not found, invalid key, etc.
   Documentation:
   Provide clear instructions on how to use the tool.
   Explain the encryption process and key management.

3. _AES Encryption in C_:

   Library: Use an existing AES library or implement the AES algorithm in C.
   Key Expansion: Understand and implement the key expansion process.
   Block Cipher Modes: Choose a block cipher mode (e.g., ECB, CBC).

4. _Key Generation_:

   Secure Key Handling: If the user doesn't provide a key, generate a secure random key.
   Key Input: Allow the user to input the key securely.

5. _File Handling_:

   Read File: Open the input file and read its content.
   Encrypt/Decrypt: Use the AES algorithm to process the file content.
   Write File: Save the result in a new file.

6. _Testing_:

   Test with Small Files: Start by testing with small files for quick verification.
   Edge Cases: Test with various file types and sizes.
   Validation: Ensure the decrypted file matches the original.

## Fun Fact

AES was established as the standard encryption algorithm by the U.S. National Institute of Standards and Technology (NIST) in 2001.

## Implementation Tips

1. Research: Understand the AES algorithm and how it works before diving into the implementation.

2. Libraries: Consider using libraries like OpenSSL or an existing AES library to simplify the implementation.

3. Step-by-Step: Implement and test each component (key generation, encryption, decryption) separately before combining them into the full tool.

## License

[GNU General Public License v2.0](https://choosealicense.com/licenses/gpl-2.0/)
