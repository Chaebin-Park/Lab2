/* $Log: exam.c,v $
 * Revision 1.2  2020/10/13 09:14:35  chaebin
 * function print() is added
 *
 * Revision 1.1  2020/10/13 09:13:02  chaebin
 * Initial revision
 * */

#include <stdio.h>

void print(char* pszMsg)
{
	puts(pszMsg);
}

int main()
{
    print(' Hello \n' );
}


