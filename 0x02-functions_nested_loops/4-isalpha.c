#include "main.h"


	/**
	 * _isalpha - checks for alphabetic character
	 * @c: the character to be checked
	 * Author: Brian Ngugi
	 * Return: 1 if c is a letter, 0 otherwise
	 */
	int _isalpha(int c)
{
	/* ASCII value of upper case letters is between 65 && 90 */
	if (c >= 65 && c <= 90)
	{
		return (1);
	}

	else
	{
		/* ASCII value of lower case letters is between 97 && 122 */
		if (c >= 97 && c <= 122)
		{
			return (1);
		}

		else
		{
			return (0);
		}
	}
}
