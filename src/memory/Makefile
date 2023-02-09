OBJS := memory_m.o \
		alloc.o

TMPL := stack_alloc.h \
		pool_alloc.h

all : $(OBJS)

%.o : %.cpp %.h $(TMPL)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $(OBJOUT)/$@
