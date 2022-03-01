#include "../../so_long.h"

int quit_game(t_soLong *game)
{
    write(1, "Goodbye!\n", 9);
    if (&(game->floor) != NULL)
        destroy_all_images(game);
    free(game->floor->img);
    free(game->player->img);
    free(game->wall->img);
    free(game->exit->img);
    free(game->coll->img);
    free(game->end->img);
    mlx_destroy_window(game->frame->mlx, game->frame->win); 
    mlx_destroy_display(game->frame->mlx);
    mlx_loop_end(game->frame->mlx);
    free(game->frame->mlx);
    freeing(game->scene);
    free(game->frame);
    free(game->player);
	free(game->wall);
	free(game->coll);
	free(game->exit);
	free(game->floor);
    free(game->end);
    exit(1);
    return (1);
}

void get_pos(t_soLong *game)
{
    int i;
    int j;

    i = 0;
    while (game->scene[i])
    {
        j = 0;
        //ft_printf("%c\n", game->scene[i][j]);
        while (game->scene[i][j])
        {
            if (game->scene[i][j] == 'P')
            {
                game->player->pos_x = j;
                game->player->pos_y = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

void    get_new_scene(t_soLong *game, int x, int y, int co)
{
    game->scene[y][x] = '0';
    //get_pos(game);
    game->player->total_moves++;
    ft_printf("\r -- %d ---", game->player->total_moves);
    mlx_destroy_image(game->frame->mlx, game->player->img->img);
    //game->player->img->img = mlx_xpm_file_to_image(game->frame->mlx, PLAYERR, &(game->player->img->width), &(game->player->img->height));
    //mlx_put_image_to_window(game->frame->mlx, game->frame->win, game->player->img->img, game->player->pos_x, game->player->pos_y);
    if (co == 1)
        game->player->nb_of_coll++;
    get_ze_game(game);
}



int	keypress(int keycode, t_soLong *game)
{
    if (keycode == ESC)
        quit_game(game);
    if (keycode == RIGHT || keycode == 100)
        moving_forward(game);
    if (keycode == LEFT || keycode == 115)
        moving_backward(game);
    if (keycode == UP || keycode == 119)
        moving_up(game);
    if (keycode == DOWN || keycode == 97)
        moving_down(game);
    return (1);
}

int resize(t_soLong*game)
{
    ft_printf("%s\n", game->scene[0]);
    return (1);
}

void playing(t_soLong *game)
{
    mlx_hook(game->frame->win, 2, 1L<<0, keypress, game);
    mlx_hook(game->frame->win, 17, 1L << 17, quit_game, game);
    //mlx_hook(game->frame->win, 25, 1L << 19, resize, game);
}