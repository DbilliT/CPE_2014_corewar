/*
** encoding_instru.c for encoding_instru in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  8 15:26:45 2014 paul david
** Last update Tue Dec  9 14:29:45 2014 paul david
*/

#include "asm.h"

void	indir_code(unsigned char *code, int *count)
{
  *code += (1 << *count);
  *count = *count - 1;
  *code += (1 << *count);
  *count = *count - 1;
}

void	dir_code(unsigned char *code, int *count)
{
  *code += (1 << *count);
  *count = *count - 1;
  *code += (0 << *count);
  *count = *count - 1;
}

void	reg_code(unsigned char *code, int *count)
{
  *code += (0 << *count);
  *count = *count - 1;
  *code += (1 << *count);
  *count = *count - 1;
}

void	encoding_code(char *buffer, int i, unsigned char *code)
{
  int	count;

  count = 7;
  while (buffer[i] != '\0' && buffer[i] != '\n')
    {
      while (buffer[i] == ' ' || buffer [i] == '\t' || buffer[i] == ',')
        i++;
      if (buffer[i] == 'r')
        reg_code(&(*code), &count);
      else if (buffer[i] == '%')
        dir_code(&(*code), &count);
      else
        indir_code(&(*code), &count);
      while (buffer[i] != ',' && buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    }
}

void		instru_code(char *buffer, int i, int k, t_code **list)
{
  unsigned char	*instru;
  unsigned char	*code;

  instru = my_x_malloc(sizeof(unsigned char) * 1);
  instru[0] = op_tab[k].code;
  add_end_code(&(*list), instru, 1);
  if (instru_tab[k].codage == 1)
    {
      code = my_x_malloc(sizeof(unsigned char) * 1);
      setzero_uns(code, 1);
      while (buffer[i] != ' ' && buffer [i] != '\t')
        i++;
      encoding_code(buffer, i, &code[0]);
      add_end_code(&(*list), code, 1);
    }
}
