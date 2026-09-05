/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:38:49 by quill             #+#    #+#             */
/*   Updated: 2026/09/01 11:13:34 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_framework	*parser(int argc, char **argv)
{
	t_framework	*fw;

	fw = ft_calloc(1, sizeof(t_framework));
	if (!fw)
		error_message("Memory allocation failed", 0);
	load_file(argc, argv, fw);
	return (fw);
}

int	main(int argc, char **argv)
{
	t_framework	*fw;

	fw = parser(argc, argv);
	if (!fw)
		return (0);
	return (0);
}
