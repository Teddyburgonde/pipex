

#include "libft.h"

size_t	ft_array_len(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i]){
		i++;
	}
	return (i);
}
