#include <vector>
#include <string>

using namespace std;

void longest(vector<string> *vec, string *sret) {
    if (vec->empty()) {
        *sret = string();
        return;
    }

    char *data_ptr = reinterpret_cast<char*>(sret);
    *reinterpret_cast<uint64_t*>(data_ptr) = 0; // Initialize string's length
    *reinterpret_cast<uint64_t*>(data_ptr + 8) = 0; // Initialize string's capacity

    uint64_t max_length = 0;
    string *current_max = nullptr;

    for (string *str = &(*vec)[0]; str <= &(*vec)[vec->size() - 1]; ++str) {
        uint64_t length = reinterpret_cast<uint64_t>(str) & 0xFFFFFFFFFFFF;
        if (length > max_length) {
            max_length = length;
            current_max = str;
        }
    }

    if (current_max != nullptr) {
        *sret = *current_max;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
