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

            Node<T>         *node() { return _current; }

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

            void _previous(){
                Node<T> *next;
				if (!_current->left){
					next = _current;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->left;
					while (next->right)
						next = next->right;
				}
                _current = next;
	        }

            void _next(){
                Node<T> *next;
				if (!_current->right){
					next = _current;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->right;
					while (next->left)
						next = next->left;
				}
                _current = next;
	        }		    
    };

    template<typename T>
    class const_BST_iterator
    {
        public:
            const_BST_iterator() : _current() {}
            const_BST_iterator(Node<T> *initLoc) : _current(initLoc) {}
            const_BST_iterator(const const_BST_iterator &src)
            : _current(src._current) {}

            ~const_BST_iterator() {}

            const_BST_iterator    &operator=(const const_BST_iterator &rhs){
                _current = rhs._current;
                return *this;
            }

            bool            operator!=(const const_BST_iterator &rhs) { return _current != rhs._current; }
            bool            operator==(const const_BST_iterator &rhs) { return _current == rhs._current; }

            Node<T>         *node() { return _current; }

            T               &operator*() const { return _current->val; }
            T               *operator->() const { return &(operator*()); }

            const_BST_iterator    operator+(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }
            const_BST_iterator    operator-(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }

            const_BST_iterator    operator+=(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }
            const_BST_iterator    operator-=(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }

            const_BST_iterator    &operator--(){
                _previous();
                return *this;
            }
            const_BST_iterator    operator--(int){
                const_BST_iterator oldCopy = *this;
                _previous();
                return oldCopy;
            }
            const_BST_iterator    &operator++(){
                _next();
                return *this;
            }
            const_BST_iterator    operator++(int){
                const_BST_iterator oldCopy = *this;
                _next();
                return oldCopy;
            }

        private:
            Node<T> *_current;

            void _previous(){
                Node<T> *next;
				if (!_current->left){
					next = _current;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->left;
					while (next->right)
						next = next->right;
				}
                _current = next;
	        }

            void _next(){
                Node<T> *next;
				if (!_current->right){
					next = _current;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->right;
					while (next->left)
						next = next->left;
				}
                _current = next;
	        }		    
    };

    template<typename T>
    class reverse_BST_iterator
    {
        public:
            reverse_BST_iterator() : _current() {}
            reverse_BST_iterator(Node<T> *initLoc) : _current(initLoc) {}
            reverse_BST_iterator(const reverse_BST_iterator &src)
            : _current(src._current) {}

            ~reverse_BST_iterator() {}

            reverse_BST_iterator    &operator=(const reverse_BST_iterator &rhs){
                _current = rhs._current;
                return *this;
            }

            bool            operator!=(const reverse_BST_iterator &rhs) { return _current != rhs._current; }
            bool            operator==(const reverse_BST_iterator &rhs) { return _current == rhs._current; }

            Node<T>         *node() { return _current; }

            T               &operator*() { return _current->val; }
            T               *operator->() { return &(operator*()); }

            reverse_BST_iterator    operator+(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }
            reverse_BST_iterator    operator-(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }

            reverse_BST_iterator    operator+=(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }
            reverse_BST_iterator    operator-=(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }

            reverse_BST_iterator    &operator--(){
                _next();
                return *this;
            }
            reverse_BST_iterator    operator--(int){
                reverse_BST_iterator oldCopy = *this;
                _next();
                return oldCopy;
            }
            reverse_BST_iterator    &operator++(){
                _previous();
                return *this;
            }
            reverse_BST_iterator    operator++(int){
                reverse_BST_iterator oldCopy = *this;
                _previous();
                return oldCopy;
            }

        private:
            Node<T> *_current;

            void _previous(){
                Node<T> *next;
				if (!_current->left){
					next = _current;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->left;
					while (next->right)
						next = next->right;
				}
                _current = next;
	        }

            void _next(){
                Node<T> *next;
				if (!_current->right){
					next = _current;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->right;
					while (next->left)
						next = next->left;
				}
                _current = next;
	        }		    
    };

    template<typename T>
    class const_reverse_BST_iterator
    {
        public:
            const_reverse_BST_iterator() : _current() {}
            const_reverse_BST_iterator(Node<T> *initLoc) : _current(initLoc) {}
            const_reverse_BST_iterator(const const_reverse_BST_iterator &src)
            : _current(src._current) {}

            ~const_reverse_BST_iterator() {}

            const_reverse_BST_iterator    &operator=(const const_reverse_BST_iterator &rhs){
                _current = rhs._current;
                return *this;
            }

            bool            operator!=(const const_reverse_BST_iterator &rhs) { return _current != rhs._current; }
            bool            operator==(const const_reverse_BST_iterator &rhs) { return _current == rhs._current; }

            Node<T>         *node() { return _current; }

            T               &operator*() const { return _current->val; }
            T               *operator->() const { return &(operator*()); }

            const_reverse_BST_iterator    operator+(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }
            const_reverse_BST_iterator    operator-(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }

            const_reverse_BST_iterator    operator+=(int x){
                while (x-- > 0)
                    _previous();
                return *this;
            }
            const_reverse_BST_iterator    operator-=(int x){
                while (x-- > 0)
                    _next();
                return *this;
            }

            const_reverse_BST_iterator    &operator--(){
                _next();
                return *this;
            }
            const_reverse_BST_iterator    operator--(int){
                const_reverse_BST_iterator oldCopy = *this;
                _next();
                return oldCopy;
            }
            const_reverse_BST_iterator    &operator++(){
                _previous();
                return *this;
            }
            const_reverse_BST_iterator    operator++(int){
                const_reverse_BST_iterator oldCopy = *this;
                _previous();
                return oldCopy;
            }

        private:
            Node<T> *_current;

            void _previous(){
                Node<T> *next;
				if (!_current->left){
					next = _current;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->left;
					while (next->right)
						next = next->right;
				}
                _current = next;
	        }

            void _next(){
                Node<T> *next;
				if (!_current->right){
					next = _current;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{
					next = _current->right;
					while (next->left)
						next = next->left;
				}
                _current = next;
	        }		    
    };
    
}

#endif