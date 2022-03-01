#include "so_long.h"

int	main(int argc, char *argv[])
{
	int 		fd;
	t_soLong 	game;

	fd = check_create(argc, argv);
	if (fd == 0)
		return (0);
	init_struct_game(&game, fd);
	verif_scene(&game);
	//freeing(game.scene);
	// Jusquici pas de Leaks
	get_background(&game);
	get_width_height(&game);
}