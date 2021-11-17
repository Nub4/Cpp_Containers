#include MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
//# include "iterator.hpp"

namespace ft
{
    template<class Key, class T, class Compare = less<key>, class Alloc = std::allocator<pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                             key_type;
            typedef T                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>           value_type;
            typedef Compare                                         key_compare;
           // typedef value_comp                                    value_compare;
            typedef Alloc                                           allocator_type;
            typedef value_type&                                     reference;
            typedef const value_type&                               const_reference;
            typedef value_type*                                     pointer;
            typedef const value_type*                               const_pointer;
            typedef ft::bidirectional_iterator<value_type>          iterator;
            typedef ft::bidirectional_iterator<const value_type>    const_iterator;
            typedef reverse_iterator<iterator>                      reverse_iterator;
            typedef reverse_iterator<const_iterator>                const_reverse_iterator;
            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;

        public:
        /* Containers: */
            explicit map(const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
            : _size(0), _capacity(0), _arr(0), _comp(comp), _alloc(alloc) {}

            template<class  InputIterator>
            map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc){
                _capacity = _distance(first, last);
                _size = _capacity;
                _arr = _alloc.allocate(_capacity);
                assign(first, last);
            }

            map(const map &x) : _size(x._size), _capacity(x._capacity), _comp(x._comp), _alloc(x._alloc){
                _arr = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _arr[i] = x._arr[i];
            }

            ~map(){
                if (_size != 0)
                    _alloc.deallocate(_arr, _capacity);
            }

            map &operator=(const map &x){
                _size = x._size;
                _capacity = x._capacity;
                _alloc = x._alloc;
                _arr = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _arr[i] = x._arr[i];
                return *this;
            }
        
        /* Iterators: */
         /*   iterator                begin(){

            }

            const_iterator          begin() const{

            }

            iterator                end(){

            }

            const_iterator          end() const{

            }

            reverse_iterator        rbegin(){

            }

            const_reverse_iterator  rbegin() const{

            }

            reverse_iterator        rend(){

            }

            const_reverse_iterator  rend() const{

            }*/

        /* Capacity: */
         /*   bool        empty() const{

            }

            size_type   size() const{

            }

            size_type   max_size() const{

            }*/

        /* Element access: */
        /*    mapped_type &operator[](const key_type &k){

            }*/

        /* Modifiers */
       /*     pair<iterator, bool>    insert(const value_type &val){

            }

            iterator                insert(iterator position, const value_type &val){

            }

            template<class InputIterator>
            void                    insert(InputIterator first, InputIterator last){

            }

            void                    erase(iterator position){

            }

            size_type               erase(const key_type &k){

            }

            void                    erase(iterator first, iterator last){

            }

            void                    swap(map &x){

            }

            void                    clear(){

            }*/

        /* Observers: */
         /*   key_compare     key_comp() const{

            }

            value_compare   value_comp() const{

            }*/

        /* Operations: */
  /*          iterator find(const key_type &k){

            }

            const_iterator find(const key_type &k) const{

            }

            size_type   count(const key_type &k) const{

            }

            iterator    lower_bound(const key_type &k){

            }

            const_iterator  lower_bound(const key_type &k) const{

            }

            iterator upper_bound(const key_type &k){

            }

            const_iterator  upper_bound(const key_type &k) const{

            }

            pair<const_iterator, const_iterator>    equal_range(const key_type &k) const{

            }

            pair<iterator, iterator>                equal_range(const key_type &k){

            }*/

        private:
            size_type       _size;
            size_type       _capacity;
            pointer         _arr;
            allocator_type  _alloc;
            key_compare     _comp;

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
}

#endif











































