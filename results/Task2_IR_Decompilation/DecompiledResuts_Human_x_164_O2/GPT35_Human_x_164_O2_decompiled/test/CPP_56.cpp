#include <string>

bool correct_bracketing(std::__cxx11::basic_string<char> *str) {
  i64 len = str->length;
  if (len == 0)
    return true;
  
  char* data = str->data;
  i64 index = 0;
  i32 count = 0;
  
  while (index != len) {
    char ch = data[index];
    if (ch == '<')
      count++;
    else if (ch == '>')
      count--;
    
    if (count < 0)
      return false;
    
    index++;
  }
  
  return count == 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (correct_bracketing("<>"));
    assert (correct_bracketing("<<><>>"));
    assert (correct_bracketing("<><><<><>><>"));
    assert (correct_bracketing("<><><<<><><>><>><<><><<>>>"));
    assert (not (correct_bracketing("<<<><>>>>")));
    assert (not (correct_bracketing("><<>")));
    assert (not (correct_bracketing("<")));
    assert (not (correct_bracketing("<<<<")));
    assert (not (correct_bracketing(">")));
    assert (not (correct_bracketing("<<>")));
    assert (not (correct_bracketing("<><><<><>><>><<>")));
    assert (not (correct_bracketing("<><><<><>><>>><>")));
}
