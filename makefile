CC=g++
CFLAGS= -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat\
	    -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion\
	    -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness\
	    -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked\
		-Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel\
		-Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override\
		-Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros\
		-Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector\
		-fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer\
		-Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla 
		-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

GRAPHICS_SRC_DIR = ./source/Graphics/
GRAPHICS_OBJ_DIR = ./object/Graphics/

MATH_TOOLS_SRC_DIR = ./source/MathTools/
MATH_TOOLS_OBJ_DIR = ./object/MathTools/

MAIN_SRC = ./source/main.cpp
MAIN_OBJ = ./object/main.o

VIEW_SRC_DIR = ./source/View/
VIEW_OBJ_DIR = ./object/View/

CONTROL_SRC_DIR = ./source/Controller/
CONTROL_OBJ_DIR = ./object/Controller/

GRAPHICS_SRC = $(wildcard $(GRAPHICS_SRC_DIR)*.cpp)
GRAPHICS_OBJ = $(patsubst $(GRAPHICS_SRC_DIR)%.cpp, $(GRAPHICS_OBJ_DIR)%.o, $(GRAPHICS_SRC))

MATH_TOOLS_SRC = $(wildcard $(MATH_TOOLS_SRC_DIR)*.cpp)
MATH_TOOLS_OBJ = $(patsubst $(MATH_TOOLS_SRC_DIR)%.cpp, $(MATH_TOOLS_OBJ_DIR)%.o, $(MATH_TOOLS_SRC))

VIEW_SRC = $(wildcard $(VIEW_SRC_DIR)*.cpp)
VIEW_OBJ = $(patsubst $(VIEW_SRC_DIR)%.cpp, $(VIEW_OBJ_DIR)%.o, $(VIEW_SRC))

CONTROL_SRC = $(wildcard $(CONTROL_SRC_DIR)*.cpp)
CONTROL_OBJ = $(patsubst $(CONTROL_SRC_DIR)%.cpp, $(CONTROL_OBJ_DIR)%.o, $(CONTROL_SRC))

all: link

link: $(GRAPHICS_OBJ) $(VIEW_OBJ) $(MATH_TOOLS_OBJ) $(MAIN_OBJ) $(CONTROL_OBJ)
	$(CC) $(MAIN_OBJ) $(GRAPHICS_OBJ) $(VIEW_OBJ) $(MATH_TOOLS_OBJ) $(CONTROL_OBJ) -o gas_model.out -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

$(GRAPHICS_OBJ_DIR)%.o : $(GRAPHICS_SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(MATH_TOOLS_OBJ_DIR)%.o : $(MATH_TOOLS_SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(VIEW_OBJ_DIR)%.o : $(VIEW_SRC_DIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ) : $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(CONTROL_OBJ) : $(CONTROL_SRC)
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm $(GRAPHICS_OBJ) $(MATH_TOOLS_OBJ) $(VIEW_OBJ) $(MAIN_OBJ) $(CONTROL_OBJ)