UNAME=$(shell uname -s)

CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

ifeq ($(UNAME), Darwin)
	LDFLAGS=
	CPPFLAGS=-arch x86_64 -DBIND_8_COMPAT=1
	LDLIBS=-lresolv
endif

SRCS=main.cpp Point.cpp JSONObject.cpp Frame.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	g++ $(LDFLAGS) -o dejong $(OBJS) $(LDLIBS)

main.o: main.cpp

Point.o: Point.h Point.cpp

JSONObject.o: JSONObject.h JSONObject.cpp

Frame.o: Frame.h Frame.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) main

