CC=g++
CFLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
       -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs \
       -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions\
	   -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security\
	   -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor\
	   -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing\
	   -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla\
	   -D_DEBUG -O2

GRAPHICS_SRC_DIR = ./source/Graphics/
GRAPHICS_OBJ_DIR = ./object/Graphics/

MATH_TOOLS_SRC_DIR = ./source/MathTools/
MATH_TOOLS_OBJ_DIR = ./object/MathTools/

MAIN_SRC = ./source/main.cpp
MAIN_OBJ = ./object/main.o

VIEW_SRC_DIR = ./source/View/
VIEW_OBJ_DIR = ./object/View/

GRAPHICS_SRC = $(wildcard $(GRAPHICS_SRC_DIR)*.cpp)
GRAPHICS_OBJ = $(patsubst $(GRAPHICS_SRC_DIR)%.cpp, $(GRAPHICS_OBJ_DIR)%.o, $(GRAPHICS_SRC))

MATH_TOOLS_SRC = $(wildcard $(MATH_TOOLS_SRC_DIR)*.cpp)
MATH_TOOLS_OBJ = $(patsubst $(MATH_TOOLS_SRC_DIR)%.cpp, $(MATH_TOOLS_OBJ_DIR)%.o, $(MATH_TOOLS_SRC))

VIEW_SRC = $(wildcard $(VIEW_SRC_DIR)*.cpp)
VIEW_OBJ = $(patsubst $(VIEW_SRC_DIR)%.cpp, $(VIEW_OBJ_DIR)%.o, $(VIEW_SRC))

all: link

link: $(GRAPHICS_OBJ) $(VIEW_OBJ) $(MATH_TOOLS_OBJ) ./object/main.o
	$(CC) ./object/main.o $(GRAPHICS_OBJ) $(VIEW_OBJ) $(MATH_TOOLS_OBJ) -o gas_model.out -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

$(GRAPHICS_OBJ_DIR)%.o : $(GRAPHICS_SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(MATH_TOOLS_OBJ_DIR)%.o : $(MATH_TOOLS_SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(VIEW_OBJ_DIR)%.o : $(VIEW_SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ) : $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(GRAPHICS_OBJ) $(MATH_TOOLS_OBJ) $(VIEW_OBJ) $(MAIN_OBJ)