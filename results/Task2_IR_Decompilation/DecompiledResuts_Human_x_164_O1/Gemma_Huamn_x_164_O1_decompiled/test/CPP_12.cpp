#include <stdint.h>

typedef struct {
  char *data;
  int64_t length;
  uint8_t *alloc;
} String;

typedef struct {
  String *data;
  String *end;
  String *capacity;
} Vector;

void longest(String *result, Vector *strings) {
  result->data = 0;
  result->length = 0;
  *(uint8_t **)result = 0;

  String *begin = strings->data;
  String *end = strings->end;

  if (begin == end) {
    return;
  }

  int64_t longest_length = 0;
  String *longest_string = end;

  for (int64_t i = 0; i < end - begin; i++) {
    String *current = begin + i;
    if (current->length > longest_length) {
      longest_length = current->length;
      longest_string = current;
    }
  }

  result->data = longest_string->data;
  result->length = longest_string->length;
  *(uint8_t **)result = longest_string->alloc;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
