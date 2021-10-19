NAME = pokerHandRanking

SOURCES = sources/main.cpp sources/PokerHand.cpp

all: $(NAME)

$(NAME):
	@ccache g++ $(SOURCES) -I headers/ -o $(NAME)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
