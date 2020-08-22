#include "minishell.h"

//!made to test how functions work
//!made to test how functions work
//!made to test how functions work
//!made to test how functions work
//!made to test how functions work

int	main(int ac, char **args, char **envp)
{
	char **env = envp;
	pid_t pid;
	int i;

	pid = fork();
	if (pid == 0)
	{
		execve(args[1], args, env);
	}
	else if (pid < 0)
	{
		ft_putendl("Pid < 0");
		exit(1);
	}
	else
		wait(NULL);
}
