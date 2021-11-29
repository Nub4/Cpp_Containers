#include "tests.hpp"

void    ft_map_testing()
{
    std::map<std::string, int> m;
    m.insert ( std::make_pair ( "Tom", 18 ) );
    m.insert ( std::make_pair ( "Jennifer", 25 ));
    m.insert ( std::make_pair ( "Carlos", 32 ));

    for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;

    ft::map<int, char> lol;

}