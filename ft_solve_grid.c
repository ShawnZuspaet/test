/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurgens <ajurgens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:02:20 by ajurgens          #+#    #+#             */
/*   Updated: 2023/04/30 15:03:54 by ajurgens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#define SIZE 4


int ft_check_view(int grid[SIZE][SIZE], int row, int col, int view[16])
{
    int i;
    int max;
    int count;

    i = 0;
    max = 0;
    count = 0;
    while (i < SIZE)
    {
        if (grid[row][i] > max)
        {
            max = grid[row][i];
            count++;
        }
        i++;
    }
    if (count != view[row * 2])
    return 0;

    i = SIZE -1;
    max = 0;
    count = 0;
    while (i >= 0)
    {
        if (grid[row][i] > max)
        {
            max = grid[row][i];
            count++;
        }
        i--;
    }
    if (count != view[row * 2 + 1])
    return 0;
    
    i = 0;
    max = 0;
    count = 0;
    while (i < SIZE)
    {
        if (grid[i][col] > max)
        {
            max = grid[i][col];
            count++;
        }
        i++;
    }
    if (count != view[8 + col * 2])
    return 0;

    i = SIZE -1;
    max = 0;
    count = 0;
    while (i >= 0)
    {
        if (grid[i][col] > max)
        {
            max = grid[i][col];
            count++;
        }
        i--;
    }
    if (count != view[9 + col * 2])
    return 0;
    return 1;
}

int ft_solve_grid(int grid[SIZE][SIZE], int row, int col, int view[16])
{
    if (row == SIZE)
    return 1;

    int next_row = row + (col + 1) / SIZE;
    int next_col = (col + 1) % SIZE;

    if(grid[row][col] != 0)
    return ft_solve_grid(grid, next_row, next_col, view);

    int num = 1;
    while (num <= SIZE)
    {
        int i = 0;
        bool isValid = true;

        while (i < SIZE && isValid)
        {
            if (grid[row][i] == num)
            isValid = false;
            i++;
        }
        
        if (isValid)
    {
        int j = 0;
        int leftCount = 0;
        int leftMax = 0;

        while (j < col)
        {
            if (grid[row][j] > leftMax)
            {
                leftMax = grid[row][j];
                leftCount++;
            }
            j++;
        }

        if (leftCount != view[row * 2])
            isValid = false;
            
        if (isValid)
        {
            j = SIZE - 1;
            int rightCount = 0;
            int rightMax = 0;
            
            while (j > col)
            {
                if (grid[row][j] > rightMax)
                {
                    rightMax = grid[row][j];
                    rightCount++;
                }
                j--;
            }

            if (rightCount != view[row * 2 + 1])
            isValid = false;
        }

        if (isValid)
        {
            j = 0;
            int topCount = 0;
            int topMax = 0;

            while (j < row)
            {
                if (grid[j][col] > topMax)
                {
                    topMax = grid[j][col];
                    topCount++;
                }
                j++;
            }

            if (topCount != view[8 + col * 2])
            isValid = false;
        }

        if (isValid)
        {
            j = SIZE - 1;
            int bottomCount = 0;
            int bottomMax = 0;
            
            while (j > row)
            {
                if (grid[j][col] > bottomMax)
                {
                    bottomMax = grid[j][col];
                    bottomCount++;
                }
                j--;
            }

            if (bottomCount != view[9 + col * 2])
            isValid = false;
        }
    }

    if(isValid)
    {
        grid[row][col] = num;
        if (ft_solve_grid(grid, next_row, next_col, view))
        return 1;
        grid[row][col] = 0;
    }
    num++;
    }
    return 0;
}
