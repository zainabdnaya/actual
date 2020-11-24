/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:33:12 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/24 17:24:13 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int mlx_close(t_minirt *rt)
{
    (void)rt;
    exit(0);
    return(0);
}

int key_hook(int key, t_minirt *rt)
{
     (void)rt;
    if (key == 53)
        exit(0);
    return (0);
}
void print_list_camera(t_list_camera *ip)
{

    while (ip != NULL)
    {
        printf("Radiuds===>%f\n", ip->fov);
        printf("Center==> %f\n", ip->look_from.x);
        printf("Center==> %f\n", ip->look_from.y);
        printf("Center==> %f\n", ip->look_from.z);
        printf("Color==> %f\n",  ip->look_at.x);
        printf("Color==> %f\n",  ip->look_at.y);
        printf("Color==> %f\n",  ip->look_at.z);
        ip = ip->next;
    }
    printf("\n");
}
void     key_press1(int keycode, t_minirt *rt)
{
    static int i = 1;
    static int j = 0;
    static int size=0;
    if(j==0)
     {
        rt->new_CamTmp=rt->list_camera;
        j=1;

        size = ft_lstsize(rt->new_CamTmp);
     }
    if(keycode == 8)
            rt->active_cam = 1;
    if(keycode == 124 && rt->active_cam == 1)
    {
        if(size == i)
        {
            rt->list_camera=rt->new_CamTmp;
            i=0;
        }
        else
             rt->list_camera = rt->list_camera->next;
        build_image(rt, rt->list_camera->look_at); 
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
        i++;
    }
    
}

int key_press(int keycode, t_minirt *rt)
{
    key_press1(keycode,rt);
    if (keycode == 123 && rt->active_cam == 1 && rt->list_camera->previous!= NULL )
    {
             rt->list_camera = rt->list_camera->previous;
        build_image(rt, rt->list_camera->look_at);
        mlx_put_image_to_window(rt->mlx.mlx_ptr, rt->mlx.win, rt->mlx.img_ptr, 0, 0);
    }
    return(0);
}