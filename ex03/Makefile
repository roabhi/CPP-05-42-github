# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 16:46:26 by rabril-h          #+#    #+#              #
#    Updated: 2023/11/01 21:14:48 by rabril-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern


RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address


FILES = main ./classes/Bureaucrat ./classes/Intern ./classes/Forms/AForm ./classes/Forms/PresidentialPardonForm ./classes/Forms/RobotomyRequestForm ./classes/Forms/ShrubberyCreationForm

SRC = $(addsuffix .cpp, $(FILES))

vpath %.cpp 


OBJ = $(SRC:.cpp=.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))


%.o: %.cpp 
	@${CC} $(CFLAGS) -MMD -c $< -o $@

all:
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ) $(DEP) --no-print-directory
	@echo "Objects cleaned"

fclean: clean
	@$(RM) $(NAME) --no-print-directory
	@echo "All compilation files removed"

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)
