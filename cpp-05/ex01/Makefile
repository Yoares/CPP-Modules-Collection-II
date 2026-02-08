NAME = Form

CC = c++ 

fLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(fLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(fLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re