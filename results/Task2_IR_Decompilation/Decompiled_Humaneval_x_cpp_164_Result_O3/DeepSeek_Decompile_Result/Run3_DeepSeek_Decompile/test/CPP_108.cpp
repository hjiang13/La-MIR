#include <vector>

using namespace std;

int count_nums(vector<int> vec) {
    int count = 0;
    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        int num = vec[i];
        if (num > 0) {
            count++;
        } else {
            int temp = -num; // Make it positive for easier processing
            if (temp >= 10) { // Check if it's a two-digit number or more
                int sum = 0;
                while (temp > 99) {
                    sum += temp % 10;
                    temp /= 10;
                }
                // Add the last two digits
                sum += temp % 10;
                sum += temp / 10;
                // Since we're just counting, we don't need the actual sum value
                count++;
            }
        }
    }
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_nums({}) == 0);
    assert (count_nums({-1, -2, 0}) == 0);
    assert (count_nums({1, 1, 2, -2, 3, 4, 5}) == 6);
    assert (count_nums({1, 6, 9, -6, 0, 1, 5}) == 5);
    assert (count_nums({1, 100, 98, -7, 1, -1}) == 4);
    assert (count_nums({12, 23, 34, -45, -56, 0}) == 5);
    assert (count_nums({-0, 1}) == 1);
    assert (count_nums({1}) == 1);
}
