HDRS := components/input_c.h \
		components/render_c.h \
		components/texture_c.h \
		components/window_c.h

$(OUT).o : $(OUT).cpp $(HDRS)
	$(MAKE) -C window
	$(MAKE) -C renderer
	$(MAKE) -C input
	$(MAKE) -C texture
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
