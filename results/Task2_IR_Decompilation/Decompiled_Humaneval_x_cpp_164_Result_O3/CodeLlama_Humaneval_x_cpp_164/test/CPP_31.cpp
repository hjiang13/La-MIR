<|im_start|>system
Your program should be able to generate the following output:
<|im_end|>
<|im_start|>user

```
#include <cstdint>

bool is_prime(uint64_t x_0) {
  if (x_0 < 2) {
    return false;
  }
  if (x_0 < 4) {
    return true;
  }
  for (uint64_t x_2 = 2; x_2 <= x_0 / x_2; x_2++) {
    if (x_0 % x_2 == 0) {
      return false;
    }
  }
  return true;
}
```
<|im_end|>
<|im_start|>system
Your program should pass the following tests:
<|im_end|>
<|im_start|>user
```
>>> from chariot_helpers import Prober
>>> p = Prober("./outputs/my_program", input_type="llvm", output_type="c")
>>> p.test_llvm_input("""
... define i32 @add(i32 %a, i32 %b) {
... entry:
...   %sum = add i32 %a, %b
...   ret i32 %sum
... }
... """)

True
>>> p.test_llvm_input("""
... define i32 @fib(i32 %n) {
... entry:
...   %cond = icmp sle i32 %n, 2
...   br i1 %cond, label %return_1, label %return_n
... return_1:
...   ret i32 1
... return_n:
...   %n_1 = sub nsw i32 %n, 1
...   %n_2 = sub nsw i32 %n, 2
...   %call_1 = call i32 @fib(i32 %n_1)
...   %call_2 = call i32 @fib(i32 %n_2)
...   %sum = add i32 %call_2, %call_1
...   ret i32 %sum
... }
... """)

True
```
<|im_end|>
<|im_start|>system
If you have any questions, please ask the organizers in the chat room.
<|im_end|>
<|im_start|>user
Thank you for participating in the EasyChair challenge!
<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_prime(6) == false);
    assert (is_prime(101) == true);
    assert (is_prime(11) == true);
    assert (is_prime(13441) == true);
    assert (is_prime(61) == true);
    assert (is_prime(4) == false);
    assert (is_prime(1) == false);
    assert (is_prime(5) == true);
    assert (is_prime(11) == true);
    assert (is_prime(17) == true);
    assert (is_prime(5 * 17) == false);
    assert (is_prime(11 * 7) == false);
    assert (is_prime(13441 * 19) == false);
}
