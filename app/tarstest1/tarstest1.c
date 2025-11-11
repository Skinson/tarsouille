// tarstest1.cpp : définit le point d'entrée de l'application.
//
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include "/home/tars/test2/WiringPi/wiringPi/wiringPi.h"
#include "tarstest1.h"

#define SERVO_PIN 1   // GPIO18 = WiringPi 1



static bool running = true;

int main()
{
	signal(SIGINT, sig_handler);
	fprintf (stdout, "Hello Tarsouilleurs !\n");
	if (wiringPiSetup () == -1)
	  {
	    fprintf (stdout, "oops: %s\n", strerror (errno)) ;
	    return 1 ;
	  }
	  pinMode(SERVO_PIN, PWM_OUTPUT);

    // PWM hardware à 50 Hz (période 20 ms)
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);      // Diviseur
    pwmSetRange(2000);     // Résolution

    // 50 Hz => période = 20 ms => 2000 "pas"
    // 1 ms = ~100 / 2 ms = ~200

    int pos_min = 50;   // 1 ms
    int pos_mid = 150;   // 1.5 ms
    int pos_max = 250;   // 2 ms

	while (1) {
		if (!running) {
		    // shutdown
		    printf("Terminating program\n");
		    return 0;
		}
		int key = getchar();
		if (key == 'u') {
			printf("Moving up !\n");
			pwmWrite(SERVO_PIN, pos_min);
        delay(1000);
		}
		if (key == 'd') {
			printf("Moving down !\n");
			pwmWrite(SERVO_PIN, pos_max);
        delay(1000);
		}
        }

}

void sig_handler(int num) {
    if (num == SIGINT) {
        running = false;
    }
}
