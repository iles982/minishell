/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:22:59 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/22 16:58:43 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (i == 3)
		return (cd(args, env));
	if (i == 7)
		return (pwd(args, env));
	if (i == 5)
		return (echo(args, env));
	if (i == 4)
	{
		//чистим все
		exit(1);
	}
	else
		return (set_env(args, env));
}
