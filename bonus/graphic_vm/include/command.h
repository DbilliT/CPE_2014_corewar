/*
** command.h for command in /home/deluss_c/rendu/test/corewartest
** 
** Made by Cédric de Lussigny
** Login   <deluss_c@epitech.net>
** 
** Started on  Tue Dec  9 19:51:24 2014 Cédric de Lussigny
** Last update Sun Dec 14 01:40:39 2014 Pierre Bechade
*/

#ifndef COMMAND_H_
# define COMMAND_H_

typedef struct		s_command_list
{
  int			prog_nbr;
  int			load_ad;
  char			*name_cor;
  int			carry;
  unsigned int		reg[REG_NUMBER];
  int			pc;
  int			is_alive;
  int			global_time;
  char			*name_champ;
  char			*desc_champ;
  int			size_act;
  unsigned char		*action;
  struct s_command_list	*next;
}			t_command_list;

typedef struct		s_command
{
  int			my_dump;
  int			live;
  int			nb_champ;
  int			no_fork_champ;
  char			*winner;
  t_command_list	*my_cor;
}			t_command;

extern t_command *command;

typedef struct		s_instru
{
  char			*mnemonique;
  int			oct;
  int			codage;
}			t_instru;

extern t_instru instru_tab[];

#endif /* COMMAND_H_ */
