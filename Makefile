DEPS= farm
compile: farm.cpp 
	 g++ farm.cpp -o $(DEPS)

run: $(DEPS)
	 ./$(DEPS)

clean: $(DEPS)
	 rm $(DEPS)
