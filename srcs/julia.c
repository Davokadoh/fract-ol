#include "fractol.h"

int	julia_iterate(t_cmplx cmplx)
{
	(void) cmplx;
	return (0);
}

void	julia_viewport(t_viewport *view)
{
	view->xmin = -2.0f;
	view->xmax = 1.0f;
	view->ymin = -1.0f;
	view->ymax = 1.0f;
	view->offx = -0.5f;

}
