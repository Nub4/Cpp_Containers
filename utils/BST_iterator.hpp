#ifndef BTS_ITERATOR_HPP
# define BTS_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "../containers/map.hpp"

namespace ft
{
    template<typename T>
    class BST_iterator
    {
        public:
            BST_iterator() : _current() {}
            BST_iterator(Node<T> *initLoc) : _current(initLoc) {}
            BST_iterator(const BST_iterator &src)
            : _current(src._current) {}

            ~BST_iterator() {}

            BST_iterator    &operator=(const BST_iterator &rhs){
                _current = rhs._current;
                return *this;
            }

            bool            operator!=(const BST_iterator &rhs) { return _current != rhs._current; }
            bool            operator==(const BST_iterator &rhs) { return _current == rhs._current; }

            T               &operator*() { return _current->val; }
            T               *operator->() { return &(operator*()); }

            BST_iterator    operator+(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }
            BST_iterator    operator-(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }

            BST_iterator    operator+=(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }
            BST_iterator    operator-=(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }

            Node<T>         &operator[](int n) { return (*(operator+(n))); }

            BST_iterator    &operator--(){
                _previous();
                return *this;
            }
            BST_iterator    operator--(int){
                BST_iterator oldCopy = *this;
                _previous();
                return oldCopy;
            }
            BST_iterator    &operator++(){
                _next();
                return *this;
            }
            BST_iterator    operator++(int){
                BST_iterator oldCopy = *this;
                _next();
                return oldCopy;
            }

        private:
            Node<T> *_current;

            void _previous()
            {
                if (_current->left && !_current->right)
                    _current = NULL;
		        else if (_current->left)
                {
			        _current = _current->left;
			        while (_current->right)
				        _current = _current->right;
		        }
                else
			        _current = _current->parent;
	        }

            void _next()
            {
                Node<T> *next;
				if (!_current->right)
				{
					next = _current;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = _current->right;
					while (next->left)
						next = next->left;
				}
                _current = next;
	        }		    
    };
}

#endif