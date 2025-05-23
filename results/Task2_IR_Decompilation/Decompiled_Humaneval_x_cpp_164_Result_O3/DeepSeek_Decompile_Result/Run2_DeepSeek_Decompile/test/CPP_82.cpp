#include <string>

using namespace std;

bool prime_length(const string &s) {
    size_t length = s.length();
    if (length < 2) {
        return false;
    }
    if (length < 4) {
        return true;
    }
    bool is_prime = true;
    for (int i = 2; i * i <= length; ++i) {
        if (length % i == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
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
