#Purpose of this script is to parse the unfiltered move list file into a more compact and easily usable representation


#Desired Output:
#Move Index
#Move Name
#Move Type
#Move Category

processFinished = False

endOfNonDataLine = "</wiki/Power> 	Accuracy </wiki/Accuracy> 	Gen </wiki/Generation>\n"

tagBegin = '</wiki/'

nameTagEnd = '_(move)>'
categoryTagEnd = '_move>'
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

def ParseInfoFromTag(tag, tagBegin, tagEnd):

	#Sanity Check on parameters
	if len(tag) < (len(tagBegin) + len(tagEnd)) or len(tagBegin) == 0 or len(tagEnd) == 0:
		return None #exception handle?




	
	j = tag.find(tagEnd)
	if j < 0:
		return None #Maybe later return something that states that no information exists
	
	i = 0
	info = ''

	i = tag.find(tagBegin)
	temp = i
	while temp < j:
		i = temp
		temp = tag.find(tagBegin,temp + 1)
		if temp == -1:
			break;
	
	i += len(tagBegin)
	
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


def ParseAllTagInfoFromLine(line):
	move = ParseInfoFromTag(line,tagBegin,nameTagEnd)
	moveType = ParseInfoFromTag(line,tagBegin,typeTagEnd)
	moveCategory = ParseInfoFromTag(line,tagBegin,categoryTagEnd)
	print move,moveType,moveCategory
	return move,moveType,moveCategory


	
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

def OnlyOfListEntries(dataSet,benchMarkList):
	for entry in dataSet:
		if entry not in benchMarkList:
			return False
	return True

#tests if line is last line of entry 
def IsEntryEnd(line):
	validEndChars = ['I','X','V']
	tokens = line.split()
	#print tokens
	if OnlyOfListEntries(tokens[-1],validEndChars):
		return True
	else:
		return False

def FilterNonListEntries(dataSet,benchMarkList):
	if isinstance(dataSet,str):
		result = ''
		for entry in dataSet:
			if entry in benchMarkList:
				result += entry
		return result
	
	result = []
	for entry in dataSet:
		if entry in benchMarkList:
			result.append(entry)
	return result

def FilterNumberInString(token):
	numberList = ['0','1','2','3','4','5','6','7','8','9']
	return FilterNonListEntries(token,numberList)

def ParseMove(fin):
	global processFinished

	line = fin.readline()
	if line == '\n' and line == '':
		return None

	entryData = line	
	while line != '' and not IsEntryEnd(line):
	#	print entryData
		line = fin.readline()
		entryData += line
	print entryData
	tokenList = entryData.split()
	if len(tokenList) == 0:
		return None
	#print tokenList
	print "herp derp"

	result = index = name = moveType = moveCategory = damage = ''




		


	#Parse Index
	index = tokenList[0]
	#Parse Name

	name = ParseInfoFromTag(entryData,tagBegin,nameTagEnd)

	#Parse Move Type
	moveType = ParseInfoFromTag(entryData,tagBegin,typeTagEnd)

	#Parse Move Category
	moveCategory = ParseInfoFromTag(entryData,tagBegin,categoryTagEnd)
	#Parse Move Damage
	damage = FilterNumberInString(tokenList[-3])


	result += index + '\n'
	result += name + '\n'
	result += moveType + '\n'
	result += moveCategory + '\n'
	result += damage + '\n' + '\n'

	return result 


def ReachBeginningOfData(fin,endingLine):
	line = fin.readline()
	while line != '' and line != endingLine:
		line = fin.readline()

	if line == '':
		print "REACHED END OF STREAM"

def ParseMoveFile(inputFileFullName,outputFileFullName):
	global processFinished
	fin = open(inputFileFullName,'r')
	fout = open(outputFileFullName,'w')

	ReachBeginningOfData(fin,endOfNonDataLine)

	data = ParseMove(fin)
	while data != None:
		fout.write(data)		
		data = ParseMove(fin)



	fin.close()
	fout.close()
	



ParseMoveFile('testInput.txt','testOutput.txt')



