/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:51:47 by tclarita          #+#    #+#             */
/*   Updated: 2020/08/20 12:18:36 by tclarita         ###   ########.fr       */
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
# include <sys/io.h>
# include <sys/wait.h>

# define TRUE 1
# define PATH_MAX 4096

void    do_comands(char **env, char **comands);
char	**c_exit(char **args, char **env);
char    **set_env(char **arg, char **env);

#endif
