#include "cub3d.h"

void	error_message(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	get_content(int fd, t_framework *fw)
{
	char	*line;
	char	*temp;
	char	*l_line;

	l_line = ft_strdup("");
	if(!l_line)
		error_message("Malloc failed");
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(l_line, line);
		free(l_line);
		free(line);
		if (!temp)
			error_message("Malloc failed");
		l_line = temp;
		line = get_next_line(fd);
	}
	fw->content = ft_split(l_line, '\n');
	free(l_line);
	if (!fw->content)
		error_message("Split failed");
}

void	parse_argv(int argc, char **argv, t_framework *fw)
{
	int len;
	int fd;

	if (argc != 2)
		error_message("Incorrect amount of arguments");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
		error_message("Invalid file extension. Expected .cub");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Failed to open file");
	get_content(fd, fw);
	close(fd);
}
void	parse_content(t_framework *fw)
{
	int i;
	char *config;
	char *map;
	char *temp;

	config = ft_strdup("");
	map = ft_strdup("");
	i = 0;
	/*while(fw->content[i])
	{
		if (ft_strncmp(fw->content[i], "R ", 2) == 0)
			config = fw->content[i];
		else if (ft_strncmp(fw->content[i], "NO ", 3) == 0)
			config = fw->content[i];
		else if (ft_strncmp(fw->content[i], "SO ", 3) == 0)
			config = fw->content[i];
		else if (ft_strncmp(fw->content[i], "WE ", 3) == 0)
			config = fw->content[i];
		else if (ft_strncmp(fw->content[i], "EA ", 3) == 0)
			config = fw->content[i];
		else if (ft_strncmp(fw->content[i], "F ", 2) == 0)
			config = fw->content[i];
		else if (ft_strncmp(fw->content[i], "C ", 2) == 0)
			config = fw->content[i];
		else if (ft_strlen(fw->content[i]) > 0)
			map = fw->content[i];
		i++;
	}*/

}

t_framework *parser(int argc, char **argv)
{
	t_framework	*fw;

	fw = ft_calloc(1, sizeof(t_framework));
	if (!fw)
		error_message("Memory allocation failed");
	parse_argv(argc, argv, fw);
	parse_content(fw);
	return (fw);
}

int main(int argc, char **argv)
{
	t_framework	*fw;

	fw = parser(argc, argv);
	if (!fw)
		return (0);
	return (0);
}
