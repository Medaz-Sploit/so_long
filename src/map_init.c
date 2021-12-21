#include "../include/so_long.h"

void	read_file(t_so_long *so_long, char *line)
{
	read_map(so_long, line);	
}
void	map_init(t_so_long *so_long, char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		printf("Error: %s\n", strerror(errno));
	while (get_next_line(fd, &line))
	{
		read_file(so_long, line);
		line = NULL;
		free(line);
	}
	
	read_file(so_long, line);
	line = NULL;
	close(fd);
	read_texture(so_long)
	free(line);
}
