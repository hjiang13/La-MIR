#include <vector>
#include <stdexcept>
#include <initializer_list>

void eat(std::vector<int>& result, int a, int b, int c) {
    if (b > c) {
        std::initializer_list<int> init_list = {a + c, 0};
        result = std::vector<int>(init_list);
    } else {
        std::initializer_list<int> init_list = {a + b, c - b};
        result = std::vector<int>(init_list);
    }
}

extern "C" void __clang_call_terminate(void*);

namespace __gnu_cxx {
    template<typename T>
    class new_allocator {
    public:
        new_allocator() noexcept {}
        new_allocator(const new_allocator&) noexcept {}
        ~new_allocator() noexcept {}

        T* allocate(std::size_t n, const void* hint = 0) {
            if (n > max_size()) {
                throw std::bad_alloc();
            }
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p, std::size_t) noexcept {
            ::operator delete(p);
        }

        std::size_t max_size() const noexcept {
            return std::numeric_limits<std::size_t>::max() / sizeof(T);
        }
    };
}

template<typename T>
class allocator : public __gnu_cxx::new_allocator<T> {
public:
    allocator() noexcept {}
    allocator(const allocator&) noexcept {}
    ~allocator() noexcept {}
};

template<typename T, typename Alloc = allocator<T>>
class vector {
    struct _Vector_impl {
        T* _M_start;
        T* _M_finish;
        T* _M_end_of_storage;
    };

    _Vector_impl _M_impl;

public:
    vector() noexcept : _M_impl{nullptr, nullptr, nullptr} {}

    vector(std::initializer_list<T> init, const Alloc& alloc = Alloc()) {
        _M_range_initialize(init.begin(), init.end());
    }

    ~vector() {
        _M_deallocate(_M_impl._M_start, _M_impl._M_end_of_storage - _M_impl._M_start);
    }

private:
    void _M_range_initialize(const T* first, const T* last) {
        std::size_t n = std::distance(first, last);
        _M_impl._M_start = _M_allocate(n);
        _M_impl._M_finish = std::uninitialized_copy(first, last, _M_impl._M_start);
        _M_impl._M_end_of_storage = _M_impl._M_start + n;
    }

    T* _M_allocate(std::size_t n) {
        if (n > _S_max_size()) {
            throw std::length_error("cannot create std::vector larger than max_size()");
        }
        return _M_get_Tp_allocator().allocate(n);
    }

    void _M_deallocate(T* p, std::size_t n) {
        if (p) {
            _M_get_Tp_allocator().deallocate(p, n);
        }
    }

    Alloc& _M_get_Tp_allocator() noexcept {
        return static_cast<Alloc&>(_M_impl);
    }

    std::size_t _S_max_size() const noexcept {
        return std::min(_M_get_Tp_allocator().max_size(), std::numeric_limits<std::ptrdiff_t>::max());
    }
};

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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}
