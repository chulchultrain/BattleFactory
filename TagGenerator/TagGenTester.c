#include <TagGenerator/FillDataFiles.h>
#include <stdio.h>
#include <stdlib.h>



int main() {

char nameDir[1000] = "BASE/NAME/";
//char entryFile[100] = "Output_R1.txt";
char entryFile2[100] = "Output_R2.txt";
char entryFile3[100] = "Output_R3.txt";
char entryFile4[100] = "Output_R4.txt";

printf("TESTEST\n\n\n");

//FillNameTagFiles(nameDir, entryFile);
FillNameTagFiles(nameDir, entryFile2);
FillNameTagFiles(nameDir, entryFile3);
FillNameTagFiles(nameDir, entryFile4);




return 0;
}
