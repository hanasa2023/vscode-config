#include <reg51.h>
// 定义IO口
sbit Beep = P3 ^ 6;
sbit LED1 = P3 ^ 7;
// 定义全局变量
int count = -1;
int count1 = 0; // 用于记录输入密码错误的次数
int counter;	// 用于计数是定时器能够定时1分钟
int counter1 = 0;
int temp = 99, signal = 0;
// 初始化密码
int key_word[4] = {99, 99, 99, 99};
// 用于接收按键接收的值
int get_word[4] = {0, 0, 0, 0};
char key_buf[] = {0xee, 0xde, 0xbe, 0x7e,
				  0xed, 0xdd, 0xbd, 0x7d,
				  0xeb, 0xdb, 0xbb, 0x7b,
				  0xe7, 0xd7, 0xb7, 0x77}; // 键模
// LED字模
char led[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f}; // 0-9
// 函数声明
void set_key();
void show1(int);
void open_key();
void input_key();
void show2(int);
void show3();
void show4();
int get_key();
// 延时函数
void delay(int x)
{
	int j = 0;
	for (; x > 0; x--)
		for (j = 0; j < 125; j++)
			;
}

// 设定密码功能
void set_key()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		while (get_key() == -1) // 等待按键按下
		{
			if (count != 0 && count != -1)
			{
				show1(count); // 显示设置的密码
			}
		}
		if (signal == 1) // 将按键的值保存
		{
			key_word[i] = get_key();
			count++;
			show1(count);
			signal = 0;
			temp = 99;
		}
		while (temp == get_key()) // 一旦长时间按按键，就一直显示密码
		{
			show1(count);
		}
	}
}

// 输入密码
void input_key()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		while (get_key() == -1) // 等待按键按下
		{
			if (count != 0 && count != -1)
			{
				show2(count); // 显示设置的密码
			}
		}
		if (signal == 1) // 将按键的值保存
		{
			get_word[i] = get_key();
			count++;
			show2(count);
			signal = 0;
			// temp=99;
		}
		while (temp == get_key()) // 一旦长时间按按键，就一直显示密码
		{
			show2(count);
		}
	}
}
// 显示输入的密码
void show2(int count)
{
	if (count == 0) // 显示1位数据
	{
		P1 = 0x0e;
		P0 = led[get_word[0]];
	}
	if (count == 1) // 显示2位数据
	{
		P1 = 0x0e;
		P0 = led[get_word[0]];
		delay(10);
		P1 = 0x0d;
		P0 = led[get_word[1]];
		delay(10);
	}

	if (count == 2) // 显示3位数据
	{
		P1 = 0x0e;
		P0 = led[get_word[0]];
		delay(10);
		P1 = 0x0d;
		P0 = led[get_word[1]];
		delay(10);
		P1 = 0x0b;
		P0 = led[get_word[2]];
		delay(10);
	}
	if (count == 3) // 显示4位数据
	{
		P1 = 0x0e;
		P0 = led[get_word[0]];
		delay(10);
		P1 = 0x0d;
		P0 = led[get_word[1]];
		delay(10);
		P1 = 0x0b;
		P0 = led[get_word[2]];
		delay(10);
		P1 = 0x07;
		P0 = led[get_word[3]];
		delay(10);
		P0 = 0;
		// count=-1;
		signal = 0;
	}
}
// 显示设置的密码
void show1(int count)
{
	int i;
	if (count == 0) // 显示一位数据
	{
		P1 = 0x0e;
		i = key_word[0];
		P0 = led[i];
	}
	if (count == 1) // 显示两位数据
	{
		P1 = 0x0e;
		P0 = led[key_word[0]];
		delay(10);
		P1 = 0x0d;
		P0 = led[key_word[1]];
		delay(10);
	}

	if (count == 2) // 显示三位数据
	{
		P1 = 0x0e;
		P0 = led[key_word[0]];
		delay(10);
		P1 = 0x0d;
		P0 = led[key_word[1]];
		delay(10);
		P1 = 0x0b;
		P0 = led[key_word[2]];
		delay(10);
	}
	if (count == 3) // 显示四位数据
	{
		P1 = 0x0e;
		P0 = led[key_word[0]];
		delay(10);
		P1 = 0x0d;
		P0 = led[key_word[1]];
		delay(10);
		P1 = 0x0b;
		P0 = led[key_word[2]];
		delay(10);
		P1 = 0x07;
		P0 = led[key_word[3]];
		delay(10);
		P0 = 0;
		count = -1;
		signal = 0;
	}
}

