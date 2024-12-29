NAME=a.exe
CC=c++
CC_FLAGS=-Wall -Werror -Wextra -std=c++17
RM=rm -f

SOURCE=1052.cpp  
OBJECT=$(SOURCE:.cpp=.o)

$(NAME): $(OBJECT)    
	$(CC) $(CC_FLAGS) $(OBJECT) -o $(NAME)

%.o: %.cpp   
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)         

all: $(NAME) clean
	./$(NAME) < input.txt > output.txt

re: fclean all 

.PHONY: clean fclean all re
