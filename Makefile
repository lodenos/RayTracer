CXX = clang++

FLAGS = -Wall -Werror -Wextra -Weverything -std=gnu++2a -Wno-reserved-id-macro \
	-Wno-padded -Wno-c++98-compat

INCLUDE = -I ./inc -I ./SDL2-2.0.12/include

LIBRARY = -L ./SDL2-2.0.12/build -lSDL2 -pthread -O4

NAME = raytracer

OBJ = $(sort $(addsuffix .o, $(basename $(SRC))))

SRC = \
  $(wildcard ./src/*.cpp) \
  $(wildcard ./src/Camera/*.cpp) \
  $(wildcard ./src/Event/*.cpp) \
  $(wildcard ./src/Object/*.cpp) \
  $(wildcard ./src/Vector/*.cpp) \
  $(wildcard ./src/Window/*.cpp)

all: $(NAME)

################################################################################
### Create Executable
################################################################################

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ) $(LIBRARY)

################################################################################
### Compiling Source
################################################################################

$(OBJ): %.o: $(basename $@)%.cpp
	$(CXX) $(FLAGS) -c $(INCLUDE) $< -o $@

###############################################################################
### Clean all obj
###############################################################################

clean:
	@rm -f $(OBJ)

###############################################################################
### Clean all
###############################################################################

fclean: clean
	@rm -f $(NAME)

###############################################################################
### Clean all && re-build
###############################################################################

re: fclean all
