#include "../so_long.h"

void    freeing(char    **game)
{
    int i;

    i = 0;
    while(game[i])
    {
        free(game[i]);
        game[i] = NULL;
        i++;
    }
    free(game);
    game = NULL;
}

void    free_crash_init(t_soLong *game)
{
    free(game->floor->img);
    free(game->wall->img);
    free(game->player->img);
    free(game->exit->img);
    free(game->coll->img);
    free(game->frame->mlx);
    free(game->frame);
    free(game->player);
	free(game->wall);
	free(game->coll);
	free(game->exit);
	free(game->floor);
    freeing(game->scene);
}