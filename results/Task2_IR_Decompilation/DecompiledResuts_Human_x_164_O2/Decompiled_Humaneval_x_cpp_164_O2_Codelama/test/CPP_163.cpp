void generate_integers(vector<int>& vec, int start, int end) {
  for (int i = start; i <= end; i++) {
    if (vec.empty()) {
      vec.push_back(i);
    } else if (i < vec[0]) {
      vec.insert(vec.begin(), i);
    } else if (i > vec[vec.size() - 1]) {
      vec.push_back(i);
    } else {
      int j = 0;
      while (j < vec.size() && vec[j] < i) {
        j++;
      }
      vec.insert(vec.begin() + j, i);
    }
  }
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
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}
