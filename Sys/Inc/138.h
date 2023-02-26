/**** 138外设片选定义 ****/
// 八位 LED 灯
#define LED 4
// 数码管位置选择
#define SMG_POS 6
// 数码管图案选择
#define SMG_CHAR 7
// ULM2003 达林顿管
#define ULN2003 5

void SendTo(unsigned char select, unsigned char dat);
