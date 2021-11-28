#include "tests.hpp"

bool     ft_compare_vector_2(std::vector<std::string> v1, ft::vector<std::string> v2)
{
    std::cout << "|" << std::setw(8) << v1.size();
    std::cout << "|" << std::setw(8) << v1.capacity() << "|";
    for (size_t i = 0; i < v1.size(); i++){
        if (i < v1.size() - 1)
            std::cout << v1[i] << ",";
        else
            std::cout << v1[i] << "\n";
    }
    if (!v1.size())
        std::cout << "\n";

    std::cout << "|" << std::setw(8) << v2.size();
    std::cout << "|" << std::setw(8) << v2.capacity() << "|";
    for (size_t i = 0; i < v2.size(); i++){
        if (i < v2.size() - 1)
            std::cout << v2[i] << ",";
        else
            std::cout << v2[i] ;
    }

    if (v1.size() != v2.size())
        return false;
    if (v1.capacity() != v2.capacity())
        return false;
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;   
            
    return true;
}

bool     ft_compare_vector(std::vector<int> v1, ft::vector<int> v2)
{
    std::cout << "|" << std::setw(8) << v1.size();
    std::cout << "|" << std::setw(8) << v1.capacity() << "|";
    for (size_t i = 0; i < v1.size(); i++){
        if (i < v1.size() - 1)
            std::cout << v1[i] << ",";
        else
            std::cout << v1[i] << "\n";
    }
    if (!v1.size())
        std::cout << "\n";

    std::cout << "|" << std::setw(8) << v2.size();
    std::cout << "|" << std::setw(8) << v2.capacity() << "|";
    for (size_t i = 0; i < v2.size(); i++){
        if (i < v2.size() - 1)
            std::cout << v2[i] << ",";
        else
            std::cout << v2[i] ;
    }

    if (v1.size() != v2.size())
        return false;
    if (v1.capacity() != v2.capacity())
        return false;
    for (size_t i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;

    return true;
}