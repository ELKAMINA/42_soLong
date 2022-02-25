#include "minilibx/include/mlx.h"
#include "so_long.h"

// int my_key_func(int keycode, void *param)
// {
//     printf("KEY EVENT %d \n", keycode);
//     // SI on veut faire un pixel put a chaue fois que lon appuie sur une touche
// }

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

void my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
void put_images (t_data *img)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < 64)
    {
        x = 0;
        while (x < 64)
        {
            my_mlx_put_pixel(img, y, x, 0x00FF0000);
            x++;
        }
        y++;
    }
}

int main()
{
    // pointeur a envoyer en arguments pour toutes les fonctions de la minilibx
    void *mlx;
    void *win;
    t_data img;
    int   x;
    int   y;


    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "Hello World");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_put_pixel(&img, 5, 5, 0x00FF0000);
    put_images(&img);
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    // on peut avoir deux fenetres qui appellent notre mlx

    // y = 50;
    // // Pour creer un carre colore
    // while (y < 150)
    // {
    //     x = 50;
    //     while (x < 150)
    //     {
    //         mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
    //         x++;
    //     }
    //     y++;
    // }
    //Pour gerer les evenements avec le touches.
        // Evenement de type Clavier arrivera ; mlx_key_hook : prend en param le ptr vers la fenetre, une onction qui sera xecutes quand le touche sera appuyee et un void parametre
        // void*paramater => est un pointeur que lon va donner a notre fonction et quelle va nous renvoyer quand la touche et la fonction vont fire
          // Quand on va appuyer sur la touhe =la minilibx va transmettre le code de notre touche et notre parametre avec la fct : key_hook(int keycode, void param); Dns void*param on peut transmette ce que lon veut, une structure qui nous sert pour notre programme ou autre
    //mlx_key_hook(win, my_key_func, mlx);
    mlx_loop(mlx);
    // faire des dessins 
   //mlx_pixel_put(mlx, win, 400, 200, 0x00FFFFFF);
}