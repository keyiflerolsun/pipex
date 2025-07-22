/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:44:31 by osancak           #+#    #+#             */
/*   Updated: 2025/07/22 13:53:02 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run_prog(t_vars *vars, char **cmds, char **envp)
{
	int	i;
	int	exit_status;

	i = -1;
	while (++i <= vars->cmd_count)
	{
		vars->cmd_index = i;
		setup_pipe(vars);
		vars->cmds[i] = ft_cmd(*vars, cmds[i], envp);
		clean_pipe(vars);
	}
	close_fd(*vars);
	free_path(vars->path);
	i = -1;
	while (++i <= vars->cmd_count)
	{
		waitpid(vars->cmds[i], &exit_status, 0);
		if (WEXITSTATUS(exit_status) != 0)
			exit(WEXITSTATUS(exit_status));
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc < 5 || !check_args(argv))
		error_exit("Usage : ./pipex infile cmd1 cmd2 outfile", 0);
	if (ft_strstr(argv[1], "here_doc"))
		waitpid(ft_heredot(argv[2]), NULL, 0);
	init_vars(&vars, argv[1], argv[argc - 1]);
	set_path(&vars, envp);
	if (!vars.path)
		error_exit("PATH environment variable not found or invalid", 0);
	if (!ft_strstr(argv[1], "here_doc"))
	{
		vars.cmd_count = argc - 4;
		run_prog(&vars, argv + 2, envp);
	}
	else
	{
		vars.cmd_count = argc - 5;
		run_prog(&vars, argv + 3, envp);
		unlink("here_doc");
	}
	return (EXIT_SUCCESS);
}
