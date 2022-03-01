#include "../../so_long.h"

void init_decor(t_soLong *game)
{
    ////ATTENTION, proteger joueurs en cas de changement de chemins dacces
    game->player->img->img = mlx_xpm_file_to_image(game->frame->mlx, PLAYER, &(game->player->img->width), &(game->player->img->height));
    game->wall->img->img = mlx_xpm_file_to_image(game->frame->mlx, WALL, &(game->wall->img->width), &(game->wall->img->height));
    game->coll->img->img = mlx_xpm_file_to_image(game->frame->mlx, COLL, &(game->coll->img->width), &(game->coll->img->height));
    game->exit->img->img = mlx_xpm_file_to_image(game->frame->mlx, EXIT, &game->exit->img->width, &game->exit->img->height);
    game->floor->img->img = mlx_xpm_file_to_image(game->frame->mlx, FLOOR, &game->floor->img->width, &game->floor->img->height);
}

void put_images(t_soLong *game, void *img, int x, int y)
{
    mlx_put_image_to_window(game->frame->mlx, game->frame->win, img, (y * IMG_SIZE), (x * IMG_SIZE));    

}

void get_the_right_image(char c, t_soLong *game, int i, int j)
{
    if (c == '1')
        put_images(game, game->wall->img->img, i, j);
    if (c == '0')
        put_images(game, game->floor->img->img, i, j);
    if (c == 'E')
        put_images(game, game->exit->img->img, i, j);
    if (c == 'C')
        put_images(game, game->coll->img->img, i, j);
    if (c == 'P')
        put_images(game, game->player->img->img, i, j);
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
    //printf("JE SUIS A LA FIN -----------%s\n", game->scene[4]);
    //game
    //exit
    playing(game);
    mlx_loop(game->frame->mlx);
}