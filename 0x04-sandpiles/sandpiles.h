#ifndef SANDPILES_H
#define SANDPILES_H

#define TRUE 1
#define FALSE 0

void elements_to_change(int grid1[3][3], int grid_elements[3][3]);
int grid_still_mutable(int grid_elements[3][3]);
void matrix_add (int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
