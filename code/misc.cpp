#include "misc.h"
#include "prettyfine.h"


void FillData( unsigned char * myPointer, unsigned char cValue, int iSize )
{

    for ( int iLoop = 0; iLoop < iSize; iLoop++)
    {
        *(myPointer + iLoop) = cValue;
    }
}

void FlipData( unsigned char * myPointer, int iSize )
{
    int iHalf = iSize / 2 ;
    int iSwap = 0;
    int iOpposite = iSize - 1;

    for ( int iLoop = 0; iLoop < iHalf; iLoop++)
    {
        iSwap = *(myPointer + iLoop);
        *(myPointer + iLoop) = *(myPointer + iOpposite);
        *(myPointer + iOpposite) = iSwap;
        iOpposite--;
        if ( iOpposite < 0) iOpposite = 0;
    }
}

unsigned char FilterInput ( unsigned char cInput)
{
    int iCheck = 0;

    if ( cInput >= 'a' && cInput <= 'z') //lower to upper
    {
        cInput-= 32;
    }

    if ( cInput == 'D' ) iCheck++;
    if ( cInput == 'H' ) iCheck++;
    if ( cInput == 'M' ) iCheck++;
    if ( cInput == 'R' ) iCheck++;

    if ( iCheck == 0 ) return 'W';
    else return cInput;
}
