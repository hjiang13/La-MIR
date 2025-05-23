```cpp
extern "C" float truncate_number(float input) {
    int truncated = static_cast<int>(input);
    float result = input - static_cast<float>(truncated);
    return result;
}
```