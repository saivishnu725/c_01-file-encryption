#include "aes_tools.h"
#include <openssl/aes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // ./main <filename> <key size> <key>
    // interactive console -> ./main <file>
    bool key_exists = false;
    // printf("argc = %d\n", argc);
    if (argc != 4 && argc != 2) {
        printf("Usage: %s <file> <key size> <key>\n", argv[0]);
        printf("\t\t (or, for interactive console) \nUsage: %s <file>\n", argv[0]);
        return 1;
    } else if (argc == 4) {
        key_exists = true;
    }
    // file name
    char *filename = argv[1];
    // printf("filename = %s\n", filename);

    // key size in bits
    int key_size_bits;
    if (!key_exists) {
        printf("Enter the key size(128, 192, 256): ");
        scanf("%d", &key_size_bits);
    } else {
        key_size_bits = atoi(argv[2]);
    }
    // printf("key_size_bits = %d\n", key_size_bits);

    // key size in bits
    if (key_size_bits != 128 && key_size_bits != 192 && key_size_bits != 256) {
        printf("Key size must be 128, 192 or 256\n");
        return 1;
    }
    // key size in bytes
    int key_size = bitoby(key_size_bits);
    // printf("Key size: %d\n", key_size);

    // ask if they have a key or should it be generated
    unsigned char *aesKey = argv[3];

    if (!key_exists) {
        // aesKey = malloc(key_size);
        /* code to generate a key*/
        generate_key(aesKey, key_size);
    }
    printf("Key: %s\n", aesKey);

    // exit the program
    return 0;
}

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
