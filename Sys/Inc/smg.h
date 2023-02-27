void SMG_Init(void);
void SMG_Deinit(void);

void SMG_ShowPattern(unsigned char pos, unsigned char pattern, unsigned int brightness);
void SMG_ShowChar(unsigned char pos, char ch, unsigned int brightness);
void SMG_ShowStr(unsigned char pos, char * str);
void SMG_SetBrightness(unsigned char pos, unsigned int brightness);
