/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:39:11 by tclarita          #+#    #+#             */
/*   Updated: 2020/09/07 13:39:36 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cd_minus(char **env)
{
	char *path;

	path = old_path(env);
	chdir(path);
	free(path);
	return (env);
}

char	**no_args(char **env)
{
	char *path;

	set_old_pwd(env);
	path = get_home(env);
	chdir(path);
	free(path);
	return (env);
}

char	**too_many_args(char **env)
{
	ft_putendl("bash: cd: too many arguments");
	return (env);
}
