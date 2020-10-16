/* testgprof.c */

#include <stdio.h>

void sub1(void);
void sub2(void);

main()
{
	int i;
	for (i=0;i<1000;i++)	sub1();
	for (i=0;i<1000;i++)	sub2();
}

void sub1(void)
{
	int i;
	for (i=0;i<1000;i++)	sub2();
}

void sub2(void)
{
	int i, j;
	for (i=0;i<1000;i++)	j++;
}
