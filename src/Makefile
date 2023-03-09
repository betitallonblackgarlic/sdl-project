$(OUT).o : $(OUT).cpp
	$(MAKE) -C window
	$(MAKE) -C game
	$(MAKE) -C input
	$(MAKE) -C render
	# $(MAKE) -C manager
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
