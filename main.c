/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/07 11:50:24 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;
	(void)argc;
	if (pipe(vars.pipe) == -1)
		return (-1);
	vars.infile = argv[1];
	vars.outfile = argv[4];
	vars.fd_infile = open(vars.infile, O_RDONLY);
	vars.fd_outfile = open(vars.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	vars.paths = grep_path(envp);
	vars.final_path1 = find_the_accessible_path(vars.paths, argv[2]);
	vars.final_path2 = find_the_accessible_path(vars.paths, argv[3]);
	vars.pid1 = fork();
	if (vars.pid1 == -1)
		exit (1);
	if (vars.pid1 == 0)
		child_process(&vars);
	else
		parent_process(&vars);
	close(vars.pipe[0]);
	close(vars.pipe[1]);
	close(vars.fd_infile);
    close(vars.fd_outfile);
	ft_free(vars.paths);
    ft_free(vars.final_path1);
    ft_free(vars.final_path2);
}
