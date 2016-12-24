CC = g++-4.9 --std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LIBS = -lcurl 

SRC_DIR = src
BIN_DIR = bin
INCL_DIR = include
OBJ_DIR = obj

EXECUTABLE = $(BIN_DIR)/summon
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/connector.o $(OBJ_DIR)/summoner_settings.o $(OBJ_DIR)/summoner_user.o $(OBJ_DIR)/summoner_workstation.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXECUTABLE) $(LIBS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCL_DIR)/connector.h $(INCL_DIR)/summoner.h
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJD_DIR)/summoner.o: $(SRC_DIR)/summoner.cpp $(INCL_DIR)/summoner.h $(INCL_DIR)/summoner_settings.h $(INCL_DIR)/summoner_user.h $(INCL_DIR)/summoner_workstation.h
	$(CC) $(CFLAGS) $(SRC_DIR)/summoner.cpp -o $(OBJ_DIR)/summoner.o

$(OBJ_DIR)/connector.o: $(SRC_DIR)/connector.cpp $(INCL_DIR)/connector.h $(INCL_DIR)/json.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/connector.cpp -o $(OBJ_DIR)/connector.o

$(OBJ_DIR)/summoner_settings.o: $(SRC_DIR)/summoner_settings.cpp $(INCL_DIR)/summoner_settings.h
	$(CC) $(CFLAGS) $(SRC_DIR)/summoner_settings.cpp -o $(OBJ_DIR)/summoner_settings.o

$(OBJ_DIR)/summoner_user.o: $(SRC_DIR)/summoner_user.cpp $(INCL_DIR)/summoner_user.h
	$(CC) $(CFLAGS) $(SRC_DIR)/summoner_user.cpp -o $(OBJ_DIR)/summoner_user.o

$(OBJ_DIR)/summoner_workstation.o: $(SRC_DIR)/summoner_workstation.cpp $(INCL_DIR)/summoner_workstation.h
	$(CC) $(CFLAGS) $(SRC_DIR)/summoner_workstation.cpp -o $(OBJ_DIR)/summoner_workstation.o
