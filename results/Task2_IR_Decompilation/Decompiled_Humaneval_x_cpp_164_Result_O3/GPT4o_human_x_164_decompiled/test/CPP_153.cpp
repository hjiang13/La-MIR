#include <string>
#include <vector>
#include <cstring>

void Strongest_Extension(std::string &result, const std::string &input, const std::vector<std::string> &vec) {
    std::string temp1;
    std::string temp2;

    if (&input == &vec[0] || &input == &vec[1]) {
        return;
    }

    for (const auto &s : vec) {
        if (s.empty()) {
            continue;
        }

        size_t len = s.length();
        const char *data = s.data();

        for (size_t i = 0; i < len; ++i) {
            char c = data[i];
            if (c >= 'A' && c < 'A' + 26) {
                ++temp1[static_cast<unsigned char>(c) - 'A'];
            }
            if (c >= 'a' && c < 'a' + 26) {
                ++temp2[static_cast<unsigned char>(c) - 'a'];
            }
        }
    }

    result.append(temp1);
    result.append(temp2);
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
