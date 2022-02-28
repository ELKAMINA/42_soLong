#include "../../so_long.h"

void quit_game(t_soLong *game)
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
        //printf("%c\n", game->scene[i][j]);
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
    printf("get new scene 1 = %d %d\n", x, y);
    printf("get caracteres = %s\n", game->scene[x]);
    game->scene[y][x] = '0';
    //get_pos(game);
    game->player->total_moves++;
    mlx_destroy_image(game->frame->mlx, game->player->img->img);
    printf("get new scene 2 = %s\n", game->scene[2]);
    //game->player->img->img = mlx_xpm_file_to_image(game->frame->mlx, PLAYERR, &(game->player->img->width), &(game->player->img->height));
    //mlx_put_image_to_window(game->frame->mlx, game->frame->win, game->player->img->img, game->player->pos_x, game->player->pos_y);
    if (co == 1)
        game->player->nb_of_coll++;
    get_ze_game(game);
}

void move(t_soLong *game, int x, int y)
{
    //printf(" FONCTION MOVE ====> Y = %d --- X = %d \n ", y,  x);
    if (game->scene[y][x + 1] == '0')
    {
        game->scene[y][x + 1] = 'P';
        //printf("new string == %s, x == %d, y==%d\n", game->scene[1], x, y);
        get_new_scene(game, x, y, 0);
    }
    else if (game->scene[y][x + 1] == 'C')
    {
        game->scene[y][x + 1] = 'P';
        //printf("fonction move %d %d\n", x, y);
        get_new_scene(game, x, y, 1);
    }
    else if (game->scene[y][x + 1] == 'E')
    {
        if (game->player->nb_of_coll == game->coll->total_nb)
            printf("CONGRATULATIONS! YOU WON");
        else
            printf("GO UP, BACK or DOWN");
    }
      
}

void moving_forward(t_soLong *game)
{
    int x;
    int y;

    get_pos(game);
    x = game->player->pos_x;
    y = game->player->pos_y;
    //printf("%d %d\n", game->player->pos_x, game->player->pos_y);
    move(game, x, y);
}


int	keypress(int keycode, t_soLong *game)
{
    printf("KEYCODE = %d\n", keycode);
    if (keycode == ESC)
        quit_game(game);
    if (keycode == RIGHT)
        moving_forward(game);
    else
    {
        write(1, "NOOOOOOTHINGS HAPPENING\n", 25);
        return (0);
    }
    return (1);
}

void playing(t_soLong *game)
{
    mlx_hook(game->frame->win, 2, 1L<<0, keypress, game);
}