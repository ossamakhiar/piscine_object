NAME = a.out
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) demo.log nonHeader.log

fclean: clean
	rm -rf $(NAME)

re: fclean all
