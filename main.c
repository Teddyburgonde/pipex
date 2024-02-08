/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:03:00 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/08 11:24:57 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_vars *vars, char **argv)
{
	vars->infile = argv[1];
	vars->outfile = argv[4];
	vars->fd_infile = open(vars->infile, O_RDONLY);
	vars->fd_outfile = open(vars->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->fd_infile == -1 || vars->fd_outfile == -1)
	{
		perror("Error opening files");
		exit(1);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;
	if (!envp || !envp[0])
		exit(1);
	if (argc != 5)
	{
		ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	if (pipe(vars.pipe) == -1)
		return (-1);
	open_files(&vars, argv);
	ft_parsing(argv, &vars);
	vars.paths = grep_path(envp);
	if (vars.paths == NULL)
	{
		ft_free(vars.paths);
		exit(1);
	}
	vars.final_path1 = find_the_accessible_path(vars.paths, argv[2]);
	vars.final_path2 = find_the_accessible_path(vars.paths, argv[3]);
	if (vars.final_path1 == NULL || vars.final_path2 == NULL)
		exit(1);
	execute_child_parent_processes(&vars, envp);
	ft_full_free(&vars);
}
