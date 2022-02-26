#include <mlx.h>
//#include "so_long.h"
#include "stdio.h"
#include "unistd.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	closes(int keycode, t_vars *vars)
{
    printf("KEYCODE = %d\n", keycode);
    if (keycode == 65307)
	    mlx_destroy_window(vars->mlx, vars->win);
    else
        write(1, "NOOOOOOTHINGS HAPPENING\n", 25);
    
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, closes, &vars);
	mlx_loop(vars.mlx);
}