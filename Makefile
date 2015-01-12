.PHONY: CXX clean
CXX=g++ -std=c++11


lextest: driver.o lex.yy.o errormsg.o 
	$(CXX) -g -o lextest driver.o lex.yy.o errormsg.o 

driver.o: driver.cc tokens.h errormsg.h util.h
	$(CXX) -g -c driver.cc

errormsg.o: errormsg.cc errormsg.h util.h
	$(CXX) -g -c errormsg.cc

lex.yy.o: lex.yy.cc tokens.h errormsg.h util.h
	$(CXX) -g -c lex.yy.cc

lex.yy.cc: tiger.lex
	flex++ tiger.lex

util.o: util.cc util.h
	$(CXX) -g -c util.cc

clean: 
	rm -f a.out util.o driver.o lex.yy.o lex.yy.cc errormsg.o lextest
