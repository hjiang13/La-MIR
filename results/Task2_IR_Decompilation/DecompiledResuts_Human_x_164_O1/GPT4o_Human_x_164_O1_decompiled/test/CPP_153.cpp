#include <iostream>
#include <string>
#include <vector>

void Strongest_Extension(std::string &result, const std::string &input, const std::vector<std::string> &vec) {
    std::string temp;
    size_t inputSize = input.size();
    
    if (inputSize > 15) {
        temp.resize(inputSize);
        for (size_t i = 0; i < inputSize; ++i) {
            char c = input[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                temp[i] = c;
            }
        }
        result = temp;
    } else {
        result = "Default String";
    }
}

int main() {
    std::string result;
    std::string input = "Example Input String";
    std::vector<std::string> vec = {"String1", "String2", "String3"};
    
    Strongest_Extension(result, input, vec);
    std::cout << result << std::endl;
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (Strongest_Extension("Watashi", {"tEN", "niNE", "eIGHt8OKe"}) == "Watashi.eIGHt8OKe");
    assert (Strongest_Extension("Boku123", {"nani", "NazeDa", "YEs.WeCaNe", "32145tggg"}) == "Boku123.YEs.WeCaNe");
    assert (Strongest_Extension("__YESIMHERE", {"t", "eMptY", "(nothing", "zeR00", "NuLl__", "123NoooneB321"}) == "__YESIMHERE.NuLl__");
    assert (Strongest_Extension("K", {"Ta", "TAR", "t234An", "cosSo"}) == "K.TAR");
    assert (Strongest_Extension("__HAHA", {"Tab", "123", "781345", "-_-"}) == "__HAHA.123");
    assert (Strongest_Extension("YameRore", {"HhAas", "okIWILL123", "WorkOut", "Fails", "-_-"}) == "YameRore.okIWILL123");
    assert (Strongest_Extension("finNNalLLly", {"Die", "NowW", "Wow", "WoW"}) == "finNNalLLly.WoW");
    assert (Strongest_Extension("_", {"Bb", "91245"}) == "_.Bb");
    assert (Strongest_Extension("Sp", {"671235", "Bb"}) == "Sp.671235");
}
