/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 10:50:13 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/22 17:18:57 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home(char **env)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i][0] != 'H')
		i++;
	path = ft_strnew(PATH_MAX);
	while (env[i][j + 5])
	{
		path[j] = env[i][j + 5];
		j++;
	}
	return (path);
}

char	*get_home_path(char **args, char **env)
{
	char	*path;
	int		i;
	int		j;

	path = get_home(env);
	i = ft_strlen(path);
	j = 1;
	while (args[1][j])
	{
		path[i] = args[1][j];
		i++;
		j++;
	}
	return (path);
}

char	**cd(char **args, char **env)
{
	char *path;
	if (args[2])
	{
		ft_putendl("bash: cd: too many arguments");
		return (env);
	}
	if (args[1])
	{
		if (args[1][0] == '~')
			path = get_home_path(args, env);
		else
			path = ft_strdup(args[1]);
	}
	else
		path = get_home(env);
	if (access(path, F_OK)  && ft_strcmp(path, "~"))
		ft_printf("%s %s %s\n", "bash: cd:", path, "No such file or directory");
	else
		chdir(path);
	free(path);
	return (env);
}
