#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// range of 16 bit int => -32768 to 32767
// short int => 16 bits
// double => 64 bits

void convert(double x){
        //assert(x >= -32768 && x <= 32767); //uncomment to try assert
        short int y = x;
        printf("y = %hd \n", y);
}

int main() {
        double x = 35000.9999; // Is over 32767 => Integer Overflow
        convert(x);

        //static_assert(1==0); //uncomment to try static_assert
        return 0;
}
