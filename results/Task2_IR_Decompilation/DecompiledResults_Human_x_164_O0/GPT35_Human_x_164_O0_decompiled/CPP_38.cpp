```cpp
#include <string>

void encode_cyclic(std::string& output, std::string& input) {
    int length = input.length();
    int num_chunks = (length + 2) / 3;
    
    std::string temp;
    bool flag = false;
    std::string result;
    
    for (int i = 0; i < num_chunks; i++) {
        int start_index = i * 3;
        int chunk_size = (start_index + 3 <= length) ? 3 : (length - start_index);
        
        temp = input.substr(start_index, chunk_size);
        result += temp;
        
        if (temp.length() < 3) {
            flag = true;
            break;
        }
    }
    
    if (flag) {
        output = result;
    } else {
        output = input;
    }
}

void decode_cyclic(std::string& output, std::string& input) {
    int length = input.length();
    int num_chunks = (length + 2) / 3;
    
    std::string temp;
    bool flag = false;
    std::string result;
    
    for (int i = 0; i < num_chunks; i++) {
        int start_index = i * 3;
        int chunk_size = (start_index + 3 <= length) ? 3 : (length - start_index);
        
        temp = input.substr(start_index, chunk_size);
        result += temp;
        
        if (temp.length() < 3) {
            flag = true;
            break;
        }
    }
    
    if (flag) {
        output = result;
    } else {
        output = input;
    }
}
```