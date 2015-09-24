#include <TagGenerator/FillDataFiles.h>
#include <stdio.h>
#include <stdlib.h>
#include <SpecialConstants/SpecialConstants.h>

//driver to fill the name files

int main() {

char nameDir[1000] = ENTRY_DIRECTORY SUB_DIR_DPP;
char entryFile[100] = ENTRY_FILE1_OF_DATA;
char entryFile2[100] = ENTRY_FILE2_OF_DATA;
char entryFile3[100] = ENTRY_FILE3_OF_DATA;
char entryFile4[100] = ENTRY_FILE4_OF_DATA;


FillNameTagFiles(nameDir, entryFile);
FillNameTagFiles(nameDir, entryFile2);
FillNameTagFiles(nameDir, entryFile3);
FillNameTagFiles(nameDir, entryFile4);




return 0;
}
