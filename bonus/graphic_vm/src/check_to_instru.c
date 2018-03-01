/*
** check_to_instru.c for check_to_instru in /home/bechad_p/rendu/Corewar/VM/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Dec 13 14:53:53 2014 Pierre Bechade
** Last update Sun Dec 14 01:47:46 2014 Pierre Bechade
*/

#include "vm.h"

void	exe_instru_solo(unsigned int para, int k)
{
  (void)para;
  if (op_tab[k].code == 1)
    {
      if ((int)para > command->no_fork_champ)
        {
          PC = gl_offset + 1;
          my_fail(0);
        }
      live(para);
    }
  if (op_tab[k].code == 9)
    my_zjmp(para);
  if (op_tab[k].code == 12)
    my_fork(para);
  if (op_tab[k].code == 15)
    my_lfork(para);
  if (op_tab[k].code == 16)
    my_aff(para);
}

void	exe_instru_tri(UNS_I para, UNS_I para2, unsigned para3, int k)
{
  if (op_tab[k].code == 4)
    my_add(para, para2, para3);
  if (op_tab[k].code == 5)
    my_sub(para, para2, para3);
  if (op_tab[k].code == 6)
    my_and(para, para2, para3);
  if (op_tab[k].code == 7)
    my_or(para, para2, para3);
  if (op_tab[k].code == 8)
    my_xor(para, para2, para3);
  if (op_tab[k].code == 10)
    my_ldi(para, para2, para3);
  if (op_tab[k].code == 11)
    my_sti(para, para2, para3);
  if (op_tab[k].code == 14)
    my_lldi(para, para2, para3);
}

void	exe_instru_duo(unsigned int para, unsigned int para2, int k)
{
  if (op_tab[k].code == 2)
    my_ld(para, para2);
  if (op_tab[k].code == 3)
    my_st(para, para2);
  if (op_tab[k].code == 13)
    my_lld(para, para2);
}

