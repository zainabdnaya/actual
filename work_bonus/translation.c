/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:17:13 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/25 14:32:03 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

t_vector        translation(char *str_to_convert,t_vector add_in)
{
    t_vector result;
    t_vector add_to;
    
    add_to = vectorSplit(str_to_convert);
    result = vectorAdd(add_in,add_to);
    return(result);
}


void        camera_translation(t_minirt *rt,int keycode)
{
       if(keycode == 0)
            rt->list_camera->look_from.x = rt->list_camera->look_from.x - 0.2; 
        if(keycode == 2)
            rt->list_camera->look_from.x = rt->list_camera->look_from.x + 0.2; 
        if(keycode == 13)
                rt->list_camera->look_from.y = rt->list_camera->look_from.y + 0.2;
        if(keycode == 1)
            rt->list_camera->look_from.y = rt->list_camera->look_from.y - 0.2;
        if(keycode == 69)
            rt->list_camera->look_from.z = rt->list_camera->look_from.z + 0.2;
        if(keycode == 78)
            rt->list_camera->look_from.z = rt->list_camera->look_from.z - 0.2;
        
}


void        light_translation(t_minirt *rt,int keycode)
{
        // printf("next|x ==> %f|\t|y ==> %f|\t|z ==> %f|\n",rt->clone.lights->position.x,rt->clone.lights->position.y,rt->clone.lights->position.z);

         if(keycode == 0)
            rt->clone.lights->position.x = rt->clone.lights->position.x - 5; 
        if(keycode == 2)
            rt->clone.lights->position.x = rt->clone.lights->position.x + 5; 
        if(keycode == 13)
            rt->clone.lights->position.y = rt->clone.lights->position.y + 5;
        if(keycode == 1)
            rt->clone.lights->position.y = rt->clone.lights->position.y - 5;
        if(keycode == 69)
            rt->clone.lights->position.z = rt->clone.lights->position.z + 5;
        if(keycode == 78)
            rt->clone.lights->position.z = rt->clone.lights->position.z - 5;
}