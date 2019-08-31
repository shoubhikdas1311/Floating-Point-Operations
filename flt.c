#include <stdio.h>
int main(int argc, char const *argv[])
{
	float num;
	for (int i = 0; i < 0x1fff; ++i)
	{
		printf("%x\t%f\n", i, num = i * 0.0439);
	}
	return 0;
}