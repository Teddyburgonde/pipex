/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:21:08 by tebandam          #+#    #+#             */
/*   Updated: 2024/01/29 11:38:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char	*find_path(char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_strncmp("PATH", envp[i], 4) != 0)
// 		i++;
// 	return (envp[i] + 5);
// }

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