
#Some of the factory entries have more than 4 moves due to some moves being used twice. 
#The purpose of this script is to find duplicates and delete them.
#Algorithm:
#	While parse through entry, store every move seen.
#	Every time you come across a new move, check if you have already seen it.
#	If you have seen it, disregard the move.
#	If you haven't seen it, add the move to moves seen.
#	At the end, store the moves seen to the filtered entry.



#The rest of the data should pass through unaltered.
#Ordering of the data should be preserved.


#Format of entry:
#	name
#	type
#	Move Lines
#	Item
#	Nature
#	EV Lines

entryInputDir = "../BASE/UNREFINED/PARTIAL_FILTER_ENTRIES/"
DPPRegionSubDir = "DPP/"
regionSubDir = DPPRegionSubDir
DPPInputFileNameList = {"R1.txt":"Filter_R1.txt","R2.txt":"Filter_R2.txt","R3.txt":"Filter_R3.txt","R4.txt":"Filter_R4.txt"}

inputFileNameList = DPPInputFileNameList

fullNameInputFileList = {}

entryOutputDir = "../BASE/UNREFINED/FULL_FILTER_ENTRIES/"

for entry in inputFileNameList:
	fullNameInputFileList[entryInputDir + regionSubDir + entry] = entryOutputDir + regionSubDir + DPPInputFileNameList[entry]
	
for entry in fullNameInputFileList:
	print entry, fullNameInputFileList[entry]


#We need to find a way to know which lines are moves.
#As of right now, we know that every move is a number.

#So, filter out the first 2 lines which are name and type.
#Then, filter out number lines until we reach the item line, which is not a number line.
#Then, filter out the rest of the entry.

#Each entry is separated by a blank line.


import sys


processFinished = False


def ParsePokemonEntry(fin,fout):
	global processFinished
	fout.write(fin.readline())
	fout.write(fin.readline())

	i = 0
	line = fin.readline()
	moveList =[]
	while line != '' and line != '\n' and line[0] >= '0' and line[0] <= '9':
		if not line in moveList:
			moveList.append(line)
			fout.write(line)
		line = fin.readline()
	
	while line != '' and line != '\n':
		fout.write(line)
		line = fin.readline()

	if line == '':
		processFinished = True
	elif line == '\n':
		fout.write(line)	

#open inputfile, open outputfile
#while not finished parsing, parse Entry
def ParsePokemonEntryFile(inputFile, outputFile):
	global processFinished
	fin = open(inputFile, 'r')
	fout = open(outputFile, 'w')
	while not processFinished:
		ParsePokemonEntry(fin,fout)

	fin.close()
	fout.close()

	processFinished = False #reset var for next call

for entry in fullNameInputFileList:
	ParsePokemonEntryFile(entry, fullNameInputFileList[entry])


