#include "dataprocess.h"


#define POLY       0x1021  
uint16_t crc16(unsigned char *addr, int num, uint16_t crc)  
{  
    int i;  
    for (; num > 0; num--)              /* Step through bytes in memory */  
    {  
        crc = crc ^ (*addr++ << 8);  
        for (i = 0; i < 8; i++)             /* Prepare to rotate 8 bits */  
        {  
            if (crc & 0x8000)            /* b15 is set... */  
                crc = (crc << 1) ^ POLY;    /* rotate and XOR with polynomic */  
            else                          
                crc <<= 1;                  /* just rotate */  
        }                             /* Loop for 8 bits */  
        crc &= 0xFFFF;                  /* Ensure CRC remains 16-bit value */  
    }                               /* Loop until num=0 */  
   return(crc);                    /* Return updated CRC */  
}

/*
  CRC check  based CRC16(MODBUS)
*/ 
 
uint16_t CalcCRCModBus(char cDataIn, uint16_t wCRCIn)
{
    int wCheck = 0,i;
    wCRCIn = wCRCIn ^ cDataIn;

    for(i = 0; i < 8; i++)
    {
        wCheck = wCRCIn & 1;
        wCRCIn = wCRCIn >> 1;
        wCRCIn = wCRCIn & 0x7fff;

        if(wCheck == 1)
        {
            wCRCIn = wCRCIn ^ 0xa001;
        }
        wCRCIn = wCRCIn & 0xffff;
    }

    return wCRCIn;
}

uint16_t CheckCRCModBus(const unsigned char* pDataIn, int iLenIn, uint16_t CRCOut)
{     
    int wHi = 0;     
    int wLo = 0;     
    int wCRC;
    int i;     
    wCRC = 0xFFFF;     
    
    for ( i = 0; i < iLenIn; i++)     
    {     
        wCRC = CalcCRCModBus(*pDataIn, wCRC);     
        pDataIn++;     
    }     
    
    wHi = wCRC / 256;     
    wLo = wCRC % 256;        
    wCRC = (wHi << 8) | wLo;     
    
    CRCOut = wCRC & 0xffff; 
    return CRCOut;    
} 


unsigned char  add_data_char(unsigned char *str,unsigned int  word)
{
        int len,i=0,j;
        unsigned int  n;
        unsigned char temp,ch[20];
        n=word;
        do{
                ch[i]=n%10+'0';
                n/=10;
                i++;

        }while(n!=0);
        ch[i]='\0';
        for (j=0,i--;j<=i/2;j++,i--)
        {
                temp=ch[j];
                ch[j]=ch[i];
                ch[i]=temp;
        }
        strcat(str,ch);
        strcat(str,"|");
        return *str;
}
             
