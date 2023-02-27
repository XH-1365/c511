#define S7 (1 << 0)
#define S6 (1 << 1)
#define S5 (1 << 2)
#define S4 (1 << 3)
#define S11 (1 << 4)
#define S10 (1 << 5)
#define S9 (1 << 6)
#define S8 (1 << 7)
#define S15 (1 << 8)
#define S14 (1 << 9)
#define S13 (1 << 10)
#define S12 (1 << 11)
#define S19 (1 << 12)
#define S18 (1 << 13)
#define S17 (1 << 14)
#define S16 (1 << 15)

/**
 * 读矩阵键盘
 * 按LSB到MSB，按键从左到右，每列从上到下
 */
unsigned int KEYBOARD_Read(void);
