/**** ULN2003����Ƭѡ���� ****/
// �̵���������ӵ��Ǹ� Led �ƣ�
#define RELAY (1 << 4)
// ���
#define MOTOR (1 << 5)
// ������
#define BUZZ (1 << 6)

#define ON 1
#define OFF 0

void ULN2003_Turn(unsigned char component, bit turn_on);

/**
 * ���Ʒ�������Դ
 */
void BUZZ_Power(bit turn_on);
