#include "main.h"


	/**
	 * main - check the code
	 *Author: Brian Ngugi
	 * Return: Always 0 (Success)
	 */
	void times_table(void)
{
	int i;
	int j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
				printf("%d", i * j);
			else
				printf("%3d", i * j);

			if (j < 9)
				printf(",");
		}
		printf("\n");
	}
}
