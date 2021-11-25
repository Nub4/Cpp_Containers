#include "tests.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Error: 1 argument needed, 'vector' or 'map'\n";
		return 1;
	}
	std::string s = av[1];
	if (s == "vector")
		ft_vector_testing();
//	else if (s == "map")
//		ft_map_testing();
	else
		std::cout << "Error: wrong argument, needed 'vector' or 'map'\n";
//	while(1){}
	return 0;
}