
NAME	=	libasm.a

SRC		=	ft_read.asm \
			ft_strcmp.asm \
			ft_strcpy.asm \
			ft_write.asm \
			ft_strlen.asm \
			ft_strdup.asm

GREEN	= 	\033[38;5;46m
WHITE	= 	\033[38;5;15m
GREY	= 	\033[38;5;8m
ORANGE	= 	\033[38;5;202m
RED		= 	\033[38;5;160m

SRC_O	=	$(SRC:.asm=.o)

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@echo "$(GREEN)Creating libasm.a$(WHITE)"
	@ar rc $(NAME) $(SRC_O)

%.o: %.asm
	@echo "$(GREY)Compilling: $(WHITE)$<"
	@nasm -fmacho64 -o $@ $<

clean:
	@echo "$(RED)Cleaning all .asm files$(WHITE)"
	@rm -f $(SRC_O)

fclean: clean
	@echo "$(RED)cleaning all .a files$(WHITE)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
