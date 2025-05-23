```cpp
#include <string>

void encode(std::string& dest, const std::string& src) {
    const char vowels[] = "aeiouAEIOU";
    
    dest.clear();
    
    for (size_t i = 0; i < src.size(); ++i) {
        char c = src[i];
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                dest.push_back(c);
            } else {
                if (c >= 'a' && c <= 'z') {
                    dest.push_back(c - 32); // convert to uppercase
                } else {
                    dest.push_back(c + 32); // convert to lowercase
                }
            }
        }
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (encode("TEST") == "tgst");
    assert (encode("Mudasir") == "mWDCSKR");
    assert (encode("YES") == "ygs");
    assert (encode("This is a message") == "tHKS KS C MGSSCGG");
    assert (encode("I DoNt KnOw WhAt tO WrItE") == "k dQnT kNqW wHcT Tq wRkTg");
}
