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
            //ft_printf("CONGRATULATIONS! YOU WON \n");
            game->scene[y][x + 1] = 'P';
            get_end_scene(game, x, y);
        }
        else
            ft_printf("GO UP, BACK or DOWN");
    }
      
}

void moving_forward(t_soLong *game)
{
    int x;
    int y;

    get_pos(game);
    x = game->player->pos_x;
    y = game->player->pos_y;
    //ft_printf("%d %d\n", game->player->pos_x, game->player->pos_y);
    move_r(game, x, y);
}

void move_l(t_soLong *game, int x, int y)
{
    //ft_printf(" FONCTION MOVE ====> Y = %d --- X = %d \n ", y,  x);
    if (game->scene[y][x - 1] == '0')
    {
        game->scene[y][x - 1] = 'P';
        //ft_printf("new string == %s, x == %d, y==%d\n", game->scene[1], x, y);
        get_new_scene(game, x, y, 0);
    }
    else if (game->scene[y][x - 1] == 'C')
    {
        game->scene[y][x - 1] = 'P';
        //ft_printf("fonction move %d %d\n", x, y);
        get_new_scene(game, x, y, 1);
    }
    else if (game->scene[y][x - 1] == 'E')
    {
        if (game->player->nb_of_coll == game->coll->total_nb)
        {
            ft_printf("CONGRATULATIONS! YOU WON");
            game->scene[y][x - 1] = 'P';
            //ft_printf("fonction move %d %d\n", x, y);
            get_end_scene(game, x, y);
        }
        else
            ft_printf("GO UP, BACK or DOWN");
    }
      
}

void moving_backward(t_soLong *game)
{
    int x;
    int y;

    get_pos(game);
    x = game->player->pos_x;
    y = game->player->pos_y;
    //ft_printf("%d %d\n", game->player->pos_x, game->player->pos_y);
    move_l(game, x, y);
}