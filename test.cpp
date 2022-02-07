#include "doublelist.h"
int main()
{
	List<char> ch;
	ch.push_back('2');
	ch.push_back('3');
	ch.push_back('4');
	ch.push_back('5');
	std::cout << ch.getSize();
	std::cout << ch.front();
	ch.insert(2, 'p');
	std::cout << ch.getSize();
	return 0;
}