#Purpose of this script is to parse the unfiltered move list file into a more compact and easily usable representation


#Desired Output:
#Move Index
#Move Name
#Move Type
#Move Category

processFinished = False

tagBegin = '</wiki/'

moveTagEnd = '_(move)>'

unrefinedDir = "../BASE/UNREFINED/"

inputDir = unrefinedDir + "/UNFILTERED_MOVE_LIST/"
inputFileName = "bulbapedia_move_list.txt"

outputDir = unrefinedDir + "/FILTERED_MOVE_LIST/"
outputFileName = "Filtered_Move_List.txt"

startingLine="</wiki/Power> 	Accuracy </wiki/Accuracy> 	Gen </wiki/Generation>\n"

def TagTokenStart(ch):
	if ch == '<':
		return True
	return False

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

def TrimEndingWhiteSpace(line):
	i = len(line) - 1
	while i >= 0 and line[i].isspace():
		i -= 1
	if i < len(line) - 1:
		return line[:i+1]
	else:
		return line

def ExistsMoveTagInLine(line):
	i = 0
	#as of right now, it may accept all tags, when necessary change to just move tags
	while i < len(line) and line[i] != '<':
		i += 1
	if i < len(line):
		return True
	else:
		return False

def IsNumber(ch):
	if ch >= '0' and ch <= '9':
		return True
	else:
		return False

def ParseIndexFromLine(line):
	i = 0
	index = ''
	while i < len(line) and IsNumber(line[i]):
		index += line[i]
		i += 1

	if i >= len(line):
		return index,''
	else:
		line = line[i:]
		line = TrimBeginningWhiteSpace(line)
		return index,line

def ParseNameFromLine(line):
	i = 0
	name = ''
	i = line.find(tagBegin) + len(tagBegin)
	if i >= len(line):
		return None,''
	else:
		line = line[i:]
		i = 0

	i = line.find(moveTagEnd)

	if i >= len(line):
		return None,''
	else:
		name = line[0:i]
		i += len(moveTagEnd)
		if i >= len(line):
			return name,''
		else:
			return name,line[i:]
	

def ParseMove(fin):

	line = fin.readline()	

	index = name = moveType = moveCategory = damage = ''

	#Parse Index
	index, line = ParseIndexFromLine(line)
	#Parse Name
	if ExistsMoveTagInLine(line):
		name,line = ParseNameFromLine(line)

	#Parse Move Type

	#Parse Move Category

	#Ignore Contest Condition

	#Ignore PP

	#Parse Move Damage

	#Ignore Move Generation

#def ParseMoveFile(inputFileFullName,outputFileFullName):
#	global processFinished
	
gg = "123 Chimchar </wiki/Chimchar_(move)>\n"
index,gg = ParseIndexFromLine(gg) 
print index,gg
name,gg = ParseNameFromLine(gg)
print name,gg
