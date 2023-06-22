# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.4seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 0/09/30 0:33:0 by suhkim            #+#    #+#              #
#    Updated: 2023/06/22 15:37:34 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98

SRC = Bureaucrat.cpp \
	  main.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
