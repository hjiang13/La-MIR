#include <stdlib.h>
#include <string.h>

struct std_vector {
	struct _Vector_base _M_impl;
};

struct _Vector_base {
	struct _Vector_base_impl_data _M_impl_data;
};

struct _Vector_base_impl_data {
	int* _M_start;
	int* _M_finish;
	int* _M_end_of_storage;
};

extern "C" void __real__Z11count_up_toi(struct std_vector *this, int n);

void count_up_toi(struct std_vector *this, int n) {
	int *start = this->_M_impl._M_impl_data._M_start;
	int *finish = this->_M_impl._M_impl_data._M_finish;
	int *end_of_storage = this->_M_impl._M_impl_data._M_end_of_storage;
	if (n > 2) {
		if (start == NULL) {
			start = (int*)malloc(2 * sizeof(int));
			finish = start;
			end_of_storage = start + 2;
		}
		for (int i = 2; i <= n; i++) {
			if (finish == end_of_storage) {
				int new_size = (end_of_storage - start) * 2;
				int *new_start = (int*)malloc(new_size * sizeof(int));
				memcpy(new_start, start, (end_of_storage - start) * sizeof(int));
				free(start);
				start = new_start;
				finish = new_start + (end_of_storage - start);
				end_of_storage = new_start + new_size;
			}
			*finish = i;
			finish++;
		}
	}
	this->_M_impl._M_impl_data._M_start = start;
	this->_M_impl._M_impl_data._M_finish = finish;
	this->_M_impl._M_impl_data._M_end_of_storage = end_of_storage;
}

int main() {
	struct std_vector v;
	count_up_toi(&v, 10);
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
    assert (issame(count_up_to(5) , {2,3}));
    assert (issame(count_up_to(6) , {2,3,5}));
    assert (issame(count_up_to(7) , {2,3,5}));
    assert (issame(count_up_to(10) , {2,3,5,7}));
    assert (issame(count_up_to(0) , {}));
    assert (issame(count_up_to(22) , {2,3,5,7,11,13,17,19}));
    assert (issame(count_up_to(1) , {}));
    assert (issame(count_up_to(18) , {2,3,5,7,11,13,17}));
    assert (issame(count_up_to(47) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}));
    assert (issame(count_up_to(101) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}));
}
