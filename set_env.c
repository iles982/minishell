/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:17:58 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/20 12:57:29 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**one_arg(char **args, char **env)
{
	// int		i;
	// int		j;
	// char	**arg;

	(void)args;
	(void)env;
	return (args);
}

char	**set_env(char **args, char **env)
{
	if (!args[1])
		return (env);
	if (!args[2])
		return (one_arg(args, env));
	return (args);
}