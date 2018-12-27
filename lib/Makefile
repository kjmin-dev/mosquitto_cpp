include ../config.mk

CC = g++

.PHONY : really clean install

MOSQ_OBJS=mosquitto.o \
		  actions.o \
		  callbacks.o \
		  connect.o \
		  handle_connack.o \
		  handle_ping.o \
		  handle_pubackcomp.o \
		  handle_publish.o \
		  handle_pubrec.o \
		  handle_pubrel.o \
		  handle_suback.o \
		  handle_unsuback.o \
		  helpers.o \
		  logging_mosq.o \
		  loop.o \
		  memory_mosq.o \
		  messages_mosq.o \
		  net_mosq.o \
		  options.o \
		  packet_mosq.o \
		  read_handle.o \
		  send_connect.o \
		  send_disconnect.o \
		  send_mosq.o \
		  send_publish.o \
		  send_subscribe.o \
		  send_unsubscribe.o \
		  socks_mosq.o \
		  srv_mosq.o \
		  thread_mosq.o \
		  time_mosq.o \
		  tls_mosq.o \
		  utf8_mosq.o \
		  util_mosq.o \
		  will_mosq.o

ALL_DEPS=libmosquitto.so.${SOVERSION}

ifeq ($(WITH_STATIC_LIBRARIES),yes)
	ALL_DEPS+=libmosquitto.a
endif

all : ${ALL_DEPS}
	$(MAKE) -C cpp

install : all
	$(INSTALL) -d "${DESTDIR}${libdir}/"
	$(INSTALL) ${STRIP_OPTS} libmosquitto.so.${SOVERSION} "${DESTDIR}${libdir}/libmosquitto.so.${SOVERSION}"
	ln -sf libmosquitto.so.${SOVERSION} "${DESTDIR}${libdir}/libmosquitto.so"
ifeq ($(WITH_STATIC_LIBRARIES),yes)
	$(INSTALL) ${STRIP_OPTS} libmosquitto.a "${DESTDIR}${libdir}/libmosquitto.a"
endif
	$(INSTALL) -d "${DESTDIR}${incdir}/"
	$(INSTALL) mosquitto.h "${DESTDIR}${incdir}/mosquitto.h"
	$(INSTALL) -d "${DESTDIR}${libdir}/pkgconfig"
	$(INSTALL) -m644 ../libmosquitto.pc.in "${DESTDIR}${libdir}/pkgconfig/libmosquitto.pc"
	sed -i -e "s#@CMAKE_INSTALL_PREFIX@#${prefix}#" -e "s#@VERSION@#${VERSION}#" "${DESTDIR}${libdir}/pkgconfig/libmosquitto.pc"
	$(MAKE) -C cpp install

uninstall :
	-rm -f "${DESTDIR}${libdir}/libmosquitto.so.${SOVERSION}"
	-rm -f "${DESTDIR}${libdir}/libmosquitto.so"
	-rm -f "${DESTDIR}${libdir}/libmosquitto.a"
	-rm -f "${DESTDIR}${incdir}/mosquitto.h"

reallyclean : clean

clean :
	-rm -f *.o libmosquitto.so.${SOVERSION} libmosquitto.so libmosquitto.a
	$(MAKE) -C cpp clean

libmosquitto.so.${SOVERSION} : ${MOSQ_OBJS}
	${CROSS_COMPILE}$(CC) -shared $(LIB_LDFLAGS) $^ -o $@ ${LIB_LIBS}

libmosquitto.a : ${MOSQ_OBJS}
	${CROSS_COMPILE}$(AR) cr $@ $^

mosquitto.o : mosquitto.cpp mosquitto.h mosquitto_internal.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

actions.o : actions.cpp mosquitto.h mosquitto_internal.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

callbacks.o : callbacks.cpp mosquitto.h mosquitto_internal.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

connect.o : connect.cpp mosquitto.h mosquitto_internal.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_connack.o : handle_connack.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_publish.o : handle_publish.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_ping.o : handle_ping.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_pubackcomp.o : handle_pubackcomp.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_pubrec.o : handle_pubrec.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_pubrel.o : handle_pubrel.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_suback.o : handle_suback.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

handle_unsuback.o : handle_unsuback.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

helpers.o : helpers.cpp
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

logging_mosq.o : logging_mosq.cpp logging_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

loop.o : loop.cpp mosquitto.h mosquitto_internal.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

messages_mosq.o : messages_mosq.cpp messages_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

memory_mosq.o : memory_mosq.cpp memory_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

net_mosq.o : net_mosq.cpp net_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

options.o : options.cpp mosquitto.h mosquitto_internal.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

packet_mosq.o : packet_mosq.cpp packet_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

read_handle.o : read_handle.cpp read_handle.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

send_connect.o : send_connect.cpp send_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

send_disconnect.o : send_disconnect.cpp send_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

send_mosq.o : send_mosq.cpp send_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

send_publish.o : send_publish.cpp send_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

send_subscribe.o : send_subscribe.cpp send_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

send_unsubscribe.o : send_unsubscribe.cpp send_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

socks_mosq.o : socks_mosq.cpp
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

srv_mosq.o : srv_mosq.cpp
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

thread_mosq.o : thread_mosq.cpp
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

time_mosq.o : time_mosq.cpp
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

tls_mosq.o : tls_mosq.cpp
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

utf8_mosq.o : utf8_mosq.cpp
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

util_mosq.o : util_mosq.cpp util_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

will_mosq.o : will_mosq.cpp will_mosq.h
	${CROSS_COMPILE}$(CC) $(LIB_CFLAGS) -c $< -o $@

