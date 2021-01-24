/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 10:39:22 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/13 16:24:22 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_env(char **args, char **env)
{
	int		i;
	int		k;
	char	*name;

	name = args[1] + 1;
	i = search_str(name, env);
	k = 0;
	if (env[i])
	{
		while (env[i][k] != '=')
			k++;
		k++;
		while (env[i][k])
		{
			ft_putchar(env[i][k]);
			k++;
		}
	}
}

char	**echo(char **args, char **env)
{
	int i;

	i = 1;
	while (args[i])
	{
		if (args[i][0] == '$')
			echo_env(args, env);
		else if (args[i][0] == '~' && !args[i][1])
			ft_putstr(get_home(env));
		else
			ft_putstr(args[i]);
		i++;
		if (args[i])
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (env);
}
