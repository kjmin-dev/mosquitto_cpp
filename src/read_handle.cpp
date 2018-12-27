/*
Copyright (c) 2009-2018 Roger Light <roger@atchoo.org>

All rights reserved. This program and the accompanying materials
are made available under the terms of the Eclipse Public License v1.0
and Eclipse Distribution License v1.0 which accompany this distribution.
 
The Eclipse Public License is available at
   http://www.eclipse.org/legal/epl-v10.html
and the Eclipse Distribution License is available at
  http://www.eclipse.org/org/documents/edl-v10.php.
 
Contributors:
   Roger Light - initial implementation and documentation.
*/

#include "config.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "mosquitto_broker_internal.h"
#include "mqtt3_protocol.h"
#include "memory_mosq.h"
#include "packet_mosq.h"
#include "read_handle.h"
#include "send_mosq.h"
#include "sys_tree.h"
#include "util_mosq.h"

using namespace std;

int handle__packet(struct mosquitto_db *db, struct mosquitto *context)
{
	
	if(!context) return MOSQ_ERR_INVAL;

	switch((context->in_packet.command)&0xF0){
		case PINGREQ:
			cout << "handle__pingreq (from read_handle.cpp)" << endl;
			return handle__pingreq(context);
		case PINGRESP:
			cout << "handle__pingresp (from read_handle.cpp)" << endl;
			return handle__pingresp(context);
		case PUBACK:
			cout << "handle__pubackcomp (from read_handle.cpp)" << endl;
			return handle__pubackcomp(db, context, "PUBACK");
		case PUBCOMP:
			cout << "handle__pubackcomp (from read_handle.cpp)" << endl;
			return handle__pubackcomp(db, context, "PUBCOMP");
		case PUBLISH:
			cout << "handle__publish (from read_handle.cpp)" << endl;
			return handle__publish(db, context);
		case PUBREC:
			cout << "handle__pubrec (from read_handle.cpp)" << endl;
			return handle__pubrec(context);
		case PUBREL:
			cout << "handle__pubrel (from read_handle.cpp)" << endl;
			return handle__pubrel(db, context);
		case CONNECT:
			cout << "handle__connect (from read_handle.cpp)" << endl;
			return handle__connect(db, context);
		case DISCONNECT:
			cout << "handle__disconnect (from read_handle.cpp)" << endl;
			return handle__disconnect(db, context);
		case SUBSCRIBE:
			cout << "handle__subscribe (from read_handle.cpp)" << endl;
			return handle__subscribe(db, context);
		case UNSUBSCRIBE:
			cout << "handle__unsubscribe (from read_handle.cpp)" << endl;
			return handle__unsubscribe(db, context);
#ifdef WITH_BRIDGE
		case CONNACK:
			cout << "handle__connack (from read_handle.cpp)" << endl;
			return handle__connack(db, context);
		case SUBACK:
			cout << "handle__suback (from read_handle.cpp)" << endl;
			return handle__suback(context);
		case UNSUBACK:
			cout << "handle__unsuback (from read_handle.cpp)" << endl;
			return handle__unsuback(context);
#endif
		default:
			/* If we don't recognise the command, return an error straight away. */
			cout << "MOSQ_ERR_PROTOCOL (from read_handle.cpp)" << endl;
			return MOSQ_ERR_PROTOCOL;
	}
}

