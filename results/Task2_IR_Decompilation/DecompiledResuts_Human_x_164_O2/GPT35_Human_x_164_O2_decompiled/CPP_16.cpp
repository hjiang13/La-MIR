```cpp
#include <string>
#include <algorithm>

int count_distinct_characters(std::basic_string<char>* str) {
    char* data = &(*str)[0];
    size_t size = str->size();

    for (size_t i = 0; i < size; ++i) {
        data[i] = tolower(data[i]);
    }

    std::sort(data, data + size);

    size_t unique_chars = std::unique(data, data + size) - data;

    return unique_chars;
}

int main() {
    std::basic_string<char> input = "vector::_M_realloc_insert";
    int result = count_distinct_characters(&input);

    return result;
}
```