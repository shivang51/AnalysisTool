CXX = clang++
CXX_VERSION = c++20

NAME = libanalysistool

INCLUDE = -Iinclude/ -Iinclude/parsers
SRC_DIR = src

INTERMEDIATE_DIR = ./out/obj/

TARGET_DIR = ../out/
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_FILES += $(wildcard $(SRC_DIR)/**/*.cpp)

TARGET = $(TARGET_DIR)$(NAME).a

OBJECTS = $(patsubst %.cpp,$(INTERMEDIATE_DIR)%.o,$(SRC_FILES))

$(NAME): $(TARGET)

$(TARGET): $(OBJECTS) | $(TARGET_DIR)
	ar rc $@ $(OBJECTS)

$(INTERMEDIATE_DIR)%.o: %.cpp | $(INTERMEDIATE_DIR)
	mkdir -p $(@D)
	$(CXX) -std=$(CXX_VERSION) $(INCLUDE) -c $< -o $@

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

$(INTERMEDIATE_DIR):
	mkdir -p $(@D)
