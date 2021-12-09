#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <cstddef>
# include "../utils/iterator.hpp"
# include "stack.hpp"
# include "../utils/utils.hpp"

namespace ft
{
    template<class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:        
            typedef T                                               value_type; 
            typedef Alloc                                           allocator_type;
            typedef value_type&                                     reference;
            typedef const value_type&                               const_reference;
            typedef value_type*                                     pointer;
            typedef const value_type*                               const_pointer;
            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<value_type>                reverse_iterator;
            typedef ft::reverse_iterator<const value_type>          const_reverse_iterator;

        public:
        
            /* Member functions: */
            explicit vector(const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _size = 0;
                _capacity = 0;
                _arr = NULL;
            }

            explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _size = n;
                _capacity = n;
                _arr = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)  
                    _alloc.construct(_arr + i, val);
            }

            vector(const vector& x)
            {
                this->_alloc = _alloc;
                this->_size = 0;
                this->_capacity = 0;
                this->_arr = NULL;
                *this = x;
            }

            template<class InputIterator>
            vector(InputIterator first, InputIterator last,
            const allocator_type &alloc = allocator_type())
            {
                _alloc = alloc;
                _size = _distance(first, last);
                _capacity = _distance(first, last);
                _arr = _alloc.allocate(_capacity);
                assign(first, last);
            }

            ~vector() { _alloc.deallocate(_arr, _capacity); }

            vector  &operator=(const vector &x){
                _size = x._size;
                _capacity = x._size;
                _alloc = x._alloc;
                _arr = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(_arr + i, x._arr[i]);
                return *this;
            }

            /* Modifiers: */
            template<class InputIterator>
            void        assign(InputIterator first, InputIterator last){
                clear();
                for ( ; first != last; first++)
                    push_back(*first);
            }

            void        assign(size_type n, const value_type& val) {
                clear();
                while (n--)
                    push_back(val);
            }

            void        push_back(const value_type &val){
                if (_size == 0){
                    _alloc.deallocate(_arr, _capacity);
                    _capacity = 1;
                    _arr = _alloc.allocate(_capacity);
                }
                else if (_size == _capacity)
                    reserve(_capacity * 2);
                _alloc.construct(_arr + _size, val);
                _size++;
            }

            void        pop_back() {
                _alloc.destroy(_arr + _size);
                _size--; 
            }
        
            void        swap(vector &x) {
                size_type       temp_size = x._size;
                size_type       temp_capacity = x._capacity;
                pointer         temp_arr = x._arr;
                allocator_type  temp_alloc = x._alloc;

                x._size = _size;
                x._capacity = _capacity;
                x._arr = _arr;
                x._alloc = _alloc;

                _size = temp_size;
                _capacity = temp_capacity;
                _arr = temp_arr;
                _alloc = temp_alloc;
            }

            void        clear() {
                while (_size)
                    pop_back();
            }

            iterator    insert(iterator position, const value_type &val){
                insert(position, (size_type)1, val);
                return _arr;
            }

          void        insert(iterator position, size_type n, const value_type &val){
                if (position == end()){
                    while (n-- > 0)
                        push_back(val);
                    return ;
                }
                T   temp[_size + n];
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(temp + i, _arr[i]);
                size_type i = 0;
                size_type k = 0;
                size_type size = _size;
                for (iterator pos = begin(); pos != position; pos++){
                    _arr[i] = temp[i];
                    i++;
                    k++;
                }
                while (n-- > 0){
                    if (i >= _size)
                        push_back(val);
                    else
                        _arr[i] = val;
                    i++;
                }
                while (k < size){ 
                    if (i >= _size)
                        push_back(temp[k]);
                    else
                        _arr[i] = temp[k];
                    i++;
                    k++;
                }
            }

            template<class InputIterator>
            void        insert(iterator position, InputIterator first, InputIterator last){
                if (position == end()){
                    while (first != last){
                        push_back(*first);
                        first++;
                    }
                    return ;
                }
                size_type i = 0;
                size_type k = 0;
                size_type size = _size;
                T   temp[_size];
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(temp + i, _arr[i]);
                for (iterator pos = begin(); pos != position; pos++){
                    _arr[i] = temp[i];
                    i++;
                    k++;
                }
                while (first != last){
                    if (i >= _size)
                        push_back(*first);
                    else
                        _arr[i] = *first;
                    i++;
                    first++;
                }
                while (k < size){
                    if (i >= _size)
                        push_back(temp[k]);
                    else
                        _arr[i] = temp[k];
                    i++;
                    k++;
                }
            }

            iterator    erase(iterator position){
                iterator out = begin();
                for (iterator it = begin(); it != end(); it++){
                    if (it != position){
                        *out = *it;
                        out++;
                    }
                }
                pop_back();
                return (out);
            }

            iterator    erase(iterator first, iterator last){
                iterator out = begin();
                size_type i = _distance(first, last);
                size_type j = i;
                for (iterator it = begin(); it != end(); it++)
                {
                    if (it == first)
                        while (i-- > 0){
                            if (it == end())
                                break;
                            it++;
                        }
                    if (it == end())
                        break;
                    *out = *it;
                    out++;
                }
                while (j-- > 0)
                    pop_back();
                return out;
            }

            /* Capasity: */
            bool            empty() const { return (_size == 0); }
            size_type       capacity() const { return (_capacity); }       
            size_type       size() const { return (_size); }
            size_type       max_size() const { return ((size_type)(-1) / sizeof(T)); }

            void            resize(size_type n, value_type val = value_type()) {
                while (n < _size)
                    pop_back();
			    if (n > _capacity)
				    reserve(n);
    			while (n > _size)
	    			push_back(val);
            }

            void            reserve(size_type n) {
                if (n > max_size())
                    throw std::length_error("vector::reserve");
                else if (n > _capacity){
                    pointer temp = _alloc.allocate(n);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.construct(temp + i, _arr[i]);
                    _alloc.deallocate(_arr, _capacity);
                    _arr = temp;
                    _capacity = n;
                }
            }

            /* Element access: */
            reference               operator[](size_type n) { return _arr[n]; }
            const_reference         operator[](size_type n) const { return _arr[n]; }

            reference               at(size_type n) {
                if (n >= _size)
                    throw std::out_of_range("out of range");
                return _arr[n];
            }

            const_reference         at(size_type n) const {
                if (n >= _size)
                    throw std::out_of_range("out of range");
                return _arr[n];
            }

            reference               front() { return _arr[0]; }
            const_reference         front() const { return _arr[0]; }
            reference               back() { return _arr[_size - 1]; }
            const_reference         back() const { return _arr[_size - 1]; }

            /* Iterators */

            const_iterator          begin() const{ return const_iterator(_arr); }
            iterator                begin(){ return iterator(_arr); }
            const_iterator          end() const{ return const_iterator(_arr + _size); }
            iterator                end(){ return iterator(_arr + _size); }

            reverse_iterator        rbegin() { return reverse_iterator(_arr + _size - 1); }
            const_reverse_iterator  rbegin() const { return const_reverse_iterator(_arr + _size - 1); }
            reverse_iterator        rend() { return reverse_iterator(_arr - 1); }
            const_reverse_iterator  rend() const { return const_reverse_iterator(_arr - 1); }

        private:
            size_type       _size;
            size_type       _capacity; 
            pointer         _arr;
            allocator_type  _alloc;

            template<class InputIterator>
            size_type  _distance(InputIterator first, InputIterator last){
                size_type i = 0;
                while (first != last){
                    i++;
                    first++;
                }
                return i;
            }
    };

    /* Non-member function overloads */
    template <class T, class Alloc>
    void    swap(vector<T,Alloc> &x, vector<T, Alloc> &y){
        x.swap(y);
    }

    template <class T, class Alloc>
    bool    operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs){
        return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool    operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs){
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool    operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs){
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool    operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs){
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool    operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs){
        return (!(lhs <= rhs));
    }

    template <class T, class Alloc>
    bool    operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs){
        return (!(lhs < rhs));
    }
}

#endif