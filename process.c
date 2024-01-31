/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:45:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/31 20:10:08 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	child_process(t_vars *vars)
{
	dup2(vars->pipe[1], 1);
	close(vars->pipe[0]);
}

void	parent_process(t_vars *vars)
{
	wait(NULL);
	dup2(vars->fd1[0], 0);
	close(vars->pipe[1]);
	execve(vars->arg_cmd1[0], vars->arg_cmd2, NULL);
    exit(EXIT_FAILURE);
}