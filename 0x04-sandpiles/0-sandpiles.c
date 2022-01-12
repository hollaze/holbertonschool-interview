#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * matrix_add - add 2 matrixes
 *
 * @grid1: first grid to add
 * @grid2: second grid to add
 */

void matrix_add(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * grid_still_mutable - check if the grid is still mutable
 *
 * @grid1: grid to check
 *
 * Return: TRUE if grid is still mutable, FALSE otherwise
 */

int grid_still_mutable(int grid_elements[3][3])
{
	int i, j;
	int grid_zero[3][3] = { {0, 0, 0},
				{0, 0, 0},
				{0, 0, 0} };
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid_elements[i][j] != grid_zero[i][j])
			{
				return (TRUE);
			}
		}
	}

	return (FALSE);
}

/**
 * elements_to_change - if there is still elements to change
 * in grid1, give them to grid_elements
 *
 * @grid1: grid to check
 * @grid_elements: grid elements to change from grid1
 */

void elements_to_change(int grid1[3][3], int grid_elements[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid_elements[i][j] = grid1[i][j];
			}
			else
			{
				grid_elements[i][j] = 0;
			}
		}
	}
}

/**
 * sandpiles_sum - get sum of the sandpiles
 *
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 *
 * Return: Sum of the sandpiles
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int grid_elements[3][3];
	int i, j;
	int count = 0;
	char *str;

	matrix_add(grid1, grid2);
	elements_to_change(grid1, grid_elements);
	
	printf("=\n");
	print_grid(grid1);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid_elements[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid1[i - 1][j] += 1;
				if (i + 1 <= 2)
					grid1[i + 1][j] += 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] += 1;
				if (j + 1 <= 2)
					grid1[i][j + 1] += 1;
			}

			if (i == 2 && j == 2)
			{
				elements_to_change(grid1, grid_elements);
				if (count < 1)
				{
					printf("=\n");
					count++;
				}
				print_grid(grid1);
				str = grid_still_mutable(grid_elements) == TRUE ? "=\n" : "";
				printf("%s", str);
				if (grid_still_mutable(grid_elements) == TRUE)
					i = - 1;
			}
		}
	}
}
