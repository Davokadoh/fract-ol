#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_W 1280
# define WIN_H 720
# define ZOOM 1.1f


typedef struct	s_cmplx
{
	double	r;
	double	i;
}				t_cmplx;

typedef struct	s_pixel
{
	t_cmplx	z;
	int		iterations;
}				t_pixel

typedef struct	s_viewport
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymin;
	double	zoom;
	double	offx;
	double	offy;
	long	max;
	t_cmplx	mouse;
}				t_viewport;

typedef void	(*t_f_viewport)(t_viewport *view);
typedef t_pixel	(*t_f_iterate)(int x, int y, t_viewport *view);

typedef struct	s_fractal
{
	char			*name;
	t_f_viewport	viewport;
	t_f_iterate		iterate;
}				t_fractal;

typedef struct	s_img
{
	void	*img;
	char	*ptr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_pixels	*pixels;
}

#endif
