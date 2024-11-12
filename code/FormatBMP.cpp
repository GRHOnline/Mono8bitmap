#include "FormatBMP.h"
#include "prettyfine.h"

int LoadInBitmapData(const char * sInput, unsigned char * cPassback, int iLimit)
{

    FILE * FRead;
    int iValue = 0;
    int iCondition = 0;
    int iFound = 0;
    int iHeader = 62;

    FRead = fopen( sInput,"r");

    if (FRead == NULL)
    {
        fclose(FRead);
        return 666;
    }
    else
    {
        // Ignore the header
        for ( iCondition = 0; iCondition < iHeader; iCondition++)
        {
            iValue = getc(FRead);
            if ( feof(FRead) != 0) return 666;
        }
        //---------------------------------------------------------------
        iCondition = 0;

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


int SaveAsBitmapData(const char * sOutput, unsigned char * cPassback, int iLimit)
{

    FILE * F_Write;

    int iCondition = 0;
    int iFound = 0;
    int iError = 0;

    char cFileSizeLow = 62;
    char cFileSizeHigh = 4;
    char cFileOffset = 62;
    char cDIBSize = 40;
    char cWidth = 32;
    char cHeightHi = 1;
    char cHeightLo = 0;
    char cBits = 1;
    char cImageSizeLow = 0;
    char cImageSizeHigh = 4;
    char cZero = 0;
    char cWhite = 255;
    char cFlipped = 255;
//    char cInputHi = 0;
//    char cInputLo = 0;


    F_Write = fopen( sOutput,"wb"); // do we need to use wb to indicate binary not text mode?

    if (F_Write == NULL)
    {
        //fclose(F_Write);
        return 666;
    }
    else
    {
        // BMP header file stuff
        fputs("BM", F_Write);
        // ------------------------- BM is the file identifier as Bitmap
        fputc( cFileSizeLow, F_Write);
        fputc( cFileSizeHigh, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        //-------------------------- Reserved - not used
        fputs( "0000", F_Write);
        //-------------------------- Offset - 4 chars
        fputc( cFileOffset, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        //-------------------------- DIB size - aka BITMAPINFOHEADER2- 4 chars
        fputc( cDIBSize, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        //------------------------- Bitmap width
        fputc( cWidth, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        //------------------------- Bitmap height
        fputc( cHeightLo, F_Write);
        fputc( cHeightHi, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        //------------------------- Colour Planes using Bits as it has the same value 1
        fputc( cBits, F_Write);
        fputc( cZero, F_Write);
        //------------------------- Colour Bits per pixel
        fputc( cBits, F_Write);
        fputc( cZero, F_Write);
        //------------------------- Compression method - not used
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        //------------------------- Image size
        fputc( cImageSizeLow, F_Write);
        fputc( cImageSizeHigh, F_Write);
        fputc( cZero, F_Write);
        fputc( cZero, F_Write);
        //------------------------- Horizontal resolution- not used
        fputs( "0000", F_Write);
        //------------------------- Vertical resolution - not used
        fputs( "0000", F_Write);
        //------------------------- Palette info - not used
        fputs( "0000", F_Write);
        //------------------------- Important Colours - not used
        fputs( "0000", F_Write);
        //------------------------- The unit of measurement used by Horizontal and Vertical resolution?
        fputs( "00", F_Write);
        //------------------------- Padding - ignore
        fputs( "00", F_Write);
        //------------------------- Where does the image start drawing from? AKA Flipped image
        fputc( cFlipped, F_Write);
        fputc( cFlipped, F_Write);
        //fputc( cBits, F_Write); // Windows bitmap expect the flip! Don't change this
        //fputc( cZero, F_Write);
        //------------------------- Half-toning info - not used.
        fputc( cZero, F_Write); // using white to put 255 just in case
        fputc( cWhite, F_Write);

        // Write the image data
        iFound = 0;
        iCondition = 0;

        while ( iCondition == 0 )
        {

            if ( iFound < iLimit && iCondition == 0)
            {
                fputc ( *(cPassback + iFound )  , F_Write );
                iFound++;

            }
            else iCondition++;
        }


            fclose(F_Write);
    }

    return iError;
}

int SortIntoBitmap( unsigned char * cPassback, int iLimit)
{
    unsigned char cSorted[FONT_SIZE][FONT_ROW];

    int iCounter = 0;
    int iFours, iEights;
    int iLoops = 0;
    int iCombo = 0;
    int iSize = FONT_ROW * FONT_SIZE;
    int iOpposite = FONT_ROW - 1;

    if ( iSize > iLimit ) iSize = iLimit; // shouldn't be problem but just in case

    while (iLoops < iSize )
    {


        for ( iFours = 0; iFours < FONT_ROW ; iFours++ )
        {
            for ( iEights = 0; iEights < FONT_SIZE; iEights++)
            {
                cSorted[iEights][(iOpposite - iFours)] = *(cPassback + iCombo);
                iCombo++;
            }
        }


        for ( iEights = 0; iEights < FONT_SIZE ; iEights++)
        {
            for ( iFours = 0; iFours < FONT_ROW ; iFours++ )
            {

                *(cPassback + iCounter) = cSorted[iEights][iFours];
                iCounter++;
            }
        }

        iLoops++;

    }


    return iCounter;

}

int SortIntoRaw( unsigned char * cPassback, int iLimit)
{
    // JUST COPIED FROM ABOVE AND BODGED!
    unsigned char cSorted[FONT_SIZE][FONT_ROW];

    int iCounter = 0;
    int iFours, iEights;
    int iLoops = 0;
    int iCombo = 0;
    int iSize = FONT_ROW * FONT_SIZE;
    int iOpposite = FONT_ROW - 1;

    if ( iSize > iLimit ) iSize = iLimit; // shouldn't be problem but just in case

    while (iLoops < iSize )
    {


        for (iEights = 0; iEights < FONT_SIZE; iEights++ )
        {
            for ( iFours = 0; iFours < FONT_ROW ; iFours++ )
            {
                cSorted[iEights][(iOpposite - iFours)] = *(cPassback + iCombo);
                iCombo++;
            }
        }


        for ( iFours = 0; iFours < FONT_ROW ; iFours++ )
        {
            for ( iEights = 0; iEights < FONT_SIZE ; iEights++ )
            {

                *(cPassback + iCounter) = cSorted[iEights][iFours];
                iCounter++;
            }
        }

        iLoops++;

    }


    return iCounter;
}
