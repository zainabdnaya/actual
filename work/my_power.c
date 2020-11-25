/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:46:55 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/24 21:07:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

double my_power(double number, int power)
{
    double result;
    int count;

    count = 1;
    result = 1;
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    while (count <= power)
    {
        result = result * number;
        count++;
    }
    return (result);
}