#define ASCII_BACKSLASH 92
#define ASCII_COMMA 44
#define ASCII_CARRIAGE_RETURN 13
#define ASCII_DOLLAR 36
#define ASCII_LINE_END 10
//#define ASCII_FSLASH 47
#define ASCII_HASH 35
#define ASCII_SEMICOLON 59
#define ASCII_FULLSTOP 46
#define ASCII_SPACE 32
#define ASCII_SPEECHMARK 34

#define ASCII_B 66
//#define ASCII_G 71
#define ASCII_M 77
//#define ASCII_LOWA 97
//#define ASCII_LOWF 102


#define ATASCII_SIZE 1024 // ATASCII is 128 symbols, each made up of 8 bytes.

#define FONT_ROW 4
#define FONT_SIZE 8
#define FONT_SPACING 24
#define BIGGEST_INCREASE 28
#define MAX_FONT_ENTRIES 768
#define COMPARE_TOTAL_FILESIZE 1087
#define COMPARE_IMAGE_SIZE 995

#define COMPARE_HEADER01 66
#define COMPARE_HEADER02 77
#define COMPARE_FILESIZE_LOW 62
#define COMPARE_FILESIZE_HIGH 4
#define COMPARE_OFFSET 62
#define COMPARE_WIDTH 32
#define COMPARE_PLANE 1
#define COMPARE_DEPTH 1
#define COMPARE_COMPRES01 0
#define COMPARE_COMPRES02 0
#define COMPARE_COMPRES03 0
#define COMPARE_COMPRES04 0

#define MAGIC_NUMBER 25 // 24 plus one. I think, I forgot how I arrived at this :(





/*
Dec  Chr   | Dec  Chr   | Dec  Chr                if ( iTrack == 2 )
                {
                    iSecond = iValue;
                    iTrack = 0;
                    bWrite = true;
                }
----------------------------------
32   Space | 64   @     | 96   `
33   !     | 65   A     | 97   a
34   "     | 66   B     | 98   b
35   #     | 67   C     | 99   c
36   $     | 68   D     | 100  d
37   %     | 69   E     | 101  e
38   &     | 70   F     | 102  f
39   '     | 71   G     | 103  g
40   (     | 72   H     | 104  h
41   )     | 73   I     | 105  i
42   *     | 74   J     | 106  j
43   +     | 75   K     | 107  k
44   ,     | 76   L     | 108  l
45   -     | 77   M     | 109  m
46   .     | 78   N     | 110  n
47   /     | 79   O     | 111  o
48   0     | 80   P     | 112  p
49   1     | 81   Q     | 113  q
50   2     | 82   R     | 114  r
51   3     | 83   S     | 115  s
52   4     | 84   T     | 116  t
53   5     | 85   U     | 117  u
54   6     | 86   V     | 118  v
55   7     | 87   W     | 119  w
56   8     | 88   X     | 120  x
57   9     | 89   Y     | 121  y
58   :     | 90   Z     | 122  z
59   ;     | 91   [     | 123  {
60   <     | 92   \     | 124  |
61   =     | 93   ]     | 125  }
62   >     | 94   ^     | 126  ~
63   ?     | 95   _     | 127  DEL
*/
