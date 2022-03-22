/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:58:11 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/22 01:58:13 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../pipex_bonus.h"

char	*get_line(int fd, char *a)
{
	int		count;
	char	*str;

	str = malloc(1 + 1);
	if (!str)
		return (NULL);
	count = 1;
	while (ft_strchr_1(a) == 0 && count)
	{
		count = read(fd, str, 1);
		if (count == -1)
		{
			free(str);
			return (NULL);
		}
		str[count] = '\0';
		a = ft_strjoin_1(a, str);
	}
	free(str);
	return (a);
}

char	*beforline(char *a)
{
	int	i;

	i = 0;
	if (!a[0])
		return (NULL);
	while (a[i] && a[i] != '\n')
	{
		i++;
	}
	return (ft_substr_1(a, 0, i + 1));
}

char	*afterline(char *a)
{
	int		i;
	char	*str;

	i = 0;
	if (!a)
		return (NULL);
	while (a[i])
	{
		if (a[i] == '\n')
		{
			str = ft_substr_1(a, i + 1, ft_strlen_1(a));
			free(a);
			return (str);
		}
		i++;
	}
	free(a);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*a;
	char		*s;

	if (fd < 0)
		return (NULL);
	a = get_line(fd, a);
	if (!a)
		return (NULL);
	s = beforline(a);
	a = afterline(a);
	return (s);
}
