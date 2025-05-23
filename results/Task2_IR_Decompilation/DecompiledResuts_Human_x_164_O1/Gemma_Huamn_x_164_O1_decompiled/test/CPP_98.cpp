#include <string>

int count_upper(const std::string& s) {
  std::string str = "AEIOU";
  int count = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (str.find(s[i]) != std::string::npos) {
      count++;
    }
  }
  return count;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}
