HDRS := components/input_c.h \
		components/texture_c.h \

$(OUT).o : $(OUT).cpp $(HDRS)
	$(MAKE) -C window
	$(MAKE) -C render
	$(MAKE) -C input
	$(MAKE) -C texture
	$(MAKE) -C memory
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
