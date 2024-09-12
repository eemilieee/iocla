//1
//a. 121 in baza 2: 0111 1001
//   121 in baza 16: 79
//   18446 in baza 2: 0100 1000 0000 1110
//   18446 in baza 16: 480E
//b. 1100 0101 1101 0010 = 2+ 2^4 + 2^6 + 2^7 + 2^8 + 2^10 + 2^14 + 2^15 = 50642
//   0xBB29 = 9 + 2*16 + 11*16^2 + 11*16*3 = 47913
//c. 0x5E = 0101 1110
//   0x4A01 = 0100 1010 0000 0001
//d. 0111 1101 = 7D
//   1000 1100 0001 1111 = 8C1F

/*#include<stdio.h>

void baza2(int x)
{
    int i;
    for(i=31; i>=0; i--)
        if(x&(1<<i))
            printf("1");
        else
            printf("0");
    printf("\n");
}

int main()
{
    int a;
    scanf("%d",&a);
    baza2(a);
    printf("%X\n",a);
}
*/