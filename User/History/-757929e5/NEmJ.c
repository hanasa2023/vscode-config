#include <reg51.h>

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
}