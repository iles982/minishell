/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:59:15 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/23 15:01:28 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**new_env(char **args, char **env, int minus)
{
	int		i;
	int		j;
	char	**env2;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	env2 = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (env[j])
	{
		if (j != minus)
		{
			env2[i] = ft_strdup(env[j]);
			i++;
		}
		j++;
	}
	return (env2);
	(void)args;
}

char	**unset_env(char **args, char **env)
{
	int		i;

	i = search_str(args[1], env);
	if (!env[i] || args[2])
		return (env);
	env = new_env(args, env, i);
	return (env);
}
