/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nrahali <nrahali@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/09 02:32:18 by nrahali		   #+#	#+#			 */
/*   Updated: 2022/03/09 03:11:28 by nrahali          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../pipex.h"

static int	words(char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (count);
}

static char	**words_all(char **dst, char *s, char c)
{
	int	i;
	int	j;
	int	temp;
	int	count;

	count = words(s, c);
	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] && s[i] == c)
			i++;
		temp = i;
		while (s[i] && s[i] != c)
			i++;
		dst[j] = (ft_substr(s, temp, i - temp));
			j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char *s, char c)
{
	char	**dst;
	int		len;

	if (!s)
		return (NULL);
	len = words(s, c);
	dst = malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	return (words_all(dst, s, c));
}
