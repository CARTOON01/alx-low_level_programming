#include "main.h"


	/**
	 * _abs - computes the absolute value of an integer
	 * @n: the int to check
	 * Return: the absolute value of int
	 * Author: Brian Ngugi
	 */
	int _abs(int n)
{

if (n < 0)
{
return (n * (-1));
}

else if (n == 0)
{
return (0);
}

else
{
return (n);
}
}

