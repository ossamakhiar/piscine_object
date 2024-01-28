NAME = a.out
SRCS = $(wildcard *.cpp pngWriter/*.cpp)
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
OBJDIR=obj
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(dir $(OBJS))

$(OBJDIR)/%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
