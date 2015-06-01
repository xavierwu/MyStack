#include "Stack.h"
#include <iostream>

int main ()
{
	Stack<int, 10> s;
	for (int i = 0; i < 10; ++i)
		s.push (i);
	while (!s.empty ()) {
		int tmp = 0;
		s.top (tmp);
		s.pop ();
		std::cout << tmp << std::endl;
	}
	return 0;
}