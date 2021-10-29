NAME = test

SOURCES = sources/point_within_triangle.c sources/test_point_within_triangle.c

all: $(NAME)

$(NAME):
	@ccache gcc $(SOURCES) -I headers/ -o $(NAME) -lm

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
