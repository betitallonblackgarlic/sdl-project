$(OUT).o : $(OUT).cpp
	$(MAKE) -C manager
	$(MAKE) -C window
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
