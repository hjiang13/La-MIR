#include <stdio.h>
#include <stdint.h>

#define CELL_SIZE 30000

uint8_t cells[CELL_SIZE];
uint8_t *ptr = cells;

void interpret(char *code) {
    while (*code) {
        switch (*code) {
            case '>':
                ptr++;
                break;
            case '<':
                ptr--;
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (*ptr == 0) {
                    int depth = 1;
                    while (depth > 0) {
                        code++;
                        if (*code == '[') {
                            depth++;
                        } else if (*code == ']') {
                            depth--;
                        }
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    int depth = 1;
                    while (depth > 0) {
                        code--;
                        if (*code == '[') {
                            depth--;
                        } else if (*code == ']') {
                            depth++;
                        }
                    }
                }
                break;
        }
        code++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <code>\n", argv[0]);
        return 1;
    }
    interpret(argv[1]);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}
