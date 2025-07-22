/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 08:30:47 by osancak           #+#    #+#             */
/*   Updated: 2025/07/22 08:11:55 by osancak          ###   ########.fr       */
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
	int	input;
	int	output;

	input = get_pipe_in(vars);
	output = get_pipe_out(vars);
	dup2(input, STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
}

pid_t	ft_cmd(t_vars vars, char *command, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*ex_path;
	int		exec;

	pid = fork();
	if (pid == 0)
	{
		fd_apply(&vars);
		close_fd(vars);
		cmd = ft_split(command, ' ');
		ex_path = get_path(vars.path, cmd[0]);
		if (ex_path)
			exec = execve(ex_path, cmd, envp);
		else
			exec = -1;
		free_allocs(cmd, ex_path, vars.path);
		if (exec == -1)
			error_exit("execve", 1);
		exit(EXIT_SUCCESS);
	}
	if (pid < 0)
		error_exit("fork", 1);
	return (pid);
}
