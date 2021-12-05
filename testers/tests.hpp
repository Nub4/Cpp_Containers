#ifndef TESTS_HPP
# define TESTS_HPP

#include <vector>
#include <map>
#include <stack>
#include <string>
#include <iomanip>
#include "../containers/map.hpp"
#include "../containers/stack.hpp"
#include "../utils/iterator.hpp"

#define YELLOW  "\033[33m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define RESET	"\033[0m"

//template <class T, class U>
bool    ft_compare_map(std::map<char, int> map1, ft::map<char, int> map2);
void    ft_map_testing();
void    ft_stack_testing();
void    ft_vector_testing();
bool    ft_compare_vector(std::vector<int> v1, ft::vector<int> v2);
bool    ft_compare_vector_2(std::vector<std::string> v1, ft::vector<std::string> v2);

#endif