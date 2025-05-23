#include <string>
#include <vector>

void Strongest_Extension(std::string &result, const std::string &input, const std::vector<std::string> &data) {
    std::__cxx11::basic_string<char> s;
    std::__cxx11::basic_string<char> temp;
    s = "";
    for (auto str : data) {
        temp = str;
        if (temp.size() == 0) {
            continue;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] < 'A' || temp[i] > 'Z') {
                temp[i] = temp[i] - 65;
            }
            else {
                temp[i] = temp[i] - 97;
            }
        }
        s += temp;
    }
    result = s;
}

int main() {
    std::string result;
    std::string input = "input_string";
    std::vector<std::string> data = {"data_1", "data_2", "data_3"};
    Strongest_Extension(result, input, data);
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
