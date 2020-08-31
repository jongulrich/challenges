all: $(patsubst %.cpp, %.bin, $(wildcard *.cpp))

CPPFLAGS := 

%.bin: %.cpp Makefile
	g++ $< $(CPPFLAGS) -o $@ 
	
clean:
	rm *.o; rm *.bin
