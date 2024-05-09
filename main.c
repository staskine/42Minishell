#include "minishell.h"

int main(void)
{
    char *rl;

	while (1)
	{
    	rl = readline("MINISHELL:) > ");
		if (!rl)
			return (-1);
    	printf("%s\n", rl);
		add_history(rl);
		free(rl);
	}
    return (0);
}
