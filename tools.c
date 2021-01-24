/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:47:49 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/24 18:32:09 by tclarita         ###   ########.fr       */
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

void	free_str2(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int		find_str(char **args, char *str)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], str))
			return (i);
		i++;
	}
	return (-1);
}

char	*get_home(char **env)
{
	char	*path;
	int		i;
	int		j;
	int		k;

	i = 0;
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
	path[j] = '\0';
	return (path);
}
