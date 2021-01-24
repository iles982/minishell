/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:51:33 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/23 22:04:38 by tclarita         ###   ########.fr       */
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
	arg[2] = getcwd(arg[2], 1024);
	set_env(arg, env);
	free(arg[0]);
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

void	loop(char **env)
{
	int		status;
	char	*line;
	char	**comands;
	int		j;

	status = TRUE;
	while (status)
	{
		j = 0;
		write(1, "\e[38;5;196m", 11);
		ft_putstr("Dota_Shell_$>");
		write(1, "\e[38;5;69m", 10);
		get_next_line(0, &line);
		comands = ft_strsplit(line, ';');
		free(line);
		env = do_comands(env, comands);
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

	env = get_env(envp);
	if (ac == 1)
	{
		loop(env);
		return (0);
	}
	ft_putstr("Wrong format input\n");
	return (1);
}
