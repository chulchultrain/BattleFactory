#Purpose of this script is to parse the unfiltered move list file into a more compact and easily usable representation


#Desired Output:
#Move Index
#Move Name
#Move Type
#Move Category

processFinished = False

unrefinedDir = "../BASE/UNREFINED/"

inputDir = unrefinedDir + "/UNFILTERED_MOVE_LIST/"
inputFileName = "bulbapedia_move_list.txt"

outputDir = unrefinedDir + "/FILTERED_MOVE_LIST/"
outputFileName = "Filtered_Move_List.txt"

startingLine="</wiki/Power> 	Accuracy </wiki/Accuracy> 	Gen </wiki/Generation>\n"


def TrimBeginningWhiteSpace(line):
	i = 0
	while i < len(line) and line[i].isspace():
		i += 1
	
	if i > 0:
		if i < len(line):
			return line[i:]
		else:
			return ''
	else:
		return line

def IsNumber(ch):
	if ch >= '0' and ch <= '9':
		return True
	else:
		return False

def ParseIndexFromLine(line):
	i = 0
	index = ''
	while i < len(line) and IsNumber(line[i]):
		i += 1
		index += line[i]

	if i >= len(line):
		return None,None
	else:
		line = line[i:]
		line = TrimBeginningWhiteSpace(line)
		return index,line

def ParseMove(fin):

	line = fin.readline()	

	#Parse Index
	index, line = ParseIndexFromLine(line)
	#Parse Name

	#Parse Move Type

	#Parse Move Category

	#Ignore Contest Condition

	#Ignore PP

	#Parse Move Damage

	#Ignore Move Generation

#def ParseMoveFile(inputFileFullName,outputFileFullName):
#	global processFinished
	
gg = "123 Chimchar\n"
print ParseIndexFromLine(gg) 


