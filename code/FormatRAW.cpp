#include "FormatRAW.h"

int LoadInRawData(const char * sInput, unsigned char * cPassback, int iLimit)
{

    FILE * FRead;
    int iValue = 0;
    int iCondition = 0;
    int iFound = 0;

    FRead = fopen( sInput,"r");

    if (FRead == NULL)
    {
        fclose(FRead);
        return 666;
    }
    else
    {
        while ( iCondition == 0 )
        {
            iValue = getc(FRead);
            iCondition = feof(FRead);

            if ( iFound < iLimit && iCondition == 0)
            {
                *(cPassback + iFound) = iValue;
                iFound++;
            }
        }


            fclose(FRead);
    }

    return 0;
}

int SaveAsRawData(const char * sOutput, unsigned char * cPassback, int iLimit)
{

    FILE * F_Write;

    int iCondition = 0;
    int iFound = 0;

    F_Write = fopen( sOutput,"wb"); // do we need to use wb to indicate binary not text mode?

    if (F_Write == NULL)
    {
        //fclose(F_Write);
        return 666;
    }
    else
    {
        while ( iCondition == 0 )
        {

            if ( iFound < iLimit && iCondition < 1)
            {
                fputc ( *(cPassback + iFound) , F_Write );
                iFound++;
            }
            else iCondition++;
        }


            fclose(F_Write);
    }

    return 0;
}
