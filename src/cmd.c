/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 08:30:47 by osancak           #+#    #+#             */
/*   Updated: 2025/07/24 10:57:24 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_allocs(char **split, char *ex_path, char **path)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	free(ex_path);
	free_path(path);
}

static void	fd_apply(t_vars *vars)
{
	dup2(get_pipe_in(vars), STDIN_FILENO);
	dup2(get_pipe_out(vars), STDOUT_FILENO);
}

static char	*err_cmd(char *command)
{
	int	i;

	i = -1;
	while (command[++i])
		if (command[i] == ' ')
			command[i] = '\0';
	return (command);
}

pid_t	ft_cmd(t_vars vars, char *command, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*ex_path;
	int		exec_err;

	exec_err = -1;
	pid = fork();
	if (pid == 0)
	{
		fd_apply(&vars);
		close_fd(vars);
		cmd = ft_split(command, ' ');
		ex_path = get_path(vars.path, cmd[0]);
		if (ex_path)
			exec_err = execve(ex_path, cmd, envp);
		free_allocs(cmd, ex_path, vars.path);
		if (exec_err)
			error_exit(err_cmd(command), 1);
		exit(EXIT_SUCCESS);
	}
	if (pid < 0)
		error_exit("fork", 1);
	return (pid);
}
