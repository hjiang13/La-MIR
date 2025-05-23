<|response|>
def choose_num(x, y):
<|im_start|>user

        ```
        -1
        ```
        <|im_end|>
<|response|>
    if y < x:
<|im_start|>system
You are doing great!
<|im_end|>
<|response|>
        return -1
<|im_start|>user

        ```
        -1
        ```
        <|im_end|>
<|response|>
    if y == x:
<|im_start|>system
Well done!
<|im_end|>
<|response|>
        return -1
    if y % 2 == 1:
<|im_start|>user

        ```
        -1
        ```
        <|im_end|>
<|response|>
        return y + 1
<|im_start|>system
Correct!
<|im_end|>
<|response|>
    return -1
<|im_start|>user

        ```
        -1
        ```
        <|im_end|>
<|response|>
```
def choose_num(x, y):
    if y < x:
        return -1
    if y == x:
        return -1
    if y % 2 == 1:
        return y + 1
    return -1
```
<|im_start|>system
Nice work!
<|im_end|>
<|response|>

"""


class CPPTest(unittest.TestCase):
    def test_cpp(self):
        interpreter = Interpreter()
        cpp_task_str = CPP_TEST_TASK
        task = json.loads(cpp_task_str)
        task_data = {"task": task}

        (
            task_class,
            task_bundle,
            task_state,
            task_full,
            _,
            _,
        ) = interpreter._make_task(task_data, 0)
        self.assertTrue(isinstance(task_class, sources.InteractiveSource))
        self.assertTrue(isinstance(task_bundle, sources.InteractiveSourceBundle))
        self.assertTrue(isinstance(task_state, sources.InteractiveSourceState))
        self.assertTrue(isinstance(task_full, sources.InteractiveSource))
#undef NDEBUG
#include<assert.h>
int main(){
    assert (choose_num(12, 15) == 14);
    assert (choose_num(13, 12) == -1);
    assert (choose_num(33, 12354) == 12354);
    assert (choose_num(5234, 5233) == -1);
    assert (choose_num(6, 29) == 28);
    assert (choose_num(27, 10) == -1);
    assert (choose_num(7, 7) == -1);
    assert (choose_num(546, 546) == 546);
}
