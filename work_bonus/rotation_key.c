/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:11:58 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/25 11:41:50 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void        camera_rotation(t_minirt *rt,int axe,int keycode)   
{
    double angle;
    
    angle = PI/18;
    if(keycode == 123) // left
        angle *= -1;
    if ( axe == 1 && (keycode == 123 || keycode == 124))
        rt->list_camera->look_at = rotation_around_x(rt->list_camera->look_at,angle);
    if ( axe == 2 && (keycode == 123 || keycode == 124))
        rt->list_camera->look_at = rotation_around_y(rt->list_camera->look_at,angle);
    if (axe == 3 && (keycode == 123 || keycode == 124))
        rt->list_camera->look_at = rotation_around_z(rt->list_camera->look_at,angle);
}
