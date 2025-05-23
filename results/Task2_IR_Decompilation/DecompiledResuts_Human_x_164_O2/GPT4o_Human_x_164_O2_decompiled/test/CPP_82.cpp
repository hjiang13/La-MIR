#include <string>

bool prime_length(const std::string& str) {
    size_t length = str.size();
    if (length < 2) {
        return false;
    }
    if (length < 4) {
        return true;
    }

    int n = 2;
    while (true) {
        int remainder = length % n;
        bool is_divisible = (remainder == 0);
        n += 1;
        if (is_divisible) {
            return true;
        }
        int square = n * n;
        if (square > length) {
            break;
        }
    }
    return false;
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
