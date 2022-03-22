/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:58:02 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/22 01:58:05 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"
#include "../get_next_line.h"

char	*ft_substr_1(char *s, int start, int len)
{
	int		i;
	char	*ptr;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	while (i < len && s[i])
		i++;
	ptr = malloc ((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (j < i)
		ptr[j++] = s[start++];
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strjoin_1(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
	int		a;
	int		b;

	a = ft_strlen_1(s1);
	b = ft_strlen_1(s2);
	new = malloc (a + b + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < a)
		new[i++] = s1[j++];
	j = 0;
	while (j < b)
		new[i++] = s2[j++];
	new[i] = '\0';
	free (s1);
	return (new);
}

int	ft_strchr_1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	while (s3[i] != '\0' && (s3[i] == s4[i]))
		i++;
	return (s3[i] - s4[i]);
}
