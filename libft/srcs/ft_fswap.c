/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:08:06 by saneveu           #+#    #+#             */
/*   Updated: 2020/03/23 04:55:34 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void        ft_fswap(float *n1, float *n2)
{
    float tmp;

    tmp = *n2;
    *n2 = *n1;
    *n1 = tmp;
}