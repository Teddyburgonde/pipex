/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:54:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/06 21:02:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parsing(int argc, char **argv, t_vars *vars)
{
	if (argc != 5)
		ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile", 2);
	if (!vars->infile || !vars->outfile)
		ft_putstr_fd("Error\nOpening the expired file", 2);
	if (access(argv[1], X_OK) == -1)
		ft_putstr_fd("Error\nYou don't have access", 2);
}
