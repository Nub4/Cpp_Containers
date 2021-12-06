#include "tests.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

void    ft_member_functions_map()
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

    std::map<char,int> f;
    std::map<char,int> s;
    f['x']=8;
    f['y']=16;
    f['z']=32;
    s=f;
    f=std::map<char,int>();

    ft::map<char,int> f2;
    ft::map<char,int> s2;
    f2['x']=8;
    f2['y']=16;
    f2['z']=32;
    s2=f2;
    f2=ft::map<char,int>();

    if (ft_compare_map(f, f2) == true)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    if (ft_compare_map(s, s2) == true)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
}

void    ft_modifiers_map()
{
    // Insert:
    std::map<char,int> mymap;
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );
    std::pair<std::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( std::pair<char,int>('z',500) );
        
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
             
    std::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, std::pair<char,int>('b',300)); 
    mymap.insert (it, std::pair<char,int>('c',400)); 
    std::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

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

    // Erase:
    std::map<char,int> m;
    std::map<char,int>::iterator i;
    m['a']=10;
    m['b']=20;
    m['c']=30;
    m['d']=40;
    m['e']=50;
    m['f']=60;
    i=m.find('b');
    m.erase (i);
    m.erase ('c');
    i=m.find ('e');
    m.erase ( i, m.end() );

    ft::map<char,int> m2;
    ft::map<char,int>::iterator i2;
    m2['a']=10;
    m2['b']=20;
    m2['c']=30;
    m2['d']=40;
    m2['e']=50;
    m2['f']=60;
    i2=m2.find('b');
    m2.erase (i2);
    m2.erase ('c');
    i2=m2.find ('e');
    m2.erase ( i2, m2.end() );

    if (ft_compare_map(m, m2) == true)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    // Swap:
    std::map<char,int> foo,bar;
    foo['x']=100;
    foo['y']=200;
    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    foo.swap(bar);

    ft::map<char,int> foo2,bar2;
    foo2['x']=100;
    foo2['y']=200;
    bar2['a']=11;
    bar2['b']=22;
    bar2['c']=33;
    foo2.swap(bar2);

    if (ft_compare_map(foo, foo2) == true)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    if (ft_compare_map(bar, bar2) == true)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    
}

void    ft_map_testing()
{
    std::cout << YELLOW << "--- Member functions: ---\n" << RESET;
    std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
    ft_member_functions_map();
    std::cout << YELLOW << "\n--- Modifiers: ---\n" << RESET;
    ft_modifiers_map();
}