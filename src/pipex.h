/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:40:48 by osancak           #+#    #+#             */
/*   Updated: 2025/07/22 13:51:27 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef MAX_PIPE
#  define MAX_PIPE 512
# endif

typedef struct s_vars
{
	int		infile;
	int		outfile;
	int		curr_pipe[2];
	int		last_read;
	char	**path;
	pid_t	cmds[MAX_PIPE];
	int		cmd_count;
	int		cmd_index;
}			t_vars;

int			check_args(char **argv);
void		error_exit(const char *msg, int exit_code);
void		set_path(t_vars *vars, char **envp);
char		*get_path(char **path, char *command);
void		free_path(char **path);
void		init_vars(t_vars *vars, char *input_file, char *output_file);
void		close_fd(t_vars vars);
pid_t		ft_cmd(t_vars vars, char *command, char **envp);
void		setup_pipe(t_vars *vars);
int			get_pipe_in(t_vars *vars);
int			get_pipe_out(t_vars *vars);
void		clean_pipe(t_vars *vars);
pid_t		ft_heredot(char *limiter);

#endif
