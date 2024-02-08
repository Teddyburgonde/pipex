/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:54:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/08 10:33:01 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parsing(char **argv, t_vars *vars)
{
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0
		|| access(argv[1], W_OK) != 0)
	{
		ft_putstr_fd("Error\nPermission denied\n", 2);
		exit(1);
	}
	if (!vars->infile || !vars->outfile)
	{
		ft_putstr_fd("Error\nOpening the expired file\n", 2);
		exit(1);
	}
}
