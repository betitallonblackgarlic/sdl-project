$(OUT).o : $(OUT).cpp
	$(MAKE) -C window
	$(MAKE) -C game
	$(MAKE) -C input
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
