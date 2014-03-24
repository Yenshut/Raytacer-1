##
## Makefile for TP in /home/garcin_s/rendu/MUL_2013_rtv1/TP
## 
## Made by garcin_s
## Login   <garcin_s@epitech.net>
## 
## Started on  Tue Feb  4 12:22:08 2014 garcin_s
## Last update Sun Mar 16 18:49:27 2014 garcin_s
##

NAME	= rtv1

SRC	= source/main.c \
	  source/my_putchar.c \
	  source/calc.c \
	  source/color.c \
	  source/light.c \
	  source/hooks.c \
	  source/init.c \
	  source/rotate.c \
	  source/trans.c \
	  source/my_put_nbr.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Iinclude

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lm

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
