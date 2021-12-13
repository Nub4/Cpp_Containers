#include "tests.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

void    ft_member_functions_and_allocator_map()
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

    // Allocator:
    int psize;
    std::map<char,int> mymapp;
    std::pair<const char,int>* p;
    p=mymapp.get_allocator().allocate(5);
    psize = sizeof(std::map<char,int>::value_type)*5;
    std::cout << "The allocated array has a size of " << psize << " bytes.\n";
    mymapp.get_allocator().deallocate(p,5);

    int psize2;
    ft::map<char,int> mymapp2;
    ft::pair<const char,int>* p2;
    p2=mymapp2.get_allocator().allocate(5);
    psize2 = sizeof(ft::map<char,int>::value_type)*5;
    std::cout << "The allocated array has a size of " << psize2 << " bytes.\n";
    mymapp2.get_allocator().deallocate(p2,5);

    if (ft_compare_map(mymapp, mymapp2) == true)
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
    ft::map<char,int>::iterator i3;
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
    i3=m2.find ('f') + 1; //
    m2.erase ( i2, i3);
 //   m2.erase ( i2, m2.end() );

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

    // Clear:
    std::map<char,int> my;
    my['x']=100;
    my['y']=200;
    my['z']=300;

    ft::map<char,int> my2;
    my2['x']=100;
    my2['y']=200;
    my2['z']=300;

    if (ft_compare_map(my, my2) == true)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    my.clear();
    my['a']=1101;
    my['b']=2202;

    my2.clear();
    my2['a']=1101;
    my2['b']=2202;

    if (ft_compare_map(my, my2) == true)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
}

void    ft_iterators_and_observes_map()
{
    // Begin & End:
    {
        std::map<char,int> mymap;
        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        ft::map<char,int> mymap2;
        mymap2['b'] = 100;
        mymap2['a'] = 200;
        mymap2['c'] = 300;

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
    // rBegin & rEnd:
    {
        std::map<char,int> mymap;
        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        ft::map<char,int> mymap2;
        mymap2['x'] = 100;
        mymap2['y'] = 200;
        mymap2['z'] = 300;

        std::cout << "|" << std::setw(8) << mymap.size() << "| ";
        for (std::map<char,int>::reverse_iterator rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
            std::cout << "[" << rit->first << ", " << rit->second << "] ";

        std::cout << "\n|" << std::setw(8) << mymap2.size() << "| ";
        for (ft::map<char,int>::reverse_iterator rit2=mymap2.rbegin(); rit2!=mymap2.rend(); ++rit2)
            std::cout << "[" << rit2->first << ", " << rit2->second << "] ";

        int i = 0;
        if (mymap.size() == mymap2.size())
            i = 0;
        else
            i++;
        ft::map<char, int>::reverse_iterator it2 = mymap2.rbegin();
        for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it, it2++)
            if (it->first != it2->first && it->second != it2->second)
                i++;
        if (i == 0)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
    // key_compare:
    {
        std::map<char,int> mymap;
        std::map<char,int>::key_compare mycomp = mymap.key_comp();
        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;

        std::cout << "STL:\n";
        char highest = mymap.rbegin()->first;
        std::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );


        ft::map<char,int> mymap2;
        ft::map<char,int>::key_compare mycomp2 = mymap2.key_comp();
        mymap2['a']=100;
        mymap2['b']=200;
        mymap2['c']=300;

        std::cout << "MY:\n";
        char highest2 = mymap2.rbegin()->first;
        ft::map<char,int>::iterator it2 = mymap2.begin();
        do {
            std::cout << it2->first << " => " << it2->second << '\n';
        } while ( mycomp2((*it2++).first, highest2) );

        int i = 0;
        if (mymap.size() == mymap2.size())
            i = 0;
        else
            i++;
        ft::map<char, int>::reverse_iterator it3 = mymap2.rbegin();
        for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it, it3++)
            if (it->first != it3->first && it->second != it3->second)
                i++;
        if (i == 0)
            std::cout << GREEN << "  OK!\n\n" << RESET;
        else
            std::cout << RED << "  False!\n\n" << RESET;
    }
    // value compare:
    {
        std::map<char,int> mymap;
        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;
        std::cout << "STL:\n";
        std::pair<char,int> highest = *mymap.rbegin();
        std::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );

        ft::map<char,int> mymap2;
        mymap2['x']=1001;
        mymap2['y']=2002;
        mymap2['z']=3003;
        std::cout << "MY:\n";
        ft::pair<char,int> highest2 = *mymap2.rbegin();
        ft::map<char,int>::iterator it2 = mymap2.begin();
        do {
            std::cout << it2->first << " => " << it2->second << '\n';
        } while ( mymap2.value_comp()(*it2++, highest2) );

        int i = 0;
        if (mymap.size() == mymap2.size())
            i = 0;
        else
            i++;
        ft::map<char, int>::reverse_iterator it3 = mymap2.rbegin();
        for (std::map<char, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); ++it, it3++)
            if (it->first != it3->first && it->second != it3->second)
                i++;
        if (i == 0)
            std::cout << GREEN << "  OK!\n\n" << RESET;
        else
            std::cout << RED << "  False!\n\n" << RESET;
    }
}

