/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:59:44 by saneveu           #+#    #+#             */
/*   Updated: 2020/05/07 03:48:50 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/3d_engine.h"

static void     framerate(t_env *e)
{
    float           oldtime;
    int             fps;

    oldtime = e->time;
    e->time = SDL_GetTicks();
    e->theta = (e->time - oldtime) / 1000;
    fps = 1.0 / e->theta;
    if (e->usr.fps)
        printf("FPS: %d\n", fps);
    SDL_GetWindowPosition(e->window, &e->wx, &e->wy);
}

static void        setup(t_env *env, int ac, char **av)
{
    int     i;
    int     mi;

    if (ac >= 2)
    {
        env->nbmesh = ac - 1;
        if (!(env->mesh = (t_mesh *)malloc(sizeof(t_mesh) * env->nbmesh)))
            ft_exit(env, "Mesh Alloc Error", 0); 
        i = 1;
        mi = 0;
        while (i < ac)
        {
            env->mesh_id = mi;
            ft_bzero(&env->mesh[mi], sizeof(t_mesh));
            env->mesh[mi] = obj_parser(av[i], env);
            env->mesh[mi].color = colorset(env, mi);
            env->mesh[mi].name = av[i];
            env->mesh[mi].id = mi;
            env->mesh[mi].img = NULL;                   //selection d'image
            mi++;
            i++;
        }
    }
    else
    {
        printf("cube init\n");
        env->nbmesh = 1;
        if (!(env->mesh = (t_mesh *)malloc(sizeof(t_mesh) * env->nbmesh)))
            ft_exit(env, "Mesh Alloc Error", 0); 
        env->mesh[0] = obj_parser("ressources/wooden_crate.obj", env);
        if (!(env->mesh[0].img = SDL_LoadBMP("ressources/wood_crate_10cm.bmp")))
            ft_exit(env, "DooM: Load Bmp Failed\n", 0);
        //init_cube(env);
    }
    init_sdl(env);
    init_data(env);
    init_world(env);
}

int         main(int ac, char **av)
{
    t_env   env;
 
    ft_memset(&env, 0, sizeof(t_env));
    setup(&env, ac, av);
    env.end = 1;
    while (env.end)
    {
        framerate(&env);
        (env.usr.f[env.usr.platform])((void*)&env);
    }
    return (0);
}

