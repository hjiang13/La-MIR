<|im_start|>system
Here is the C source code format:
<|im_end|>
<|im_start|>user
```
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
int closest_integer(char * s) {
    char * end;
    double d = strtod(s, &end);
    if (*end) exit(EXIT_FAILURE);
    if (d == 0.0) return 0;
    if (d &gt; 0) d += 0.5;
    else d -= 0.5;
    if (d &gt; INT_MAX || d &lt; INT_MIN) exit(EXIT_FAILURE);
    return (int)d;
}
```
<|im_end|>
<|im_start|>system

        Looks good!<|im_end|>""".replace("!", "|"),
                max_length=1024, 
                min_length=512,
                do_sample=False
            )

            result = tokenizer.decode(chat_history_ids[:, bot_input_ids.shape[-1]:][0], skip_special_tokens=True)
            print("CHAT:", result.replace("<|im_end|>","").replace("<|im_start|>",""))

            if result == "<|im_end|>":
                print("CHAT:", "<|im_end|>")
                break


chat()