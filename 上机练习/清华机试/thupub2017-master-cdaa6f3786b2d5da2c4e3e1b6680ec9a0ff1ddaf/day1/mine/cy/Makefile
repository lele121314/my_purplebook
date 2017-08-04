
COMMON_DIR = ../../interview/cy/common.dir
CXX_FLAGS = -Wall -I$(COMMON_DIR)

default: std.exe val.exe

std.exe: std/mine.cpp $(COMMON_DIR)/common.h $(COMMON_DIR)/common.cpp
	g++ $< $(COMMON_DIR)/common.cpp -o $@ $(CXX_FLAGS)

val.exe: val/val.cpp $(COMMON_DIR)/common.h $(COMMON_DIR)/common.cpp
	g++ $< $(COMMON_DIR)/common.cpp -o $@ $(CXX_FLAGS)

run: std.exe
	./std.exe

val: val.exe std.exe
	python val/main.py