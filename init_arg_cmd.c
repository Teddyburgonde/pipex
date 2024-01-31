/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:41 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/31 15:45:20 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen_mod(char *str)
{
	int	i;
	int	save;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32)
			break ;
		i++;
	}
	i++;
	save = i;
	while (str[save])
		save++;
	save = save - i;
	return (save);
}

static int	search_espace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32)
			return (i);
		i++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	init_arg_cmd1(t_vars *vars, char **argv)
{
	int	size;

	vars->arg_cmd1 = malloc(sizeof(char *) * 3);
	if (!vars->arg_cmd1)
		exit(1);
	size = ft_strlen_mod(argv[2]);
	vars->arg_cmd1[0] = NULL;
	if (argv[2] && search_espace(argv[2]) == 0)
		vars->arg_cmd1[1] = NULL;
	else if (argv[2])
	{
		vars->arg_cmd1[1] = malloc(size + 1);
		if (!vars->arg_cmd1[1])
			exit(1);
		ft_strncpy(vars->arg_cmd1[1], &argv[2][search_espace(argv[2]) + 1],
			size + 1);
		vars->arg_cmd1[1][size] = '\0';
	}
	vars->arg_cmd1[2] = NULL; //liberer la memoire
}

void	init_arg_cmd2(t_vars *vars, char **argv)
{
	int	size;

	vars->arg_cmd2 = malloc(sizeof(char *) * 3);
	if (!vars->arg_cmd2)
		exit(1);
	size = ft_strlen_mod(argv[3]);
	vars->arg_cmd2[0] = NULL;
	if (argv[3] && search_espace(argv[3]) == 0)
		vars->arg_cmd2[1] = NULL;
	else if (argv[3])
	{
		vars->arg_cmd2[1] = malloc(size + 1);
		if (!vars->arg_cmd2[1])
			exit(1);
		ft_strncpy(vars->arg_cmd2[1], &argv[3][search_espace(argv[3]) + 1],
			size + 1);
		vars->arg_cmd2[1][size] = '\0';
		ft_printf("%s\n", vars->arg_cmd2[1]);
	}
	vars->arg_cmd2[2] = NULL; // liberer la memoire
}
