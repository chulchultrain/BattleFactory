#Purpose of this script is to parse the unfiltered move list file into a more compact and easily usable representation


#Desired Output:
#Move Index
#Move Name
#Move Type
#Move Category

processFinished = False

tagBegin = '</wiki/'

moveTagEnd = '_(move)>'
typeTagEnd = '_(type)>'

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

#As of right now, the above function is sufficient to test. I add this indirection for later upgrade if i feel like it.
def ExistsTypeTagInLine(line):
	return ExistsMoveTagInLine(line)

def IsNumber(ch):
	if ch >= '0' and ch <= '9':
		return True
	else:
		return False

def ParseInformationFromTag(tag, tagBegin, tagEnd):

	#Sanity Check on parameters
	if len(tag) < (len(tagBegin) + len(tagEnd)) or len(tagBegin) == 0 or len(tagEnd) == 0:
		return None #exception handle?

	i = 0
	info = ''
	i = tag.find(tagBegin)

	if i < 0:
		return None #Maybe later return something that states that no information exists
	
	i += len(tagBegin)	
	j = tag.find(tagEnd)
	
	if j > i:
		info = tag[i:j]
		return info
	else: #either tagEnd doesn't exist in tag or tagEnd occurs before tagStart
		return None #exception handle

	

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
	i = line.find(tagBegin)
	if i == -1:
		return None,''
	else:
		i += len(tagBegin)
		line = line[i:]
		i = 0

	i = line.find(moveTagEnd)

	if i == -1:
		return None,''
	else:
		name = line[0:i]
		i += len(moveTagEnd)
		if i >= len(line):
			return name,''
		else:
			line = TrimBeginningWhiteSpace(line[i:])
			return name, line
	
def ParseMoveTypeFromLine(line):
	i = 0
	moveType = ''
	i = line.find(tagBegin)
	if i == -1:
		return None,''
	else:
		i += len(tagBegin)
		line = line[i:]
		i = 0

	i = line.find(typeTagEnd)
	
	if i == -1:
		return None,''
	else:
		moveType = line[0:i]
		i += len(typeTagEnd)
		if i >= len(line):
			return moveType,''
		else:
			line = TrimBeginningWhtieSpace(line[i:])
			return moveType,line


def ParseMove(fin):

	line = fin.readline()	

	index = name = moveType = moveCategory = damage = ''

	#Parse Index
	index, line = ParseIndexFromLine(line)
	#Parse Name
	if ExistsMoveTagInLine(line):
		name,line = ParseNameFromLine(line)

	#Parse Move Type
	if ExistsTypeTagInLine(line):
		moveType,line = ParseMoveTypeFromLine(line)
	#Parse Move Category

	#Ignore Contest Condition

	#Ignore PP

	#Parse Move Damage

	#Ignore Move Generation

#def ParseMoveFile(inputFileFullName,outputFileFullName):
#	global processFinished
	
gg = "123 Chimchar </wiki/Chimchar_(move)>\n Hello"
index,gg = ParseIndexFromLine(gg) 
print index,gg
name,gg = ParseNameFromLine(gg)
print name
print gg
