.SUFFIXES:
.SUFFIXES: .o .cpp
#============================================================
TARGET1 = conv2d
C_OBJS1 = conv2d.o

TARGET2 = timing
C_OBJS2 = timing.o


ALL_SOURCES = Makefile $(C_SOURCES) $(MY_INCLUDES)

DATA_FILES =

CCX = g++
CXXFLAGS = -g -Wall
#-std=c99
#============================================================
conv2d: $(TARGET1)
timing: $(TARGET2)
all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

.o:.cpp	$(MY_INCLUDES)
	$(CCX)  -c  $(CXXFLAGS) $<  

$(TARGET1) :   $(C_OBJS1)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@
$(TARGET2) :   $(C_OBJS2)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@ 
$(TARGET3) :   $(C_OBJS3)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@ 
	
$(TARGET4) :   $(C_OBJS4)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@ 

$(TARGET5) :   $(C_OBJS5)
	$(CCX) $(CXXFLAGS)  $^ $(LIBDIRS)  -o $@ 



# Implicit rules: $@ = target name, $< = first prerequisite name, $^ = name of all prerequisites
#============================================================


clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(C_OBJS1) $(C_OBJS2) $(C_OBJS3) $(C_OBJS4) $(C_OBJS5) *~

tar: $(ALL_SOURCES) $(DATA_FILES)
	tar cvf HW4_code.tar $(ALL_SOURCES)  $(DATA_FILES)



