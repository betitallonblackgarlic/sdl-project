export CXX := g++-11
CWD := $(PWD)

export CXXFLAGS := `sdl2-config --cflags --libs` -g --std=c++17 -Wall -Werror
LDFLAGS := 

LIBS := 	`sdl2-config --libs` \
					# -lSDL2_image \
					# -lSDL2_ttf \
					# -lSDL2_mixer \
					
SRC := src

export OUT := linuxmain
export OBJOUT := '$(CWD)/objs'

all :
	@ mkdir -p /$(OBJOUT)
	$(MAKE) -C $(SRC)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(OBJOUT)/*.o -o $(OUT) $(LIBS)

.PHONY : run
run :
	./$(OUT)


.PHONY : clean
clean :
	rm -f $(OUT)
	rm -rf $(OBJOUT)