/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:04:09 by tclarita          #+#    #+#             */
/*   Updated: 2020/09/07 12:34:03 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_arg(char *second, char *first)
{
	char	*str;
	int		i;

	i = ft_strlen(first);
	first[i] = '/';
	first[i + 1] = '\0';
	str = ft_strjoin(first, second);
	free(first);
	return (str);
}

int		find_path(char **args, char **env, int i)
{
	char	*path;
	int		j;
	int		k;

	j = search_str("PATH", env);
	if (env[j][i] == '\0')
		return (-1);
	if (!env[j])
		return (-1);
	path = ft_strnew(PATH_MAX);
	k = 0;
	while (env[j][i] != ':' && env[j][i])
	{
		path[k] = env[j][i];
		k++;
		i++;
	}
	path = join_arg(args[0], path);
	if (execve(path, args, env) == -1)
	{
		free(path);
		return (i + 1);
	}
	free(path);
	return (-1);
}

int		try_paths(char **args, char **env, int i)
{
	if (execve(args[0], args, env) == -1)
		return(find_path(args, env, i));
	else
		return (-1);
}

char	**do_fork(char **args, char **env, int i)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)	//запускаем дочерний процесс
	{
		i = 5;
		while (i != -1)
			i = try_paths(args, env, i);
	}
	else if (pid < 0)
		exit(1);
	else
		wait(NULL);
	return (env);
}

char	**execute(char **args, char **env, char **comand)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (!ft_strcmp(args[0], comands(i)))
		{
			env = execute_comand(args, env, i, comand);
			i = 8;
			break;
		}
		i++;
	}
	if (i == 9)
	{
		i = 5;
		env = do_fork(args, env, i);
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
		args = ft_strtok(comands[i], DELIM);
		if (!args[0])
		{
			j = 0;
			while (args[j])
			{
				free(args[j]);
				j++;
			}
			free(args);
			return (env);
		}
		env = execute(args, env, comands);
		j = 0;
		while (args[j])
		{
			free(args[j]);
			j++;
		}
		free(args);
		i++;
	}
	return (env);
}
