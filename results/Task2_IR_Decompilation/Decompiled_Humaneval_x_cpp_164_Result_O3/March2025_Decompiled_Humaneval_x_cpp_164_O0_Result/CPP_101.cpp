```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <new>

void words_string(std::vector<std::string>& result, const std::string& input) {
    std::string temp;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c == ' ' || c == ',') {
            if (!temp.empty()) {
                result.push_back(temp);
                temp.clear();
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        result.push_back(temp);
    }
}

namespace std {
    template<typename T>
    class allocator {
    public:
        T* allocate(size_t n) {
            if (n > max_size()) {
                throw std::bad_alloc();
            }
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p, size_t) {
            ::operator delete(p);
        }

        size_t max_size() const noexcept {
            return size_t(-1) / sizeof(T);
        }

        template<typename U, typename... Args>
        void construct(U* p, Args&&... args) {
            ::new((void*)p) U(std::forward<Args>(args)...);
        }

        template<typename U>
        void destroy(U* p) {
            p->~U();
        }
    };

    template<typename T, typename Alloc = allocator<T>>
    class vector {
    public:
        vector() : start(nullptr), finish(nullptr), end_of_storage(nullptr) {}

        ~vector() {
            clear();
            alloc.deallocate(start, capacity());
        }

        void push_back(const T& value) {
            if (finish == end_of_storage) {
                reallocate();
            }
            alloc.construct(finish, value);
            ++finish;
        }

        size_t size() const noexcept {
            return finish - start;
        }

        size_t capacity() const noexcept {
            return end_of_storage - start;
        }

        void clear() noexcept {
            while (finish != start) {
                alloc.destroy(--finish);
            }
        }

    private:
        void reallocate() {
            size_t old_size = size();
            size_t new_capacity = old_size ? 2 * old_size : 1;
            T* new_start = alloc.allocate(new_capacity);
            T* new_finish = new_start;
            try {
                for (T* it = start; it != finish; ++it, ++new_finish) {
                    alloc.construct(new_finish, std::move(*it));
                }
            } catch (...) {
                while (new_start != new_finish) {
                    alloc.destroy(--new_finish);
                }
                alloc.deallocate(new_start, new_capacity);
                throw;
            }
            clear();
            alloc.deallocate(start, capacity());
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start + new_capacity;
        }

        T* start;
        T* finish;
        T* end_of_storage;
        Alloc alloc;
    };
}
```