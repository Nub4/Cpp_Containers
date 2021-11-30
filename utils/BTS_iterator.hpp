#ifndef BTS_ITERATOR_HPP
# define BTS_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "../containers/map.hpp"

namespace ft
{
    // template<typename T>
    // class BTS_iterator
    // {
    //     public:
    //     /* Is default-constructible, copy-constructible, copy-assignable and destructible:*/
    //         BTS_iterator() : _current() {}
    //         BTS_iterator(T *initLoc) : _current(initLoc) {}
    //         BTS_iterator(const BTS_iterator &src) : _current(src._current) {}
    //         virtual ~BTS_iterator() {}

    //         BTS_iterator    &operator=(const BTS_iterator &rhs){
    //             _current = rhs._current;
    //             return *this;
    //         }

    //         /* Can be compared for equivalence using the equality/inequality operators
    //         (meaningful when both iterator values iterate over the same underlying sequence): */
    //         bool    operator!=(const BTS_iterator &rhs) { return _current != rhs._current; }
    //         bool    operator==(const BTS_iterator &rhs) { return _current == rhs._current; }

    //         /* Can be dereferenced as an rvalue (if in a dereferenceable state): */
    //         T       &operator*() { return *_current; }
    //         T       *operator->() { return &(operator*()); }

    //         /* Supports the arithmetic operators + and - between an iterator and an integer value,
    //         or subtracting an iterator from another: */
    //         BTS_iterator  operator+(int x){
    //             while (x-- > 0)
    //                 _current++;
    //             return *this;
    //         }
    //         BTS_iterator  operator-(int x){
    //             while (x-- > 0)
    //                 _current--;
    //             return *this;
    //         }

    //     private:
    //         T   *_current;
    // };
}

#endif