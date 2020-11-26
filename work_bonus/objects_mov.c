/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_mov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:22:08 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/26 19:44:40 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void object_press(t_minirt *rt, int keycode)
{
    key_press7(keycode,rt);
    key_press8(keycode,rt);
    if(keycode == 17)
        rt->trans_rot_index = 1;
    if(keycode == 15)
        rt->trans_rot_index= 2;
    if(rt->trans_rot_index == 1 )
    {   
        objects_trans(rt,keycode);
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
    if(rt->trans_rot_index == 2)
    {   
        objects_rot(rt,keycode);
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
        
}
void        objects_trans(t_minirt *rt,int keycode)
{
    if ( rt->clone.objects->wich_objects == 1)
         sphere_translation(rt,keycode);
    else if ( rt->clone.objects->wich_objects == 2)
        plan_trans(rt,keycode);
    else if ( rt->clone.objects->wich_objects == 3)
         triangle_trans(rt,keycode);
  else if ( rt->clone.objects->wich_objects == 4)
         square_trans(rt,keycode);
  else if ( rt->clone.objects->wich_objects == 5)
         cylindre_trans(rt,keycode);
}
void        objects_rot(t_minirt *rt,int keycode)
{
    wich_axe(rt,keycode);
    if ( rt->clone.objects->wich_objects == 2)
        plan_rot(rt,rt->axe,keycode);
  else if ( rt->clone.objects->wich_objects == 4)
         square_rot(rt,rt->axe,keycode);
  else if ( rt->clone.objects->wich_objects == 5)
         cylindre_rot(rt,rt->axe,keycode);

}


// void        sphere_mv(t_minirt *rt,int keycode)
// {
//     if (rt->trans_rot_index == 1)
       
//     build_image(rt, rt->list_camera->look_at);
//     mlx_clear_window (rt->mlx.mlx_ptr, rt->mlx.win );
//     mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
// }

// void        rot_cylindre(t_minirt *rt,int keycode)
// {
//     //  if ( keycode == 14)
//     //     if(keycode == 7)
//     //  key_press7(keycode,rt);
//     // key_press8(keycode,rt);
//     wich_axe(rt, keycode);
//     if (rt->axe == 1 || rt->axe == 2 || rt->axe == 3)
//         cylindre_rot(rt, keycode);
//     build_image(rt, rt->list_camera->look_at);
//     mlx_clear_window(rt->mlx.mlx_ptr, rt->mlx.win);
//     mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
// }
// void        cylindre_mv(t_minirt *rt,int keycode)
// { 
   
//     if (keycode == 17)
//         rt->trans_rot_index = 1;
//     if (keycode == 15)
//         rt->trans_rot_index = 2;
//     if (rt->trans_rot_index == 1 )
//         { 
//                 // key_press7(keycode,rt);

//                 // key_press8(keycode,rt);
//             cylindre_trans(rt,keycode);
//             build_image(rt, rt->list_camera->look_at);
//             mlx_clear_window(rt->mlx.mlx_ptr, rt->mlx.win);
//             mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
//         }
//     if (rt->trans_rot_index == 2)
//         rot_cylindre(rt,keycode);
// }

// void      plan_rt(t_minirt *rt,int keycode )
// {
    
// }

// void       plan_mv(t_minirt *rt,int keycode)
// {
//     //  key_press7(keycode, rt);
//     //  key_press8(keycode, rt);
//     if (rt->trans_rot_index == 1)
//     {
//         plan_trans(rt, keycode);
//         build_image(rt, rt->list_camera->look_at);
//         mlx_clear_window(rt->mlx.mlx_ptr, rt->mlx.win);
//         mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
//     }
//     if (rt->trans_rot_index == 2)
//     {
//         wich_axe(rt, keycode);
//         if (rt->axe == 1 || rt->axe == 2 || rt->axe == 3)
//             plan_rot(rt, rt->axe, keycode);
//         build_image(rt, rt->list_camera->look_at);
//         mlx_clear_window(rt->mlx.mlx_ptr, rt->mlx.win);
//         mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
//     }
// }
