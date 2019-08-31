#include "stdio.h"

#define SET_BIT(num, n, bit) 						((num) |= n << bit)

typedef union __attribute__((__packed__)){
	int bytes:14;
}FLOAT_14_BIT;

int power(int base, int pow)
{
    int res = 1;
    for (int i = 0; i < pow; i++)
    {
        res *= base;
    }
    return res;
}
int enc_func(float input, float maxVal, int encBit)
{    
    int num = 0x00, result;
    float iter, resolution = (float)(maxVal/power(2, (encBit-1)));
    printf("Resol : %f", resolution);
    if (input < 0)
    {
        SET_BIT(result,1,encBit);
    }
    
    for (int i = 0; i < SET_BIT(num,1,(encBit-1)); i++)
    {
        printf("%x\t%f\n",i, (iter = (float)(i * resolution)));
        if (iter >= input)
        {
            printf("Val = %f\n", iter);
            result = i;
            break;
        }
        
    }
    return result;
}
int main(int argc, char const *argv[])
{
    FLOAT_14_BIT result;
    result.bytes = (FLOAT_14_BIT *)enc_func(235.6785f,360.0f,14);
    printf("%x\n", result.bytes);
    return 0;
}
