#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <limits>
# include "../utils/utils.hpp"
# include "../utils/BST_iterator.hpp"

namespace ft
{
    template<class Key, class T, class Compare = ft::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<key_type, mapped_type>                 value_type;
            typedef Compare                                         key_compare;
            class value_compare : ft::binary_function<value_type, value_type, bool>
            {
                friend class map<Key, T, Compare, Alloc>;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
            typedef Alloc                                           allocator_type;
            typedef value_type&                                     reference;
            typedef const value_type&                               const_reference;
            typedef value_type*                                     pointer;
            typedef const value_type*                               const_pointer;
            typedef ft::BST_iterator<value_type>                    iterator;
            typedef ft::const_BST_iterator<value_type>              const_iterator;
            typedef ft::reverse_BST_iterator<value_type>              reverse_iterator;
            typedef ft::const_reverse_BST_iterator<value_type>  const_reverse_iterator;
            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;

        public:
        /* Containers: */
            explicit map(const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _comp(comp), _rootNode(NULL), _size(0) {}

            template <class InputIterator>
            map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
            : _alloc(alloc), _comp(comp), _rootNode(NULL), _size(0){
                for ( ; first != last; first++)
                    insert(*first);
            }

            map(const map& x)
            : _alloc(x._alloc), _comp(x._comp), _rootNode(NULL), _size(0){
                insert(x.begin(), x.end());
            }

            ~map() { clear(); }

            map& operator= (const map& x){
                clear();
                insert(x.begin(), x.end());
                return *this;
            }

        /* Capacity: */
            bool empty() const{
                if (!_size)
                    return true;
                return false;
            }

            size_type size() const { return _size; }

            size_type max_size() const { return _node.max_size(); }

        /* Iterators: */
            iterator                 begin(){
                if (!_size)
                    return iterator(_rootNode);
                return iterator(_first_node(_rootNode));
            }

            const_iterator           begin() const{
                if (!_size)
                    return const_iterator(_rootNode);
                return const_iterator(_first_node(_rootNode));
            }

            iterator                 end(){
                if (!_size)
                    return iterator(_rootNode);
                Node<value_type> *temp = _last_node(_rootNode);
                return iterator(temp->right);
            }

            const_iterator           end() const{
                if (!_size)
                    return const_iterator(_rootNode);
                Node<value_type> *temp = _last_node(_rootNode);
                return const_iterator(temp->right);
            }

            reverse_iterator         rbegin(){
                if (!_size)
                    return reverse_iterator(_rootNode);
                return reverse_iterator(_last_node(_rootNode));
            }

            const_reverse_iterator   rbegin() const{
                if (!_size)
                    return const_reverse_iterator(_rootNode);
                return const_reverse_iterator(_last_node(_rootNode));
            }

            reverse_iterator         rend(){
                if (!_size)
                    return reverse_iterator(_rootNode);
                Node<value_type> *temp = _first_node(_rootNode);
                return reverse_iterator(temp->left);
            }

            const_reverse_iterator   rend() const{
                if (!_size)
                    return const_reverse_iterator(_rootNode);
                Node<value_type> *temp = _first_node(_rootNode);
                return const_reverse_iterator(temp->left);
            }

        /* Operations: */
            iterator    find(const key_type& k){
                iterator it = begin();
                while (it != end() && k != it->first)
                    it++;
                return it;
            }

            const_iterator find (const key_type& k) const{
                const_iterator it = begin();
                while (it != end() && k != it->val.first)
                    it++;
                return it;
            }

            size_type count (const key_type& k) const{
                const_iterator it = begin();
                while (it != end() && k != it->first)
                    it++;
                if (it == end())
                    return 0;
                return 1;
            }

            iterator lower_bound (const key_type& k){
                iterator it = begin();
                while (it != end() && k != it->first)
                    it++;
                return it;   
            }

            const_iterator lower_bound (const key_type& k) const{
                const_iterator it = begin();
                while (it != end() && k != it->first)
                    it++;
                return it;
            }

            iterator upper_bound (const key_type& k){
                iterator it = begin();
                while (it != end() && k != it->first)
                    it++;
                if (it == end())
                    return it;
                return (it + 1);
            }

            const_iterator upper_bound (const key_type& k) const{
                const_iterator it = begin();
                while (it != end() && k != it->first)
                    it++;
                if (it == end())
                    return it;
                return (it + 1);
            }

            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
                return ft::make_pair(lower_bound(k), upper_bound(k));
            }

            ft::pair<iterator, iterator>    equal_range (const key_type& k){
                return ft::make_pair(lower_bound(k), upper_bound(k));
            }

        /* Element access: */

            mapped_type& operator[] (const key_type& k){
                iterator it = find(k);
                if (it == end())
                    insert(ft::make_pair(k, mapped_type()));
                iterator it2 = find(k);
                return it2->second;
            }

