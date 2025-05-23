<|im_end|>

### DALLE-dialogue

DALLE-dialogue accepts a dialogue history as input and generates a human-like response.

We provide several examples in `DALLE-dialogue/inputs`. 

We provide 3 prompt templates for DALLE-dialogue in `DALLE-dialogue/templates`.

#### Example 1: Conversation with yourself

Template: `Conversation with myself,`

Output: 

<|im_start|>
<|im_end|>

#### Example 2: Conversation with a chatbot

Template: `Conversation with a chatbot,`

Output: 

<|im_start|>
<|im_end|>

#### Example 3: Conversation with a therapist

Template: `Conversation with a therapist,`

Output: 

<|im_start|>
<|im_end|>

### DALLE-multitask

DALLE-multitask accepts a dialogue history as input and generates a human-like response.

We provide several examples in `DALLE-multitask/inputs`. 

Output: 

<|im_start|>
<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_distinct_characters("") == 0);
    assert (count_distinct_characters("abcde") == 5);
    assert (count_distinct_characters("abcdecadeCADE") == 5);
    assert (count_distinct_characters("aaaaAAAAaaaa") == 1);
    assert (count_distinct_characters("Jerry jERRY JeRRRY") == 5);
}
