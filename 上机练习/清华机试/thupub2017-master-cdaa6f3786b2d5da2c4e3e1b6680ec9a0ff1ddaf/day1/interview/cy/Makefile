
COMMON_DIR = common.dir
CXX_FLAGS = -Wall -I$(COMMON_DIR)

std.exe: std/interview.cpp $(COMMON_DIR)/common.h $(COMMON_DIR)/common.cpp
	g++ $< $(COMMON_DIR)/common.cpp -o $@ $(CXX_FLAGS)

val.exe: val/val.cpp $(COMMON_DIR)/common.h $(COMMON_DIR)/common.cpp
	g++ $< $(COMMON_DIR)/common.cpp -o $@ $(CXX_FLAGS)

run: std.exe
	./std.exe

val: val.exe
	python val/main.py