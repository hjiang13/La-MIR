#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Rb_tree_node_base {
    int _M_color;
    struct _Rb_tree_node_base* _M_parent;
    struct _Rb_tree_node_base* _M_left;
    struct _Rb_tree_node_base* _M_right;
} _Rb_tree_node_base;

typedef struct _Rb_tree_header {
    _Rb_tree_node_base* _M_header;
    long _M_node_count;
} _Rb_tree_header;

typedef struct basic_string {
    char* _M_data;
    long _M_size;
    long _M_capacity;
} basic_string;

int check_dict_case(void* dict) {
    _Rb_tree_header* header = (_Rb_tree_header*)dict;
    if (header->_M_node_count == 0) {
        return 0;
    }

    _Rb_tree_node_base* node = header->_M_header->_M_left;
    basic_string str;
    long size;
    while (node != header->_M_header) {
        str._M_data = (_Rb_tree_node_base*)((char*)node + 1);
        size = *((long*)((char*)node + 24));
        if (size > 15) {
            str._M_data = malloc(size);
            memcpy(str._M_data, (_Rb_tree_node_base*)((char*)node + 1), size);
        }

        int lower = 0;
        int upper = 0;
        for (int i = 0; i < size; i++) {
            char c = str._M_data[i];
            if (c < 'A') {
                break;
            } else if (c > 'Z') {
                upper = 1;
            } else {
                lower = 1;
            }
        }

        if (lower && upper) {
            free(str._M_data);
            return 0;
        }

        node = (_Rb_tree_node_base*)((char*)node + 32);
    }

    return 1;
}
