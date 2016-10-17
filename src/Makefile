CC=g++-5
CFLAGS=-c -std=c++14
LDFLAGS=-pthread -lpthread
SOURCES=main.cpp adjacencylist.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pagerank
BUILD_DIR=./bin

all: $(SOURCES) $(EXECUTABLE)
	
debug: CFLAGS += -DDEBUG -g
debug: $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) copy
	mkdir -p $(BUILD_DIR)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(BUILD_DIR)/$@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm *.o
	rm -rf $(BUILD_DIR)
	
copy:
	mkdir -p $(BUILD_DIR)
	cp -f ./Makefile $(BUILD_DIR)/Makefile
	
check:
	./$(EXECUTABLE) ${ARGS}