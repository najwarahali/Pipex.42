/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:29:17 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/21 01:59:16 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;
	char			*s3;
	char			*s4;

	if (n == 0)
		return (0);
	s3 = (char *)s1;
	s4 = (char *)s2;
	i = 0;
	while (s3[i] != '\0' && (s3[i] == s4[i]) && i < n - 1)
		i++;
	return (s3[i] - s4[i]);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char)));
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	s[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (s);
}

char	*ft_strjoin_not(char *s1, char *s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char)));
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	s[ft_strlen(s1) + i] = '\0';
	return (s);
}
