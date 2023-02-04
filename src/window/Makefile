OBJS := window_s.o

all : $(OBJS)

%.o : %.cpp %.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
