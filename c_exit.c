
#include "minishell.h"

char	**c_exit(char **args, char **env)
{
	write(1, "Q\n", 2);
	exit(1);
	(void)args;
	(void)env;
}
