OBJS := texture_m.o

all : $(OBJS)

%.o : %.cpp %.h
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
