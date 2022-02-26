#include "so_long.h"

int	main(int argc, char *argv[])
{
	int 		fd;
	t_soLong 	game;
	t_frame		frametest;

	game.frame = &frametest;
	fd = check_create(argc, argv);
	if (fd == 0)
		return (0);
	// init structs
	init_struct_game(&game, fd);
	init_struct_frame(&game);

	// Load game
	verif_scene(&game);
	get_background(&game);
	get_width_height(&game);


	//freeing(game.scene);
	//FREE FRAME AND IMAGE !!!!!!;
}
