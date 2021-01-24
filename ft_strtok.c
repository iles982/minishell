/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:48:56 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/24 17:19:47 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_strtok(char *str, int i2, int i, char **tab)
{
	int i3;

	i3 = 0;
	tab[i2] = (char *)malloc(sizeof(char) * 1024);
	while (str[i] > 32)
	{
		tab[i2][i3] = str[i];
		i++;
		i3++;
	}
	tab[i2][i3] = '\0';
	return (tab);
}

char		**ft_strtok(char *str)
{
	int		i;
	int		i2;
	int		i3;
	char	**tab;

	i = 0;
	i2 = 0;
	tab = (char**)malloc(sizeof(char *) * 1024);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			tab = get_strtok(str, i2, i, tab);
			while (str[i] > 32)
				i++;
			i2++;
		}
		else
			i++;
	}
	tab[i2] = 0;
	return (tab);
}