        /* Modifiers */
            ft::pair<iterator,bool> insert(const value_type& val){
                if (!_rootNode){
                    _node_insert_value(&_rootNode, val, NULL);
                    return ft::make_pair(iterator(_rootNode), true);
                }
                Node<value_type> *temp = _rootNode;
                int mark = 0;
                while (mark == 0){
                    if (val.first == temp->val.first)
                        return ft::make_pair(iterator(temp), false);
                    if (temp->val.first > val.first){
                        if (!temp->left){
                            _node_insert_value(&temp->left, val, temp);
                            mark = 1;
                        }
                        else
                            temp = temp->left;
                    }
                    else{
                        if (!temp->right){
                            _node_insert_value(&temp->right, val, temp);
                            mark = 1;
                        } 
                        else
                            temp = temp->right;
                    }
                }
                return ft::make_pair(iterator(temp), true);
            }

            iterator insert (iterator position, const value_type& val){
                (void)position;
                ft::pair<iterator,bool> temp = insert(val);
                return temp.first;
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last){
                for (; first != last; first++)
                    insert(*first);
            }

            void    clear() { _delete_all_nodes(_rootNode); _rootNode = NULL; }

            void erase (iterator position){
                iterator it = begin();
                while (it != end() && it != position)
                    it++;
                if (it == end())
                    return ;
                _delete_node(position.node());
            }

            size_type erase (const key_type& k){
                iterator it = find(k);
                if (it == end())
                    return 0;
                erase(it);
                return 1;
            }

            void erase (iterator first, iterator last){
                while (first != last)
                    erase(first++);
            }

            void swap (map& x){
                ft::swap(_size, x._size);
                ft::swap(_rootNode, x._rootNode);
            }

        /* Observes */
            key_compare key_comp() const { return key_compare(); }

            value_compare value_comp() const { return value_compare(key_compare()); }

        /* Allocator */
            allocator_type get_allocator() const { return _alloc; }

        private:
            allocator_type                      _alloc;
            key_compare                         _comp;
            Node<value_type>                    *_rootNode;
            size_type                           _size;
            std::allocator<Node<value_type> >   _node;

            void _newNode(Node<value_type> **dest, ft::pair<Key, T> val, Node<value_type> *parent = NULL){
			    *dest = _node.allocate(1);
			    _node.construct(*dest, Node<value_type>(val, parent));
			    _size++;
		    }

            void    _delete_all_nodes(Node<value_type> *root)
            {
                if (!root)
                    return ;
                if (root->left)
                    _delete_all_nodes(root->left);
                if (root->right)
                    _delete_all_nodes(root->right);
                _node.destroy(root);
                _node.deallocate(root, 1);
                _size--;
            }

            void _delete_node(Node<value_type> *n){
                if (!n->left && !n->right && !n->parent)
                {
                    _node.destroy(n);
                    _node.deallocate(n, 1);
                    _size--;
                    _rootNode = NULL;
					return ;
                }
				Node<value_type> *parent = n->parent;
				if (!n->left && !n->right && parent){
					if (parent->right == n)
						parent->right = 0;
					else
						parent->left = 0;
                    _node.destroy(n);
                    _node.deallocate(n, 1);
                    _size--;
					return ;
			    }
				if (n->right && !n->left && parent){
					if (parent->right == n)
						parent->right = n->right;
					else
						parent->left = n->right;
					n->right->parent = parent;
                    _node.destroy(n);
                    _node.deallocate(n, 1);
                    _size--;
					return ;
				}
				if (n->left && !n->right && parent){
					if (parent->right == n)
						parent->right = n->left;
					else
						parent->left = n->left;
					n->left->parent = parent;
                    _node.destroy(n);
                    _node.deallocate(n, 1);
                    _size--;
					return ;
				}
				Node<value_type> *next = (++iterator(n)).node();
				if (!next)
					next = (--iterator(n)).node();
				ft::swap(next->val, n->val);
				_delete_node(next);
			};

            Node<value_type>    *_first_node(Node<value_type> *root){
                while (root->left)
                    root = root->left;
                return (root);
            }

            Node<value_type>    *_first_node(Node<value_type> *root) const{
                while (root->left)
                    root = root->left;
                return (root);
            }

            Node<value_type>    *_last_node(Node<value_type> *root){
                while (root->right)
                    root = root->right;
                return (root);
            }

            Node<value_type>    *_last_node(Node<value_type> *root) const{
                while (root->right)
                    root = root->right;
                return (root);
            }

            void    _node_insert_value(Node<value_type> **root, value_type value, Node<value_type> *p)
            {
                if (!(*root))
                    _newNode(root, value, p);
                else if (value.first < (*root)->val.first)
                    _node_insert_value(&(*root)->left, value, *root);
                else
                    _node_insert_value(&(*root)->right, value, *root);
            }
    };
}

#endif











































