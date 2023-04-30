/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurgens <ajurgens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:03:40 by ajurgens          #+#    #+#             */
/*   Updated: 2023/04/30 14:30:47 by ajurgens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 4

int ft_validate_view(char *view);
int ft_solve_grid(int grid[SIZE][SIZE], int row, int col,const char *view);
void ft_print_grid(int grid[SIZE][SIZE]);
void ft_putnbr(int num);
void ft_putstr(char *str);
void ft_putchar(char c);

int main(int argc, char *argv[])
{
    int grid[SIZE][SIZE] = {{0}};
    
    if (argc != 2)
    {
        ft_putstr("Error\n");
        return 0;
    }
    
    char *view = argv[1];
    
    if (!ft_validate_view(view))
    {
    ft_putstr("Error\n");
    return 0;
    }

    if (ft_solve_grid(grid, 0, 0, view))
    {
        ft_print_grid(grid);
    }
    else
    {
        ft_putstr("Error\n");
    }
    return 0;
}
