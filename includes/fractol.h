#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_W 640
# define WIN_H 360
# define ZOOM 1.1f

# define MANDEL 1 
# define JULIA 2
# define BS 3

typedef struct	s_palette
{
	int	size;
	int	colors[5];
}				t_palette;

typedef struct	s_cmplx
{
	double	r;
	double	i;
}				t_cmplx;

typedef struct	s_pixel
{
	t_cmplx	z;
	int		iterations;
}				t_pixel;

typedef struct	s_viewport
{
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			zoom;
	double			offx;
	double			offy;
	unsigned long	max;
	t_cmplx	mouse;
}				t_viewport;

typedef struct	s_img
{
	void	*bff;
	char	*ptr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

typedef struct	s_mouse
{
	int	x;
	int	y;
	int	last_x;
	int	last_y;
	int	down;
}				t_mouse;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_pixel		*pixels;
	t_viewport	viewport;
	t_palette	palette;
	t_mouse		mouse;
	int			smooth;
	int			name;
}				t_env;

//Hooks
int					hook_mousedown(int button, int x, int y, t_env *env);
int					hook_mouseup(int button, int x, int y, t_env *env);
int					hook_mousemove(int x, int y, t_env *env);
int					hook_keydown(int key, t_env *env);

//Fractals
int					julia_iterate(t_cmplx c);
void				julia_viewport(t_viewport *v);
int					mandelbrot_iterate(t_cmplx c);
void				mandelbrot_viewport(t_viewport *v);
int					burningship_iterate(t_cmplx c);
void				burningship_viewport(t_viewport *v);

//Render
t_palette			get_palette(int i);
void				reset_viewport(t_env *env);
void				render(t_env *env);
void				zoom(int x, int y, t_viewport *v, double z);

//Other
int					match(char *name);
t_env				*init(char *fractal);
t_cmplx				pixel_to_cmplx(int x, int y, t_viewport *v);

#endif
