##
## Makefile for Makefile in /home/bechad_p/rendu/Corewar/VM
## 
## Made by Pierre Bechade
## Login   <bechad_p@epitech.net>
## 
## Started on  Thu Dec  4 11:31:48 2014 Pierre Bechade
## Last update Sun Dec 14 20:40:32 2014 paul david
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Werror -Wextra -g3

CFLAGS	+=	-I./include/

NAME	=	corewar

SRCS	=	src/parse.c			\
		src/aff_bad_parse.c		\
		src/error_functions.c		\
		src/tools.c			\
		src/tools2.c			\
		src/tools3.c			\
		src/tools4.c			\
		src/main.c			\
		src/endian.c			\
		src/check_command.c		\
		src/check_dump_n.c		\
		src/check_load.c		\
		src/check_overlap.c		\
		src/fill_champ.c		\
		src/check_instru_action.c	\
		src/check_instru_action2.c	\
		src/check_to_instru.c		\
		src/check_instru_fill.c		\
		src/check_instru_fill2.c	\
		src/my_check_cor.c		\
		src/my_battle.c			\
		src/my_battle2.c		\
		src/how_many_alive.c		\
		src/instru.c			\
		src/op.c			\
		src/setzero.c			\
		src/mnemonique/live.c		\
		src/mnemonique/my_fail.c	\
		src/mnemonique/ld.c		\
		src/mnemonique/st.c		\
		src/mnemonique/add.c		\
		src/mnemonique/sub.c		\
		src/mnemonique/and.c		\
		src/mnemonique/or.c		\
		src/mnemonique/xor.c		\
		src/mnemonique/zjmp.c		\
		src/mnemonique/ldi.c		\
		src/mnemonique/lldi.c		\
		src/mnemonique/lld.c		\
		src/mnemonique/sti.c		\
		src/mnemonique/aff.c		\
		src/mnemonique/fork.c		\
		src/mnemonique/lfork.c

RM	=	rm -f

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(HH) $(LIB)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)
re	:	fclean all
