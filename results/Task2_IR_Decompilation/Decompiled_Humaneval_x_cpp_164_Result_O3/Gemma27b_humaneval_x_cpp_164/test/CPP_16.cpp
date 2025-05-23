#include <stdlib.h>
#include <string.h>

int count_distinct_characters(const char* str) {
  const char* start = str;
  size_t len = strlen(str);

  if (len == 0) {
    return 0;
  }

  for (size_t i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }

  char* seen = NULL;
  char* current = NULL;
  char* new_seen = NULL;

  for (size_t i = 0; i < len; i++) {
    char c = str[i];
    int found = 0;

    for (size_t j = 0; j < i; j++) {
      if (str[j] == c) {
        found = 1;
        break;
      }
    }

    if (found) {
      continue;
    }

    if (seen == NULL) {
      seen = malloc(sizeof(char));
      if (seen == NULL) {
        free(current);
        return 0;
      }
      seen[0] = c;
      current = seen;
    } else {
      new_seen = realloc(seen, (i + 1) * sizeof(char));
      if (new_seen == NULL) {
        free(current);
        return 0;
      }
      seen = new_seen;
      seen[i] = c;
      current = seen;
    }
  }

  free(current);
  return strlen(seen);
}

int tolower(int c) {
  return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_distinct_characters("") == 0);
    assert (count_distinct_characters("abcde") == 5);
    assert (count_distinct_characters("abcdecadeCADE") == 5);
    assert (count_distinct_characters("aaaaAAAAaaaa") == 1);
    assert (count_distinct_characters("Jerry jERRY JeRRRY") == 5);
}
