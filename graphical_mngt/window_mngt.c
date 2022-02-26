#include "../so_long.h"

int	keypress(int keycode, t_soLong *game)
{
    printf("KEYCODE = %d\n", keycode);
    if (keycode == ESC)
    {
        write(1, "Goodbye!", 7);
        freeing(game->scene);
        if (&(game->floor) != NULL)
		    destroy_all_images(game);
	    mlx_destroy_window(game->frame->mlx, game->frame->win);
        mlx_destroy_display(game->frame->mlx);
        //free(game->frame->mlx);
        exit(1);
        //freeing(game->scene);
        //free(game->frame->mlx);
	    return (0);
        // PROBLEME DE FREE ICI A REVOIR 
    }
    else
    {
        write(1, "NOOOOOOTHINGS HAPPENING\n", 25);
        return (0);
    }
}

void win_management(t_soLong *game)
{
    mlx_hook(game->frame->win, 2, 1L<<0, keypress, &game);
}