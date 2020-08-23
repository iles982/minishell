/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:22:59 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/23 15:50:10 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	comand[6] = "setenv"; //повтор
	comand[7] = "pwd";
	comand[8] = "PATH";
	return (comand[i]);
}

char	**execute_comand(char **args, char **env, int i)
{
	if (i == 0)
		return (set_env(args, env));
	if (i == 1)
		return (print_env(env));
	if (i == 2)
		return (unset_env(args, env));
	if (i == 3)
		return (cd(args, env));
	if (i == 5)
		return (echo(args, env));
	if (i == 7)
		return (pwd(args, env));
	if (i == 4)
	{
		//чистим все
		exit(1);
	}
	else
		return (env);
}
