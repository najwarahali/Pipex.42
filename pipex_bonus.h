/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:45:06 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/22 01:43:28 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_ppb
{
	int		num_fork;
	int		num_pipe;
	int		fileout;
	int		filein;
	char	**cmd;
	int		fid;
	int		*p;
	int		i;
	int		j;

}	t_ppb;

int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *s);
int		check_fd1(char *av);
int		check_fd2(char *av);
void	ft_free_it(char	**cmd, int i);
char	*ft_substr(char *s, int start, int len);
char	**get_path(char **path);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	**access_path(char **env, char *av);
int		here_doc(char **av);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strjoin_not(char *s1, char *s2);
void	check_fork1_doc(int pfd[2], char **env, char *av2, char **av);
void	check_fork2_doc(int pfd[2], char **env, char *av4, char *av3);
void	ft_fork_bonus(int ac, char **av, char **env, t_ppb *pip);
void	bonus_fonction(int ac, char **av, char **env);
void	create_pipe(t_ppb *pip);

#endif