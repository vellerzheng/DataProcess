#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dataprocess.h"

int main()
{

 	unsigned char data1[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};  
	unsigned char data2[] = {'5', '6', '7', '8', '9'};  
	unsigned char data3[]={0x02,0x03,0x00,0x2A,0x00,0x01};
	unsigned short c1, c2,c3;  
	c1 = crc16(data1, 9, 0xffff);  
	c2 = crc16(data1, 4, 0xffff);  
	c2 = crc16(data2, 5, c2);  
    	c3 = CheckCRCModBus(data3,6,c3);	
	printf("%04x\n", c1);  
	printf("%04x\n", c2); 
	printf("%04x\n", c3); 
        return 0;
}
