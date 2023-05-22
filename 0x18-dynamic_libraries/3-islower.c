#include "main.h"


	/**
	 * _islower - check if char is lowercase
	 * @c: is the char to be checked
	 * Author: Brian Ngugi
	 * Return: 1 if char is lowercase, otherwise 0.
	 */


	int _islower(int c)
{
	/* ASCII value of lower case letters is between 97 & 122 */
	if (c >=  97 && c <= 122)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}

