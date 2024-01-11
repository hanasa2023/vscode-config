#include <reg51.h>

void Delay(unsigned int x)
{
	while (x--)
	{
		unsigned char i, j;
		i = 2;
		j = 239;
		do
		{
			while (--j)
				;
			while (--i)
				;
		}
	}
}

unsigned char M()
{
	// 矩阵键盘按列扫描
	P1 = 0xFF;
	P1_3 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while (P1_7 = 0)
			;
		Delay(20);
		t = 1;
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while (P1_6 = 0)
			;
		Delay(20);
		t = 5;
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while (P1_5 = 0)
			;
		Delay(20);
		t = 9;
	}
	P1 = 0xFF;
	P1_2 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while (P1_7 = 0)
			;
		Delay(20);
		t = 1;
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while (P1_6 = 0)
			;
		Delay(20);
		t = 5;
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while (P1_5 = 0)
			;
		Delay(20);
		t = 9;
	}
	P1 = 0xFF;
	P1_1 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while (P1_7 = 0)
			;
		Delay(20);
		t = 1;
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while (P1_6 = 0)
			;
		Delay(20);
		t = 5;
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while (P1_5 = 0)
			;
		Delay(20);
		t = 9;
	}
	P1 = 0xFF;
	P1_0 = 0;
	if (P1_7 == 0)
	{
		Delay(20);
		while (P1_7 = 0)
			;
		Delay(20);
		t = 1;
	}
	if (P1_6 == 0)
	{
		Delay(20);
		while (P1_6 = 0)
			;
		Delay(20);
		t = 5;
	}
	if (P1_5 == 0)
	{
		Delay(20);
		while (P1_5 = 0)
			;
		Delay(20);
		t = 9;
	}

	return t;
}

void Timer0Init() // 初始化定时器
{
	TMOD &= 0xF0; // 高四位保持不变，低四位清零
	TMOD |= 0x01; // 高四位不变，最低位置设为1
	TF0 = 0;	  // 允许计时器0的中断标志为0
	TR0 = 1;	  // 允许计时器0工作
	EA = 0;		  // 中断连接
	PT0 = 0;	  // 优先级为最低级
	TH0 = 0xFC;
	TL0 = 0x10;
}

void N_Scan(unsigned char x, unsigned char y)
{
	unsigned char m[] = {0x3F,
						 0x06,
						 0x5B,
						 0x4F,
						 0x66,
						 0x6D,
						 0x7D,
						 0x07,
						 0x7F,
						 0x6F,
						 0x00} // 数码管显示的内容
	P0 = 0x00;
	switch (x) // 选择哪个数码管
	{
	case 1:
		P2_2 = 1;
		P2_3 = 1, P2_4 = 1;
		break;
	case 2:
		P2_2 = 0;
		P2_3 = 1, P2_4 = 1;
		break;
	case 1:
		P2_2 = 1;
		P2_3 = 0, P2_4 = 1;
		break;
	}
}