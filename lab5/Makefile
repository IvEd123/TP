TARGET = Lab5
DEBUG = -g
CC = g++

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))



$(TARGET)) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	$(CC) -c $(DEBUG) $< -o $@

clean :
	rm $(PREF_OBJ)*.o