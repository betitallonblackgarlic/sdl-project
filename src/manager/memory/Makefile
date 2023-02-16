# OBJS := memory_m.o \

HDRS := pool.h \

all : $(OBJS)

%.o : %.cpp %.h $(HDRS)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
