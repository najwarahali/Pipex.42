/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:22:21 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/20 03:34:26 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	**get_path(char **path)
{
	int		i;
	char	*multiple_path;
	char	**r;

	i = 0;
	while (path[i])
	{
		if (!ft_strncmp(path[i], "PATH=", 5))
		{
			multiple_path = ft_substr(path[i], 5, ft_strlen(path[i]));
			r = ft_split(multiple_path, ':');
			free (multiple_path);
			return (r);
		}
		i++;
	}
	return (NULL);
}

void	ft_free_it(char	**cmd, int i)
{
	while (cmd[i] != '\0')
	{
		free (cmd[i]);
		i++;
	}
	free (cmd);
}

char	**access_path(char **env, char *av)
{
	char	**r;
	char	*join2;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(av, ' ');
	r = get_path(env);
	while (r[i])
	{
		r[i] = ft_strjoin(r[i], "/");
		join2 = ft_strjoin(r[i], cmd[0]);
		if (!(access(join2, X_OK)))
		{
			free (cmd[0]);
			cmd[0] = join2;
			ft_free_it(r, ++i);
			return (cmd);
		}
		free (join2);
		i++;
	}
	free(r);
	return (cmd);
}
