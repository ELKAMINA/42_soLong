#include "../../so_long.h"

void move_r(t_soLong *game, int x, int y)
{
    if (game->scene[y][x + 1] == '0')
    {
        game->scene[y][x + 1] = 'P';
        get_new_scene(game, x, y, 0);
    }
    else if (game->scene[y][x + 1] == 'C')
    {
        game->scene[y][x + 1] = 'P';
        get_new_scene(game, x, y, 1);
    }
    else if (game->scene[y][x + 1] == 'E')
    {
        if (game->player->nb_of_coll == game->coll->total_nb)
        {
            game->scene[y][x + 1] = 'P';
            get_end_scene(game, x, y);
        }
        else
            ft_printf("\nGO UP, BACK or DOWN\n");
    }
      
}

void moving_forward(t_soLong *game)
{
    int x;
    int y;

    get_pos(game);
    x = game->player->pos_x;
    y = game->player->pos_y;
    move_r(game, x, y);
}

void move_l(t_soLong *game, int x, int y)
{
    if (game->scene[y][x - 1] == '0')
    {
        game->scene[y][x - 1] = 'P';
        get_new_scene(game, x, y, 0);
    }
    else if (game->scene[y][x - 1] == 'C')
    {
        game->scene[y][x - 1] = 'P';
        get_new_scene(game, x, y, 1);
    }
    else if (game->scene[y][x - 1] == 'E')
    {
        if (game->player->nb_of_coll == game->coll->total_nb)
        {
            game->scene[y][x - 1] = 'P';
            get_end_scene(game, x, y);
        }
        else
            ft_printf("\nGO UP, BACK or DOWN\n");
    }
      
}

void moving_backward(t_soLong *game)
{
    int x;
    int y;

    get_pos(game);
    x = game->player->pos_x;
    y = game->player->pos_y;
    move_l(game, x, y);
}