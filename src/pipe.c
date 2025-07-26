/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:38:23 by osancak           #+#    #+#             */
/*   Updated: 2025/07/24 11:05:58 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_pipe(t_vars *vars)
{
	if (vars->cmd_index != vars->cmd_count)
		if (pipe(vars->curr_pipe) == -1)
			error_exit("pipe", 1);
}

int	get_pipe_in(t_vars *vars)
{
	return (vars->last_read);
}

int	get_pipe_out(t_vars *vars)
{
	if (vars->cmd_index == vars->cmd_count)
		return (vars->outfile);
	return (vars->curr_pipe[1]);
}

void	clean_pipe(t_vars *vars)
{
	close(vars->last_read);
	close(vars->curr_pipe[1]);
	vars->last_read = vars->curr_pipe[0];
}
