/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:51:33 by tclarita          #+#    #+#             */
/*   Updated: 2020/09/07 12:35:23 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(char **envp)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	j = 0;
	while (envp[i])
		i++;
	env = (char **)malloc(sizeof(char *) * i + 100);
	while (i > j)
	{
		env[j] = ft_strdup(envp[j]);
		j++;
	}
	return (env);
}

void	set_old_pwd(char **env)
{
	char **arg;

	arg = (char **)malloc(sizeof(char *) * 4);
	arg[0] = ft_strdup("setenv");
	arg[1] = ft_strdup("OLDPWD");
	arg[2] = NULL;
	arg[3] = NULL;
	arg[2] = getcwd(arg[2], PATH_MAX);
	set_env(arg, env);
	free(arg[0]);
	free(arg[1]);
	free(arg[2]);
	free(arg[3]);
	free(arg);
	return ;
}

void	loop(char **env)
{
	int status;
	char *line;
	char **comands;

	status = TRUE;
	// int i = 0;
	while (status)
	{
		ft_putstr("Dota_Shell_$>");
		get_next_line(0, &line);
		// if (i == 0)
		// 	line = ft_strdup("foo");
		// if (i == 1)
		// 	line = ft_strdup("/bin/ls");
		// if (i == 2)
		// 	line = ft_strdup("/bin/ls -laF");
		// if (i == 3)
		// 	line = ft_strdup("/bin/ls -l -a -F");
		// if (i == 4)
		// 	line = ft_strdup("echo 'It works!'");
		// if (i == 5)
		// 	line = ft_strdup("cd ../../");
		// if (i == 6)
		// 	line = ft_strdup("cd Desktop");
		// if (i == 7)
		// 	line = ft_strdup("cd");
		// if (i == 8)
		// 	line = ft_strdup("cd -");
		// if (i == 9)
		// 	line = ft_strdup("cd ~/Desktop/minishell/printf");
		// if (i == 10)
		// 	line = ft_strdup("env");
		// if (i == 11)
		// 	line = ft_strdup("setenv FOO bar");
		// if (i == 12)
		// 	line = ft_strdup("/usr/bin/env");
		// if (i == 13)
		// 	line = ft_strdup("unsetenv FOO");
		// if (i == 14)
		// 	line = ft_strdup("env");
		// if (i == 15)
		// 	line = ft_strdup("unsetenv FOO");
		// if (i == 16)
		// 	line = ft_strdup("/usr/bin/env");
		// if (i == 17)
		// 	line = ft_strdup("             ");
		// if (i == 18)
		// 	line = ft_strdup("				");
		// if (i == 19)
		// 	line = ft_strdup("exit");
		// i++;
		comands = ft_strsplit(line, ';');
		free(line);
		env = do_comands(env, comands);
		int j = 0;
		while (comands[j])
		{
			free(comands[j]);
			j++;
		}
		free(comands);
	}
}

int		main(int ac, char **av, char *envp[])
{
	char	**env;

	if (ac == 1)
	{
		env = get_env(envp);
		loop(env);
		return (0);
	}
	ft_putstr(av[1]);
	return(1);
}
