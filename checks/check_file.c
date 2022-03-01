#include "../so_long.h"

int	check_file(char *argv)
{
	int				fd;
	
	fd = open(argv, O_RDWR);
	if (fd == -1)
	{
		write(1, "Error\n", 7);
		write(1, "Error - Directory not File\n", 28);
		return (0);
	}
	else
		return (fd);
}

int	double_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\n')
		i++;
	while (s[i] && s[i + 1])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	**get_stage(int fd)
{
	char			*buf;
	char			**map;
	static	char	*final;

	buf = get_next_line(fd);
	while (buf)
	{
		final = ft_strjoin(final, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	if	(double_newline(final) == 1)
	{
		write(1, "Error\n", 7);
        write(1, "Invalid map\n", 13);
        free(final);
		exit(0);
	}
	else
	{
		map = ft_split(final, '\n');
		free(final);
		close(fd);
	}
	return (map);
}


