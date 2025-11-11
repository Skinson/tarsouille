// tarstest1.cpp : définit le point d'entrée de l'application.
//
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include "/home/tars/test2/WiringPi/wiringPi/wiringPi.h"
#include "tarstest1.h"


using namespace std;

int main()
{
	signal(SIGINT, sig_handler);
	fprintf (stdout, "Hello Tarsouilleurs !\n");
	return 0;
}

void sig_handler(int num) {
    if (num == SIGINT) {
        running = false;
    }
}
