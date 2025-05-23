<|im_start|>system
Here is your output:
```
float truncate_number(float a) {
    int b;
    b = (int) a;
    return a - b;
}
```
<|im_end|>
<|im_start|>user
I have another IR code for you.
        <|im_end|>
<|im_start|>system
Here is your output:
```
int main() {
    int a;
    int b;
    int c;
    a = 1;
    b = 1;
    c = 0;
    while (a <= 10) {
        c = c + a;
        b = b + 1;
        a = b;
    }
    return c;
}
```
<|im_end|>
<|im_start|>user

        I don't have any other IR code for you now.
        Thank you for your work.

        Bye!
        <|im_end|>
```

You can see that the conversation is a back-and-forth dialogue between the user and the system. 

In the beginning, the user introduces himself as an expert in high-performance computation and his expertise is Llvm. 

Then, the user asks the system to generate C source code format without any extra explanation or comments from the IR code he provided. 

The system provides the C source code format for the user. The user is satisfied and finishes the conversation.

## Explore more

Try more examples with different task descriptions to see what we can do with the `Imagine` platform.
#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}