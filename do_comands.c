/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:04:09 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/20 15:46:30 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **args, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)	//запускаем дочерний процесс
	{
		execve(&c_exit, args, env);
		perror("Ошибка EXEC");
	}
	else if (pid < 0)
		exit(1);
	else
		wait(NULL);
	(void)args;
	(void)env;
}

void	do_comands(char **env, char **comands)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	j = 0;
	while (comands[i])
	{
		j = 0;
		args = ft_strsplit(comands[i], ' ');
		free(comands[i]);
		execute(args, env);
		while (args[j])
		{
			free(args[j]);
			j++;
		}
		i++;
	}
}
