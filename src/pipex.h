/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:40:48 by osancak           #+#    #+#             */
/*   Updated: 2025/07/21 17:11:16 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef MAX_PIPE
#  define MAX_PIPE 512
# endif

typedef struct s_fd
{
	int		in_f;
	int		out_f;
	int		pipe[2];
	char	**path;
	pid_t	cmds[MAX_PIPE];
}			t_fd;

void		error_exit(const char *msg, int errno);
void		set_path(t_fd *fd, char **envp);
char		*get_path(char **path, char *command);
void		free_path(char **path);
void		init_fd(t_fd *fd, char *input_file, char *output_file);
void		close_fd(t_fd fd);
pid_t		ft_cmd(t_fd fd, char *command, char **envp, int cmd_index);

#endif
