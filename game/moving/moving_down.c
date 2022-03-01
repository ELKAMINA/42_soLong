#include "../../so_long.h"

void moving_down(t_soLong *game)
{
    int x;
    int y;

    get_pos(game);
    x = game->player->pos_x;
    y = game->player->pos_y;
    move_d(game, x, y);
}

void move_d(t_soLong *game, int x, int y)
{
    if (game->scene[y + 1][x] == '0')
    {
        game->scene[y + 1][x] = 'P';
        get_new_scene(game, x, y, 0);
    }
    else if (game->scene[y + 1][x] == 'C')
    {
        game->scene[y + 1][x] = 'P';
        get_new_scene(game, x, y, 1);
    }
    else if (game->scene[y + 1][x] == 'E')
    {
        if (game->player->nb_of_coll == game->coll->total_nb)
        {
            game->scene[y + 1][x] = 'P';
            get_end_scene(game, x, y);
        }
        else
            ft_printf("\nGO UP, BACK or DOWN\n");
    }
      
}