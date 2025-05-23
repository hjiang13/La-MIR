#include <string.h>

void exchange(std::string* result, std::vector<int>* v1, std::vector<int>* v2) {
    int* v1_data = v1->_M_impl._M_start;
    int* v2_data = v2->_M_impl._M_start;
    size_t v1_size = v1->_M_impl._M_finish - v1->_M_impl._M_start;
    size_t v2_size = v2->_M_impl._M_finish - v2->_M_impl._M_start;

    size_t i = 0;
    if (v1_size != 0) {
        size_t v1_loop_size = (v1_size + 3) / 4;
        for (i = 0; i < v1_loop_size; ++i) {
            int v1_value = v1_data[i];
            result->_M_data._M_p[i] = (v1_value & 1) ^ 1;
        }
    }

    size_t j = 0;
    if (v2_size != 0) {
        size_t v2_loop_size = (v2_size + 3) / 4;
        for (j = 0; j < v2_loop_size; ++j) {
            int v2_value = v2_data[j];
            result->_M_data._M_p[i + j] = (v2_value & 1) ^ 1;
        }
    }

    if (i + j > v1_size) {
        result->_M_data._M_p[i + j - 1] = 0;
        result->_M_length = i + j - 1;
    } else {
        memcpy(result->_M_data._M_p, "YES", 3);
        result->_M_length = 3;
        result->_M_data._M_p[3] = 0;
    }
}
