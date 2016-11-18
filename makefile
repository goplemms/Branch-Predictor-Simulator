predictors: predictors.o parse.o memory.o onebitmemory.o twobitmemory.o gshare.o tournamentpredictor.o
	g++ predictors.o parse.o memory.o onebitmemory.o twobitmemory.o gshare.o tournamentpredictor.o -o predictors
predictors.o: predictors.cpp
	g++ -c predictors.cpp
parse.o: parse.cpp
	g++ -c parse.cpp
memory.o: memory.cpp
	g++ -c memory.cpp
onebitmemory.o: onebitmemory.cpp
	g++ -c onebitmemory.cpp
twobitmemory.o: twobitmemory.cpp
	g++ -c twobitmemory.cpp
gshare.o: gshare.cpp
	g++ -c gshare.cpp
tournamentpredictor.o: tournamentpredictor.hpp
	g++ -c tournamentpredictor.cpp
clean:
	rm *.o predictors
test:
	make	
	./predictors short_trace1.txt short_trace1-test.txt
	diff short_trace1-output.txt short_trace1-test.txt
	./predictors short_trace2.txt short_trace2-test.txt
	diff short_trace2-output.txt short_trace2-test.txt
	./predictors short_trace3.txt short_trace3-test.txt
	diff short_trace3-output.txt short_trace3-test.txt	
	./predictors long_trace1.txt long_trace1-test.txt
	diff long_trace1-output.txt long_trace1-test.txt
	./predictors long_trace2.txt long_trace2-test.txt
	diff long_trace2-output.txt long_trace2-test.txt
	./predictors long_trace3.txt long_trace3-test.txt
	diff long_trace3-output.txt long_trace3-test.txt
