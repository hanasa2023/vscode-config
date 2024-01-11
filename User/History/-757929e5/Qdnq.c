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

void Timer0_Init() // 初始化定时器
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
						 0x00}; // 数码管显示的内容
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

unsigned char Nixie_Buf[9] = {0, 10, 10, 10, 10, 10, 10, 10, 10};

void Nixie_SetBuf(unsigned char Location, unsigned char Number) // 用来更改数组的值
{
	Nixie_Buf[Location] = Number;
}

void N_Loop() // 每调用一次就会显示数组中的值
{
	static unsigned char i = 1;
	N_Scan(i, Nixie_Buf[i])
	{
		i++;
		if (i >= 9)
			i = 1;
	}
}

void Timer0_Routine() interrupt 1 // 调用定时器0
{
	static unsigned int T0Count1;
	TL0 = 0x18; // 设定初值
	TH0 = 0xFC;
	T0Count1++;
	if (T0Count1 >= 2) // 每2ms调用下面的函数
	{
		T0Count1 = 0;
		N_Loop();
	}
}

void main()
{
	Timer0_Init();
	while (1)
	{
		unsigned char x = M(); // 获得键盘返回值
		if (x != 0)
		{
			Delay(200);	 // 延时200ms
			if (x <= 10) // 如果按下的是前九个按键
			{
				if (count <= 4) // 限制密码的位数
				{
					if (count == 1) // 显示密码的第一个值
					{
						g = x - 1;
						Nixie_SetBuf(1, g);
					}
					if (count == 1) // 显示密码的第二个值
					{
						g = x - 1;
						Nixie_SetBuf(1, g);
					}
					if (count == 1) // 显示密码的第三个值
					{
						g = x - 1;
						Nixie_SetBuf(1, g);
					}
					if (count == 1) // 显示密码的第四个值
					{
						g = x - 1;
						Nixie_SetBuf(1, g);
					}
					count++;
				}
			}
		}
	}
}