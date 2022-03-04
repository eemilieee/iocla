#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main() {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
    int n=sizeof(v)/sizeof(int), i, *r;
    unsigned char *p=(unsigned char *)v;
    short *q=(short *)v;
    //adrese din octet in octet
    for(i=0; i<sizeof(v); i++)
        printf("%p -> OX%x\n",p+i,*(p+i));
    printf("\n");
    //adrese din 2 in 2 octeti
    for(i=0; i<sizeof(v)/2; i++)
         printf("%p -> OX%x\n",q+i,*(q+i));
    printf("\n");
    //adrese din 4 in 4 octeti
    for(r=v; r<v+n; r++)
        printf("%p -> OX%x\n",r,*r);
    return 0;
}
