RM  = rm 
CXX = c++

RMFLAGS  = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DEPS = ./Data.hpp ./Serializer.hpp 
SRCS = ./Data.cpp ./Serializer.cpp ./main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = run 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@  -I ./

%.o : %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

.PHONY : re fclean clean all 
