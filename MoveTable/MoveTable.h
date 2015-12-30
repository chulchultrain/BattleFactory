#ifndef __MOVETABLE_H_INCLUDED__
#define __MOVETABLE_H_INCLUDED__

/*
typedef struct MoveTablePrivate MoveTablePrivate;

typedef struct MoveTable {
MoveTablePrviate *mem;

} MoveTable;


MoveTable *NewMoveTable();

void FillMoveTable(MoveTable *original, char *fileName);

void DeleteMoveTable(MoveTable* recall);
*/

void GetMoveNameFromID(unsigned int ID, char *dest, unsigned int dest_limit);

#endif
