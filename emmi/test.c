#include "../minishell.h"

void	free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

int	main(int argc, char **argv)
{
	char	**split;
	int	index;
	int	i;

	index = 1;
	while (argv[index])
	{
		i = 0;
		split = parser(argv[index]);
		while (split[i])
		{
			printf("split[%d] = %s\n", i, split[i]);
			i++;
		}
		free_array(split);
		index++;
	}
	return (0);
}