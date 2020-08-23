/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:51:33 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/23 17:54:26 by tclarita         ###   ########.fr       */
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
	env = (char **)malloc(sizeof(char *) * i + 1);
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
	arg[2] = ft_strnew(PATH_MAX);
	arg[3] = NULL;
	getcwd(arg[2], PATH_MAX);
	set_env(arg, env);
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
	while (status)
	{
		ft_putstr("Dota_Shell_$>");
		get_next_line(0, &line);
		comands = ft_strtok(line, ";");
		env = do_comands(env, comands);
		free(line);
		//?free comands;
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
