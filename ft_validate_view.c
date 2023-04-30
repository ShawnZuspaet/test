/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurgens <ajurgens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:59:10 by ajurgens          #+#    #+#             */
/*   Updated: 2023/04/29 15:11:02 by ajurgens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int ft_validate_view(char *view)
{
    int i = 0;
    int count = 0;
    int height;

    while (view[i])
    {
        if (view[i] == ' ')
            i++;
        else
        {
            height = view[i] - '0';
            if (height < 1 || height > SIZE)
            return 0;
            count++;
            while (view[i] && view[i] != ' ')
            i++;
        }
    }
    
    return count == 2 * SIZE * 2;
}
