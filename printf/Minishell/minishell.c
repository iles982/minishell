/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 10:47:10 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/17 11:46:36 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(char **envp)
{
	char	**env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envp[i])
		i++;
	env = (char **)malloc(sizeof(char *) * i + 1);
	while (j < i)
	{
		env[j] = ft_strdup(envp[j]);
		ft_printf("%s\n", env[j]);
		j++;
	}
	return (env);
}

char	*get_shell_line(void)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

void    loop(char **env)
{
    int		status;
    char	*line;
	char	**comands;

	status = TRUE;
	while (status)
	{
		ft_putstr("Dota_Shell_$>");
		line = get_shell_line();
		comands = ft_strsplit(line, ';');
		// status = execute(comands, env);
		free(line);
		//?очистить всю выделенную память под команды
	}
}

int		main(int ac, char **av, char *envp[])
{
	char	**env;

	env = get_env(envp);
	loop(env);
	return (0);
}
