<|im_start|>system
```
int is_bored(std::string s)
{
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            counter++;
    }
    return counter;
}
```
<|im_end|>
```