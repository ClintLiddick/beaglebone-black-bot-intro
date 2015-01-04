/* Simple on-board LED blinking program
 * Written by Clinton Liddick
 * based on program by Derek Molloy [derekmolloy.ie]
 *
 * TODO
 */

#include <iostream>
#include <fstream>
#include <unistd.h>
 using namespace std;

#define LED0_PATH "/sys/class/leds/beaglebone:green:usr0"

void remove_trigger() {
	// set LED trigger to "none"
	std::fstream fs;
	fs.open(LED0_PATH "/trigger", std::fstream::out);
	fs << "none";
	fs.close();
}

void flash_native() {
	std::fstream fs;
	fs.open(LED0_PATH "/trigger", std::fstream::out);
	fs << "timer";
	fs.close();
	fs.open(LED0_PATH "/delay_on", std::fstream::out);
	fs << "50";
	fs.close();
	fs.open(LED0_PATH "/delay_off", std::fstream::out);
	fs << "50";
	fs.close();
}

void stop_LED() {
	std::fstream fs;
	fs.open(LED0_PATH "/trigger", std::fstream::out);
	fs << "none";
	fs.close();
}

void reset_LED() {
	std:fstream fs;
	fs.open(LED0_PATH "/trigger", std::fstream::out);
	fs << "heartbeat";
	fs.close();
}


int main(int argc, char **argv) {
	cout << "Stopping USR0 LED for 2 seconds" << endl;
	stop_LED();
	sleep(2);
	cout << "Flashing LED with native timer for 5 seconds" << endl;
	flash_native();
	sleep(5);
	cout << "Resetting LED to heartbeat" << endl;
	reset_LED();

	return 0;
}