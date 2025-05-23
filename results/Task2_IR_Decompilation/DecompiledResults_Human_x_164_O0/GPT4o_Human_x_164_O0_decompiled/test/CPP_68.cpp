#include <vector>
#include <initializer_list>
#include <stdexcept>

class VectorWrapper {
public:
    VectorWrapper() : v() {}

    VectorWrapper(std::initializer_list<int> init) : v(init) {}

    void pluck(const VectorWrapper& other) {
        for (size_t i = 0; i < other.v.size(); ++i) {
            int value = other.v[i];
            if (value % 2 == 0) {
                v.push_back(value);
            }
        }
    }

    size_t size() const {
        return v.size();
    }

    int operator[](size_t index) const {
        if (index >= v.size()) {
            throw std::out_of_range("Index out of range");
        }
        return v[index];
    }

private:
    std::vector<int> v;
};

int main() {
    VectorWrapper vec1 = {1, 2, 3, 4, 5};
    VectorWrapper vec2 = {6, 7, 8, 9, 10};

    vec1.pluck(vec2);

    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << std::endl;
    }

    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
