#include <reg52.h>
sbit keyin1 = P2 ^ 4;
sbit keyin2 = P2 ^ 5;
sbit keyin3 = P2 ^ 6;
sbit keyin4 = P2 ^ 7;
sbit keyout1 = P2 ^ 3;
sbit keyout2 = P2 ^ 2;
sbit keyout3 = P2 ^ 1;
sbit keyout4 = P2 ^ 0;
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;
sbit BUZZ = P1 ^ 6;
bit flagBUZZ = 0;
bit flagMODE = 0;
unsigned char code LedChar[] = {0xc0, 0xf9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char LedBuf[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
unsigned char Keysta[4][4] = {
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1}}; // ����ȷ��ֵ
unsigned char code KeyCodeMap[4][4] = {
	// ���󰴼���ŵ���׼���̼����ӳ���
	{0x31, 0x32, 0x33, 0x26}, // ���ּ�1�����ּ�2�����ּ�3�����ϼ�
	{0x34, 0x35, 0x36, 0x25}, // ���ּ�4�����ּ�5�����ּ�6�������
	{0x37, 0x38, 0x39, 0x28}, // ���ּ�7�����ּ�8�����ּ�9�����¼�
	{0x30, 0x1B, 0x0D, 0x27}  // ���ּ�0��ESC����  �س����� ���Ҽ�
};
unsigned char codesta[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};	// ��ǰ����ֵ��
unsigned char BackupCode[6] = {0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0}; // ��ȷ��������ֵ
void KeyDriver();
void main()
{
	EA = 1;
	ET0 = 1;
	TMOD = 0x01;
	TH0 = 0xFC;
	TL0 = 0x67;
	TR0 = 1;
	ENLED = 0;
	ADDR3 = 1;
	while (1)
	{
		KeyDriver();
	}
}
void init()
{
	unsigned char i;
	for (i = 0; i < 6; i++)
	{
		LedBuf[i] = 0xFF;
		codesta[i] = 0xFF;
	}
}
void KeyAtion(unsigned char keycode) // ������
{
	static unsigned char l = 0, k = 0;
	signed char i;
	if ((keycode >= 0x30) && (keycode <= 0x39))
	{
		if (flagMODE == 0)
		{
			if (l < 6)
			{
				codesta[5 - l] = LedChar[keycode - 0x30];
				LedBuf[5 - l] = 0xBF;
				l++;
			}
		}
		else
		{
			if (k < 6)
			{
				BackupCode[5 - k] = LedChar[keycode - 0x30];
				LedBuf[5 - k] = BackupCode[5 - k];
				for (i = 0; i < (5 - k); i++)
				{
					BackupCode[i] = 0xFF;
				}
				k++;
			}
		}
	}
	if ((keycode == 0x26) && (flagBUZZ == 1))
	{
		flagMODE = 1;
	}
	if (keycode == 0x0D)
	{
		if (flagMODE == 0)
		{
			for (i = 5; i >= 0; i--)
			{
				if (codesta[i] == BackupCode[i])
				{
					if (i == 0)
					{
						flagBUZZ = 1;
					}
				}
				else
				{
					flagBUZZ = 0;
					break;
				}
			}
		}
		else
		{
			flagMODE = 0;
			flagBUZZ = 0;
		}
		k = 0;
		l = 0;
		init();
	}
}
void KeyDriver()
{
	static unsigned char backup[4][4] = {
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1}}; // ��������ֵ
	unsigned char i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (backup[i][j] != Keysta[i][j])
			{
				if (backup[i][j] == 1)
				{
					KeyAtion(KeyCodeMap[i][j]);
				}
				backup[i][j] = Keysta[i][j];
			}
		}
	}
}
void Ledscan()
{
	static unsigned char i = 0; // �����ˢ������
	P0 = 0xFF;					// ���������
	switch (i)
	{
	case 0:
		ADDR2 = 0;
		ADDR1 = 0;
		ADDR0 = 0;
		P0 = LedBuf[0];
		i++;
		break;
	case 1:
		ADDR2 = 0;
		ADDR1 = 0;
		ADDR0 = 1;
		P0 = LedBuf[1];
		i++;
		break;
	case 2:
		ADDR2 = 0;
		ADDR1 = 1;
		ADDR0 = 0;
		P0 = LedBuf[2];
		i++;
		break;
	case 3:
		ADDR2 = 0;
		ADDR1 = 1;
		ADDR0 = 1;
		P0 = LedBuf[3];
		i++;
		break;
	case 4:
		ADDR2 = 1;
		ADDR1 = 0;
		ADDR0 = 0;
		P0 = LedBuf[4];
		i++;
		break;
	case 5:
		ADDR2 = 1;
		ADDR1 = 0;
		ADDR0 = 1;
		P0 = LedBuf[5];
		i = 0;
		break;
	}
}
void Keyscan() // ���ڽ�ɳ̲�̳�//
{
	static unsigned char KeyBuf[4][4] = {
		{0xFF, 0xFF, 0xFF, 0xFF},
		{0xFF, 0xFF, 0xFF, 0xFF},
		{0xFF, 0xFF, 0xFF, 0xFF},
		{0xFF, 0xFF, 0xFF, 0xFF}};
	static unsigned char keyout = 0;
	unsigned char i;
	KeyBuf[keyout][0] = (KeyBuf[keyout][0] << 1) | keyin1;
	KeyBuf[keyout][1] = (KeyBuf[keyout][1] << 1) | keyin2;
	KeyBuf[keyout][2] = (KeyBuf[keyout][2] << 1) | keyin3;
	KeyBuf[keyout][3] = (KeyBuf[keyout][3] << 1) | keyin4;
	for (i = 0; i < 4; i++)
	{
		if (KeyBuf[keyout][i] == 0xFF)
		{
			Keysta[keyout][i] = 1;
		}
		else if (KeyBuf[keyout][i] == 0xF0)
		{
			Keysta[keyout][i] = 0;
		}
	}
	keyout++;
	if (keyout >= 4)
	{
		keyout = 0;
	}
	switch (keyout)
	{
	case 0:
		keyout4 = 1;
		keyout1 = 0;
		break;
	case 1:
		keyout1 = 1;
		keyout2 = 0;
		break;
	case 2:
		keyout2 = 1;
		keyout3 = 0;
		break;
	case 3:
		keyout3 = 1;
		keyout4 = 0;
		break;
	default:
		break;
	}
}
void timer0() interrupt 1
{
	TH0 = 0xFC;
	TL0 = 0x67;
	Ledscan();
	Keyscan();
	if (flagBUZZ == 1)
	{
		BUZZ = ~BUZZ;
	}
}