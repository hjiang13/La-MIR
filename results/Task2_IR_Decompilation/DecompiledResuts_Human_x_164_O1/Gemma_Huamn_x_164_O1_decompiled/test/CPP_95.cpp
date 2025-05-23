#include <stdlib.h>
#include <string.h>

typedef struct _Rb_tree_node_base {
    int i32;
    struct _Rb_tree_node_base *left;
    struct _Rb_tree_node_base *right;
    struct _Rb_tree_node_base *parent;
} _Rb_tree_node_base;

typedef struct _Rb_tree_color {
    char c;
} _Rb_tree_color;

typedef struct _Alloc_hider {
    char *p;
} _Alloc_hider;

typedef struct basic_string {
    struct _Alloc_hider _Alloc_hider;
    long long _M_length;
    union {
        long long _M_data;
        char _M_data_ptr[8];
    };
} basic_string;

typedef struct map {
    struct _Rb_tree_node_base _M_header;
    long long _M_size;
} map;

int check_dict_case(map *m) {
    long long size = *((long long *)((char *)m + 40));
    if (size == 0) {
        return 0;
    }
    _Rb_tree_node_base *root = (_Rb_tree_node_base *)((char *)m + 24);
    _Rb_tree_node_base *current = root;
    int count = 0;
    int result = 0;
    while (current != (_Rb_tree_node_base *)((char *)m + 8)) {
        basic_string key;
        char *key_data = *((char **)((char *)&current + 8));
        long long key_length = *((long long *)((char *)&current + 16));
        key._M_length = key_length;
        key._Alloc_hider.p = key_data;
        int ascii_count = 0;
        int non_ascii_count = 0;
        for (long long i = 0; i < key_length; i++) {
            if (key_data[i] < 127) {
                ascii_count++;
            } else {
                non_ascii_count++;
            }
        }
        if (ascii_count > 0 && non_ascii_count > 0) {
            result = 1;
        }
        count++;
        current = (_Rb_tree_node_base *)((char *)current + 24);
        if (current == (_Rb_tree_node_base *)((char *)m + 8)) {
            break;
        }
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (check_dict_case({{"p","pineapple"}, {"b","banana"}}) == true);
    assert (check_dict_case({{"p","pineapple"}, {"A","banana"}, {"B","banana"}}) == false);
    assert (check_dict_case({{"p","pineapple"}, {"5","banana"}, {"a","apple"}}) == false);
    assert (check_dict_case({{"Name","John"}, {"Age","36"}, {"City","Houston"}}) == false);
    assert (check_dict_case({{"STATE","NC"}, {"ZIP","12345"} }) == true  );
    assert (check_dict_case({{"fruit","Orange"}, {"taste","Sweet"} }) == true  );
    assert (check_dict_case({}) == false);
}
