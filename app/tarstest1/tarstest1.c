// tarstest1.cpp : définit le point d'entrée de l'application.
//
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include "/home/tars/test2/WiringPi/wiringPi/wiringPi.h"
#include "tarstest1.h"


using namespace std;

static bool running = true;

int main()
{
	signal(SIGINT, sig_handler);
	fprintf (stdout, "Hello Tarsouilleurs !\n");
	while (1) {
		if (!running) {
		    // shutdown
		    printf("Terminating program\n");
		    return 0;
		}
		int key = getchar();
		if (key == 'u') {
			printf("Moving up !\n");
		}
		if (key == 'd') {
			printf("Moving down !\n");
		}
        }

}

void sig_handler(int num) {
    if (num == SIGINT) {
        running = false;
    }
}
