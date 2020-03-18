/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:31:07 by saneveu           #+#    #+#             */
/*   Updated: 2020/03/18 03:58:15 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/3d_engine.h"

static void         key_tab(t_env *e)
{
    if (e->event.key.keysym.scancode == SDL_SCANCODE_W)
        e->key[W] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_S)
        e->key[S] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_A)
        e->key[A] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_D)
        e->key[D] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_Q)
        e->key[Q] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_E)
        e->key[E] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_R)
        e->key[R] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_F)
        e->key[F] = e->event.type == SDL_KEYDOWN ? 1 : 0;

    else if (e->event.key.keysym.scancode == SDL_SCANCODE_SPACE)
        e->key[SPACE] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_LCTRL)
     { 
         printf("||||||||||||||||||||||||||||||||||||||||||\n");
        e->key[LCTRL] = e->event.type == SDL_KEYDOWN ? 1 : 0;
     }

    else if (e->event.key.keysym.scancode == SDL_SCANCODE_UP)
        e->key[UP] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        e->key[DOWN] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_LEFT)
        e->key[LEFT] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
            e->key[RIGHT] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_1)
        e->key[NUM1] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_2)
        e->key[NUM2] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_3)
        e->key[NUM3] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_4)
        e->key[NUM4] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_5)
        e->key[NUM5] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_6)
        e->key[NUM6] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_7)
        e->key[NUM7] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_8)
        e->key[NUM8] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.key.keysym.scancode == SDL_SCANCODE_KP_9)
        e->key[NUM9] = e->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (e->event.type == SDL_MOUSEMOTION)
        e->key[MOUSE] = 1;
}

//static void         camera_move_event(t_env *e)
//{
//    if (e->key[W] || e->key[S])
//    {
//        e->vlist.forward = vectormult(e->vlist.lookdir, 8.0 * e->theta);
//        if (e->key[W])
//            e->vlist.vcamera = vectoradd(e->vlist.vcamera, e->vlist.forward);
//        else if (e->key[S])
//            e->vlist.vcamera = vectorsub(e->vlist.vcamera, e->vlist.forward);
//    }
//    if (e->key[UP])
//        e->vlist.vcamera.y += 8.0 * e->theta;
//    if (e->key[DOWN])
//        e->vlist.vcamera.y -= 8.0 * e->theta;
//    if (e->key[A])
//        e->vlist.vcamera.x += 8.0 * e->theta;
//    if (e->key[D])
//        e->vlist.vcamera.x -= 8.0 * e->theta;
//}

//void                camera_rot_event(t_env *e)
//{
//    if (e->key[Q])
//    {
//        e->yaw -= 2.0 * e->theta;
//        init_matrix_roty(&e->mlist.camroty, e->yaw);
//    }
//    if (e->key[E])
//    {
//        e->yaw += 2.0 * e->theta;
//        init_matrix_roty(&e->mlist.camroty, e->yaw);    
//    }
//    if (e->key[R])
//    {
//        e->xaw -= 2.0 * e->theta;
//        init_matrix_rotx(&e->mlist.camrotx, e->xaw);
//    }
//    if (e->key[F])
//    {
//        e->xaw += 2.0 * e->theta;
//        init_matrix_rotx(&e->mlist.camrotx, e->xaw);    
//    }
//}

void                event(t_env *env)
{
    while (SDL_PollEvent(&env->event))
    {
        if ((env->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE
		&& env->event.type == SDL_KEYDOWN)
		|| env->event.type == SDL_QUIT)
            ft_exit(env, "fini\n", 1);
        key_tab(env);
    }
    camera_event(env);
    mesh_rot_event(env);
}
