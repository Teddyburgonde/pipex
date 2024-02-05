/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:15:30 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/05 19:14:07 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **grep_path(char **envp)
{
	int	i;
	char	**tmp;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	if (envp[i] != NULL)
	{
		tmp = ft_split(envp[i] + 5, ':');
		return (tmp);
	}
	return (NULL);
}