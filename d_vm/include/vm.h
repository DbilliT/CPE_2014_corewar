/*
** vm.h for vm in /home/bechad_p/rendu/Corewar/VM/include
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Dec  4 11:33:01 2014 Pierre Bechade
** Last update Sun Dec 14 20:30:10 2014 paul david
*/

#ifndef _VM_H_
# define _VM_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "command.h"

# define MPC3 (para3 % IDX_MOD)
# define MPC2 (para2 % IDX_MOD)
# define MPC ((PC + para) % MEM_SIZE)
# define PC command->my_cor->pc
# define CURRENT command->my_cor
# define LIST t_command_list
# define UNS_I unsigned int
# define UNS_C unsigned char

extern unsigned char	*arena;
extern int		gl_type[3];
extern int		gl_offset;
extern int		gl_pos;

/* IN SRC/ERROR_FUNCTIONS.C */
void	my_putchar_e(char c);
void	my_putstr_e(char *str);
void	my_put_nbr_calc_e(int nb);
int	my_put_nbr_e(int nb);

/* IN SRC/PARSE.C */
void	my_vm(const char *pathname);
void	my_fill_cmd(t_command_list **list, header_t head, unsigned char *act);

/* IN SRC/AFF_BAD_PARSE.C */
void	check_file();
void	check_access(const char *pathname, int fd);
void	check_header(int fd);
void	check_prog_size(int rd, int fd);
void	my_check_magic();

/* IN SRC/CHECK_COMMAND.C */
void	add_end_sort(t_command_list **list, t_command_list *node);
void	add_end_code(t_command_list **list, char *data, int a, int b);
int	check_command(int ac, char **av);

/* IN SRC/CHECK_DUMP.C */
void	is_error(char *message);
int	check_dump(char *str);
void	check_dump_number(char *str);
int	check_n(char *str);
int	check_prog_number(char *str);

/* IN SRC/CHECK_OVERLAP.C */
unsigned char	*my_set_zero(unsigned char *my_tab);
char		*my_set_zero2(char *my_tab);
unsigned char	*class_champ2(unsigned char *my_tab, int champ_nbr, char *order);
unsigned char	*class_champ(unsigned char *my_tab, int champ_nbr);
unsigned char	*check_overlap();

/* IN CHECK_LOAD.C */
int	check_a(char *str);
int	check_load_value(char *str);
int	check_cor(char *str);
int	check_arg(char *str, char **av, int *j);
void	check_number_used();

/* IN SRC/TOOLS.C */
int	my_strlen(char *str);
void	my_putchar(char c);
void	my_putstr(char *str);

/* IN SRC/TOOLS2.C */
int	compt_word(char *str);
char	*my_strncpy(char *dest, char *src, int n);
char	**my_str_to_wordtab(char *str, char c);
void	my_putcons_e(const char*str);

/* IN SRC/TOOLS3.C */
void	*my_xmalloc(int size);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);
char	*my_b_zero(char*str, int size);

/* IN SRC/TOOLS4.C */
int	my_calc_getnbr(char *str, int i, double nb_final, int nb_return);
int	my_getnbr(char *str);
void	my_put_calc(int nb);
int	my_put_nbr(int nb);

/* IN SRC/ENDIAN.C */
int		is_big_endian();
int		convert_endian(int val);
unsigned int	convert_endian_int(unsigned int val);
unsigned short	convert_endian_short(unsigned short val);

/* IN SRC/MY_BATTLE.C */
void	my_aff_list(t_command_list *list);
int	my_calc_champ(t_command_list *list);
void	my_trans_circ(t_command_list **list);
void	my_kill_chain(t_command_list **list);
void	my_battle(unsigned char *map, int, int, int);

/* IN SRC/HOW_MANY_IS_ALIVE.C */
int	how_many_alive();
int	my_no_fork_champ();

/* IN FILL_CHAMP.C */
int	number_of_champ();
void	fill_struct_champ1(LIST *tmp, unsigned char *my_tab, int champ_nbr);
void	fill_struct_champ2(t_command_list *tmp, unsigned char *my_tab);
void	fill_struct_champ3(t_command_list *tmp2, unsigned char *my_tab, int j);
void	fill_struct_champ4(LIST *tmp2, unsigned char *my_tab, int j, int champ_nbr);

