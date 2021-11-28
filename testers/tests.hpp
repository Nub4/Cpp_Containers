#ifndef TESTS_HPP
# define TESTS_HPP

#include <vector>
#include <stack>
#include <string>
#include <iomanip>
#include "../containers/stack.hpp"
#include "../utils/iterator.hpp"

#define YELLOW  "\033[33m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define RESET	"\033[0m"

void    ft_vector_testing();
void    ft_member_functions();
void    ft_modifiers();
void    ft_capacity();
void    ft_element_access();
bool    ft_compare_vector(std::vector<int> v1, ft::vector<int> v2);
bool     ft_compare_vector_2(std::vector<std::string> v1, ft::vector<std::string> v2);

#endif