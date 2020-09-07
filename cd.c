/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 10:50:13 by tclarita          #+#    #+#             */
/*   Updated: 2020/09/07 13:39:06 by tclarita         ###   ########.fr       */
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
	i = search_str("HOME", env);
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

char	*old_path(char **env)
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
	set_old_pwd(env);
	return (path);
}

char	**cd(char **args, char **env)
{
	char *path;

	if (!args[1])
		return (no_args(env));
	if (args[1][0] != '-' && args[1][1] != '\0')
		set_old_pwd(env);
	if (args[2])
		return (too_many_args(env));
	else
	{
		if (!ft_strcmp(args[1], "-"))
			return (cd_minus(env));
		if (args[1][0] == '~')
			path = get_home_path(args, env);
		else
			path = ft_strdup(args[1]);
	}
	if (access(path, F_OK)  && ft_strcmp(path, "~"))
		ft_printf("%s %s %s\n", "bash: cd:", path, "No such file or directory");
	else
		chdir(path);
	free(path);
	return (env);
}