/* IN SRC/CHECK_INSTRU_ACTION.C */
int	check_instru_duo_part(int *bits, unsigned int *ptr, int k, int offset);
void	check_instru_duo(int k);
void	check_instru_mul(int k);
void	check_instru();

/* IN SRC/CHECK_INSTRU_ACTION2.C */
void	check_instru_solo(int k);
int	check_instru_tri_part(int *bits, unsigned int *ptr, int k, int offset);
void	check_instru_tri(int k);

/* IN SRC/CHECK_INSTRU_FILL.C */
void	fill_dir(unsigned int *para);
void	fill_indir(unsigned int *para);
void	fill_reg(unsigned int *para);
int	fill_duo_ind(int k, int *bits, unsigned int *para);
int	fill_duo_dir(int k, int *bits, unsigned int *para);

/* IN SRC/CHECK_INSTRU_FILL2.C */
int	fill_duo_reg(int k, int *bits, unsigned int *para);
int	fill_tri_ind(int k, int *bits, unsigned int *para);
int	fill_tri_dir(int k, int *bits, unsigned int *para);
int	fill_tri_reg(int k, int *bits, unsigned int *para);

/* IN SRC/CHECK_TO_INSTRU.C */
void	exe_instru_tri(unsigned int para, unsigned int para2, unsigned para3, int k);
void	exe_instru_duo(unsigned int para, unsigned int para2, int k);
void	exe_instru_solo(unsigned int para, int k);

/* IN SRC/MY_CHECK_COR.C */
void	my_check_cor();

/* IN SRC/MNEMONIQUE/LIVE.C */
void	live(unsigned int player);

/* IN SRC/MNEMONIQUE/MY_FAIL.C */
void	my_fail(int value);

/* IN SRC/MNEMONIQUE/LD.C */
void	my_ld(unsigned int data, unsigned int data2);

/* IN SRC/MNEMONIQUE/ST.C */
void	my_st(unsigned int data1, unsigned int data2);

/* IN SRC/MNEMONIQUE/MY_ADD.C */
void	my_add(unsigned int rg, unsigned int rg2, unsigned int rg3);

/* IN SRC/MNEMONIQUE/SUB.C */
void	my_sub(unsigned int rg, unsigned int rg2, unsigned int rg3);

/* IN SRC/MNEMONIQUE/AND.C */
void	my_and(unsigned int p1, unsigned int p2, unsigned int r3);

/* IN SRC/MNEMONIQUE/OR.C */
void	my_or(unsigned int p1, unsigned int p2, unsigned int r3);

/* IN SRC/MNEMONIQUE/XOR.C */
void	my_xor(unsigned int p1, unsigned int p2, unsigned int r3);

/* IN SRC/MNEMONIQUE/ZJMP.C */
void	my_zjmp(unsigned int value);

/* IN SRC/MNEMONIQUE/LDI.C */
void	my_ldi(unsigned int para, unsigned int para2, unsigned int para3);

/* IN SRC/MNEMONIQUE/LLD.C */
void	my_lld(unsigned int data, unsigned int data2);

/* IN SRC/MNEMONIQUE/LLDI.C */
void	my_lldi(unsigned int para, unsigned int para2, unsigned int para3);

/* IN SRC/MNEMONIQUE/STI.C */
void	my_sti(unsigned int para, unsigned int para2, unsigned int para3);

/* IN SRC/MNEMONIQUE/AFF.C */
void	my_aff(unsigned int para);

/* IN SRC/MNEMONIQUE/FORK.C */
void	my_fork(int para);

/* IN SRC/MNEMONIQUE/LFORK.C */
void	my_lfork(int para);

/* IN SRC/SETZERO.C */
void	my_memset(void  *s, int value, int size);
void	setzero_uns(unsigned char *str, int j);
void	setzero(char *str, int j);

#endif /* _VM_H_ */
