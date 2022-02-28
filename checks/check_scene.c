#include "../so_long.h"

void    verif_scene(t_soLong *game)
{
    count_initials(game);
}

void    count_initials(t_soLong *game)
{
  int   i;
  int   j;

  i = 0;
  while (game->scene[i])
  {
        j = 0;
        printf("string = %s i = %d\n", game->scene[i], i);
        while (game->scene[i][j])
        {
            increment(game, game->scene[i][j]);
            j++;
        }
        i++;
  }
    check_validity(game);
    check_walls(game);
}

void increment(t_soLong *game, char c)
{
    if (c == 'P')
        game->player->total_nb += 1;
    if (c == '0')
        game->floor->total_nb += 1;
    if (c == '1')
        game->wall->total_nb += 1;
    if (c == 'C')
        game->coll->total_nb += 1;
    if (c == 'E')
        game->exit->total_nb += 1;
}

void check_validity(t_soLong *game)
{
    if (game->exit->total_nb < 1 || game->coll->total_nb < 1 || game->player->total_nb < 1)
    {
        write(1, "Error\n", 7);
        write(1, "At least 1 item, 1 collectible, 1 exit\n", 40);
        freeing(game->scene);
        exit(0);
        return ;
    }
    
}

void    check_walls(t_soLong *game)
{
    check_square(game);
    check_fence(game);
}