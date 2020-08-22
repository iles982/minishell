/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 10:39:22 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/22 14:54:54 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**echo(char **args, char **env)
{
	int i;

	i = 1;
	while (args[i])
	{
		if (args[i][0] == '~' && !args[i][1])
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
