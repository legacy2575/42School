#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_grid(int grid[4][4]);
int solve(int grid[4][4], int clues[16], int row, int col);
int is_safe(int grid[4][4], int clues[16], int row, int col, int num);
int check_visibility(int grid[4][4], int clues[16]);

void print_grid(int grid[4][4]) 
{
    for (int i = 0; i < 4; i++) 
	{
        for (int j = 0; j < 4; j++) 
		{
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
	{
        printf("Error\n");
        return 1;
    }

    // Parse input
    int clues[16];
    for (int i = 0; i < 16; i++) 
	{
        clues[i] = argv[1][i * 2] - '0'; // Convert char to int
    }

    int grid[4][4] = {0};

    if (solve(grid, clues, 0, 0)) 
	{
        print_grid(grid);
    } else {
        printf("Error\n");
    }

    return 0;
}

int solve(int grid[4][4], int clues[16], int row, int col) 
{
    if (row == 4) {
        return check_visibility(grid, clues);
    }

    if (col == 4) {
        return solve(grid, clues, row + 1, 0);
    }

    for (int num = 1; num <= 4; num++) 
	{
        if (is_safe(grid, clues, row, col, num)) 
		{
            grid[row][col] = num;
            if (solve(grid, clues, row, col + 1)) 
			{
                return 1;
            }
            grid[row][col] = 0; // Backtrack
        }
    }
    return 0;
}

int is_safe(int grid[4][4], int clues[16], int row, int col, int num) 
{
    for (int x = 0; x < 4; x++) 
	{
        if (grid[row][x] == num || grid[x][col] == num) 
		{
            return 0;
        }
    }
    return 1;
}

int count_visible_boxes(int *line, int reverse) 
{
    int max_height = 0, visible_count = 0;
    for (int i = 0; i < 4; i++) 
	{
        int height = reverse ? line[3 - i] : line[i];
        if (height > max_height) {
            max_height = height;
            visible_count++;
        }
    }
    return visible_count;
}

int check_visibility(int grid[4][4], int clues[16]) 
{
    int line[4];

    // Check columns from top and bottom
    for (int col = 0; col < 4; col++) 
	{
        for (int row = 0; row < 4; row++) 
		{
            line[row] = grid[row][col];
        }
        if (count_visible_boxes(line, 0) != clues[col] || count_visible_boxes(line, 1) != clues[col + 4]) 
		{
            return 0;
        }
    }

    // Check rows from left and right
    for (int row = 0; row < 4; row++) 
	{
        for (int col = 0; col < 4; col++) 
		{
            line[col] = grid[row][col];
        }
        if (count_visible_boxes(line, 0) != clues[row + 8] || count_visible_boxes(line, 1) != clues[row + 12]) 
		{
            return 0;
        }
    }

    return 1;
}

