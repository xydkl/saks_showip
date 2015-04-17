#include <wiringPi.h>
#include <stdio.h>

/*数码管映射
#     __1_
#    |     |    |  0 ->  0011 1111 -> 0x3f
#  6 |     | 2  |  1 ->  0000 0110 -> 0x06
#    |__7__|    |  2 ->  0101 1011 -> 0x5b
#    |     |    |  3 ->  0100 1111 -> 0x4f
#  5 |     | 3  |  4 ->  0110 0110 -> 0x66
#    |__4__|  .8|  5 ->  0110 1101 -> 0x6d
#                  6 ->  0111 1101 -> 0x7d
#                  7 ->  0000 0111 -> 0x07
#                  8 ->  0111 1111 -> 0x7f
#                  9 ->  0110 1111 -> 0x6f
#
#
#
*/

unsigned char digit[17] = {
        0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f,
            0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00

};

//管脚映射
unsigned int pin[] = {
    29, 27, 24, 22, 21, 28, 25, 23
}; 

//位选
unsigned int sel[] = {
    0, 2, 3, 12
};

void setup() {
    int i;
    wiringPiSetup();
    for(i=0;i<8;++i)
        pinMode(pin[i], OUTPUT);
    for(i=0;i<4;++i)
        pinMode(sel[i], OUTPUT);
}

void reset() {
    int i;
    for(i=0;i<8;++i)
        digitalWrite(pin[i], HIGH);
}

void display(int bitsel, int dig) {
   int i;
   
   digitalWrite(sel[bitsel], LOW);
   
   for(i=0;i<8;++i)
   {
       digitalWrite(pin[i], dig&1);
       dig >>= 1;
   }
   
   digitalWrite(sel[bitsel], HIGH);
   
   reset();
}

