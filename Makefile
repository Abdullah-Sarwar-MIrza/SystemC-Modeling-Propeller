SYSTEMC = D:/UAV LAB JOB/Systemc/systemc-3.0.2
SYSTEMCAMS = D:/UAV LAB JOB/Systemc/systemc-ams-2.3.4

CXX ?= g++.exe

CXXFLAGS += -g3 -Wall -Wextra -Wno-unused-parameter -Wno-ignored-qualifiers -Wno-deprecated-copy -std=c++17
INCLUDES = -I$(SYSTEMC)/src -isystem$(SYSTEMCAMS)/src
LIBDIRS = -L$(SYSTEMC)/build/src -L$(SYSTEMCAMS)/build/src
LIBS = -lsystemc-ams -lsystemc -lm

SRCS = \
	sc_main.cpp \
	Motor_module.cpp \
	PID_controller_module.cpp \
	hall_sensor.cpp \
	boom_system.cpp \
	reference_model.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = sc_main.exe

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LIBDIRS) $(LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET)
	.\$(TARGET)

clean:
ifeq ($(OS),Windows_NT)
	-cmd /C del /F /Q $(OBJS) $(TARGET) >NUL 2>NUL
else
	-rm -f $(OBJS) $(TARGET)
endif
