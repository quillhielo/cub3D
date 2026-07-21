/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:16:55 by acarbajo          #+#    #+#             */
/*   Updated: 2025/08/12 14:25:57 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*save_trim(char *buffer)
{
	char	*trim;
	int		i;
	int		j;
	
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	trim = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		trim[j++] = buffer[i++];
	free(buffer);
	return (trim);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;
	
	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));//linea reservada null con espacio para salto o eol
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*until_skip(char *reminder, int fd)
{
	char	*buffer;
	char	*temp;
	int		byte_count;
	
	if (!reminder)//si todavía no existe reminder, la inicializamos en 0/
		reminder = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	byte_count = 1;
	while (byte_count > 0)
	{
		if (ft_strchr(reminder, '\n'))
			break ;
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count == -1)
			return (free(buffer), NULL);
		buffer[byte_count] = '\0';//finalizamos correctamente//
		temp = ft_strjoin(reminder, buffer);
		free (reminder);
		reminder = temp;
	}
	free(buffer);
	return (reminder);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)//comprobacion de errores//
		return (NULL);
	buffer = until_skip(buffer, fd);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = save_trim(buffer);
	return (line);
}
