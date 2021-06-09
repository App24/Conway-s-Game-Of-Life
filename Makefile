include .env

CFLAGS = -std=c++17 -I. -I$(SFML_INCLUDE_PATH) -g -DSFML_STATIC
LDFLAGS = -L$(SFML_LIB_PATH) -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lopengl32 -lfreetype -lwinmm -lgdi32

TARGET_NAME=GOL

BUILD_DIR=obj
OUT_DIR=bin
SRC_DIR=src

TARGET_WINDOWS=$(OUT_DIR)/$(TARGET_NAME).exe
TARGET_LINUX=$(OUT_DIR)/$(TARGET_NAME).out

SRCS = $(shell findd $(SRC_DIR)/ -name "*.cpp")
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

default: $(TARGET_WINDOWS)

.SECONDEXPANSION:

$(OBJS): $$(patsubst $(BUILD_DIR)/%.o, $(SRC_DIR)/%.cpp, $$@)
	"mkdir" -p $(@D)
	g++ $(CFLAGS) -c -o $@ $<

$(TARGET_WINDOWS): $(OBJS)
	"mkdir" -p $(OUT_DIR)
	g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: default

# $(OBJS): build/%.o : src/%.cpp
# 	"mkdir" -p $(dir $@)
# 	g++ $(CFLAGS) $(patsubst build/%.o, src/%.cpp, $@) -o $@ $(LDFLAGS)

# build: $(SRCS)
# 	g++ $(CFLAGS) -o Test.exe $@ $(LDFLAGS)

# build: clean executable

# executable: *.cpp *.h
# 	g++ $(CFLAGS) -o Build/$(TARGET_WINDOWS) *.cpp $(LDFLAGS)
# 	g++ $(CFLAGS) -o Build/$(TARGET_LINUX) *.cpp $(LDFLAGS)

# .PHONY: clean

# clean:
# 	del /f Build\\$(TARGET_WINDOWS) >nul 2>&1
# 	del /f Build\\$(TARGET_LINUX) >nul 2>&1