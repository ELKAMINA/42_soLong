#include "./so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


int main()
{
	void	*mlx;
	void	*win;
	char	*relative_path = "images/wall.xpm";
	int		img_width;
	int		img_height;
	t_data img;
	void	*mlx2;
	void	*win2;
	char	*relative_path2 = "images/player.xpm";
	int		img_width2;
	int		img_height2;
	t_data img2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img2.img = mlx_xpm_file_to_image(mlx, relative_path2, &img_width2, &img_height2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
								&img2.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    // my_mlx_pixel_put(&img, 15, 15, 0x00FFFF00);
    // my_mlx_pixel_put(&img, 25, 25, 0x00FF0FF00);
    // my_mlx_pixel_put(&img, 45, 45, 0x00FF0FF00);
    // my_mlx_pixel_put(&img, 145, 145, 0x00FF0FF00);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2.img, 10, 20);
	mlx_loop(mlx);
}