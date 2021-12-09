#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <cstddef>
# include "../containers/vector.hpp"

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t,
    class Pointer = T*, class Reference = T&>
    class iterator
    {
        typedef Distance  difference_type;
        typedef T         value_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
    };

    struct random_access_iterator_tag {};

    template <class Iterator>
    class iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };
    
    template <class T>
    class iterator_traits<T*>
    {
        typedef ptrdiff_t                           difference_type;
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        typedef ft::random_access_iterator_tag      iterator_category;
    };
    
    template <class T>
    class iterator_traits<const T*>
    {
        typedef ptrdiff_t                           difference_type;
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        typedef ft::random_access_iterator_tag      iterator_category;
    };

    template<typename T>
    class random_access_iterator
    {
        public:
            random_access_iterator() : _current() {}
            random_access_iterator(T *initLoc) :_current(initLoc) {}
            random_access_iterator(const random_access_iterator &src)
            : _current(src._current) {}
            
            ~random_access_iterator() {}

            random_access_iterator  &operator=(const random_access_iterator &rhs){
                _current = rhs._current;
                return *this;
            }

            bool    operator!=(const random_access_iterator &rhs) { return _current != rhs._current; }
            bool    operator==(const random_access_iterator &rhs) { return _current == rhs._current; }

            T       &operator*() const { return *_current; }
            T       *operator->() const { return &(operator*()); }

            random_access_iterator  operator+(int x){
                while (x-- > 0)
                    _current++;
                return *this;
            }
            random_access_iterator  operator-(int x){
                while (x-- > 0)
                    _current--;
                return *this;
            }

            random_access_iterator  operator+=(int x){
                while (x-- > 0)
                    _current++;
                return *this;
            }
            random_access_iterator  operator-=(int x){
                while (x-- > 0)
                    _current--;
                return *this;
            }

            T   &operator[](int n) { return (*(operator+(n))); }

            random_access_iterator  &operator--(){
                _current--;
                return *this;
            }
            random_access_iterator  operator--(int){
                random_access_iterator oldCopy = *this;
                _current--;
                return oldCopy;
            }
            random_access_iterator  &operator++(){
                _current++;
                return *this;
            }
            random_access_iterator  operator++(int){
                random_access_iterator oldCopy = *this;
                _current++;
                return oldCopy;
            }

            private:
                T   *_current;
    };

    template<typename T>
    class reverse_iterator
    {
        public:
            reverse_iterator() : _current() {}
            reverse_iterator(T *initLoc) :_current(initLoc) {}
            reverse_iterator(const reverse_iterator &src)
            : _current(src._current) {}
                
            ~reverse_iterator() {}

            reverse_iterator  &operator=(const reverse_iterator &rhs){
                _current = rhs._current;
                return *this;
            }

            bool    operator!=(const reverse_iterator &rhs) { return _current != rhs._current; }
            bool    operator==(const reverse_iterator &rhs) { return _current == rhs._current; }

            T       &operator*() const { return *_current; }
            T       *operator->() const { return &(operator*()); }

            reverse_iterator  operator+(int x){
                while (x-- > 0)
                    _current--;
                return *this;
            }
            reverse_iterator  operator-(int x){
                while (x-- > 0)
                    _current++;
                return *this;
            }

            reverse_iterator  operator+=(int x){
                while (x-- > 0)
                    _current--;
                return *this;
            }
            reverse_iterator  operator-=(int x){
                while (x-- > 0)
                    _current++;
                return *this;
            }

            T   &operator[](int n) { return (*(operator-(n))); }

            reverse_iterator  &operator--(){
                _current++;
                return *this;
            }
            reverse_iterator  operator--(int){
                reverse_iterator oldCopy = *this;
                _current++;
                return oldCopy;
            }
            reverse_iterator  &operator++(){
                _current--;
                return *this;
            }
            reverse_iterator  operator++(int){
                reverse_iterator oldCopy = *this;
                _current--;
                return oldCopy;
            }

            private:
                T   *_current;
    };
}

#endif