/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurgens <ajurgens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:02:50 by ajurgens          #+#    #+#             */
/*   Updated: 2023/04/30 14:31:29 by ajurgens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void ft_putnbr(int num);
void ft_putchar(char c);

void ft_print_grid(int grid[SIZE][SIZE])
{
    int i = 0;
    int j = 0;

    while (i < SIZE)
    {
        j = 0;
        while (j < SIZE)
        {
            ft_putnbr(grid[i][j]);
            if (j != SIZE - 1)
            ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}
