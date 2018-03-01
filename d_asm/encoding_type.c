/*
** encoding_type.c for encoding_type in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Mon Dec  8 16:01:08 2014 paul david
** Last update Mon Dec  8 16:03:35 2014 paul david
*/

#include "asm.h"

void		encode_reg(char *buffer, int i, t_code **code_list)
{
  char		*nbr;
  unsigned char	*code;
  int		count;

  count = 0;
  nbr = my_x_malloc(sizeof(char) * 3);
  code = my_x_malloc(sizeof(unsigned char) * 1);
  while (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != ','
         && buffer[i] != '\n' && buffer[i] != '\0')
    {
      nbr[count] = buffer[i];
      i++;
      count++;
    }
  nbr[count] = '\0';
  code[0] = my_getnbr(nbr);
  free(nbr);
  add_end_code(&(*code_list), code, 1);
}

unsigned int	*encode_dir(char *buffer, int i, int j, t_label_list *list)
{
  char		*nbr;
  unsigned int	*code;
  int		count;

  code = my_x_malloc(sizeof(unsigned int) * 1);
  count = 0;
  if (buffer[i] == LABEL_CHAR)
    code[0] = encode_label_int(buffer, ++i, j, list);
  else
    {
      nbr = my_x_malloc(sizeof(char) * 11);
      while (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\n'
             && buffer[i] != ',' && buffer[i] != '\0')
        {
          nbr[count] = buffer[i];
          count++;
          i++;
        }
      nbr[count] = '\0';
      code[0] = my_getnbr(nbr);
      free(nbr);
    }
  if (is_big_endian() != 1)
    code[0] = convert_endian_int(code[0]);
  return (code);
}

unsigned short		*encode_indir(char *buffer, int i, int j, t_label_list *list)
{
  char			*nbr;
  unsigned short	*code;
  int			count;

  code = my_x_malloc(sizeof(unsigned short) * 1);
  count = 0;
  if (buffer[i] == LABEL_CHAR)
    code[0] = encode_label_sh(buffer, ++i, j, list);
  else
    {
      nbr = my_x_malloc(sizeof(char) * 11);
      while (buffer[i] != ' ' && buffer[i] != '\t'
             && buffer[i] != '\n' && buffer[i] != '\0')
        {
          nbr[count] = buffer[i];
          count++;
          i++;
        }
      nbr[count] = '\0';
      code[0] = my_getnbr(nbr);
      free(nbr);
    }
  if (is_big_endian() != 1)
    code[0] = convert_endian_short(code[0]);
  return (code);
}
