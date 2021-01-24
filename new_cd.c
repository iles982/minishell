/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:03:56 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/24 18:24:20 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*home_path(char *path, char **env)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = search_str("HOME", env);
	path = ft_strnew(1024);
	while (env[i][j + 5])
	{
		path[k] = env[i][j + 5];
		k++;
		j++;
	}
	path[k] = '\0';
	return (path);
}

char	*get_old_path(char **env)
{
	int		i;
	char	*path;
	int		j;

	i = search_str("OLDPWD", env);
	path = ft_strnew(PATH_MAX);
	j = 0;
	while (env[i][j + 7])
	{
		path[j] = env[i][j + 7];
		j++;
	}
	ft_putendl(path);
	return (path);
}

char	*tilda_path(char **args, char **env)
{
	char	*path;
	int		i;
	int		j;

	path = home_path(path, env);
	i = ft_strlen(path);
	j = 1;
	while (args[1][j])
	{
		path[i] = args[1][j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

char	*get_path(char **args, char **env)
{
	char	*path;

	if (!args[1])
		path = home_path(path, env);
	else if (!ft_strcmp(args[1], "-"))
		path = get_old_path(env);
	else if (args[1][0] == '~')
		path = tilda_path(args, env);
	else
		path = ft_strdup(args[1]);
	set_old_pwd(env);
	return (path);
}

char	**new_cd(char **args, char **env)
{
	char	*path;

	if (args[2])
	{
		ft_putendl("bash: cd: too many arguments");
		return (env);
	}
	path = get_path(args, env);
	if (access(path, R_OK))
	{
		write(1, "\e[38;5;97m", 10);
		ft_printf("cd: permission denied: %s\n", path);
		free(path);
		return (env);
	}
	if (access(path, F_OK) && ft_strcmp(path, "~"))
		ft_printf("%s %s %s\n", "bash: cd:", path, "No such file or directory");
	chdir(path);
	free(path);
	return (env);
}