// 主函数
void main()
{
	int op;
	LED1 = 0;
	Beep = 1;
	while (1)
	{
		op = get_key();
		switch (op)
		{
		case 13:
			while (temp == get_key())
				;		// 等待选择功能按键释放后再进行设置密码
			count = -1; // 在使用标志位时将标志位进行初始化
			signal = 1;
			set_key();
			break;

		case 14:
			while (temp == get_key())
				;
			count = -1; // 初始化标志位
			signal = 1;
			input_key();
			while (get_key() != 15) // 当按下登陆键，输入的密码不再显示
			{
				show2(count);
			}
			if (compare() == -1)
			{
				count1++;
				while (get_key() != 14 && count1 != 3)
				{
					show3(); // 密码错误，显示ERR
				}
				P0 = 0; // 按下输入密码键后，清屏
				if (count1 == 3)
				{
					// 开启定时器中断
					TMOD = 0x01;
					TH0 = 0x9E; // 装载初值25ms
					TL0 = 0x58;
					EA = 1;	 // 开总中断
					ET0 = 1; // 开定时器0
					TR0 = 1; // 开启定时器0
					while (counter1 < 60)
						;	 // 只有当蜂鸣器响完一分钟之后，才能退出循环
					TR0 = 0; // 关闭定时器
				}
			}
			else
			{
				LED1 = 1;				// 当输入密码正确时，开启LED灯
				while (get_key() != 12) // 直到按下退出键，屏幕一直显示on
				{
					show4();
				}
				LED1 = 0; // 退出后关闭LED灯
				P0 = 0;	  // 清屏
			}
			break;
		default:
			break;
		}
	}
}

// 获取键值
int get_key()
{
	char key_scan[] = {0xef, 0xdf, 0xbf, 0x7f};
	int i = 0;
	int j = 0;
	for (i = 0; i < 4; i++) // 判断
	{
		P2 = key_scan[i];
		if ((P2 & 0x0f) != 0x0f)
		{
			for (j = 0; j < 16; j++)
			{
				if (key_buf[j] == P2)
				{
					if (temp != key_buf[j]) // 一旦长时间按键,将只会读取一次按键的值
					{
						signal = 1;
						temp = j;
						return j;
					}
					else
						signal = 0;
				}
			}
		}
	}
	return -1;
}

// 输入的密码和设定的密码比较
int compare()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (get_word[i] != key_word[i])
			return -1; // 输入密码不等于设定的密码返回-1
	}
	return 1; // 输入的密码等于设定密码返回1
}

void show3() // 显示ERR
{
	P1 = 0x0e;
	P0 = 0x79;
	delay(10);
	P1 = 0x0d;
	P0 = 0x77;
	delay(10);
	P1 = 0x0b;
	delay(10);
}
void show4() // 显示on
{
	P1 = 0x0e;
	P0 = 0x5c;
	delay(10);
	P1 = 0x0d;
	P0 = 0x54;
	delay(10);
}

// 定时器中断函数，定时1分钟
call_police() interrupt 1
{
	counter++;
	if (counter == 39)
	{
		counter = 0;
		Beep = ~Beep;
		counter1++;
		if (counter1 == 60) // 定时一分钟
		{
			count1 = 0;
			Beep = 1; // 关闭定时器
		}
	}
	else
	{
		TH0 = 0x9E;
		TL0 = 0x58;
	}
}