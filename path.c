/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:21:08 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/30 17:41:02 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, t_vars *vars)
{
	int	j;

	j = 0;
	while (envp[j])
	{
		if (envp[j][0] == 'P' && envp[j][3] == 'H')
			vars->paths = ft_split(&envp[j][5], ':');
		j++;
	}
	return (NULL);
}

void	init_arg_cmd(t_vars *vars, char **argv)
{
	vars->arg_cmd1 = malloc(sizeof(char*) *3);
	vars->arg_cmd2 = malloc(sizeof(char*) *3);

	vars->arg_cmd1[0] = NULL;
	// ft_strlen modifier qui compte apres un espace et je fais un malloc de cette taille
	// i + 1
	// voir si je compte l'espace. 
	// sur la chaine argv[2]

	// si il y a pas d'espace dans argv[2]
	//vars->arg_cmd1 == NULL;
	
	// a la fin je met un NULL; 
	vars->arg_cmd1[1] = ft_split(argv[2], ' ');
}


// arg_cmd1[0] == NULL;
// arg_cmd1[1] == argv[2];
