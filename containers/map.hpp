#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include "../utils/utils.hpp"

namespace ft
{
    template<class Key, class T, class Compare = ft::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;
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
            typedef std::__is_bidirectional_iterator<value_type>          iterator;
            typedef std::__is_bidirectional_iterator<const value_type>    const_iterator;
            typedef std::reverse_iterator<iterator>                      reverse_iterator;
            typedef std::reverse_iterator<const_iterator>                const_reverse_iterator;
            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;

        public:
        /* Containers: */
            explicit map(const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
            {
                _size = 0;
                _alloc = alloc;
                _comp = comp;
                _root = NULL;
            }

        /* Capacity: */
            bool empty() const { _size = 0 ? true : false; }

            size_type size() const { return _size; }

            size_type max_size() const { return _alloc.max_size(); }

        private:

            struct _Node
            {
                value_type       val;
                struct _Node     *left;
                struct _Node     *right;
            };

            size_type           _size;
            key_compare         _comp;
            _Node                *_root;
            allocator_type      _alloc;

            /* creates new node with a value */
            // _Node   *_createNode(value_type val)
            // {
            //     _Node *newNode = _alloc.allocate(1);
                // if (newNode)
                // {
                //     newNode->val = val;
                //     newNode->left = NULL;
                //     newNode->right = NULL;
                // }
            //     return newNode;
            // }

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
            // void    _node_insert_value(_Node **root, void *value, int (*cmpf)(void *, void *))
            // {
            //     if (!(*root))
            //         _createNode(value);
            //     else if ((*cmpf)(value, (*root)->val) < 0)
            //         _node_insert_value(&(*root)->left, value, cmpf);
            //     else
            //         _node_insert_value(&(*root)->right, value, cmpf);
            // }

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











































