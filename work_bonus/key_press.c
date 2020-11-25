/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:49:22 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/25 14:43:11 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

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
    {
        if( keycode == 7) //x
            rt->axe = 1;
        if(keycode == 16) //y
            rt->axe = 2;
        if(keycode == 6) //z
            rt->axe = 3;
        if(rt->axe == 1 || rt->axe == 2 || rt->axe == 3)
            camera_rotation(rt,rt->axe,keycode);
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
}

void     key_press3(int keycode, t_minirt *rt)
{
    static int i = 1;
    static int j = 0;
    static int size=0;
    if(j==0)
     {
        rt->new_lightTmp=rt->clone.lights;
        j=1;

        size = ft_lstsize1(rt->new_lightTmp);
    //  printf("==>size%i",size);
     }
    if(keycode == 124 && rt->active == 2)
    {
        if(size == i)
        {
            rt->clone.lights=rt->new_lightTmp;
            i=0;

        }
        else
        //{
                 rt->clone.lights = rt->clone.lights->next;
            //    printf("next|x ==> %f|\t|y ==> %f|\t|z ==> %f|\n",rt->clone.lights->position.x,rt->clone.lights->position.y,rt->clone.lights->position.z);
       // }
                write(1, "puf m here\n",11);

        // build_image(rt, rt->list_camera->look_at); 
        // mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
        i++;
    }
    // rt->list_light = rt->clone.lights;
}
void    key_press4(int keycode,t_minirt *rt)
{
     if (keycode == 123 && rt->active == 2 && rt->clone.lights->previous!= NULL )
    {
        rt->clone.lights = rt->clone.lights->previous;
        // printf("previous|x ==> %f|\t|y ==> %f|\t|z ==> %f|\n",rt->clone.lights->position.x,rt->clone.lights->position.y,rt->clone.lights->position.z);
        build_image(rt, rt->list_camera->look_at);
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
}

void          light_press(t_minirt *rt,int keycode)
{
    key_press3(keycode,rt);
    key_press4(keycode,rt);
    if(keycode == 17)
        rt->trans_rot_index = 1;
    if(rt->trans_rot_index == 1  )
    {   
        write(1, "now im here\n",11);
        light_translation(rt,keycode);
        build_image(rt, rt->list_camera->look_at);
        mlx_clear_window (rt->mlx.mlx_ptr, rt->mlx.win );
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }   
}
