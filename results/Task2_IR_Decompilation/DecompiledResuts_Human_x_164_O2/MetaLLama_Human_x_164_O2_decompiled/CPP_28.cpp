#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* ptr;
    long length;
} string_t;

typedef struct {
    string_t* begin;
    string_t* end;
} vector_t;

void concatenate(vector_t* vector, string_t* result) {
    long size = 0;
    for (string_t* it = vector->begin; it != vector->end; ++it) {
        size += it->length;
    }

    char* buffer = (char*)malloc(size + 1);
    char* dest = buffer;

    for (string_t* it = vector->begin; it != vector->end; ++it) {
        while (*it->ptr != '\0') {
            *dest++ = *it->ptr++;
        }
    }

    *dest = '\0';

    result->ptr = buffer;
    result->length = size;
}

int main() {
    vector_t vector;
    string_t str1, str2;
    str1.ptr = "Hello ";
    str1.length = strlen(str1.ptr);
    str2.ptr = "World";
    str2.length = strlen(str2.ptr);
    vector.begin = &str1;
    vector.end = &str2 + 1;

    string_t result;
    concatenate(&vector, &result);

    printf("%s\n", result.ptr);

    free(result.ptr);

    return 0;
}
