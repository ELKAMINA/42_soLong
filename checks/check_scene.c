#include "../so_long.h"

void    count_initials(t_soLong *game)
{
  int   i;
  int   j;

  i = 0;
  while (game->scene[i])
  {
        j = 0;
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
        game->p += 1;
    if (c == '0')
        game->v += 1;
    if (c == '1')
        game->w += 1;
    if (c == 'C')
        game->c += 1;
    if (c == 'E')
        game->e += 1;
}

void check_validity(t_soLong *game)
{
    if (game->e < 1 || game->c < 1 || game->p < 1)
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