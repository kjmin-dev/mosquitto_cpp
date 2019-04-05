#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "mosquitto.h"
//#include <iostream>

int on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *msg)
{

    int pid;
    char *return_payload;

    printf("%s %s (%d)\n", msg->topic, (const char *)msg->payload, msg->payloadlen);

    return_payload = (char *) malloc (sizeof(char)*(msg->payloadlen + 1));

    // for preventing re-sending
    strncpy(return_payload, "0", 1);
    strncpy(return_payload + 1, msg->payload, msg->payloadlen); 

    printf("this will be returned --> %s\n", return_payload);

    pid = fork();

    if (pid == 0) {
        // child process 
        execlp("publisher", "-DCPSInfoRepo", "localhost:12345", "-t", "udp" , "-n", msg->topic  ,"-m", return_payload);
    }
    else {
        // parent process
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int rc; 
    int topics_len;
    char **topics;
    int i;

    if (argc < 3) {
        printf("[ERROR] Please EXECUTE with host and topics");
    }

    topics_len = argc - 2;
    topics = (char **) malloc (sizeof(char *) * topics_len);

    for (i = 2; i < argc; i ++) {
        // add topics to another array
        topics[i-2] = argv[i];
    }

    mosquitto_lib_init();

    rc = mosquitto_subscribe_callback_topics(
            on_message, NULL,
            topics, topics_len, 0,
            argv[1], 1883,
            NULL, 60, true,
            NULL, NULL,
            NULL, NULL);

    if(rc){
        printf("Error: %s\n", mosquitto_strerror(rc));
    } 
    mosquitto_lib_cleanup();

    return rc; 
}

