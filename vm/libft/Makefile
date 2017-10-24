NAME = libft.a
DIR_OBJS = objs
DIR_SRCS = srcs

MEM=	ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		ft_memset.c ft_quicksort.c ft_swap.c ft_swap_ints.c \
		ft_arrlen.c ft_arrdel.c
SRCS += $(addprefix $(DIR_SRCS)/mem/, $(MEM))

STR=	ft_contstr.c ft_strappend.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcmpr.c ft_strcont.c \
		ft_strcpy.c ft_strctrim.c ft_strdel.c ft_strdup.c \
		ft_strequ.c ft_strftrim.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		ft_strmapi.c ft_strmerge.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strprepend.c ft_strrchr.c ft_strremove.c ft_strreplace.c \
		ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtolower.c \
		ft_strtoupper.c ft_strtrim.c ft_tolower.c ft_toupper.c \
		ft_strchrs.c
SRCS += $(addprefix $(DIR_SRCS)/str/, $(STR))

IS=		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_islower.c ft_isprint.c ft_isupper.c ft_iswhitespace.c \
		ft_isint.c ft_isuintmax.c
SRCS += $(addprefix $(DIR_SRCS)/is/, $(IS))

CONV=	ft_atoi.c ft_atoimax.c ft_imaxtoa.c ft_imaxtoa_sign.c \
		ft_itoa.c ft_uimaxtoa_base.c ft_atouimax.c
SRCS += $(addprefix $(DIR_SRCS)/conv/, $(CONV))

PUT=	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
SRCS += $(addprefix $(DIR_SRCS)/put/, $(PUT))

LST=	ft_lstadd.c ft_lstat.c ft_lstdel.c ft_lstdelone.c \
		ft_lstiter.c ft_lstiter_rev.c ft_lstlen.c ft_lstmap.c \
		ft_lstnew.c ft_lstpop.c ft_lstpush.c ft_lstreduce.c \
		ft_lstshift.c ft_lsttail.c ft_lstaddnew.c ft_lstpushnew.c \
		ft_lstremoveif.c
SRCS += $(addprefix $(DIR_SRCS)/lst/, $(LST))

BTREE=	ft_btree_apply_infix.c ft_btree_apply_prefix.c ft_btree_apply_suffix.c \
		ft_btreeadd.c ft_btreedelone.c ft_btreenew.c ft_btreeaddnew.c \
		ft_btree_apply_infixp.c ft_btreedel.c
SRCS += $(addprefix $(DIR_SRCS)/btree/, $(BTREE))

PRINTF=	ft_conv_buox.c ft_conv_c.c ft_conv_d.c ft_conv_pc.c \
		ft_conv_s.c ft_conv_ubase.c ft_conv_wc.c ft_conv_ws.c \
		ft_createph.c ft_doconv.c ft_doprint.c ft_error.c \
		ft_getph.c ft_numprec.c ft_printf.c ft_puts.c \
		ft_wchar.c ft_width.c
SRCS += $(addprefix $(DIR_SRCS)/printf/, $(PRINTF))

GNL=	get_next_line.c process_line.c
SRCS += $(addprefix $(DIR_SRCS)/gnl/, $(GNL))

MAP=	ft_mapget_lst.c
SRCS += $(addprefix $(DIR_SRCS)/map/, $(MAP))

OBJS = $(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

DIRS_OBJS= mem str lst is conv put btree printf gnl map

all: $(NAME)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

$(DIRS_OBJS): $(DIR_OBJS)
	@mkdir -p $(DIR_OBJS)/$@

$(OBJS): $(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@gcc -Wall -Wextra -Werror -Iincludes -c $< -o $@

$(NAME): $(DIRS_OBJS) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) done!"

clean:
	@rm -rf $(DIR_OBJS)
	@echo "objects deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
