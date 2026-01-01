RM  = rm 
CXX = c++

RMFLAGS  = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DEPS = AType.hpp DoubleType.hpp IntType.hpp FloatType.hpp CharType.hpp Printer.hpp ScalarConverter.cpp 
SRCS = AType.cpp DoubleType.cpp IntType.cpp FloatType.cpp CharType.cpp Printer.cpp ScalarConverter.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = run 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c  $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME) 

re : fclean all 

.PHONY : re fclean clean all  
