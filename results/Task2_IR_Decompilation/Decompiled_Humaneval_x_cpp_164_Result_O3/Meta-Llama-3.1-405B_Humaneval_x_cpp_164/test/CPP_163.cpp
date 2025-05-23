#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct VectorBase {
    int* data;
    int* begin;
    int* end;
};

struct Vector {
    struct VectorBase base;
};

void generate_integers(struct Vector* vector, int num1, int num2) {
    int* data;
    int* begin;
    int* end;
    int size;

    if (num2 < num1) {
        size = num1;
    } else {
        size = num2;
    }

    data = vector->base.data;
    begin = vector->base.begin;
    end = vector->base.end;

    memset(vector, 0, sizeof(struct Vector));

    while (size < 10) {
        if ((size & 1) == 0) {
            if (end == begin) {
                if (size == 0) {
                    data = malloc(sizeof(int));
                } else {
                    data = realloc(data, size * sizeof(int));
                }
                if (data == NULL) {
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                begin = data;
                end = data + size;
                *end = size;
                size++;
            } else {
                *end = size;
                size++;
                end++;
            }
        } else {
            if (size == 0) {
                data = malloc(sizeof(int));
            } else {
                data = realloc(data, size * sizeof(int));
            }
            if (data == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            begin = data;
            end = data + size;
            *end = size;
            size++;
        }
    }
}

int main() {
    struct Vector vector;
    generate_integers(&vector, 10, 20);
    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}
