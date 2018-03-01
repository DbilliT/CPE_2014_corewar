/*
** my_get_nbr.c for my_get_number in /home/david_k/rendu/Bistromathique/lib/my
** 
** Made by paul david
** Login   <david_k@epitech.net>
** 
** Started on  Tue Nov  4 20:47:17 2014 paul david
** Last update Mon Dec  8 19:31:24 2014 paul david
*/

unsigned short	my_calcule3(char *str, int i, double nb_final, unsigned short nb_return)
{
  while ((str[i] != '\0') && ((str[i] >= '0' && str[i] <= '9')
			      || (str[i] == '-' || str[i] == '+')))
    {
      if (str[i] >= '0' && str[i] <= '9')
	nb_final = (nb_final * 10) + (str[i] - 48);
      if (str[i] == '-')
	nb_return = nb_return + 1;
      i++;
    }
  if ((nb_return % 2) != 0)
    nb_final = nb_final - (2 * nb_final);
  if (nb_final > 65535 || nb_final < -65535)
    return (0);
  nb_return = nb_final;
  return (nb_return);
}

unsigned short		my_getnbr_sh(char *str)
{
  unsigned short	result;
  double		nb_final;
  int			i;
  unsigned short	nb_return;

  result = 0;
  nb_final = 0;
  i = 0;
  nb_return = 0;
  result = my_calcule3(str, i, nb_final, nb_return);
  return (result);
}
