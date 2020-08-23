/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:04:09 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/23 18:22:49 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**execute(char **args, char **env)
{
	pid_t	pid;
	int		i;
	char	*path;
	char	*path2;

	i = 0;
	while (i < 9)
	{
		if (!ft_strcmp(args[0], comands(i)))
		{
			env = execute_comand(args, env, i);
			i = 8;
			break;
		}
		i++;
	}
	if (i == 9)
	{
		pid = fork();
		if (pid == 0)	//запускаем дочерний процесс
		{
			if (execve(args[0], args, env) == -1)
			{
				path = ft_strnew(PATH_MAX);	
				int j =	search_str("PATH", env);
				int i = 0;
				while (env[j][i + 5] != ':')
				{
					path[i] = env[j][i + 5];
					i++;
				}
				path[i] = '/';
				path[i + 1] = '\0';
				path = ft_strjoin(path, args[0]);
			}
			if (execve(path, args, env) == -1)
			{
				path2 = ft_strnew(PATH_MAX);	
				int j =	search_str("PATH", env);
				int i = 0;
				while (env[j][i + 10])
				{
					path2[i] = env[j][i + 10];
					i++;
				}
				path2[i] = '/';
				path2[i + 1] = '\0';
				path2 = ft_strjoin(path2, args[0]);
				ft_putendl(path2);
			}
			if (execve(path2, args, env) == -1)
				ft_printf("%s%s\n", args[0], ": command not found");
		}
		else if (pid < 0)
			exit(1);
		else
			wait(NULL);
	}
	return (env);
}

char	**do_comands(char **env, char **comands)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	j = 0;
	while (comands[i])
	{
		j = 0;
		args = ft_strtok(comands[i], DELIM);
		if (!args[0])
			return (env);
		free(comands[i]);
		env = execute(args, env);
		while (args[j])
		{
			free(args[j]);
			j++;
		}
		i++;
	}
	return (env);
}
