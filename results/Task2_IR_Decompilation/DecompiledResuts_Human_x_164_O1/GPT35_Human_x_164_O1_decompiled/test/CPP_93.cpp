```cpp
#include <string>

void encode(std::string& result, const std::string& input) {
    const char vowels[] = "aeiouAEIOU";
    
    result.clear();
    
    for (char c : input) {
        char encoded = c;
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c >= 'a' && c <= 'z') {
                encoded = vowels[(c - 'a') % 5];
            } else {
                encoded = vowels[(c - 'A') % 5 + 5];
            }
        }
        
        result += encoded;
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
