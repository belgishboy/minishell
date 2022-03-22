/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:22:46 by vheymans          #+#    #+#             */
/*   Updated: 2022/03/22 16:41:26 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 * DEFINES
 */

# define MAX_PATH 1024

/*
**	LIBRARY
*/

# include "../lft/libft.h"

/*
**	INCLUDES
*/

# include <stdio.h> // readline, printf
# include <stdlib.h> // malloc, free, exit, getenv, 
# include <fcntl.h> // open
# include <unistd.h> // access, unlink, close, read, write, pipe, dup, dup2,
// execve, fork, getcwd, chdir, stat, lstat, fstat, isatty, ttyname, ttyslot,
// ioctl
# include <sys/wait.h> // waitpid, wait, wait3, wait4
# include <signal.h> // signal, sigaction, kill
# include <sys/types.h> // opendir, closedir
# include <dirent.h> // readdir
# include <stdio.h> // perror
# include <string.h> // strerror
# include <termios.h> // tcsetattr, tcgetattr
# include <curses.h> // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <readline/readline.h>
# include <readline/history.h>

/*
** MACROS
*/

# define PROMT "minishell v1.0$"
# define PIPE '|'
# define S_Q '\''
# define D_Q '\"'


/*
**	STRUCTS
*/

typedef struct s_seq	t_seq;

/*
** Main Struct
 * @param env linked t_list for enviroment
 * @param seq Seq Struct array 
 * @param n_cmds [int] nbr of pipe splits needed
 * @param input string containing the whole input from the user
*/
typedef struct s_shell
{
	t_list	*env;
	t_seq	**seq;
	int		n_cmds;
	char	*input;
} t_shell;

/*
**Sequence struct
@param seq string befor being split
@param split string array containing the splitted sequence
@param path_cmd string (for bash) exe path and cmd
@param cmd_arg argumants (for bash) for the cmd
@param fd int array contains input and output fd
@param wht_cmd [int] 0 if shell cmd, + if ours
@param nbr_arg [int] number of arguments
*/
typedef struct s_seq
{
	char	*seq;
	char	**split;
	char	*path_cmd;
	char	**cmd_args;
	int		fd[2];
	int		wht_cmd;
	int		nbr_arg;
}	t_seq;

/*
**	FUNCTIONS
*/


/*
**	MAIN
*/

int		shell(char **env);


#endif
