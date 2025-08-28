FLAGS ?=  -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef \
-Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
-Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ \
-Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
-Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
-Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
-Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
-Wwrite-strings -Werror=vla -D _DEBUG -D _EJUDGE_CLIENT_SIDE

all: square_solver

square_solver: main.o input.o output.o square_solver.o  test.o
	g++ main.o input.o output.o square_solver.o  test.o -o square_solver.exe

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

input.o: input.cpp
	g++ $(FLAGS) -c input.cpp

output.o: output.cpp
	g++ $(FLAGS) -c output.cpp

test.o: test.cpp
	g++ $(FLAGS) -c test.cpp

clean:
	rm *.o

