#include <iostream>

bool iscuber(int n) {
  int x = n;
  while (x > 0) {
    if (x % 10 == 3) {
      return true;
    }
    x /= 10;
  }
  return false;
}

int main() {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;
  if (iscuber(n)) {
    std::cout << "The number is a cuber." << std::endl;
  } else {
    std::cout << "The number is not a cuber." << std::endl;
  }
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (iscuber(1) == true);
    assert (iscuber(2) == false);
    assert (iscuber(-1) == true);
    assert (iscuber(64) == true);
    assert (iscuber(180) == false);
    assert (iscuber(1000) == true);
    assert (iscuber(0) == true);
    assert (iscuber(1729) == false);
}
