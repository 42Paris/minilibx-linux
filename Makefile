##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script

#######################################
#               LIBRARY               #
#######################################
NAME		=	libmlx.a
NAME_UNAME	=	libmlx_$(shell uname).a

######################################
#              COMMANDS              #
######################################
CC			=	gcc -c -o
LINK		=	ar rcs
RM			=	rm -rf
MKDIR		=	mkdir -p
CP			=	cp

#####################################
#            DIRECTORIES            #
#####################################
SRCD		=	srcs/
OBJD		=	objs/
INCD		=	includes/
PRIV_INCD	=	private/

######################################
#            SOURCE FILES            #
######################################
SRCS		=	\
				${addprefix mlx_event/,				\
					mlx_int_param_ButtonPress.c		\
					mlx_int_param_ButtonRelease.c	\
					mlx_int_param_Expose.c			\
					mlx_int_param_generic.c			\
					mlx_int_param_KeyPress.c		\
					mlx_int_param_KeyRelease.c		\
					mlx_int_param_MotionNotify.c	\
					mlx_int_param_undef.c			\
				}									\
				${addprefix mlx_new_image/,			\
					mlx_clean_quit.c				\
					mlx_int_new_image.c				\
					mlx_int_new_xshm_image.c		\
					mlx_new_image2.c				\
					mlx_new_image.c					\
					mlx_set_val.c					\
				}									\
				${addprefix mlx_xpm/,				\
					mlx_int_file_get_rid_comment.c	\
					mlx_int_get_col_name.c			\
					mlx_int_get_line.c				\
					mlx_int_get_text_rgb.c			\
					mlx_int_parse_xpm.c				\
					mlx_int_static_line.c			\
					mlx_int_xpm_set_pixel.c			\
					mlx_return.c					\
					mlx_xpm_file_to_image.c			\
					mlx_xpm_to_image.c				\
					part0_4.c						\
					spart0_4.c						\
					strlcpy_is_not_posix.c			\
				}									\
				mlx_clear_window.c					\
				mlx_destroy_display.c				\
				mlx_destroy_image.c					\
				mlx_destroy_window.c				\
				mlx_expose_hook.c					\
				mlx_flush_event.c					\
				mlx_get_color_value.c				\
				mlx_get_data_addr.c					\
				mlx_hook.c							\
				mlx_init.c							\
				mlx_int_anti_resize_win.c			\
				mlx_int_do_nothing.c				\
				mlx_int_get_visual.c				\
				mlx_int_set_win_event_mask.c		\
				mlx_int_str_to_wordtab.c			\
				mlx_int_wait_first_expose.c			\
				mlx_key_hook.c						\
				mlx_loop_hook.c						\
				mlx_loop.c							\
				mlx_mouse_hook.c					\
				mlx_mouse.c							\
				mlx_new_window.c					\
				mlx_pixel_put.c						\
				mlx_put_image_to_window.c			\
				mlx_screen_size.c					\
				mlx_set_font.c						\
				mlx_string_put.c

######################################
#            OBJECT FILES            #
######################################
OBJS		=	${SRCS:.c=.o}
OBJS		:=	${addprefix ${OBJD}, ${OBJS}}

DEPS		=	${OBJS:.o=.d}

#####################################
#               FLAGS               #
#####################################
CFLAGS		=	-Wall -Wextra -Werror -MMD -I${INCD} -I${PRIV_INCD}
LDFLAGS		=	

#####################################
#               FLAGS               #
#####################################
${NAME}:	${OBJS}
	${LINK} $@ ${LDFLAGS} $^

${NAME_UNAME}:	${NAME}
	${CP} $< $@

all: ${NAME} ${NAME_UNAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME} ${NAME_UNAME}

re:	fclean all

norm:
	@norminette ${SRCD} | grep 'Error' ; true

coffee:
	@echo '                                              '
	@echo '                   "   "                      '
	@echo '                  " " " "                     '
	@echo '                 " " " "                      '
	@echo '         _.-==="""""""""===-._                '
	@echo '        |=___    ~ ~ ~    ___=|=,.            '
	@echo '        |    """======="""    |  \\           '
	@echo '        |                     |   ||          '
	@echo '        |                     |   ||          '
	@echo '        |                     |   ||          '
	@echo '        |                     |   ||          '
	@echo '        |                     |  //           '
	@echo '         \                   /==""            '
	@echo '          \                 /                 '
	@echo '           ""--._______.--""                  '
	@echo '                                              '

.PHONY:	all clean fclean re norm coffee
