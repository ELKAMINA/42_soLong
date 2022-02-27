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

// void get_pos(t_soLong *game)
// {
//     int i;
//     int j;

//     i = 0;
//     while (game->scene[i][j])
//     {
//         j = 0;
//         while (game->scene[i][j])
//         {
//             if (game->scene[i][j] == 'P')
//             {
//                 game->thing->pos_x = j;
//                 game->thing->pos_y = i;
//             }
//             j++;
//         }
//         i++;
//     }
// }


// void moving_forward(t_soLong *game)
// {
//     init_struct_pos(game);
//     get_pos(game);
//     printf("%d\n", game->thing->pos_x);
// }


int	keypress(int keycode, t_soLong *game)
{
    printf("KEYCODE = %d\n", keycode);
    if (keycode == ESC)
        quit_game(game);
    // if (keycode == RIGHT)
    //     moving_forward(game);
    else
    {
        write(1, "NOOOOOOTHINGS HAPPENING\n", 25);
        return (0);
    }
    return (1);
}

void playing(t_soLong *game)
{
    mlx_hook(game->frame->win, 2, 1L<<0, keypress, &game);
}