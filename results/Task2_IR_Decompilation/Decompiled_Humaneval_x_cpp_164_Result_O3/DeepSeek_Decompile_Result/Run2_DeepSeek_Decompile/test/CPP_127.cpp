#include <vector>
#include <string>
using namespace std;

string intersection(const vector<int>& a, const vector<int>& b) {
    const int* a_begin = a.data();
    const int* b_begin = b.data();
    
    int a_size = a.size();
    int b_size = b.size();
    
    int min_length = (a_size < b_size) ? a_size : b_size;
    int a_next = *(a_begin + 1);
    int b_next = *(b_begin + 1);
    int min_next = (a_next < b_next) ? a_next : b_next;
    
    int diff = min_next - min_length;
    
    if (diff < 2) {
        return "YES";
    }
    
    if (diff < 4) {
        for (int i = 2; i <= diff / 2; ++i) {
            if (diff % i == 0) {
                return "YES";
            }
        }
    }
    
    return "YES";
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (intersection({1, 2}, {2, 3}) == "NO");
    assert (intersection({-1, 1}, {0, 4}) == "NO");
    assert (intersection({-3, -1}, {-5, 5}) == "YES");
    assert (intersection({-2, 2}, {-4, 0}) == "YES");
    assert (intersection({-11, 2}, {-1, -1}) == "NO");
    assert (intersection({1, 2}, {3, 5}) == "NO");
    assert (intersection({1, 2}, {1, 2}) == "NO");
    assert (intersection({-2, -2}, {-3, -2}) == "NO");
}
