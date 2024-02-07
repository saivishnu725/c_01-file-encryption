#include "aes_tools.h"
#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // ./main <key size> <filename>
    if (argc < 3) {
        printf("Usage: %s <key size> <file>\n", argv[0]);
        return 1;
    } else if (argc > 3) {
        printf("Too many arguments\n");
        return 1;
    }

    // key size in bits
    int key_size_bits = atoi(argv[1]);
    if (key_size_bits != 128 && key_size_bits != 192 && key_size_bits != 256) {
        printf("Key size must be 128, 192 or 256\n");
        return 1;
    }

    // key size in bytes
    int key_size = 16;
    switch (key_size_bits) {
    case 128:
        key_size = 16;
        break;
    case 192:
        key_size = 24;
        break;
    case 256:
        key_size = 32;
        break;
    default:
        key_size = 16;
        break;
    }

    // ask if they have a key or should it be generated
    unsigned char *aesKey = malloc(key_size);
    char key_exists;
    printf("Do you have a %d-bit key? (y/n): ", key_size_bits);
    scanf("%c", &key_exists);
    if (key_exists == 'y' || key_exists == 'Y') {
        /* code to accept the existing key */
        printf("Please enter the key: ");
        scanf("%s", aesKey);
        // fgets(aesKey, key_size - 1, stdin);
    } else {
        /* code to generate a key*/
        generate_key(aesKey, key_size);
    }
    printf("Key: %s\n", aesKey);

    return 0;
}
//     // ask for key size
//     printf("Key size (128, 192, 256): ");
//     int key_size;
//     scanf("%d", &key_size);

//     printf("Key size: %d\n", key_size);
//     if (key_size != 128 || key_size != 192 || key_size != 256)
//     {
//         printf("Key size: %d\n", key_size);
//         printf("Invalid key size\n");
//         return 1;
//     }

//     // ask if they have a key or should I randomly generate one
//     char *key;
//     printf("Do you have a key? (y/n): ");
//     char existing;
//     scanf("%c", &existing);
//     if (existing == 'y' || existing == 'Y')
//         scanf("%s", key);
//     else
//         key = generate_key(key_size);

//     printf("%s", key);

//     // open the file
//     FILE *fp = fopen(argv[1], "r");
//     if (fp == NULL)
//     {
//         printf("Cannot open file %s\n", argv[1]);
//         return 1;
//     }
//     char c;
//     while ((c = fgetc(fp)) != EOF)
//     {
//     }
//     fclose(fp);

//     return 0;
// }