/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_enginebis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 23:11:06 by saneveu           #+#    #+#             */
/*   Updated: 2020/03/23 02:55:47 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/3d_engine.h"

t_vec    center(t_vec *out)
{
        out->x *= 0.5f * W_W;
        out->y *= 0.5f * W_H;
        return(*out);
}

int       lumiere(t_env *e, t_vec normal)
{
    float dp;
    
    e->vlist.light_dir = vectornormal(e->vlist.light_dir);
    dp = vectorproduct(normal, e->vlist.light_dir);
    return (color_shading(e->mesh[e->mesh_id].color, dp));
}

void            matrix_world(t_env *e, float xtheta, float ytheta, float ztheta)
{
    init_matrix_rotz(&e->mlist.matrotz, ztheta * 0.5f);
    init_matrix_rotx(&e->mlist.matrotx, xtheta);
    init_matrix_roty(&e->mlist.matroty, ytheta * 0.8);
    //init_matrix_translation(&e->mesh[e->usr.event_i_mesh].mattrans, (t_vec){0.0f, 0.0f, e->zoom});
    init_matrix_translation(&e->mesh[e->mesh_id].mattrans, e->mesh[e->mesh_id].dir);
    e->mlist.matworld = matrix_mult_matrix(e->mlist.matroty, e->mlist.matrotx);
    e->mlist.matworld = matrix_mult_matrix(e->mlist.matworld, e->mlist.matrotz);
    e->mlist.matworld = matrix_mult_matrix(e->mlist.matworld, e->mesh[e->mesh_id].mattrans);
}

void            matrix_view(t_env *e)
{
    t_matrix        matcam;
    t_matrix        camrot;
    t_vec           up;
    t_vec           target;

    e->vlist.lookdir = (t_vec){ 0,0,1,0 };
    up = (t_vec){ 0,-1,0,0 };
    target = (t_vec){ 0,0,1,0 };
 
    init_matrix_roty(&e->mlist.camroty, ft_to_radian(e->yaw) * 21);
    init_matrix_rotx(&e->mlist.camrotx, ft_to_radian(e->xaw) * 11); 

    init_matrix_identity(&camrot);
    camrot = matrix_mult_matrix(e->mlist.camrotx, e->mlist.camroty);
    
    e->vlist.lookdir = matrix_mult_vector(camrot, target);
    target = vectoradd(e->vlist.vcamera, e->vlist.lookdir);
    
    up = matrix_mult_vector(camrot, up);
    
    pointatmatrix(&matcam, e->vlist.vcamera, target, up);
    quickinversematrix(&e->mlist.matview, matcam);
}