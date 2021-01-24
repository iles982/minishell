/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:03:15 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/06 17:31:08 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_comand(char **args, int a)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * a + 1);
	while (i < a)
	{
		res[i] = args[i];
		i++;
	}
	return (res);
}

char	**create_file(char **args, char **env, int a)
{
	int		file;
	int		pid;
	int		i;
	char	**comand1;

	file = open(args[a + 1], O_WRONLY | O_CREAT, 0777);
	pid = fork();
	comand1 = get_comand(args, a);
	if (pid == 0)
	{
		dup2(file, STDOUT_FILENO);
		i = 5;
		while (i != -1)
			i = try_paths(comand1, env, i);
		exit(0);
	}
	close(file);
	free(comand1);
	waitpid(pid, NULL, 0);
	return (env);
}

char	**fill_file(char **args, char **env, int a)
{
	int		file;
	int		i;
	int		pid;
	char	**comand1;

	file = open(args[a + 1], O_WRONLY | O_APPEND, 0777);
	pid = fork();
	comand1 = get_comand(args, a);
	if (pid == 0)
	{
		dup2(file, STDOUT_FILENO);
		i = 5;
		while (i != -1)
			i = try_paths(comand1, env, i);
		exit(0);
	}
	free(comand1);
	close(file);
	waitpid(pid, NULL, 0);
	return (env);
}
