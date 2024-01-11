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
	TH0 = 0xFC;	  // 优先级为最低级
	TL0 = 0x10;
}