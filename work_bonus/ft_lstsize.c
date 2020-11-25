/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:09:24 by mac               #+#    #+#             */
/*   Updated: 2020/11/25 12:01:38 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int		ft_lstsize(t_list_camera *lst)
{
	int		count;
	t_list_camera	*tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}




int		ft_lstsize1(t_list_lights *lst)
{
	int		count;
	t_list_lights	*tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
