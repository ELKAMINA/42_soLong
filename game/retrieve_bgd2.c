#include "../so_long.h"

// void my_mlx_put_pixel(t_img_data *img, int x, int y, int color)
// {
//     char    *dst;

//     dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

void init_decor(t_soLong *game)
{
    ////ATTENTION, proteger joueurs en cas de changement de chemins dacces
    game->floor = mlx_xpm_file_to_image(game->frame->mlx, FLOOR, &game->img_width, &game->img_height);
    game->wall = mlx_xpm_file_to_image(game->frame->mlx, WALL, &game->img_width, &game->img_height);
    game->coll = mlx_xpm_file_to_image(game->frame->mlx, COLL, &game->img_width, &game->img_height);
    game->exit = mlx_xpm_file_to_image(game->frame->mlx, EXIT, &game->img_width, &game->img_height);
    game->player = mlx_xpm_file_to_image(game->frame->mlx, PLAYER, &game->img_width, &game->img_height);
}

void put_images(t_soLong *game, void *img, int x, int y)
{
    mlx_put_image_to_window(game->frame->mlx, game->frame->win, img, (y * IMG_SIZE), (x * IMG_SIZE));    
}

void get_the_right_image(char c, t_soLong *game, int i, int j)
{
    if (c == '1')
        put_images(game, game->wall, i, j);
    if (c == '0')
        put_images(game, game->floor, i, j);
    if (c == 'E')
        put_images(game, game->exit, i, j);
    if (c == 'C')
        put_images(game, game->coll, i, j);
    if (c == 'P')
        put_images(game, game->player, i, j);
}

void    get_ze_game(t_soLong *game)
{
    int         i;
    int         j;

    i = 0;
    init_decor(game);
    while (game->scene[i])
    {
        j = 0;
        while (game->scene[i][j])
        {
            get_the_right_image(game->scene[i][j], game, i, j);
            j++;
        }
        i++;
    }
    //game
    //exit
    mlx_loop(game->frame->mlx);
}