/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:02:50 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/25 10:04:13 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**pwd(char **args, char **env)
{
	char *path;

	path = ft_strnew(PATH_MAX);
	getcwd(path, PATH_MAX);
	ft_putendl(path);
	free(path);
	(void)args;
	(void)env;
	return (env);
}
