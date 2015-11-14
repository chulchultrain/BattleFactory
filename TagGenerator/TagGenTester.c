#include <TagGenerator/FillDataFiles.h>
#include <stdio.h>
#include <stdlib.h>
#include <SpecialConstants/SpecialConstants.h>

//driver to fill the name files

int main() {

char nameDir[1000] = ENTRY_DIRECTORY SUB_DIR_DPP;
char entryFile[100] = FULL_FILTER_ENTRIES SUB_DIR_DPP ENTRY_FILE1_OF_DATA ;
char entryFile2[100] = FULL_FILTER_ENTRIES SUB_DIR_DPP ENTRY_FILE2_OF_DATA ;
char entryFile3[100] = FULL_FILTER_ENTRIES SUB_DIR_DPP ENTRY_FILE3_OF_DATA ;
char entryFile4[100] = FULL_FILTER_ENTRIES SUB_DIR_DPP ENTRY_FILE4_OF_DATA ;

char region[MAX_REGION_SUBDIR_LENGTH] = SUB_DIR_DPP;


FillNameTagFiles(nameDir, entryFile, region);
FillNameTagFiles(nameDir, entryFile2, region);
FillNameTagFiles(nameDir, entryFile3, region);
FillNameTagFiles(nameDir, entryFile4, region);




return 0;
}
