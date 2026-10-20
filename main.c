#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char shift_char(char c, int key) {
    if (c >= 'a' && c <= 'z') {
        return (char)('a' + (c - 'a' + key) % 26);
    }
    if (c >= 'A' && c <= 'Z') {
        return (char)('A' + (c - 'A' + key) % 26);
    }
    return c;
}

int main(int argc, char *argv[]) {
    int key;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <shift> [text...]\n", argv[0]);
        return 1;
    }
    key = atoi(argv[1]) % 26;
    if (key < 0) {
        key += 26;
    }

    if (argc >= 3) {
        for (int i = 2; i < argc; i++) {
            for (size_t j = 0; j < strlen(argv[i]); j++) {
                putchar(shift_char(argv[i][j], key));
            }
            putchar(i == argc - 1 ? '\n' : ' ');
        }
    } else {
        int c;
        while ((c = getchar()) != EOF) {
            putchar(shift_char((char)c, key));
        }
    }
    return 0;
}
