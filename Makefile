# Makefile for gameof1d
#
# Part of assignment 3 for 2024 PHY1610
#
CXX=g++
CXXFLAGS=-O3 -march=native
OBJS=gameof1d.o fillcells.o updatecells.o outputcells.o

all: gameof1d originalgameof1d test_init test_output test_update run_test_init run_test_output run_test_update

integrated_test: originaltestoutput.txt testoutput.txt
	diff originaltestoutput.txt testoutput.txt

originaltestoutput.txt: originalgameof1d
	./originalgameof1d > originaltestoutput.txt

testoutput.txt: gameof1d
	./gameof1d > testoutput.txt

originalgameof1d: originalgameof1d.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

gameof1d: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

gameof1d.o: gameof1d.cpp fillcells.h updatecells.h outputcells.h celltype.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $< 

fillcells.o: fillcells.cpp fillcells.h celltype.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

updatecells.o: updatecells.cpp updatecells.h celltype.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

outputcells.o: outputcells.cpp outputcells.h celltype.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

test_init.o: test_init.cpp fillcells.h celltype.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

test_init: test_init.o fillcells.o	
	$(CXX) $^ -o $@ -lCatch2Main -lCatch2

test_output.o: test_output.cpp outputcells.h celltype.h 

test_output: test_output.o outputcells.o
	$(CXX) $^ -o $@ -lCatch2Main -lCatch2

test_update.o: test_update.cpp updatecells.h celltype.h 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

test_update: test_update.o updatecells.o
	$(CXX) $^ -o $@ -lCatch2Main -lCatch2

run_test_init: test_init
	./test_init -s

run_test_output: test_output
	./test_output -s

run_test_update: test_update
	./test_update -s

run: gameof1d
	./gameof1d

clean:
	$(RM) $(OBJS)
