/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:54:17 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/25 17:54:39 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int main(int argc,char **argv)
{
    t_minirt rt;
    t_static stc;

    if (argc < 2 || argc > 4)
    {
            error(1);
            exit(1);
    }
    if (ft_compare_end(argv[1], ".rt") != 1)
     {
           error(2);
           exit(1);
     }
    ft_bzero(&rt,sizeof(t_minirt));
     rt.name = argv[1];

     initial_all_objects(&rt);
    if(argc ==3)
     {
         if(ft_compare_end(argv[2],"--save") == 1)
            rt.save = 1;
     }
    rt.mlx.mlx_ptr = mlx_init();
    parsing_RT(argv[1],&rt);
    rt.clone.objects = rt.list_obj; 
    rt.clone.lights = rt.list_light; 
    rt.clone.camera = rt.list_camera; 
    // print_light(rt.list_light);
    // rt.clone.lights = rt.clone.lights->next; 
    // printf("next|x ==> %f|\t|y ==> %f|\t|z ==> %f|\n",rt.clone.lights->position.x,rt.clone.lights->position.y,rt.clone.lights->position.z);
    rt.stc.i = 1;
    rt.stc.j = 0;
    rt.stc.size =0; 
    create_window(&rt, rt.resol.WIDTH, rt.resol.HEIGHT);               
}