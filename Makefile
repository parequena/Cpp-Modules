.PHONY: all release cls info

CXX := g++-12
COMMON_WARN := -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
CXX_FLAGS := -std=c++20

ifeq ($(word 1, $(subst ++, ,$(CXX))), g)
CXX_FLAGS += -fmodules-ts $(COMMON_WARN) -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast
else # clang
CXX_FLAGS += $(COMMON_WARN) -Weverything -Wno-c++98-compat # Modules support?
endif

ifdef REL
	CXX_FLAGS += -O3
else
	CXX_FLAGS += -g
endif

BUILD_DIR := build/
OBJ_DIR   := $(BUILD_DIR)obj/

DEBUG_FLAGS := -g -fsanitize=address,leak

all: $(OBJ_DIR)
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Point2D.cpp -o $(OBJ_DIR)Point2D.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Line_calc.cpp -o $(OBJ_DIR)Line_calc.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Line.cpp -o $(OBJ_DIR)Line.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Math/Vect2D.cpp -o $(OBJ_DIR)Math_Vect2D.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Math/Vect3D.cpp -o $(OBJ_DIR)Math_Vect3D.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Math/Math.cpp -o $(OBJ_DIR)Math_Math.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Render/Component.cpp -o $(OBJ_DIR)Render_Component.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) -c src/Render/System.cpp -o $(OBJ_DIR)Render_System.o
	$(CXX) $(DEBUG_FLAGS) $(CXX_FLAGS) main.cpp $(OBJ_DIR)*.o -o build/exe

release: $(OBJ_DIR)
	$(CXX) -O3 $(CXX_FLAGS) -c src/Point2D.cpp -o $(OBJ_DIR)Point2D.o
	$(CXX) -O3 $(CXX_FLAGS) -c src/Line_calc.cpp -o $(OBJ_DIR)Line_calc.o
	$(CXX) -O3 $(CXX_FLAGS) -c src/Line.cpp -o $(OBJ_DIR)Line.o
	$(CXX) -O3 $(CXX_FLAGS) -c src/Math/Vect2D.cpp -o $(OBJ_DIR)Math_Vect2D.o
	$(CXX) -O3 $(CXX_FLAGS) -c src/Math/Vect3D.cpp -o $(OBJ_DIR)Math_Vect3D.o
	$(CXX) -O3 $(CXX_FLAGS) -c src/Math/Math.cpp -o $(OBJ_DIR)Math_Math.o
	$(CXX) -O3 $(CXX_FLAGS) main.cpp $(OBJ_DIR)*.o -o build/exe
	rm -fr build/obj/

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

cls:
	rm -fr build/
	rm -fr gcm.cache