#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
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
            typedef ft::reverse_BST_iterator<iterator>              reverse_iterator;
            typedef ft::const_reverse_BST_iterator<const_iterator>  const_reverse_iterator;
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

            ~map() {}// clear(); }

            map& operator= (const map& x){
                _alloc = x._alloc;
                _comp = x._comp;
                _rootNode = NULL;
                _size = 0;
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
                    return reverse_iterator(_rootNode->left);
                Node<value_type> *temp = _first_node(_rootNode);
                return reverse_iterator(temp->left);
            }

            const_reverse_iterator   rend() const{
                if (!_size || !_rootNode->left)
                    return const_reverse_iterator(_rootNode->left);
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
                iterator it = begin();
                while (it != end() && k != it->val.first)
                    it++;
                if (it == end())
                    return 0;
                return 1;
            }

            iterator lower_bound (const key_type& k){
                iterator it = begin();
                while (it != end() && k >= it->val.first)
                    it++;
                return it;   
            }

            const_iterator lower_bound (const key_type& k) const{
                const_iterator it = begin();
                while (it != end() && k >= it->val.first)
                    it++;
                return it;
            }

            iterator upper_bound (const key_type& k){
                iterator it = begin();
                while (it != end() && k >= it->val.first)
                    it++;
                if (it == end())
                    return it;
                return (it + 1);
            }

            const_iterator upper_bound (const key_type& k) const{
                const_iterator it = begin();
                while (it != end() && k >= it->val.first)
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
                iterator it = find(val.first);
                if (it != end())
                    return ft::make_pair(it, false);
                Node<value_type> *temp = _rootNode;
                int mark = 0;
                while (mark == 0){
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

            void    clear() { _delete_all_nodes(_rootNode); }

            void erase (iterator position){
                iterator it = begin();
                while (it != end() && it != position)
                    it++;
                if (it == end())
                    return ;
                _rootNode = _delete_node(_rootNode, position->val.first);
            }

            size_type erase (const key_type& k){
                // if (_find_key(_rootNode, k) == 0)
                //     return 0;
                _rootNode = _delete_node(_rootNode, k);
                return 1;
            }

            void erase (iterator first, iterator last){
                iterator it = begin();
                while (it != end() && it != first)
                    it++;
                if (it == end())
                    return ;
                while (it != end() && it != last){
                    _rootNode = _delete_node(_rootNode, it->val.first);
                    it++;
                }
            }

            void swap (map& x){
                size_type                           temp_size = x._size;
                key_compare                         temp_comp = x._comp;
                Node<value_type>                    *temp_rootNode = x._rootNode;
                allocator_type                      temp_alloc = x._alloc;

                x._size = _size;
                x._comp = _comp;
                x._rootNode = _rootNode;
                x._alloc = _alloc;

                _size = temp_size;
                _comp = temp_comp;
                _rootNode = temp_rootNode;
                _alloc = temp_alloc;
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

            void _newNode(Node<value_type> **dest, ft::pair<Key, T> val, Node<value_type> *parent = NULL)
		    {
			    *dest = _node.allocate(1);
			    _node.construct(*dest, Node<value_type>(val, parent));
			    _size++;
		    }

            int     _find_key(Node<value_type> *root, const key_type& k)
            {
                if (!(root))
                    return (0);
                _find_node((root)->left, k);
                if (root->val.first == k)
                    return (1);
                _find_node((root)->right, k);
                return (0);
            }

            Node<value_type>    *_find_node(Node<value_type> *root, const key_type& k)
            {
                if (root->val.first == k)
                    return (root);
                if (root->left)
                    _find_node((root)->left, k);
                if (root->right)
                    _find_node((root)->right, k);
                return (0);
            }

            void    _apply_new_nodes(Node<value_type> *temp)
            {
                _rootNode = _createNode(temp->val);
                if (temp->left)
                    _node_apply_suffix(temp->left);
                if (temp->right)
                    _node_apply_suffix(temp->right);
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

            Node<value_type>    *_min_value_node(Node<value_type> *node)
            {
                Node<value_type> *current = node;
                while (current && current->left != NULL)
                    current = current->left;
                return current;
            }

            Node<value_type>    *_delete_node(Node<value_type> *root, key_type k)
            {
                if (root == NULL)
                    return root;
                if (k < root->val.first)
                    root->left = _delete_node(root->left, k);
                else if (k > root->val.first)
                    root->right = _delete_node(root->right, k);
                else {
                    if (root->left==NULL and root->right==NULL)
                        return NULL;
                    else if (root->left == NULL) {
                        Node<value_type> *temp = root->right;
                        _node.destroy(root);
                        _node.deallocate(root, 1);
                        _size--;
                        return temp;
                    }
                    else if (root->right == NULL) {
                        Node<value_type> *temp = root->left;
                        _node.destroy(root);
                        _node.deallocate(root, 1);
                        _size--;
                        return temp;
                    }
                    Node<value_type> *temp = _min_value_node(root->right);
                    root->val = temp->val;
                    root->right = _delete_node(root->right, temp->val.first);
                }
                return root;
            }

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

            /* apply elements from top to the left and right */
            // void    _node_apply_prefix(_Node *root, void (*apply)(void *))
            // {
            //     (*apply)(root->val);
            //     if (root->left)
            //         _node_apply_prefix(root->left, apply);
            //     if (root->right)
            //         _node_apply_prefix(root->right, apply);
            // }

            /* apply elements from left to the right (smallest one to the highest) */
            // void    _node_apply_infix(_Node *root, void (*applyf)(void *))
            // {
            //     if (root->left)
            //         _node_apply_infix(root->left, applyf);
            //     (*applyf)(root->val);
            //     if (root->right)
            //         _node_apply_infix(root->right, applyf);
            // }

            /* apply elements from the bottom first left side, then right side and root last */
            // void    _node_apply_suffix(_Node *root, void (*applyf)(void *))
            // {
            //     if (root->left)
            //         _node_apply_suffix(root->left, applyf);
            //     if (root->right)
            //         _node_apply_suffix(root->right, applyf);
            //     (*applyf)(root->val);
            // }

            /* insert data, cmpf is compare function */
            void    _node_insert_value(Node<value_type> **root, value_type value, Node<value_type> *p)
            {
                if (!(*root))
                    _newNode(root, value, p);
                else if (value.first < (*root)->val.first)
                    _node_insert_value(&(*root)->left, value, *root);
                else
                    _node_insert_value(&(*root)->right, value, *root);
            }

            /* search value from the tree from the left to the right (smallest one to the highest) */
            // void    *_node_search_value(_Node *root, void *value, int (*cmpf)(void *, void *))
            // {
            //     if (!(root))
            //         return (0);
            //     _node_search_value((root)->left, value, cmpf);
            //     if ((*cmpf)(value, (*root)->val) == 0)
            //         return (root);
            //     _node_search_value((root)->right, value, cmpf);
            //     return (0);
            // }


    };
}

#endif











































