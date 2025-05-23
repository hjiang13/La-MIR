#include <stdlib.h>
#include <string.h>



int check_dict_case(void *arg0) {
  
  int64_t a2 = 0;
  char *a3 = (char *)malloc(32);
  int64_t a4 = 0;
  int64_t a5 = 0;
  int64_t a6 = 0;
  int64_t a7 = 0;

  *((int64_t *)arg0 + 5)

  if (*((int64_t *)arg0 + 5) > 0) {
    void *a8 = (void *)*((int64_t *)arg0 + 1) + 24;
    void *a9 = (void *)*((int64_t *)arg0 + 1) + 8;
    while (a8 != a9) {
      a2 = 0;
      a4 = 0;
      a5 = 0;
      void *a10 = *((void **)a8 + 1);
      a4 = (int64_t)strlen((char *)a10);
      memcpy(a3, a10, a4);
      a3[a4] = '\0';
      a5 = a4;
      int a11 = 0;
      for (int64_t a12 = 0; a12 < a4; a12++) {
        if (a3[a12] >= 'A' && a3[a12] <= 'Z') {
          a11 = 1;
          break;
        } else if (a3[a12] >= 'a' && a3[a12] <= 'z') {
          if (a11) {
            break;
          }
          a6++;
          a7++;
        }
      }
      if (a6 == a5) {
        a2 = 1;
        break;
      }
      a8 = *((void **)a8 + 2);
    }
  }
  free(a3);
  return a2;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (check_dict_case({{"p","pineapple"}, {"b","banana"}}) == true);
    assert (check_dict_case({{"p","pineapple"}, {"A","banana"}, {"B","banana"}}) == false);
    assert (check_dict_case({{"p","pineapple"}, {"5","banana"}, {"a","apple"}}) == false);
    assert (check_dict_case({{"Name","John"}, {"Age","36"}, {"City","Houston"}}) == false);
    assert (check_dict_case({{"STATE","NC"}, {"ZIP","12345"} }) == true  );
    assert (check_dict_case({{"fruit","Orange"}, {"taste","Sweet"} }) == true  );
    assert (check_dict_case({}) == false);
}
