#include <string.h>

void intersection(std::string* result, std::vector<int>* v1, std::vector<int>* v2) {
    int* data1 = v1->_M_impl._M_start;
    int* data2 = v2->_M_impl._M_start;
    int size1 = *data1;
    int size2 = *data2;
    int min_size = (size1 < size2) ? size1 : size2;
    int* data1_next = data1 + 1;
    int* data2_next = data2 + 1;
    int next1 = *data1_next;
    int next2 = *data2_next;
    int diff = (next2 < next1) ? next2 : next1;
    diff -= min_size;
    if (diff < 2) {
        result->_M_data._M_p = (char*)"YES";
        result->_M_string_length = 2;
    } else if (diff < 4) {
        int i = 2;
        while (1) {
            int square = i * i;
            if (square > diff) break;
            if (diff % i == 0) {
                result->_M_data._M_p = (char*)"YES";
                result->_M_string_length = 2;
                break;
            }
            i++;
        }
        if (i * i > diff) {
            result->_M_data._M_p = (char*)"NO";
            result->_M_string_length = 2;
        }
    } else {
        result->_M_data._M_p = (char*)"NO";
        result->_M_string_length = 2;
    }
    result->_M_data._M_p[result->_M_string_length] = '\0';
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
