BUILD = release
PROGECT_NAME = square_equation_solver.exe

CC=g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
-Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe \
-fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
-Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual \
-Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
-Wwrite-strings -Werror=vla -D_EJUDGE_CLIENT_SIDE 

ifeq ($(BUILD),debug)
	CFLAGS += -D_DEBUG
endif

SOURCES = main.cpp equation_data.cpp equation_tests.cpp equation_data.h equation_tests.h
OBJECTS = $(SOURCES:.c=.o)
TARGET = square_equation_solver.exe

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

release:
	$(MAKE) BUILD=release

debug:
	$(MAKE) BUILD=debug

clean:
	rm *.o *.exe 2>nul || exit 0

.PHONY: clean

