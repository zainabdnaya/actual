/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:13:54 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/26 19:40:53 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void wich_axe(t_minirt *rt,int keycode)
{
    if( keycode == 7) //x
            rt->axe = 1;
        if(keycode == 16) //y
            rt->axe = 2;
        if(keycode == 6) //z
            rt->axe = 3;
} 

// void wich_one(t_minirt *rt, int keycode)
// {
//     if (keycode == 4)
//         rt->obj = 1;
//     if (keycode == 35)
//         rt->obj = 2;
//     if (keycode == 45)
//         rt->obj = 3;
//     if (keycode == 12)
//         rt->obj = 4;
//     if (keycode == 5)
//         rt->obj = 5;
// }

void          light_press(t_minirt *rt,int keycode)
{
    key_press3(keycode,rt);
    key_press4(keycode,rt);
    if(keycode == 17)
        rt->trans_rot_index = 1;
    if(rt->trans_rot_index == 1  )
    {   
        light_translation(rt,keycode);
        build_image(rt, rt->list_camera->look_at);
        // mlx_clear_wsindow (rt->mlx.mlx_ptr, rt->mlx.win );
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }   
}

void        cam_rot(t_minirt *rt,int keycode)
{
        wich_axe(rt,keycode);
        if(rt->axe == 1 || rt->axe == 2 || rt->axe == 3)
            camera_rotation(rt,rt->axe,keycode);
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);   
}
void          camera_press(t_minirt *rt,int keycode)
{
  
    key_press1(keycode,rt);
    key_press2(keycode,rt);
    if(keycode == 17)
        rt->trans_rot_index = 1;
    if(keycode == 15)
        rt->trans_rot_index= 2;
    if(rt->trans_rot_index == 1 )
    {   
        camera_translation(rt,keycode);
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
    if(rt->trans_rot_index == 2)
        cam_rot(rt,keycode);
}

