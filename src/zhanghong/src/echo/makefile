BASE_NAME=$(shell pwd) 
OBJECTS=$(shell find . -name "*.cc" | sed "s%\./%$(BASE_NAME)%" | sed "s%\.cc%\.o%") 

all:$(OBJECTS) 

.SUFFIXES:.o.cc 
.cc.o: 
	g++ -c $(INCLUDES) $(CFLAGS) $*.cc -o $*.o 
