TARGET = tracer

SRC_DIR = src

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Done building target '$@'"

# test
TEST_TARGET = tester
TEST_SRC_DIR = test
TEST_SRCS = $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

$(TEST_TARGET): $(TEST_OBJS) $(filter-out $(SRC_DIR)/main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Done building tester"

.PHONY: clean
clean:
	@rm -f $(TARGET) $(OBJS)
	@rm -f $(TEST_TARGET) $(TEST_OBJS)
	@echo "done cleaning up"

.PHONY: test_build
test_build: $(TEST_TARGET)

.PHONY: test
test: test_build
	@./$(TEST_TARGET)
