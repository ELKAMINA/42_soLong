#include "../../so_long.h"

void    get_end_scene(t_soLong *game, int x, int y)
{
    game->scene[y][x] = '0';
    //get_pos(game);
    game->player->total_moves++;
    ft_printf("\r -- %d ---", game->player->total_moves);
    //mlx_destroy_image(game->frame->mlx, game->player->img->img);
    //game->player->img->img = mlx_xpm_file_to_image(game->frame->mlx, PLAYERR, &(game->player->img->width), &(game->player->img->height));
    //mlx_put_image_to_window(game->frame->mlx, game->frame->win, game->player->img->img, game->player->pos_x, game->player->pos_y);
    quit_game(game);
}
