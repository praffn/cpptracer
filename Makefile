TARGET = tracer

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CC = g++
CFLAGS = -std=c++11 -Wall -I$(INC_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(TARGET): $(OBJS)
	@echo "🚧 Building target '$@'"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "✅ Done building target '$@'"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\t🚧 Building object '$@'"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "\t✅ Done building object '$@'"

# test
T_TARGET = test_runner
T_SRC_DIR = test
T_OBJ_DIR = test_obj
T_SRCS = $(wildcard $(T_SRC_DIR)/*.cpp)
T_OBJS = $(T_SRCS:$(T_SRC_DIR)/%.cpp=$(T_OBJ_DIR)/%.o)

$(T_TARGET): $(T_OBJS) $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
	@echo "🚧 Building target '$@'"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "✅ Done building target '$@'"

$(T_OBJ_DIR)/%.o: $(T_SRC_DIR)/%.cpp
	@echo "\t🚧 Building object '$@'"
	@mkdir -p $(T_OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "\t✅ Done building object '$@'"



.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(TARGET)
	@rm -rf $(T_OBJ_DIR)
	@rm -f $(T_TARGET)
	@echo "done cleaning up"

.PHONY: test
test: $(T_TARGET)

.PHONY: run_test
run_test: test
	./$(T_TARGET)
