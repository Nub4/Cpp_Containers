#include "tests.hpp"

bool     ft_compare_vector(std::vector<int> v1, ft::vector<int> v2)
{
    std::cout << "STL size:" << v1.size() << std::endl;
    std::cout << "MY size:" << v2.size() << std::endl;
    std::cout << "STL capacity:" << v1.capacity() << std::endl;
    std::cout << "MY capacity:" << v2.capacity() << std::endl;
    std::cout << "STL max_size:" << v1.max_size() << std::endl;
    std::cout << "MY max_size:" << v2.max_size() << std::endl;
    for (size_t i = 0; i < v1.size(); i++){
        std::cout << v1[i] << " " << v2[i] << std::endl;
    }

    if (v1.size() != v2.size())
        return false;
    if (v1.capacity() != v2.capacity())
        return false;
    if (v1.max_size() != v2.max_size())
        return false;
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;
    
    return true;
}