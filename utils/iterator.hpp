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
    template<typename T>
    class random_access_iterator
    {
        public:
                random_access_iterator(T *initLoc){
                    _current = initLoc;
                }

                bool    operator!=(const random_access_iterator &rhs){
                    return _current != rhs._current;
                }

                bool    operator==(const random_access_iterator &rhs){
                    return _current == rhs._current;
                }

                random_access_iterator    operator+(int x){
                    while (x > 0){
                        _current++;
                        x--;
                    }
                    return *this;
                }

                random_access_iterator    operator-(int x){
                    while (x > 0){
                        _current--;
                        x--;
                    }
                    return *this;
                }

                random_access_iterator  &operator--(){
                    _current--;
                    return *this;
                }
                random_access_iterator  operator--(int){
                    random_access_iterator oldCopy = *this;
                    _current--;
                    return oldCopy;
                }

                random_access_iterator   &operator++(){
                    _current++;
                    return *this;
                }
                random_access_iterator   operator++(int){
                    random_access_iterator oldCopy = *this;
                    _current++;
                    return oldCopy;
                }
                T   &operator*(){
                    return *_current;
                }

            private:
                T   *_current;
    };

    template<typename T>
    class reverse_iterator
    {
        public:
            reverse_iterator(T *initLoc){
                _current = initLoc;
            }

            bool    operator!=(const reverse_iterator &rhs){
                return _current != rhs._current;
            }

            reverse_iterator    operator+(int x){
                while (x > 0){
                    _current++;
                    x--;
                }
                return *this;
            }

            reverse_iterator    operator-(int x){
                while (x > 0){
                    _current--;
                    x--;
                }
                return *this;
            }

            reverse_iterator   &operator++(){
                _current++;
                return *this;
            }
            reverse_iterator   operator++(int){
                reverse_iterator oldCopy = *this;
                _current++;
                return oldCopy;
            }
            T   &operator*(){
                return *_current;
            }

        private:
            T   *_current;
    };

    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1) {
            if (!(*first1 == *first2)) 
                return false;
            ++first1; ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1){
            if (first2==last2 || *first2<*first1)
                return false;
            else if (*first1<*first2)
                return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }
}

#endif