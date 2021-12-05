#include "tests.hpp"

void    ft_map_testing()
{
    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    std::cout << mymap['a'] << std::endl;

    while (!mymap.empty())
    {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
    }

    ft::map<char,int> mymap2;

    mymap2['b']=10;
    mymap2['a']=20;
    mymap2['c']=30;

    ft::map<char,int>::iterator it = mymap2.begin();

    for (; it != mymap2.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;

    // std::cout << mymap2['a'] << std::endl;

    // while (!mymap2.empty())
    // {
    //     std::cout << mymap2.begin()->first << " => " << mymap2.begin()->second << '\n';
    //     mymap2.erase(mymap2.begin());
    // }

}