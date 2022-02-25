#include "../so_long.h"

void my_mlx_put_pixel(t_img_data *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void square (t_img_data *img, int i, int j)
{
    int x;
    int n_i;
    //int n_j;
    int y;

    x = 0;
    y = 0;
    n_i = i;
    //n_j = j;
    // printf("Test1");
    while (y < 64)
    {
        x = 0;
        i = n_i;
        while (x < 64)
        {
            my_mlx_put_pixel(img, i, j, 0x00FF0000);
            i++;
            x++;
        }
        y++;
        j++;
    }
}

void    get_colored_square(t_frame *frame, t_soLong *game)
{
    t_img_data img;
    int i;
    int j;

    i = 0;
    //printf("Test");
    init_struct_imgData(&img);
    img.img = mlx_new_image(frame->mlx, frame->win_w, frame->win_h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // mi_mlx_put_pixel(&img, 5, 5, 0x00FF0000);
    //img.img = mlx_xpm_file_to_image(frame->mlx, img.rpath, img.img_width, img.img_height);
    while (game->scene[i])
    {
        j = 0;
        while (game->scene[i][j])
        {
            square(&img, (j * 64), (i * 64));
            j++;
        }
        i++;
    }
    //game
    //exit
    mlx_put_image_to_window(frame->mlx, frame->win, img.img, 0, 0);
    mlx_loop(frame->mlx);
}