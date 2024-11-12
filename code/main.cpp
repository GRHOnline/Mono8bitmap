#include <iostream>
#include <fstream> // file loading stuff
//#include <string> // needed for StringToInteger
#include "FormatASM.h"
#include "FormatBMP.h"
#include "FormatRAW.h"
#include "misc.h"
#include "prettyfine.h"

using namespace std;

int main()
{
    bool bFailed = false;

    char cInType;
    char cOutType;

    ifstream FyleRead;

    //int iTemp = 0;
    int iLine = 0;
    string sGrab;
    string sInFile;
    string sOutFile;


    const char * cConfig = "files.txt"; // our default input file

    unsigned char cData[ATASCII_SIZE];
    unsigned char *pData = cData; // pointer

    cout << "Mono8bitmap" << endl;
    cout << "-----------" << endl << endl;
    cout << "Convert data defined for 8 bit Atari assembler code from or into a Monochrome BMP file." << endl << endl;
    cout << "Loading configuration from file called " << cConfig << endl << endl;

    //-------------------------------------------- Load data in
    FyleRead.open(cConfig);
    if (FyleRead.is_open() != true)
    {
        cout << "Failed to open the configuration file - " << cConfig << endl;
    }
    else
    {
        while ( bFailed == false)
        {
            getline(FyleRead,sGrab);

            //Ignore comments that start with
            if ( sGrab[0] != ASCII_SEMICOLON )
            {
                if ( sGrab.length() > 0 )
                {
                    switch ( iLine )
                    {
                        case 0:
                            sInFile = sGrab;
                            bFailed = FyleRead.fail();
                            iLine++;
                            cout << "Input file : " << sInFile;
                            break;
                        case 1:
                            cInType = FilterInput(sGrab[0]);
                            bFailed = FyleRead.fail();
                            iLine++;
                            cout << " - type = " << cInType <<endl;
                            break;
                        case 2:
                            sOutFile = sGrab;
                            bFailed = FyleRead.fail();
                            iLine++;
                            cout << "Output file : " << sOutFile;
                            break;
                        case 3:
                            cOutType = FilterInput(sGrab[0]);
                            bFailed = true;
                            iLine++;
                            cout << " - type = " << cOutType << endl;
                            break;
                        default:
                            cout << "Too many file entries. " << sGrab << " is being ignored." << endl;
                            bFailed = true;
                            break;
                    }

                }

            }
            else
            {
                bFailed = FyleRead.fail();
            }

        }
        FyleRead.close();
    }

    //--------------------------------------------------------------------------------------------
    FillData( pData, 0, ATASCII_SIZE); // Blank the array in case we get less data than expected.

    if ( cInType == 'D')
    {
        cout << "Load DEC ASM, errors found = " << LoadDecAssemblerData(sInFile.c_str(), pData, ATASCII_SIZE) << endl;
        //return 0;
    }

    if ( cInType == 'H')
    {
        if ( LoadHexAssemblerData(sInFile.c_str(), pData, ATASCII_SIZE) == 666)
        {
            cout << "Error opening the Assembler, Hex Input file \n";
            return 0;
        }
        //else cout << "Errors found = " << LoadHexAssemblerData(sInFile.c_str(), pData, ATASCII_SIZE) << endl;
    }

    if ( cInType == 'M') // monochrome bitmap - TODO write the sort2raw code!
    {

        if ( LoadInBitmapData(sInFile.c_str(), pData, ATASCII_SIZE) == 66 )
        {
            cout << "Error loading the bitmap file! " << endl;
            return 0;
        }
        iLine = SortIntoRaw( pData, ATASCII_SIZE);
        FlipData( pData, ATASCII_SIZE);
    }

    if ( cInType == 'R')// Raw data / .FNT
    {
        if ( LoadInRawData(sInFile.c_str(), pData, ATASCII_SIZE) == 666 )
        {
            cout << "Error opening the raw Input file!" << endl;
            return 0;
        }
    }

    if ( cInType == 'W')
    {
        FillData (pData, 255, ATASCII_SIZE );// just fill the data white
        cout << "Input type is W so filling the dataset with the default pattern.\n Check the config file if this isn't what you wanted!\n ";
    }

    //-------------------------------------------------------------------------------------------
       if ( cOutType == 'D')
    {
        if ( SaveDecAssemblerData(sOutFile.c_str(), pData, ATASCII_SIZE) == 666)
        {
            cout << "Error Saving the Decimal ASM file! \n";
        }
        //return 0;
    }
        if ( cOutType == 'H')
    {
        if ( SaveHexAssemblerData(sOutFile.c_str(), pData, ATASCII_SIZE) == 666)
        {
            cout << "Error Saving the Hexadecimal ASM file! \n";
        }
    }

    if ( cOutType == 'M' )
    {
        FlipData(pData,ATASCII_SIZE);
        iLine = SortIntoBitmap( pData,ATASCII_SIZE );
        if ( SaveAsBitmapData(sOutFile.c_str(), pData, ATASCII_SIZE) == 666)
        {
            cout << "Error saving the Bitmap output file!" << endl;
        }
    }

    if ( cOutType == 'R' )
    {

        if ( SaveAsRawData(sOutFile.c_str(), pData, ATASCII_SIZE) == 666)
        {
            cout << "Error saving the raw output file!" << endl;
        }
    }

    if ( cOutType == 'W')
    {
        //FillData (pData, 255, ATASCII_SIZE );// just fill the data white
        cout << "Incorrect setting for output type.\n Check the config file if this isn't what you wanted!\n ";
    }

    cout << "Program finished. Press a any key to exit. \n" << endl;
    iLine = getchar();

    return 0;
}
