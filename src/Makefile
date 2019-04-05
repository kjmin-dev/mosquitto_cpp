include ../config.mk

CC = g++

.PHONY: all install uninstall clean reallyclean

ifeq ($(WITH_TLS),yes)
all : mosquitto mosquitto_passwd
else
all : mosquitto
endif

OBJS=	pugixml.o \
	tinyxml2.o \
	mosquitto.o \
		bridge.o \
		conf.o \
		conf_includedir.o \
		context.o \
		database.o \
		handle_connack.o \
		handle_connect.o \
		handle_ping.o \
		handle_pubackcomp.o \
		handle_publish.o \
		handle_pubrec.o \
		handle_pubrel.o \
		handle_suback.o \
		handle_subscribe.o \
		handle_unsuback.o \
		handle_unsubscribe.o \
		logging.o \
		loop.o \
		memory_mosq.o \
		net.o \
		net_mosq.o \
		packet_mosq.o \
		persist.o \
		plugin.o \
		read_handle.o \
		security.o \
		security_default.o \
		send_connack.o \
		send_connect.o \
		send_disconnect.o \
		send_mosq.o \
		send_publish.o \
		send_suback.o \
		send_subscribe.o \
		send_unsubscribe.o \
		service.o \
		signals.o \
		subs.o \
		sys_tree.o \
		time_mosq.o \
		tls_mosq.o \
		utf8_mosq.o \
		util_mosq.o \
		websockets.o \
		will_mosq.o

mosquitto : ${OBJS}
	${CROSS_COMPILE}${CC} $^ -o $@ ${LDFLAGS} $(BROKER_LIBS)

pugixml.o : pugixml.cpp
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@
tinyxml2.o : tinyxml2.cpp
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

mosquitto.o : mosquitto.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

bridge.o : bridge.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

conf.o : conf.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

conf_includedir.o : conf_includedir.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

context.o : context.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

database.o : database.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_connack.o : handle_connack.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_connect.o : handle_connect.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_ping.o : ../lib/handle_ping.cpp ../lib/read_handle.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_pubackcomp.o : ../lib/handle_pubackcomp.cpp ../lib/read_handle.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_publish.o : handle_publish.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_pubrec.o : ../lib/handle_pubrec.cpp ../lib/read_handle.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_pubrel.o : ../lib/handle_pubrel.cpp ../lib/read_handle.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_suback.o : ../lib/handle_suback.cpp ../lib/read_handle.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_subscribe.o : handle_subscribe.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_unsuback.o : ../lib/handle_unsuback.cpp ../lib/read_handle.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

handle_unsubscribe.o : handle_unsubscribe.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

logging.o : logging.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

loop.o : loop.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

memory_mosq.o : ../lib/memory_mosq.cpp ../lib/memory_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

net.o : net.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

net_mosq.o : ../lib/net_mosq.cpp ../lib/net_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

persist.o : persist.cpp persist.h mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

packet_mosq.o : ../lib/packet_mosq.cpp ../lib/packet_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

plugin.o : plugin.cpp mosquitto_plugin.h mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

read_handle.o : read_handle.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

security.o : security.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

security_default.o : security_default.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_connect.o : ../lib/send_connect.cpp ../lib/send_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_disconnect.o : ../lib/send_disconnect.cpp ../lib/send_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_connack.o : send_connack.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_mosq.o : ../lib/send_mosq.cpp ../lib/send_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_publish.o : ../lib/send_publish.cpp ../lib/send_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_suback.o : send_suback.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_subscribe.o : ../lib/send_subscribe.cpp ../lib/send_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

send_unsubscribe.o : ../lib/send_unsubscribe.cpp ../lib/send_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

service.o : service.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

signals.o : signals.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

subs.o : subs.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

sys_tree.o : sys_tree.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

time_mosq.o : ../lib/time_mosq.cpp ../lib/time_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

tls_mosq.o : ../lib/tls_mosq.cpp
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

util_mosq.o : ../lib/util_mosq.cpp ../lib/util_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

utf8_mosq.o : ../lib/utf8_mosq.cpp
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

websockets.o : websockets.cpp mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

will_mosq.o : ../lib/will_mosq.cpp ../lib/will_mosq.h
	${CROSS_COMPILE}${CC} $(BROKER_CFLAGS) -c $< -o $@

mosquitto_passwd : mosquitto_passwd.o
	${CROSS_COMPILE}${CC} $^ -o $@ ${LDFLAGS} $(PASSWD_LIBS)

mosquitto_passwd.o : mosquitto_passwd.cpp
	${CROSS_COMPILE}${CC} -I.. $(CFLAGS) ${CPPFLAGS} -c $< -o $@

plugin_defer.so : plugin_defer.cpp mosquitto_plugin.h mosquitto_broker.h mosquitto_broker_internal.h
	${CROSS_COMPILE}${CC} -I. -I../lib -fPIC -shared $< -o $@

install : all
	$(INSTALL) -d "${DESTDIR}$(prefix)/sbin"
	$(INSTALL) ${STRIP_OPTS} mosquitto "${DESTDIR}${prefix}/sbin/mosquitto"
	$(INSTALL) -d "${DESTDIR}$(prefix)/include"
	$(INSTALL) mosquitto_broker.h "${DESTDIR}${prefix}/include/mosquitto_broker.h"
	$(INSTALL) mosquitto_plugin.h "${DESTDIR}${prefix}/include/mosquitto_plugin.h"
ifeq ($(WITH_TLS),yes)
	$(INSTALL) -d "${DESTDIR}$(prefix)/bin"
	$(INSTALL) ${STRIP_OPTS} mosquitto_passwd "${DESTDIR}${prefix}/bin/mosquitto_passwd"
endif

uninstall :
	-rm -f "${DESTDIR}${prefix}/sbin/mosquitto"
	-rm -f "${DESTDIR}${prefix}/include/mosquitto_broker.h"
	-rm -f "${DESTDIR}${prefix}/include/mosquitto_plugin.h"
	-rm -f "${DESTDIR}${prefix}/bin/mosquitto_passwd"

clean : 
	-rm -f *.o mosquitto mosquitto_passwd

reallyclean : clean
	-rm -rf *.orig *.db
