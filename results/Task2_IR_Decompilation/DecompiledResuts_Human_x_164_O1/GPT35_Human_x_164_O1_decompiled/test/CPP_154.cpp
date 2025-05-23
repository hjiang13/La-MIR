```cpp
#include <string>

bool cycpattern_check(std::basic_string<char> *param_1, std::basic_string<char> *param_2) {
  if (param_2->size() != 0) {
    if (param_2->size() > 15) {
      *param_1 = std::__cxx11::basic_string<char>::_M_create(*param_2, 0);
      if (param_1->size() == 1) {
        param_1->at(0) = param_2->at(0);
      } else {
        std::memcpy(&param_1->at(0), &param_2->at(0), param_2->size());
      }
    } else {
      param_1->assign(*param_2, 0, param_2->size());
    }
  }
  
  return (param_1->find(param_1->c_str(), 0, param_1->size()) != std::string::npos);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert  (cycpattern_check("xyzw","xyw") == false );
    assert  (cycpattern_check("yello","ell") == true );
    assert  (cycpattern_check("whattup","ptut") == false );
    assert  (cycpattern_check("efef","fee") == true );
    assert  (cycpattern_check("abab","aabb") == false );
    assert  (cycpattern_check("winemtt","tinem") == true );
}