void    ft_capacity_and_access_map()
{
    // Empty:
    {
        std::map<char,int> mymap;
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        ft::map<char,int> mymap2;
        mymap2['a']=10;
        mymap2['b']=20;
        mymap2['c']=30;

        while (!mymap.empty())
        {
            if (ft_compare_map(mymap, mymap2) == true)
                std::cout << GREEN << " OK!\n\n" << RESET;
            else
                std::cout << RED << " False!\n\n" << RESET;
            mymap.erase(mymap.begin());
            mymap2.erase(mymap2.begin());
        }
    }
    // Size:
    {
        std::map<char,int> mymap;
        mymap['a']=101;
        mymap['b']=202;
        mymap['c']=302;

        ft::map<char,int> mymap2;
        mymap2['a']=101;
        mymap2['b']=202;
        mymap2['c']=302;

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
    // Element access:
    {
        std::map<char,std::string> mymap;
        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        ft::map<char,std::string> mymap2;
        mymap2['a']="an element";
        mymap2['b']="another element";
        mymap2['c']=mymap2['b'];

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }

}

void    ft_operations()
{
    // Find:
    {
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;
        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;
        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase (it);

        ft::map<char,int> mymap2;
        ft::map<char,int>::iterator it2;
        mymap2['a']=50;
        mymap2['b']=100;
        mymap2['c']=150;
        mymap2['d']=200;
        it2 = mymap2.find('b');
        if (it2 != mymap2.end())
            mymap2.erase (it2);

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
    // Lower and upper bound:
    {
        std::map<char,int> mymap;
        std::map<char,int>::iterator itlow,itup;
        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;
        itlow=mymap.lower_bound ('b');
        itup=mymap.upper_bound ('d');
        mymap.erase(itlow,itup);

        ft::map<char,int> mymap2;
        ft::map<char,int>::iterator itlow2,itup2;
        mymap2['a']=20;
        mymap2['b']=40;
        mymap2['c']=60;
        mymap2['d']=80;
        mymap2['e']=100;
        itlow2=mymap2.lower_bound ('b');
        itup2=mymap2.upper_bound ('d');
        mymap2.erase(itlow2,itup2);

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
    // Count:
    {
        std::map<char,int> mymap;
        char c;
        int i = 0;
        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
            if (mymap.count(c)>0)
                i++;

        ft::map<char,int> mymap2;
        char c2;
        int i2 = 0;
        mymap2 ['a']=101;
        mymap2 ['c']=202;
        mymap2 ['f']=303;

        for (c2='a'; c2<'h'; c2++)
            if (mymap2.count(c2)>0)
                i2++;

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;

        std::cout << "STL count: " << i << "\n" << "MY count: " << i2;
        if (i == i2)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
    // Equal range:
    {
        std::map<char,int> mymap;
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');
        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';
        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';

        ft::map<char,int> mymap2;
        mymap2['a']=10;
        mymap2['b']=20;
        mymap2['c']=30;
        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret2;
        ret2 = mymap2.equal_range('b');
        std::cout << "lower bound points to: ";
        std::cout << ret2.first->first << " => " << ret2.first->second << '\n';
        std::cout << "upper bound points to: ";
        std::cout << ret2.second->first << " => " << ret2.second->second;

        if (ret.first->first == ret2.first->first && ret.first->second == ret2.first->second &&
        ret.second->first == ret2.second->first && ret.second->second == ret2.second->second)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
    }
}

void    ft_iterator_compare_2()
{
    std::map<int, int> v;
    v[2]=19;
    v[3]=19;
    v[4]=19;
    v[5]=19;
    std::map<int, int>::iterator it = v.begin();
    std::map<int, int>::const_iterator it2 = v.begin();
    std::map<int, int>::reverse_iterator rit = v.rend();
    std::map<int, int>::const_reverse_iterator rit2 = v.rend();

    ft::map<int, int> vec;
    vec[2]=19;
    vec[3]=19;
    vec[4]=19;
    vec[5]=19;
    ft::map<int, int>::iterator itt = vec.begin();
    ft::map<int, int>::const_iterator itt2 = vec.begin();
    ft::map<int, int>::reverse_iterator ritt = vec.rend();
    ft::map<int, int>::const_reverse_iterator ritt2 = vec.rend();

    int mark = 0;
    int mark2 = 0;

    std::cout << "iterator & const_iterator compare '=='";
    if (it==it2) mark++;
    if (itt==itt2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << "iterator & const_iterator compare '!='";
    if (it!=it2) mark++;
    if (itt!=itt2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << "reverse_iterator & const_reverse_iterator compare '=='";
    if (rit==rit2) mark++;
    if (ritt==ritt2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << "reverse_iterator & const_reverse_iterator compare '!='";
    if (rit!=rit2) mark++;
    if (ritt!=ritt2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
}

void    ft_erase_insert()
{
    {
		std::map<char,int> mymap;
        std::map<char,int>::iterator it;
        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;
		mymap['e']=250;
        mymap['f']=300;
        it = mymap.find('d');
        std::cout << "STL iterator before and after:\n" << it->first << " " << it->second << std::endl;
        mymap.erase('b');
        mymap.erase('c');
        mymap.erase('f');
        mymap['b']=100;
        mymap['c']=150;
        mymap['f']=300;
        std::cout << it->first << " " << it->second << "\nMY iterator before and after:" << std::endl;

        ft::map<char,int> mymap2;
        ft::map<char,int>::iterator it2;
        mymap2['a']=50;
        mymap2['b']=100;
        mymap2['c']=150;
        mymap2['d']=200;
		mymap2['e']=150;
        mymap2['f']=200;
        it2 = mymap2.find('d');
        std::cout << it2->first << " " << it2->second << std::endl;
        mymap2.erase('b');
        mymap2.erase('c');
        mymap2.erase('f');
        mymap2['b']=100;
        mymap2['c']=150;
        mymap2['f']=300;
        std::cout << it2->first << " " << it2->second << std::endl;

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
	}
	{
		std::map<char,int> mymap;
        std::map<char,int>::iterator it;
        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;
		mymap['e']=250;
        mymap['f']=300;
        it = mymap.find('a');
        std::cout << "STL iterator before and after:\n" << it->first << " " << it->second << std::endl;
        mymap.erase('b');
        mymap.erase('c');
		mymap.erase('d');
		mymap.erase('e');
        mymap.erase('f');
        mymap['c']=150;
		mymap['d']=200;
		mymap['e']=250;
        std::cout << it->first << " " << it->second << "\nMY iterator before and after:" << std::endl;

        ft::map<char,int> mymap2;
        ft::map<char,int>::iterator it2;
        mymap2['a']=50;
        mymap2['b']=100;
        mymap2['c']=150;
        mymap2['d']=200;
		mymap2['e']=150;
        mymap2['f']=200;
        it2 = mymap2.find('a');
        std::cout << it2->first << " " << it2->second << std::endl;
        mymap2.erase('b');
        mymap2.erase('c');
		mymap2.erase('d');
		mymap2.erase('e');
        mymap2.erase('f');
        mymap2['c']=150;
		mymap2['d']=200;
		mymap2['e']=250;
        std::cout << it2->first << " " << it2->second << std::endl;

        if (ft_compare_map(mymap, mymap2) == true)
            std::cout << GREEN << " OK!\n\n" << RESET;
        else
            std::cout << RED << " False!\n\n" << RESET;
	}
}

void    ft_map_testing()
{
    std::cout << YELLOW << "--- Member functions and allocator: ---\n" << RESET;
    std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
    ft_member_functions_and_allocator_map();
    std::cout << YELLOW << "\n--- Modifiers: ---\n" << RESET;
    ft_modifiers_map();
    std::cout << YELLOW << "--- Iterators and observes: ---\n" << RESET;
    std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
    ft_iterators_and_observes_map();
    std::cout << YELLOW << "--- Capacity and element access: ---\n" << RESET;
    std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
    ft_capacity_and_access_map();
    std::cout << YELLOW << "--- Operations: ---\n" << RESET;
    std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
    ft_operations();
    std::cout << YELLOW << "--- Iterator compare: ---\n" << RESET;
    ft_iterator_compare_2();
    std::cout << YELLOW << "--- Iterator check with insert and erase: ---\n" << RESET;
    std::cout << YELLOW << "|" << std::setw(9) << "Size|" << "Range" << RESET << std::endl;
    ft_erase_insert();
}