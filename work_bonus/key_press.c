/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:49:22 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/26 19:36:16 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"


void     key_press3(int keycode, t_minirt *rt)
{
    if(rt->stc.j==0)
     {
        rt->new_lightTmp=rt->clone.lights;
        rt->stc.j=1;
        rt->stc.size = ft_lstsize1(rt->new_lightTmp);
     }
    if(keycode == 126 && rt->active == 2)
    {
        if(rt->stc.size <= rt->stc.i)
        {
            rt->clone.lights=rt->new_lightTmp;
            rt->stc.i=0;

        }
        else
                 rt->clone.lights = rt->clone.lights->next;
        // build_image(rt, rt->list_camera->look_at);
        // mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
        rt->stc.i++;
    }
}

void    key_press4(int keycode,t_minirt *rt)
{
     if (keycode == 125 && rt->active == 2 && rt->clone.lights->previous!= NULL )
    {
        rt->clone.lights = rt->clone.lights->previous;
        // build_image(rt, rt->list_camera->look_at);
        // mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
}

void     key_press7(int keycode, t_minirt *rt)
{
    // write(1,"i m here",8);
    if(rt->stc.j==0)
     {
        rt->new_Tmp=rt->clone.objects;
        rt->stc.j=1;
        rt->stc.size = ft_lstsize2(rt->new_Tmp);
     }
    if(keycode == 126 && rt->active == 3  )
    {
        if(rt->stc.size <= rt->stc.i)
        {
            rt->clone.objects=rt->new_Tmp;
            rt->stc.i=0; 
        }
        else
          rt->clone.objects= rt->clone.objects->next;
        //  build_image(rt, rt->list_camera->look_at);
        // mlx_clear_window (rt->mlx.mlx_ptr, rt->mlx.win );
        // mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
       rt->stc.i++;
    }
}
void    key_press8(int keycode,t_minirt *rt)
{
     if (keycode == 125 && rt->active == 3 && rt->clone.objects->previous!= NULL )
    {
        rt->clone.objects = rt->clone.objects->previous;
        // build_image(rt, rt->list_camera->look_at);
        // mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
}