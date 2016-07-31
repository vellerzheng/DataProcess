#ifdef __DataProcess__
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/**********************************************************************/
/*     CRC check based  CCITT  standard                               */
/*     This function can be used to CRC checking ,                    */
/*     From: http://blog.csdn.net/liyuanbhu/article/details/7882789   */
/**********************************************************************/

uint16_t crc16(unsigned char *addr, int num, uint16_t crc);

/**********************************************************************/
/*      CRC check based  CRC16 MODBUS  standard                       */
/*      Input parameter: pDataIn --data address, iLenIn -- Data lenth */
/*      Output parameter: CRCOut  --2 byte checking value             */
/*      From : http://blog.csdn.net/qsycn/article/details/5430886     */
/**********************************************************************/


uint16_t CheckCRCModBus(const unsigned char * pDataIn, int iLenIn, uint16_t CRCOut);

/**********************************************************************/
/*      This function can switch "uint" to charcacter string          */
/*	Example : 123|134|23|23434|234|988|34|3435|889|               */
/*      Input parameter: pDataIn --data address, iLenIn -- Data lenth */
/*      Output parameter: CRCOut  --2 byte checking value             */
/**********************************************************************/

unsigned char  add_data_char(unsigned char *str,unsigned int  word);
