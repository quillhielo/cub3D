#include "cub3d.h"

t_framework *parser(int argc, char **argv)
{
	t_framework	*fw;

	fw = ft_calloc(1, sizeof(t_framework));
	if (!fw)
		error_message("Memory allocation failed");
	load_file(argc, argv, fw);
	return (fw);
}

int main(int argc, char **argv)
{
	t_framework	*fw;

	fw = parser(argc, argv);
	if (!fw)
		return (0);
	if (init_exec(fw) != 0)
		return (1);
	return (0);
}
