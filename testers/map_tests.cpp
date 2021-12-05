#include "tests.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};



void    ft_map_testing()
{
    std::cout << YELLOW << "--- Constructors: ---\n" << RESET;

    {
        std::map<char,int> first;
        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;
        std::map<char,int> second (first.begin(),first.end());
        std::map<char,int> third (second);
        std::map<char,int,classcomp> fourth;
        bool(*fn_pt)(char,char) = fncomp;
        std::map<char,int,bool(*)(char,char)> fifth (fn_pt);

        ft::map<char,int> first2;
        first2['a']=10;
        first2['b']=30;
        first2['c']=50;
        first2['d']=70;
        ft::map<char,int> second2 (first2.begin(),first2.end());
        ft::map<char,int> third2 (second2);
        ft::map<char,int,classcomp> fourth2;
        bool(*fn_pt2)(char,char) = fncomp;
        ft::map<char,int,bool(*)(char,char)> fifth2 (fn_pt2);

        std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
        if (ft_compare_map(first, first2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
        if (ft_compare_map(second, second2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
        if (ft_compare_map(third, third2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }

    std::cout << YELLOW << "\n--- Insert: ---\n" << RESET;

    {
        // STL //
        std::map<char,int> mymap;
        mymap.insert ( std::pair<char,int>('a',100) );
        mymap.insert ( std::pair<char,int>('z',200) );
        std::pair<std::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( std::pair<char,int>('z',500) );
        
        // MY //
        ft::map<char,int> mymap2;
        mymap2.insert ( ft::pair<char,int>('a',100) );
        mymap2.insert ( ft::pair<char,int>('z',200) );
        ft::pair<ft::map<char,int>::iterator,bool> ret2;
        ret2 = mymap2.insert ( ft::pair<char,int>('z',500) );

        if (ret.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }
        if (ret2.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret2.first->second;
        }
        if (ret.second == ret2.second)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
        

        // STL //        
        std::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, std::pair<char,int>('b',300)); 
        mymap.insert (it, std::pair<char,int>('c',400)); 
        std::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.find('c'));

        // MY //
        ft::map<char,int>::iterator it2 = mymap2.begin();
        mymap2.insert (it2, ft::pair<char,int>('b',300)); 
        mymap2.insert (it2, ft::pair<char,int>('c',400)); 
        ft::map<char,int> anothermap2;
        anothermap2.insert(mymap2.begin(),mymap2.find('c'));

        std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;

        if (ft_compare_map(anothermap, anothermap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
}