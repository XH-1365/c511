#ifndef __SMG_H
#define __SMG_H

void SMG_Init(void);
void SMG_Deinit(void);

void SMG_ShowChar(unsigned char pos, char ch, bit dot);
void SMG_ShowStr(char * str);
void SMG_Flash();

#endif // __SMG_H
