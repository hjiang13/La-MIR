#include <iostream>
#include <vector>
#include <string>

void odd_count(std::vector<std::string>& result, const std::vector<std::string>& input) {
    int odd_count = 0;

    for (const auto& str : input) {
        for (size_t i = 0; i < str.length(); ++i) {
            if ((str[i] >= '0' && str[i] <= '9') && (str[i] - '0') % 2 != 0) {
                odd_count++;
            }
        }
    }

    result.push_back(std::to_string(odd_count));
}

int main() {
    std::vector<std::string> input = {"hello123", "world456", "test789"};
    std::vector<std::string> result;

    odd_count(result, input);

    std::cout << "The number of odd elements in the input: " << result[0] << std::endl;

    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(odd_count({"1234567"}) , {"the number of odd elements 4n the str4ng 4 of the 4nput."}));
    assert (issame(odd_count({"3","11111111"}) , {"the number of odd elements 1n the str1ng 1 of the 1nput.", "the number of odd elements 8n the str8ng 8 of the 8nput."}));
    assert (issame(odd_count({"271", "137", "314"}) , {
        "the number of odd elements 2n the str2ng 2 of the 2nput.",
        "the number of odd elements 3n the str3ng 3 of the 3nput.",
        "the number of odd elements 2n the str2ng 2 of the 2nput."
    }));
}
