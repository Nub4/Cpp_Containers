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

bool    ft_compare_map(std::map<char, int> map1, ft::map<char, int> map2)
{ 
    std::cout << "|" << std::setw(8) << map1.size() << "| ";
    for (std::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it)
        std::cout << "[" << it->first << ", " << it->second << "] ";

    std::cout << "\n|" << std::setw(8) << map2.size() << "| ";
    for (ft::map<char, int>::iterator it2 = map2.begin(); it2 != map2.end(); ++it2)
        std::cout << "[" << it2->first << ", " << it2->second << "] ";

    if (map1.size() != map2.size())
        return false;
    ft::map<char, int>::iterator it2 = map2.begin();
    for (std::map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it, it2++)
        if (it->first != it2->first && it->second != it2->second)
            return false;

    return true;
}

bool    ft_compare_map(std::map<char, std::string> map1, ft::map<char, std::string> map2)
{ 
    std::cout << "|" << std::setw(8) << map1.size() << "| ";
    for (std::map<char, std::string>::iterator it = map1.begin(); it != map1.end(); ++it)
        std::cout << "[" << it->first << ", " << it->second << "] ";

    std::cout << "\n|" << std::setw(8) << map2.size() << "| ";
    for (ft::map<char, std::string>::iterator it2 = map2.begin(); it2 != map2.end(); ++it2)
        std::cout << "[" << it2->first << ", " << it2->second << "] ";

    if (map1.size() != map2.size())
        return false;
    ft::map<char, std::string>::iterator it2 = map2.begin();
    for (std::map<char, std::string>::iterator it = map1.begin(); it != map1.end(); ++it, it2++)
        if (it->first != it2->first && it->second != it2->second)
            return false;

    return true;
}