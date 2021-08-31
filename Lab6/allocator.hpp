//
// Created by YaTeb on 12/27/2020.
//

#ifndef LAB6_ALLOCATOR_HPP
#define LAB6_ALLOCATOR_HPP
#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <memory>

#include <stack>

namespace allocators {

    template<class T,size_t BLOCK_COUNT = 100>
    class stack_allocator {
    private:
        char* _used_blocks;
        std::stack<char*> _free_blocks;

    public:
        using value_type = T;
        using pointer = T * ;
        using const_pointer = const T*;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using is_always_equal = std::false_type;

        stack_allocator() {
            static_assert(BLOCK_COUNT>0);
            _used_blocks = (char*) malloc(sizeof(T) * BLOCK_COUNT);

            for (uint64_t i = 0; i < BLOCK_COUNT; ++i)
                _free_blocks.push((char*)(_used_blocks + i * sizeof(T)));
        }

        ~stack_allocator(){
            free(_used_blocks);
        }

        template<typename U>
        struct rebind {
            using other = stack_allocator<U, BLOCK_COUNT>;
        };

        T* allocate(size_t n) {

            size_t free_count = _free_blocks.size();
            if (free_count < n) {
                throw std::bad_alloc();
            }

            T* ptr = (T*)(_used_blocks + (BLOCK_COUNT - free_count));
            for (size_t i = 0; i < n; ++i)
                _free_blocks.pop();

            return ptr;
        }

        void deallocate(T* ptr,  size_t n = 1) {
            for (size_t i = 0; i < n; ++i)
                _free_blocks.push( (char*)ptr + (i * sizeof(T)) );
        }

        template<typename U, typename ...Args>
        void construct(U *p, Args &&...args) {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p) {
            p->~T();
        }

    };
}
#endif //LAB6_ALLOCATOR_HPP
