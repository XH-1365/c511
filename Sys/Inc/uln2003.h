/**** ULN2003外设片选定义 ****/
// 继电器（后面接的是个 Led 灯）
#define RELAY (1 << 4)
// 电机
#define MOTOR (1 << 5)
// 蜂鸣器
#define BUZZ (1 << 6)

#define ON 1
#define OFF 0

void ULN2003_Turn(unsigned char component, bit turn_on);

/**
 * 控制蜂鸣器电源
 */
void BUZZ_Power(bit turn_on);
