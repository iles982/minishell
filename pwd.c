/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 11:02:50 by tclarita          #+#    #+#             */
/*   Updated: 2020/09/06 16:35:02 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**pwd(char **args, char **env)
{
	char *line;

	line = NULL;
	line = getcwd(line, PATH_MAX);
	ft_putendl(line);
	free(line);
	(void)args;
	(void)env;
	return (env);
}
