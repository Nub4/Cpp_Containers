#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
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

    template <class T1, class T2>
    struct pair
    {
            typedef T1      first_type;
            typedef T2      second_type;

            pair() : first(), second() {}

            template<class U, class V>
            pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

            pair(const first_type &a, const second_type &b)
            : first(a), second(b) {}

            pair    &operator=(const pair &pr){
                first = pr.first;
                second = pr.second;
                return *this;
            }

            friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
                return lhs.first==rhs.first && lhs.second==rhs.second;
            }
            friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
                return !(lhs==rhs);
            }
            friend bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
                return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
            }
            friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
                return !(rhs<lhs);
            }
            friend bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
                return rhs<lhs;
            }
            friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
                return !(lhs<rhs);
            }
    
            first_type  first;
            second_type second;
    };

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return pair<T1, T2>(x, y);
    };

    template <class arg1, class arg2, class result>
	struct binary_function
	{
		typedef	arg1       first_argument_type;
		typedef	arg2       second_argument_type;
		typedef	result     result_type;
	};

    template <class T>
    struct less : binary_function <T ,T ,bool>
    {   
        bool operator() (const T &x, const T &y) const { return x < y; }    
    };

    template<bool, class T>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template<bool val, typename T>
	struct is_integral_base
	{
		typedef T type;
		static bool const value = val;
	};

    template <class T>
	struct Node
    {
		T       val;
        Node    *parent;
	    Node    *left;
        Node    *right;

		Node() : val(), parent(NULL), left(NULL), right(NULL) {}

        Node(T value)
        : val(value), parent(NULL), left(NULL), right(NULL) {}

        Node(T value, Node *p)
        : val(value), parent(p), left(NULL), right(NULL) {}

        Node(const Node &src)
        : val(src.val), parent(src.parent), left(src.left), right(src.right) {}

        ~Node() {}

	    Node &operator=(const Node &rhs){
		    val = rhs.val;
            parent = rhs.parent;
		    left = rhs.left;
		    right = rhs.right;
		    return *this;
		}
	};

    template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
}

#endif