/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:29:00 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/24 16:48:28 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_list *creat_new_node(void  *data)
{
  t_list *new;
  
   if(!( new = malloc(sizeof(t_list))))
      return(NULL);
  new->content = data;
  new->next = NULL;
  return(new);

}
