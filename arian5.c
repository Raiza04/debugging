#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// range of 16 bit int => -32768 to 32767

void convert(long int x){
	assert(x >= -32768 && x <= 32767);
	short int y = (short int)x;
	printf("y = %hd \n", y);
}

int main() {
	long int x = 40000; // Is over 32767 => Integer Overflow
	convert(x);
	return 0;
}

