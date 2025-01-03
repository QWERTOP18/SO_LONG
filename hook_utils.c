/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:14:34 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 19:21:28 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_handler.h"
#include <math.h>

#define DEBUG 1

void	zoom_screen(t_sys *sys, double ratio, int x, int y)
{
	t_screen	screen;
	t_complex	center;

	ft_memset(sys->iter, 0, sizeof(sys->iter));
	sys->sup_iteri = 0;
	screen = sys->screen;
	center.re = (double)x / SCREEN_WIDTH * screen.width + screen.base.re;
	center.im = (double)y / SCREEN_HEIGHT * screen.height + screen.base.im;
	screen.base.re = center.re + (screen.base.re - center.re) * ratio;
	screen.base.im = center.im + (screen.base.im - center.im) * ratio;
	screen.width *= ratio;
	screen.height *= ratio;
	sys->screen = screen;
}

void	pan_screen(t_sys *sys, int id)
{
	static double	dx[4] = {0, 1, 0, -1};
	static double	dy[4] = {1, 0, -1, 0};
	t_screen		screen;

	ft_memset(sys->iter, 0, sizeof(sys->iter));
	sys->sup_iteri = 0;
	screen = sys->screen;
	screen.base.re += dy[id] * screen.width * DELTA;
	screen.base.im += dx[id] * screen.height * DELTA;
	sys->screen = screen;
}

void	modify_coefficient(t_sys *sys, int id)
{
	static double	dx[4] = {-0.01, 0, 0.01, 0};
	static double	dy[4] = {0, -0.01, 0, 0.01};

	ft_memset(sys->iter, 0, sizeof(sys->iter));
	sys->sup_iteri = 0;
	sys->coef.im += dy[id];
	sys->coef.re += dx[id];
	sys->coef.im = fmax(-1.0, fmin(1.0, sys->coef.im));
	sys->coef.re = fmax(-1.0, fmin(1.0, sys->coef.re));
}

void	modify_color_range(t_sys *sys, int id)
{
	(void)id;
	ft_memset(sys->iter, 0, sizeof(sys->iter));
	sys->sup_iteri = 0;
}
