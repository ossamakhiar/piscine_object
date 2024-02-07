NAME = a.out
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o:%.cpp
	$(CPP)  -c $< -o $@

$(NAME): $(OBJS)
	$(CPP)  $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
