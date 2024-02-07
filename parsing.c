/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:54:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/07 16:13:53 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parsing(int argc, char **argv, t_vars *vars)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile", 2);
		exit(1);
	}
	else if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0
		|| access(argv[1], W_OK) != 0)
	{
		ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile", 2);
		exit(1);
	}
	else if (!vars->infile || !vars->outfile)
	{
		ft_putstr_fd("Error\nOpening the expired file", 2);
		exit(1);
	}
}