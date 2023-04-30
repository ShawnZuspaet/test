/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurgens <ajurgens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:57:36 by ajurgens          #+#    #+#             */
/*   Updated: 2023/04/30 15:05:36 by ajurgens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);

void ft_putnbr(int num)
{
    if (num < 0)
    {
        ft_putchar('-');
        num = -num;
    }

    if (num >= 10)
    {
        ft_putnbr(num / 10);
        ft_putnbr(num % 10);
    }
    else
    {
        ft_putchar(num + '0');
    }
}
