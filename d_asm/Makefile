##
## Makefile for do-op in /home/david_k/rendu/Piscine_C_J11/do-op
## 
## Made by paul david
## Login   <david_k@epitech.net>
## 
## Started on  Mon Oct 20 11:12:52 2014 paul david
## Last update Tue Dec  9 15:02:26 2014 paul david
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wall -Werror -Wextra -g -g3 -ggdb

CFLAGS	+=	-I./include

NAME	=	asm

SRCS	=	asm.c			\
		instru.c		\
		pars_head.c		\
		pars_instru.c		\
		check_error.c		\
		type_compar.c		\
		create_list.c		\
		encoding_instru.c	\
		encoding_type.c		\
		encoding_label.c	\
		oct_count.c		\
		write_asm.c		\
		free_list.c		\
		aff.c			\
		aff_err.c		\
		aff_line_err.c		\
		aff_line_err_lab.c	\
		op.c			\
		my_get_nbr_sh.c		\
		my_get_nbr.c		\
		my_put_nbr.c		\
		my_strncmp.c		\
		label_compar.c		\
		compar.c		\
		my_x_malloc.c		\
		setzero.c		\
		endian.c

RM	=	rm -f

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS) 
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)
re	:	fclean all
