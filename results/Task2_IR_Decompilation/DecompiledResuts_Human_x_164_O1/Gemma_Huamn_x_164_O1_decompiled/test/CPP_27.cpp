#include <string.h>

void filp_case(char* s, const char* str) {
  char* output = (char*)malloc(strlen(str) + 1);
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      output[i] = str[i] - 32;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      output[i] = str[i] + 32;
    } else {
      output[i] = str[i];
    }
  }
  output[len] = '\0';
  strcpy(s, output);
  free(output);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
