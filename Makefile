# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: nrahali <nrahali@student.42.fr>			+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2022/03/05 03:14:50 by nrahali		   #+#	#+#			  #
#	Updated: 2022/03/09 02:30:41 by nrahali		  ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME= pipex
BONUS= bonus
CC= gcc
FLAGS= -Wall -Wextra -Werror
SRC= ./Mondatory/main.c ./Mondatory/pipex_utils.c ./Mondatory/ft_split.c ./Mondatory/check_files.c ./Mondatory/check_cmd.c ./Mondatory/pipe.c

SRC_bonus= ./pipex_bonus/main_bonus.c ./pipex_bonus/pipex_utils_bonus.c ./pipex_bonus/ft_split.c ./pipex_bonus/check_files_bonus.c ./pipex_bonus/check_cmd_bonus.c ./pipex_bonus/get_next_line.c ./pipex_bonus/get_next_line_utils.c ./pipex_bonus/here_doc.c

OBJ= $(SRC:.c=.o)
OBJ_BONUS = $(SRC_bonus:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
bonus: $(OBJ_BONUS)
	$(CC) $(FLAGS) $(SRC_bonus) -o $(BONUS) #-fsanitize=address
clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all