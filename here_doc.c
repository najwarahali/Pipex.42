/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrahali <nrahali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:19:50 by nrahali           #+#    #+#             */
/*   Updated: 2022/03/21 02:33:28 by nrahali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int here_doc(char **av)
{
    char    *str;
    char    *join;
    int     file_tem;

    file_tem = open("tem",O_CREAT | O_WRONLY | O_TRUNC ,0644);
    join = ft_strjoin_not(av[2] ,"\n");
    write(1, "heredoc>", 9);
    str = get_next_line(0);
    while(ft_strcmp(join, str) != 0)
    {
        write(1, "heredoc>", 9);
        write(file_tem, str, ft_strlen(str));
        str = get_next_line(0);
    }
   return(file_tem);
}