#include "tests.hpp"

void    ft_member_functions()
{
        // STL:
		std::vector<int> v1(7);
		std::vector<int> v2(4, 42);
        std::vector<int> v3(v2); 
		std::vector<int> v4 = v1;
        std::vector<int> v5; 
        for (size_t i = 0; i < v1.size(); i++)
			v1[i] = i;
        std::vector<int> v6(v1.begin(), v1.end()); 

        // MY:
		ft::vector<int> vv1(7); 
		ft::vector<int> vv2((size_t)4, 42);
        ft::vector<int> vv3(vv2);
		ft::vector<int> vv4 = vv1;
        ft::vector<int> vv5; 
        for (size_t i = 0; i < vv1.size(); i++)
			vv1[i] = i;
        ft::vector<int> vv6(vv1.begin(), vv1.end()); 

        // COMPARE:
        if (ft_compare_vector(v1, vv1))
            std::cout << "OK!\n";
        else
            std::cout << "False!\n";

        if (ft_compare_vector(v2, vv2))
            std::cout << "OK!\n";
        else
            std::cout << "False!\n";

        if (ft_compare_vector(v3, vv3))
            std::cout << "OK!\n";
        else
            std::cout << "False!\n";

        if (ft_compare_vector(v4, vv4))
            std::cout << "OK!\n";
        else
            std::cout << "False!\n";

        if (ft_compare_vector(v5, vv5))
            std::cout << "OK!\n";
        else
            std::cout << "False!\n";
            
        if (ft_compare_vector(v6, vv6))
            std::cout << "OK!\n";
        else
            std::cout << "False!\n";
}

void    ft_modifiers()
{
    // STL:
    std::vector<int> v1(7);
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4(2);
    std::vector<int> v6(8);
    for (size_t i = 0; i < 6; i++){
        v1.push_back(i);
        v2.push_back(i);
    }
    for (size_t i = 0; i < 2; i++){
        v1.pop_back();
        v2.pop_back();
    }
    v1.swap(v2);
    v3.assign((size_t)4, 19);
    v4.assign((size_t)6, 42);
    std::vector<int> v5(v2.begin(), v2.end());

    // MY:
    ft::vector<int> vv1(7);
    ft::vector<int> vv2;
    ft::vector<int> vv3;
    ft::vector<int> vv4(2);
    ft::vector<int> vv6(8);
    for (size_t i = 0; i < 6; i++){
        vv1.push_back(i);
        vv2.push_back(i);
    }
    for (size_t i = 0; i < 2; i++){
       vv1.pop_back();
        vv2.pop_back();
    }
    vv1.swap(vv2);
    vv3.assign((size_t)4, 19);
    vv4.assign((size_t)6, 42);
    ft::vector<int> vv5(vv2.begin(), vv2.end());

    // COMPARE:
    if (ft_compare_vector(v1, vv1))
            std::cout << "OK!\n";
    else
        std::cout << "False!\n";

    if (ft_compare_vector(v2, vv2))
            std::cout << "OK!\n";
    else
        std::cout << "False!\n";

    if (ft_compare_vector(v3, vv3))
        std::cout << "OK!\n";
    else
        std::cout << "False!\n";

    if (ft_compare_vector(v4, vv4))
        std::cout << "OK!\n";
    else
        std::cout << "False!\n";

    if (ft_compare_vector(v5, vv5))
        std::cout << "OK!\n";
    else
        std::cout << "False!\n";
            
    // INSERT
    for (size_t i = 0; i < v3.size(); i++){
        v3[i] = i;
        vv3[i] = i;
    }
    for (size_t i = 0; i < v2.size(); i++){
        v2[i] = i;
        vv2[i] = i;
    }
    v4.insert(v4.begin() + 2, 22);
    v3.insert(v3.begin() +3, (size_t)10, 100);
    v2.insert(v2.begin() + 12, v2.begin() + 3, v2.end() - 2);
    vv4.insert(vv4.begin() + 2, 22);
    vv3.insert(vv3.begin() + 3, (size_t)10, 100);
    vv2.insert(vv2.begin() + 12, vv2.begin() + 3, vv2.end() - 2);
    for (size_t i = 0; i < v6.size(); i++){
        v6[i] = i;
        vv6[i] = i;
    }
    if (ft_compare_vector(v3, vv3))
        std::cout << "OK!\n";
    else
        std::cout << "False!\n";
    v6.insert(v6.begin() + 1, v6.begin() + 3, v6.end() - 2);
    vv6.insert(vv6.begin() + 1, vv6.begin() + 3, vv6.end() - 2);
    // COMPARE
    if (ft_compare_vector(v4, vv4))
        std::cout << "OK!\n";
    else
        std::cout << "False!\n";

    if (ft_compare_vector(v2, vv2))
            std::cout << "OK!\n";
    else
        std::cout << "False!\n";

    if (ft_compare_vector(v6, vv6))
        std::cout << "OK!\n";
    else
        std::cout << "False!\n";

    v1.clear();
    vv1.clear();
    if (ft_compare_vector(v1, vv1))
            std::cout << "OK!\n";
    else
        std::cout << "False!\n";

}

void    ft_vector_testing()
{
    std::cout << "--- Member functions ---\n";
    ft_member_functions();
    std::cout << "--- Modifiers ---\n";
    ft_modifiers();
 /*   ft_capacity();
    ft_element_access();
    ft_iterators();
    ft_non_member_function_overloads();*/
    
}