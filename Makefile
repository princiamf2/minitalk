# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:29:27 by mm-furi           #+#    #+#              #
#    Updated: 2024/10/21 15:20:33 by mm-furi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
BCLIENT = client_bonus
BSERVER = server_bonus
FLAGS = -Wall -Werror -Wextra
GCC = cc
SRCC = ft_putstr.c ft_atoi.c client.c
SRCS = ft_putchar.c ft_putnbr.c ft_server.c
INC = minitalk.h
BSRCC =  ft_putstr.c ft_atoi.c client_bonus.c
BSRCS =  ft_putchar.c ft_putnbr.c ft_server_bonus.c

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(SRCC)
	$(CC) $(FLAGS) $(SRCC) -o $(CLIENT)
$(SERVER) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(SERVER)

bonus : $(BCLIENT) $(BSERVER)

$(BCLIENT) : $(BSRCC)
	$(CC) $(FLAGS) $(BSRCC) -o $(BCLIENT)
$(BSERVER) : $(BSRCS)
	$(CC) $(FLAGS) $(BSRCS) -o $(BSERVER)

fclean : 
	rm -rf $(CLIENT) $(SERVER) $(BCLIENT) $(BSERVER)

re : fclean all

.PHONY : all bonus fclean re