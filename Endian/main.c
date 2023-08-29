#include <stdio.h>
int main()
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)   
       printf("Little endian %d",*c);
   else
       printf("Big endian %d",*c);
   getchar();
   return 0;
}