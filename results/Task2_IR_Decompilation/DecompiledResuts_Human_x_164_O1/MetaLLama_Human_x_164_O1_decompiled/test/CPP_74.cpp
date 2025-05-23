#include <string.h>
#include <stddef.h>

typedef struct {
    char* data;
    size_t size;
    size_t capacity;
} Vector;

typedef struct {
    char* data;
    size_t size;
} String;

void total_match(Vector* result, const Vector* vec1, const Vector* vec2) {
    if (vec1->size == 0) {
        *result = *vec2;
        memset(vec2, 0, sizeof(Vector));
        return;
    }

    if (vec2->size == 0) {
        *result = *vec1;
        memset(vec1, 0, sizeof(Vector));
        return;
    }

    size_t sum1 = 0;
    for (size_t i = 0; i < vec1->size; i++) {
        String* str = (String*)vec1->data + i;
        sum1 += str->size;
    }

    size_t sum2 = 0;
    for (size_t i = 0; i < vec2->size; i++) {
        String* str = (String*)vec2->data + i;
        sum2 += str->size;
    }

    if (sum1 > sum2) {
        *result = *vec1;
        memset(vec1, 0, sizeof(Vector));
    } else {
        *result = *vec2;
        memset(vec2, 0, sizeof(Vector));
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(total_match({}, {}) , {}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi"}) , {"hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi", "admin", "project"}) , {"hi", "admin"}));
    assert (issame(total_match({"4"}, {"1", "2", "3", "4", "5"}) , {"4"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "Hi"}) , {"hI", "Hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hi"}) , {"hI", "hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hii"}) , {"hi", "admin"}));
    assert (issame(total_match({}, {"this"}) , {}));
    assert (issame(total_match({"this"}, {}) , {}));
}
