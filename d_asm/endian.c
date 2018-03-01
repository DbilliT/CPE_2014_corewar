/*
** endian.c for endian in /home/david_k/rendu/CPE_2014_corewar/d_asm
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Nov 25 19:55:36 2014 paul david
** Last update Sat Dec  6 12:32:25 2014 paul david
*/

int	is_big_endian()
{
  int	nbr;
  char	*ptr;

  nbr = 0x0A0B0C0D;
  ptr = (char *)&nbr;
  return ((ptr[0] == 0x0A) ? 1 : 0);
}

int	convert_endian(int val)
{
  char	str[4];
  int	result;

  str[3] = val & 0xFF;
  str[2] = (val >> 8) & 0xFF;
  str[1] = (val >> 16) & 0xFF;
  str[0] = (val >> 24) & 0xFF;
  result = *(int *)&str;
  return (result);
}

unsigned int	convert_endian_int(unsigned int val)
{
  char		str[4];
  unsigned int	result;

  str[3] = val & 0xFF;
  str[2] = (val >> 8) & 0xFF;
  str[1] = (val >> 16) & 0xFF;
  str[0] = (val >> 24) & 0xFF;
  result = *(unsigned int *)&str;
  return (result);
}

unsigned short		convert_endian_short(unsigned short val)
{
  char			str[2];
  unsigned short	result;

  str[1] = val & 0xFF;
  str[0] = (val >> 8) & 0xFF;
  result = *(unsigned short *)&str;
  return (result);
}
