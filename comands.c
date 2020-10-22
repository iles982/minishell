/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:22:59 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/22 10:47:37 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_exit(char **args, char **env, char **comands)
{
	int i;

	i = 0;
	while (comands[i])
	{
		free(comands[i]);
		i++;
	}
	free(comands);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	exit(0);
}

char	**print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
	return (env);
}

char	*comands(int i)
{
	char	*comand[9];

	comand[0] = "setenv";
	comand[1] = "env";
	comand[2] = "unsetenv";
	comand[3] = "cd";
	comand[4] = "exit";
	comand[5] = "echo";
	comand[6] = "setenv";
	comand[7] = "pwd";
	return (comand[i]);
}

char	**execute_comand(char **args, char **env, int i, char **comands)
{
	if (i == 0)
		return (set_env(args, env));
	if (i == 1)
		return (print_env(env));
	if (i == 2)
		return (unset_env(args, env));
	if (i == 3)
		return (cd(args, env));
	if (i == 4)
	{
		my_exit(args, env, comands);
		return (env);
	}
	if (i == 5)
		return (echo(args, env));
	if (i == 7)
		return (pwd(args, env));
	else
		return (env);
}
