#include "../../so_long.h"

void moving_up(t_soLong *game)
{
    int x;
    int y;

    get_pos(game);
    x = game->player->pos_x;
    y = game->player->pos_y;
    //printf("%d %d\n", game->player->pos_x, game->player->pos_y);
    move_u(game, x, y);
}

void move_u(t_soLong *game, int x, int y)
{
    //printf(" FONCTION MOVE ====> Y = %d --- X = %d \n ", y,  x);
    if (game->scene[y - 1][x] == '0')
    {
        game->scene[y - 1][x] = 'P';
        //printf("new string == %s, x == %d, y==%d\n", game->scene[1], x, y);
        get_new_scene(game, x, y, 0);
    }
    else if (game->scene[y - 1][x] == 'C')
    {
        game->scene[y - 1][x] = 'P';
        //printf("fonction move %d %d\n", x, y);
        get_new_scene(game, x, y, 1);
    }
    else if (game->scene[y - 1][x] == 'E')
    {
        if (game->player->nb_of_coll == game->coll->total_nb)
            ft_printf("CONGRATULATIONS! YOU WON");
        else
            ft_printf("GO UP, BACK or DOWN");
    }
      
}