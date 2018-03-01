##
## Makefile for do-op in /home/david_k/rendu/Piscine_C_J11/do-op
## 
## Made by paul david
## Login   <david_k@epitech.net>
## 
## Started on  Mon Oct 20 11:12:52 2014 paul david
## Last update Sun Dec 14 01:06:33 2014 Cédric de Lussigny
##

all	:
		make re -C d_asm/
		make re -C d_vm/

clean	:
		make clean -C d_asm/
		make clean -C d_vm/

fclean	:
		make fclean -C d_asm/
		make fclean -C d_vm/

re	:
		make clean -C d_asm/
		make clean -C d_vm/
		make re -C d_asm/
		make re -C d_vm/
