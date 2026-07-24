/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:08:38 by quill             #+#    #+#             */
/*   Updated: 2026/07/24 18:52:33 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void tidy_content(t_framework *fw)
{
    int start_map;

    start_map = find_map_start(fw);
    if (start_map == -1)
        error_message("No valid map");
    copy_map(fw, start_map);
    copy_config(fw, start_map);
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
    tidy_content(fw);
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
