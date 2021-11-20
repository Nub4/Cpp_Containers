#include <vector>
#include <stack>
#include "../containers/stack.hpp"
#include "../utils/iterator.hpp"

int	main()
{
	std::cout << "--- STL vector ---\n";
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	for (std::vector<int>::reverse_iterator lool = v.rbegin(); lool != v.rend(); lool++)
		std::cout << *lool << std::endl;

	std::stack<int, std::vector<int> > s(v);

	std::cout << "stack = " << s.top() << std::endl;

	v.erase(v.begin() + 3, v.end());

	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;


	std::cout << "--- my own vector ---\n";
	ft::vector<int> vec;
	ft::vector<int> vec2;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);

	for (ft::vector<int>::reverse_iterator lol = vec.rbegin(); lol != vec.rend(); lol++)
		std::cout << *lol << std::endl;

	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	vec2.push_back(4);
	vec2.push_back(5);
	vec2.push_back(6);

	ft::stack<int, ft::vector<int> > sta(vec);
	ft::stack<int, ft::vector<int> > sta2(vec2);

	if (sta == sta2)
		std::cout << "THEY ARE SAME!\n";

	std::cout << "stack = " << sta.top() << std::endl;
	sta.pop();
	std::cout << "stack = " << sta.top() << std::endl;
	std::cout << "size = " << sta.size() << std::endl;

	vec.erase(vec.begin() + 3, vec.end());

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
	return 0;
}