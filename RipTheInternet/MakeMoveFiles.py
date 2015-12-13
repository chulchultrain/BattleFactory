


unrefinedDir = "../BASE/UNREFINED/"


inputDir = unrefinedDir + "/UNFILTERED_MOVE_LIST/"
inputFileName = "bulbapedia_move_list.txt"

inputDir = unrefinedDir + "/FILTERED_MOVE_LIST/"
inputFileName = "Filtered_Move_List.txt"

outputDir = "../BASE/MOVES/"

fullInputFileName = inputDir + inputFileName


def MakeMoveFile(index,fin):
	fout = open(outputDir + index[:-1],'w')
	fout.write(index)
	i = 0
	while i < 5:
		fout.write(fin.readline())
		i += 1
	
		
	

def MakeMoveFiles(inputFile):
	fin = open(inputFile,'r')

	index = fin.readline()

	while index != '':
		MakeMoveFile(index,fin)
		index = fin.readline()

	fin.close()



MakeMoveFiles(fullInputFileName)
