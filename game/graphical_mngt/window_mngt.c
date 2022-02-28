#include "../../so_long.h"

int quit_game(t_soLong *game)
{
    write(1, "Goodbye!", 7);
    //freeing(game->scene);

    // A REVOIR CA SEG FAULT

    if (&(game->floor) != NULL)
        destroy_all_images(game);
    mlx_destroy_window(game->frame->mlx, game->frame->win); 
    mlx_destroy_display(game->frame->mlx);
    //free(game->frame->mlx);
    freeing(game->scene);
    exit(1);
    return (1);
    //free(game->frame->mlx);
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
    ft_printf("get new scene 1 = %d %d\n", x, y);
    ft_printf("get caracteres = %s\n", game->scene[y]);
    game->scene[y][x] = '0';
    //get_pos(game);
    game->player->total_moves++;
    ft_printf("Player's movement == %d\n", game->player->total_moves);
    mlx_destroy_image(game->frame->mlx, game->player->img->img);
    ft_printf("get new scene 2 = %s\n", game->scene[2]);
    //game->player->img->img = mlx_xpm_file_to_image(game->frame->mlx, PLAYERR, &(game->player->img->width), &(game->player->img->height));
    //mlx_put_image_to_window(game->frame->mlx, game->frame->win, game->player->img->img, game->player->pos_x, game->player->pos_y);
    if (co == 1)
        game->player->nb_of_coll++;
    get_ze_game(game);
}



int	keypress(int keycode, t_soLong *game)
{
    ft_printf("KEYCODE == %d\n", keycode);
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
    // else
    // {
    //     write(1, "NOOOOOOTHINGS HAPPENING\n", 25);
    //     return (0);
    // }
    return (1);
}

void playing(t_soLong *game)
{
    mlx_hook(game->frame->win, 2, 1L<<0, keypress, game);
    mlx_hook(game->frame->win, 33, 1L << 5, quit_game, game);
}