#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge
 *
 * @level: Level of the Menger Sponge to draw
 */

void menger(int level)
{
	int level_size, row, col;

	/* The size of a level N Menger sponge is calculated as follows: 3^N */
	level_size = pow(3, level);

	for (row = 0; row < level_size; row++)
	{
		for (col = 0; col < level_size; col++)
		{
			print_menger(row, col);
		}

		putchar('\n');
	}
}

/**
 * print_menger - Get character ton print
 *
 * @row: 2D row
 * @col: 2D column
 */
void print_menger(int row, int col)
{
	char c = '#';

	while (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			c = ' ';
		row = row / 3;
		col = col / 3;
	}

	putchar(c);
}
