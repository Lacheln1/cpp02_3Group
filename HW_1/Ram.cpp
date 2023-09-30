#include "Ram.h"

Ram::Ram() {};

Ram::~Ram() {};

char Ram::read(int address) {
	return mem[address];
}

void Ram::write(int address, char value){
	mem[address] = value;
}



