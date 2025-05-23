#include <string>

bool prime_length(std::basic_string<char>* str) {
    int length = str->size();
    
    if (length < 2) {
        return false;
    } else if (length < 4) {
        return true;
    } else {
        int divisor = 2;
        
        while (divisor * divisor <= length) {
            if (length % divisor == 0) {
                return false;
            }
            divisor++;
        }
        
        return true;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_length("Hello") == true);
    assert (prime_length("abcdcba") == true);
    assert (prime_length("kittens") == true);
    assert (prime_length("orange") == false);
    assert (prime_length("wow") == true);
    assert (prime_length("world") == true);
    assert (prime_length("MadaM") == true);
    assert (prime_length("Wow") == true);
    assert (prime_length("") == false);
    assert (prime_length("HI") == true);
    assert (prime_length("go") == true);
    assert (prime_length("gogo") == false);
    assert (prime_length("aaaaaaaaaaaaaaa") == false);
    assert (prime_length("Madam") == true);
    assert (prime_length("M") == false);
    assert (prime_length("0") == false);
}
