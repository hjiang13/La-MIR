#include <string>

using namespace std;

void _Z10string_xorNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES4_(
    basic_string<char>* sret,
    const basic_string<char>& arg1,
    const basic_string<char>& arg2) {

  for (int i = 0; i < arg1.length(); i++) {
    sret[i] = arg1[i] ^ arg2[i];
  }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
