#include <stdint.h>
#include <string.h>

int can_arrange(int* data, int size) {
    int i;
    int result = -1;
    for (i = 0; i < size; i++) {
        if (i < data[i]) {
            result = i;
        }
    }
    return result;
}

int main() {
    // Call the can_arrange function with some sample data
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    int result = can_arrange(data, size);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}
