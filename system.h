/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:09 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 14:34:04 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <X11/X.h>
# include <X11/Xutil.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define E_ALLOCATE -1
# define E_MLX_INIT -2
# define E_WINDOW_CREATE -3
# define E_INVALID_INPUT -4

# define ERRMSG "PLEASE TYPE * mandelbrot\n* julia\n* burningship\n"
# define OPTIONS "mandelbrot&#$~julia$#&&&"

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 1000

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

typedef struct s_simg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_simg;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_sys
{
	void	*mlx;
	void	*win;
	t_simg	img;
	int		type;
	//      t_fractal_drawer	fractal_drawer;
	t_complex coef; // hjkl keyで調整できるように todo

}			t_sys;

t_sys		*system_init(char *arg);
void		system_exit(t_sys *sys, int status);

#endif