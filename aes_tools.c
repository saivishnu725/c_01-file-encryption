#include <stdlib.h>
#include <time.h>

void generate_key(char *key, int size) {
    int index;
    char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL));
    for (int i = 0; i < size; i++) {

        index = rand() % 62;
        key[i] = charset[index];
    }
    key[size] = '\0';
}

int bitoby(int bits) {
    return bits % 8;
}