/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:51:47 by tclarita          #+#    #+#             */
/*   Updated: 2021/01/24 17:07:45 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "printf/ft_printf.h"
# include <errno.h>
# include <limits.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdint.h>
# include <sys/wait.h>
# define TRUE 1
# define DELIM " \t\n\r\a\""
# define PATH_MAX1 2048

char	**ft_strtok(char *str);
char	**do_comands(char **env, char **comands);
char	**c_exit(char **args, char **env);
char	**echo(char **args, char **env);
char	**set_env(char **arg, char **env);
char	**cd(char **args, char **env);
int		search_str(char *first, char **env);
void	set_old_pwd(char **env);
char	**unset_env(char **args, char **env);

char	**cd_minus(char **env);
char	**no_args(char **env);
char	*old_path(char **env);
char	**too_many_args(char **env);
int		find_str(char **args, char *str);
int		try_paths(char **args, char **env, int i);
char	**fill_file(char **args, char **env, int a);
char	**get_comand2(char **args, int a);
char	**do_pipe(char **args, char **env, int a);
char	**create_file(char **args, char **env, int a);

char	*get_home(char **env);
char	*join_arg(char *second, char *first);
void	free_str2(char **str);
char	**print_env(char **env);
char	*comands(int i);
char	**execute_comand(char **args, char **env, int i, char **comands);
char	**new_cd(char **args, char **env);

#endif
