#ifndef __SMG_H
#define __SMG_H

void SMG_Init(void);
void SMG_Deinit(void);

void SMG_ShowPattern(unsigned char pos, unsigned char pattern, unsigned int brightness);
unsigned char SMG_ShowChar(unsigned char pos, char ch, unsigned int brightness);
void SMG_ShowStr(unsigned char pos, char * str);
void SMG_SetBrightness(unsigned char pos, unsigned int brightness);

#endif // __SMG_H
