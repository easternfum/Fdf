/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:24:38 by kfum              #+#    #+#             */
/*   Updated: 2022/04/07 15:55:19 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Calculate X axis angle
*/
void	x_angle(float *y, float *z, float angle)
{
	float	y_angle;
	float	z_angle;

	y_angle = *y;
	z_angle = *z;
	(*y) = y_angle * cosf(angle) + (z_angle) * sinf(angle);
	(*z) = (-y_angle) * sinf(angle) + z_angle * cosf(angle);
}

/*
** Calculate Y axis angle
*/
void	y_angle(float *x, float *z, float angle)
{
	float	x_angle;
	float	z_angle;

	x_angle = *x;
	z_angle = *z;
	(*x) = x_angle * cosf(angle) + (z_angle) * sinf(angle);
	(*z) = (-x_angle) * sinf(angle) + z_angle * cosf(angle);
}

/*
** Calculate Z axis angle
*/
void	z_angle(float *x, float *y, float angle)
{
	float	y_angle;
	float	x_angle;

	y_angle = (*y);
	x_angle = (*x);
	(*x) = x_angle * cosf(angle) - y_angle * sinf(angle);
	(*y) = x_angle * sinf(angle) + y_angle * cosf(angle);
}
