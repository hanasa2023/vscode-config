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