/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:11:39 by acarbajo          #+#    #+#             */
/*   Updated: 2025/05/22 20:53:03 by acarbajo         ###   ########.fr       */
/*                                                                       */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*until_skip(char *reminder, int fd);
char	*extract_line(char *buffer);
char	*save_trim(char *buffer);

#endif