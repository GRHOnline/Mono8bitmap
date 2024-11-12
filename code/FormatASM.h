#include <iostream>

int ConvertToDecimal(int iHexHigh, int iHexLow);
int LoadDecAssemblerData( const char * sInput ,unsigned char * cPassback, int iLimit);
int SaveDecAssemblerData(const char * sOutput, unsigned char * cPassback, int iLimit);
int LoadHexAssemblerData( const char * sInput ,unsigned char * cPassback, int iLimit);
int SaveHexAssemblerData(const char * sOutput, unsigned char * cPassback, int iLimit);
