/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:47:49 by tclarita          #+#    #+#             */
/*   Updated: 2020/09/07 13:48:29 by tclarita         ###   ########.fr       */
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
