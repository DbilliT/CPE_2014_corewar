/*
** asm.h for asm.h in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Sun Nov 23 16:06:27 2014 paul david
** Last update Sun Dec 14 16:30:07 2014 paul david
*/

#ifndef ASM_H_
# define ASM_H_

# define COND buffer[*i] != '\n' && buffer[*i] != '\0' && buffer[*i] != ','

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "op.h"

typedef struct		s_label_list
{
  char			*name;
  int			line;
  struct s_label_list	*next;
}			t_label_list;

typedef struct	s_instru
{
  char		*mnemonique;
  int		oct;
  int		codage;	
}		t_instru;

typedef struct	s_code
{
  void		*data;
  int		size;
  struct s_code	*next;
}		t_code;

extern t_instru instru_tab[];

void		free_code(t_code **);
void		free_label_data(t_label_list **);
void		free_label(t_label_list **);
unsigned short	my_getnbr_sh(char *);
void		is_s(char *);
char		*create_newpath(char *);
int		count_prog_size(t_code *);
void		write_asm(header_t, t_code *, char *);
int		pars_instru_line_part(char *, int);
t_code		*pars_instru_line(char *, int, int, t_label_list *);
t_code		*pars_instru(char *, int, int, t_label_list *);
void		encode_reg(char *, int, t_code **);
unsigned int	*encode_dir(char *, int, int, t_label_list *);
unsigned short	*encode_indir(char *, int, int, t_label_list *);
int		label_before(char *, int, t_label_list *);
int		label_after(char *, int, t_label_list *);
unsigned short	encode_label_sh(char *, int, int, t_label_list *);
unsigned int	encode_label_int(char *, int, int, t_label_list *);
int		oct_count_part(char *, int *, int, int);
int		oct_count(char *, int *, int, int);
void		reg_code(unsigned char *, int *);
void		dir_code(unsigned char *, int *);
void		indir_code(unsigned char *, int *);
void		encoding_code(char *, int , unsigned char *);
void		instru_code(char *, int, int, t_code **);
void		add_end_code(t_code **, void *, int);
void		check_instru_line(char *, int, int, int);
int		check_prog(char *, int, int, t_label_list **);
void		check_prog_line(char *, int *, int);
char		is_reg(	char *, int, int);
char		is_dir(char *, int, int, int);
char		is_indir(char *, int, int);
void		create_label_list(t_label_list **, char *, int *, int);
void		add_end(t_label_list **, char *, int);
int		is_label_chars(char, int);
int		is_label_def(char *, int, int);
int		is_label_call(char *, int, int);
void		*my_x_realloc(char **, int);
void		*my_x_malloc(int);
int		my_getnbr(char *);
int		is_number(char);
int		is_label(char *, int, int);
int		check_prog(char *, int, int, t_label_list **);
void		my_memset(void *, int, int);
void		setzero(char *, int);
void		setzero_uns(unsigned char *, int);
void		label_error_line(int, char *, int);
void		line_head_comment(header_t *, char *, int);
void		line_head_name(header_t *, char *, int);
int		pars_comment_check(char *, int *, int *, header_t *);
void		pars_before_name(char *, int *, int *);
void		pars_name_check(char *, int *, int *, header_t *);
void		no_instru_err();
void		message_reg_line(int);
void		warning_indir_line(int);
void		warning_dir_line(int);
void		warning_comment_line(int);
void		message_error_line(int);
unsigned short	convert_endian_short(unsigned short);
unsigned int	convert_endian_int(unsigned int);
int		convert_endian(int val);
int		is_big_endian();
int		my_strncmp(char *s1, char *s2, int n, int k);
void		my_putchar(char);
void		my_putchar_error(char);
void		my_putstr_error(char *str);
int		my_strlen(char *str);
int		my_put_nbr_error(int);

#endif /* ASM_H_ */
