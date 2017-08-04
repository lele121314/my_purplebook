
COMMON_DIR = ../cy/common.dir
CXX_FLAG = -Wall -I$(COMMON_DIR)

default: random1.exe random2.exe

random1.exe: random1.cpp $(COMMON_DIR)/common.cpp $(COMMON_DIR)/common.h
	g++ random1.cpp $(COMMON_DIR)/common.cpp -o $@ $(CXX_FLAG)

random2.exe: random2.cpp $(COMMON_DIR)/common.cpp $(COMMON_DIR)/common.h
	g++ random2.cpp $(COMMON_DIR)/common.cpp -o $@ $(CXX_FLAG)

run: random1.exe random2.exe
	python main.py