/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:17:58 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/24 16:45:13 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_mystr(char *first, char *second, char c)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = ft_strlen(first);
	j = ft_strlen(second);
	str = ft_strnew(i + j + 1);
	k = 0;
	while (k < i)
	{
		str[k] = first[k];
		k++;
	}
	str[k] = c;
	i = 0;
	k++;
	while (i < j)
	{
		str[k] = second[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

int		search_str(char *first, char **env)
{
	int i;
	int j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (first[j] && env[i][j] != '=' && (first[j] == env[i][j]))
		{
			if (first[j] == env[i][j])
				j++;
			if (first[j] == '\0' && env[i][j] == '=')
				return (i);
		}
		i++;
	}
	return (i);
}

char	**set_env(char **args, char **env)
{
	int		i;
	char	*str;

	if (!args[1] || !args[2] || args[3])
		return (env);
	i = search_str(args[1], env);
	if (env[i])
	{
		str = ft_mystr(args[1], args[2], '=');
		free(env[i]);
		env[i] = ft_strdup(str);
		free(str);
	}
	else
	{
		str = ft_mystr(args[1], args[2], '=');
		env[i] = ft_strdup(str);
		free(str);
		env[i + 1] = NULL;
	}
	return (env);
}
