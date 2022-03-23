/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:57:24 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/24 00:33:03 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

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
void	check_fork1(int pfd[2], char **env, char **av, int filein);
void	check_fork2(int pfd[2], char **env, char **av, int fileout);

#endif
