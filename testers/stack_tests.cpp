#include "tests.hpp"
#include <list>
#include <deque>

void    ft_vector_stack()
{
    // STL:
    std::stack<int, std::vector<int> > s1;
    // MY:
    ft::stack<int, ft::vector<int> > ss1;

    int sum(0);
    int summ(0);

    std::cout << YELLOW << "empty:\n\n" << RESET << s1.empty() << "\n" << ss1.empty();
    if (s1.empty() == ss1.empty())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    for (int i=1;i<=10;i++){
        s1.push(i);
        ss1.push(i);
    }

    while (!s1.empty()){
        sum += s1.top();
        s1.pop();
    }
    while (!ss1.empty()){
        summ += ss1.top();
        ss1.pop();
    }
    std::cout << sum << "\n" << summ;
    if (sum == summ)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "size:\n\n" << RESET << s1.size() << "\n" << ss1.size();
    if (s1.size() == ss1.size())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    for (int i=1;i<=10;i++){
        s1.push(i);
        ss1.push(i);
    }
    std::cout << s1.size() << "\n" << ss1.size();
    if (s1.size() == ss1.size())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "top:\n\n" << RESET << s1.top() << "\n" << ss1.top();
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    s1.push(25);
    ss1.push(25);
    std::cout << s1.top() << "\n" << ss1.top();
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "pop:\n\n" << RESET;
    for (size_t i = 0; i < 5; i++){
        s1.push(i);
        ss1.push(i);
    }
    while (!s1.empty() && !ss1.empty()){
        std::cout << s1.top() << " ";
        s1.pop();
    }
    std::cout << "\n";
    while (!ss1.empty()){
        std::cout << ss1.top() << " ";
        ss1.pop();
    }
    std::cout << GREEN << " OK!\n\n" << RESET;

    std::cout << YELLOW << "push:\n\n" << RESET;
    for (size_t i = 0; i < 10; i++){
        s1.push(i);
        std::cout << s1.top() << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < 10; i++){
        ss1.push(i);
        std::cout << ss1.top() << " ";
    }
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "operator overloading:\n\n" << RESET;
    std::stack<std::string, std::vector<std::string> > foo;
    std::stack<std::string, std::vector<std::string> > bar;
    ft::stack<std::string, ft::vector<std::string> > foo2;
    ft::stack<std::string, ft::vector<std::string> > bar2;
    int mark = 0;
    int mark2 = 0;

    std::cout << " operator overloading '=='";
    if (foo==bar) mark++;
    if (foo2==bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << " operator overloading '!='";
    if (foo!=bar) mark++;
    if (foo2!=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '<'";
    if (foo< bar) mark++;
    if (foo2< bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '>'";
    if (foo> bar) mark++;
    if (foo2> bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << " operator overloading '<='";
    if (foo<=bar) mark++;
    if (foo2<=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '>='";
    if (foo>=bar) mark++;
    if (foo2>=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
}

void    ft_list_stack()
{
    // STL:
    std::stack<int, std::list<int> > s1;
    // MY:
    ft::stack<int, std::list<int> > ss1;

    int sum(0);
    int summ(0);

    std::cout << YELLOW << "empty:\n\n" << RESET << s1.empty() << "\n" << ss1.empty();
    if (s1.empty() == ss1.empty())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    for (int i=1;i<=10;i++){
        s1.push(i);
        ss1.push(i);
    }

    while (!s1.empty()){
        sum += s1.top();
        s1.pop();
    }
    while (!ss1.empty()){
        summ += ss1.top();
        ss1.pop();
    }
    std::cout << sum << "\n" << summ;
    if (sum == summ)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "size:\n\n" << RESET << s1.size() << "\n" << ss1.size();
    if (s1.size() == ss1.size())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    for (int i=1;i<=10;i++){
        s1.push(i);
        ss1.push(i);
    }
    std::cout << s1.size() << "\n" << ss1.size();
    if (s1.size() == ss1.size())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "top:\n\n" << RESET << s1.top() << "\n" << ss1.top();
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    s1.push(25);
    ss1.push(25);
    std::cout << s1.top() << "\n" << ss1.top();
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "pop:\n\n" << RESET;
    for (size_t i = 0; i < 5; i++){
        s1.push(i);
        ss1.push(i);
    }
    while (!s1.empty() && !ss1.empty()){
        std::cout << s1.top() << " ";
        s1.pop();
    }
    std::cout << "\n";
    while (!ss1.empty()){
        std::cout << ss1.top() << " ";
        ss1.pop();
    }
    std::cout << GREEN << " OK!\n\n" << RESET;

    std::cout << YELLOW << "push:\n\n" << RESET;
    for (size_t i = 0; i < 10; i++){
        s1.push(i);
        std::cout << s1.top() << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < 10; i++){
        ss1.push(i);
        std::cout << ss1.top() << " ";
    }
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "operator overloading:\n\n" << RESET;
    std::stack<std::string, std::list<std::string> > foo;
    std::stack<std::string, std::list<std::string> > bar;
    ft::stack<std::string, std::list<std::string> > foo2;
    ft::stack<std::string, std::list<std::string> > bar2;
    int mark = 0;
    int mark2 = 0;

    std::cout << " operator overloading '=='";
    if (foo==bar) mark++;
    if (foo2==bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << " operator overloading '!='";
    if (foo!=bar) mark++;
    if (foo2!=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '<'";
    if (foo< bar) mark++;
    if (foo2< bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '>'";
    if (foo> bar) mark++;
    if (foo2> bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << " operator overloading '<='";
    if (foo<=bar) mark++;
    if (foo2<=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '>='";
    if (foo>=bar) mark++;
    if (foo2>=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
}

void    ft_deque_stack()
{
    // STL:
    std::stack<int, std::deque<int> > s1;
    // MY:
    ft::stack<int, std::deque<int> > ss1;

    int sum(0);
    int summ(0);

    std::cout << YELLOW << "empty:\n\n" << RESET << s1.empty() << "\n" << ss1.empty();
    if (s1.empty() == ss1.empty())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    for (int i=1;i<=10;i++){
        s1.push(i);
        ss1.push(i);
    }

    while (!s1.empty()){
        sum += s1.top();
        s1.pop();
    }
    while (!ss1.empty()){
        summ += ss1.top();
        ss1.pop();
    }
    std::cout << sum << "\n" << summ;
    if (sum == summ)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "size:\n\n" << RESET << s1.size() << "\n" << ss1.size();
    if (s1.size() == ss1.size())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    for (int i=1;i<=10;i++){
        s1.push(i);
        ss1.push(i);
    }
    std::cout << s1.size() << "\n" << ss1.size();
    if (s1.size() == ss1.size())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "top:\n\n" << RESET << s1.top() << "\n" << ss1.top();
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    s1.push(25);
    ss1.push(25);
    std::cout << s1.top() << "\n" << ss1.top();
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "pop:\n\n" << RESET;
    for (size_t i = 0; i < 5; i++){
        s1.push(i);
        ss1.push(i);
    }
    while (!s1.empty() && !ss1.empty()){
        std::cout << s1.top() << " ";
        s1.pop();
    }
    std::cout << "\n";
    while (!ss1.empty()){
        std::cout << ss1.top() << " ";
        ss1.pop();
    }
    std::cout << GREEN << " OK!\n\n" << RESET;

    std::cout << YELLOW << "push:\n\n" << RESET;
    for (size_t i = 0; i < 10; i++){
        s1.push(i);
        std::cout << s1.top() << " ";
    }
    std::cout << "\n";
    for (size_t i = 0; i < 10; i++){
        ss1.push(i);
        std::cout << ss1.top() << " ";
    }
    if (s1.top() == ss1.top())
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << YELLOW << "operator overloading:\n\n" << RESET;
    std::stack<std::string, std::deque<std::string> > foo;
    std::stack<std::string, std::deque<std::string> > bar;
    ft::stack<std::string, std::deque<std::string> > foo2;
    ft::stack<std::string, std::deque<std::string> > bar2;
    int mark = 0;
    int mark2 = 0;

    std::cout << " operator overloading '=='";
    if (foo==bar) mark++;
    if (foo2==bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << " operator overloading '!='";
    if (foo!=bar) mark++;
    if (foo2!=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '<'";
    if (foo< bar) mark++;
    if (foo2< bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '>'";
    if (foo> bar) mark++;
    if (foo2> bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
    
    std::cout << " operator overloading '<='";
    if (foo<=bar) mark++;
    if (foo2<=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;

    std::cout << " operator overloading '>='";
    if (foo>=bar) mark++;
    if (foo2>=bar2) mark2++;
    if (mark == mark2)
        std::cout << GREEN << " OK!\n\n" << RESET;
    else
        std::cout << RED << " False!\n\n" << RESET;
}   

void    ft_stack_testing()
{
    // VECTOR
    std::cout << GREEN << "\n--- STACK TESTING (VECTOR) ----\n\n" << RESET;
    ft_vector_stack();
    // LIST
    std::cout << GREEN << "\n--- STACK TESTING (LIST) ----\n\n" << RESET;
    ft_list_stack();
    // DEQUE
    std::cout << GREEN << "\n--- STACK TESTING (DEQUE) ----\n\n" << RESET;
    ft_deque_stack();
}