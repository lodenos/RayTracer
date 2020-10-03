CXX = clang++

FLAGS = -Wall -Werror -Wextra -Weverything -std=gnu++2a -Wno-reserved-id-macro \
	-Wno-padded -Wno-c++98-compat

INCLUDE = -I ./inc -I ./SDL2-2.0.12/include

LIBRARY = -L ./SDL2-2.0.12/build -lSDL2 -pthread -Ofast

NAME = raytracer

OBJ = $(sort $(addsuffix .o, $(basename $(SRC))))

SRC = \
  $(wildcard ./src/*.cpp)

all: $(NAME)

################################################################################
### Create Executable
################################################################################

$(NAME): $(OBJ)
	@printf "Compiling " $(NAME)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ) $(LIBRARY)

################################################################################
### Compiling Source
################################################################################

$(OBJ): %.o: $(basename $@)%.cpp
	$(CXX) $(FLAGS) -c $(INCLUDE) $< -o $@
	@$(call _GREEN, $(addsuffix .cpp, $(basename $@)))

###############################################################################
### Clean all obj
###############################################################################

clean:
	@rm -f $(OBJ)
	@$(call _GREEN, "ok")

###############################################################################
### Clean all
###############################################################################

fclean: clean
	@rm -f $(NAME)
	@rm -rf libuWS.dylib
	@$(call _GREEN, "ok")

###############################################################################
### Clean all && re-build
###############################################################################

re: fclean all
	@$(call _GREEN, "ok")
