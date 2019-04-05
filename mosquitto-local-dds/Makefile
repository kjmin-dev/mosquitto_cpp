include ../config.mk

#CC = g++
#CFLAGS += -Wno-sign-compare

.PHONY: all
SOVERSION=1

all : dds_mosquitto_sub

dds_mosquitto_sub : dds_mosquitto_sub.o
	${CROSS_COMPILE}${CC} $^ -o $@ ../lib/libmosquitto.so.${SOVERSION}

dds_mosquitto_sub.o : main.c ../lib/libmosquitto.so.${SOVERSION} 
	${CROSS_COMPILE}${CC} -c $< -o $@ -I../lib ${CFLAGS}

../lib/libmosquitto.so.${SOVERSION} :
	$(MAKE) -C ../lib

clean : 
	-rm -f *.o dds_mosquitto_sub
