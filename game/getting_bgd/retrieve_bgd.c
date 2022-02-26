#include "../../so_long.h"

void    get_background(t_soLong *game)
{
    get_mlx_win(game);
    get_game_base(game);
}

void    get_mlx_win(t_soLong *game)
{
    game->frame->mlx = mlx_init();
    get_width_height(game);
    game->frame->win = mlx_new_window(game->frame->mlx, game->frame->win_w, game->frame->win_h, "Wimbledon");
}

void get_width_height(t_soLong *game)
{
    int wi_g;
    int hei_g;

    hei_g = check_square(game);
    wi_g = ft_strlen(game->scene[0]);
    game->frame->win_w = wi_g * IMG_SIZE;
    game->frame->win_h = hei_g * IMG_SIZE;
}

void    get_game_base(t_soLong *game)
{
// MALLOC STRUCT ???????   
    get_ze_game(game);

}