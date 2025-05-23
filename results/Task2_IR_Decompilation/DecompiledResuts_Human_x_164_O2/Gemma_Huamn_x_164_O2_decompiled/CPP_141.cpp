```c
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *data;
  long size;
} string;

void file_name_check(string *result, string *name) {
  if (name->size < 5) {
    result->data = (char *)malloc(3);
    strcpy(result->data, "No");
    result->size = 2;
    return;
  }
  char *p = name->data;
  if (*p >= 65 && *p <= 90 || *p >= 97 && *p <= 122) {
    result->data = (char *)malloc(3);
    strcpy(result->data, "Yes");
    result->size = 2;
    return;
  }

  if (name->size >= 4 && !strcmp(name->data + name->size - 4, ".txt")) {
    result->data = (char *)malloc(3);
    strcpy(result->data, "Yes");
    result->size = 2;
    return;
  }
  if (name->size >= 5 && !strcmp(name->data + name->size - 5, ".exe")) {
    result->data = (char *)malloc(3);
    strcpy(result->data, "Yes");
    result->size = 2;
    return;
  }
  if (name->size >= 5 && !strcmp(name->data + name->size