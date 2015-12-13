#Purpose of this script is to take all the usable data and present it in a format for my other programs to understand.
#The information we will be taking from the files will be
#Name	- string
#Type	- string
#Move List - string of numbers
#Item - string
#Nature - string
#EV List 


#Parse Name
#Parse UselessToken
#Parse Type
#Parse move Parse UselessToken repeat
#Parse Empty New Line

entryInputDir = "../BASE/UNREFINED/UNFILTERED_FACTORY_ENTRIES/"
DPPRegionSubDir = "DPP/"
regionSubDir = DPPRegionSubDir
DPPInputFileNameList = {"Kanto.txt":"Filter_R1.txt","Johto.txt":"Filter_R2.txt","Hoenn.txt":"Filter_R3.txt","Sinnoh.txt":"Filter_R4.txt"}
inputFileNameList = DPPInputFileNameList

fullNameInputFileList = {}

entryOutputDir = "../BASE/UNREFINED/FULL_FILTER_ENTRIES/"

for entry in inputFileNameList:
	fullNameInputFileList[entryInputDir + regionSubDir + entry] = entryOutputDir + regionSubDir + DPPInputFileNameList[entry]
	
for entry in fullNameInputFileList:
	print entry, fullNameInputFileList[entry]


#DPPOutputFileNameList = DPPInputFileNameList

#fullNameOutputFileList = []

#for entry in outputFileNameList:
#	fullNameOutputFileList += [entryOutputDir + regionSubDir + entry]
	

#for entry in fullNameOutputFileList
#	print entry


import sys

moveDexString = "dex/techdex/"


def TagTokenStart(ch):
	if ch == '<':
		return True
	return False

def TagTokenEnd(ch):
	if ch == '>':
		return True
	return False

#Trims off the white space characters at the end of a string
def TrimEndingWhiteSpace(line):
	i = len(line) - 1
	while i >= 0 and line[i].isspace():
		i -= 1
	if i < len(line) - 1:
		return line[:i+1]
	else:
		return line


#Trims off the white space characters at the beginning of a string
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
	


#name is always the first string until the < to indicate a tag.
#return 2-tuple name, line without the name
def FilterNameFromEntry(line):
	i = 0
	while i < len(line) and not TagTokenStart(line[i]): #iterate through entry to check when the name is
		i += 1

	name = line[0:i]
	line = line[i + 1:]
	name = TrimEndingWhiteSpace(name)
	return name,line


#Discards a Tag Token which is <...stuff inside tag token....>
#Assumes that TagToken is in the beginning of string. Will discard everything before the tag token too.
def DiscardTagTokenFromEntry(line):
	start = 0
	while start < len(line) and not TagTokenStart(line[start]):
		start += 1
	end = start
	while end < len(line) and not TagTokenEnd(line[end]):
		end += 1
	
	if end + 1 >= len(line):
		return ''

	return line[end + 1:]

def ValidTypeChar(ch):
	if not ch.isspace():
		return True
	else:
		return False
	
#returns 2-tuple typeData,line without typeData
def FilterTypeFromEntry(line):
	line = TrimBeginningWhiteSpace(line)
	i = 0
	while i < len(line) and ValidTypeChar(line[i]):
		i += 1
	if i >= len(line):
		return '',''

	return line[0:i],line[i:]

def RidOfBeginningZeroes(num):
	i = 0
	while i < len(num) and num[i] == '0':
		i += 1
#	if i != 0:
#		print num[i:]
	return num[i:]

#returns 2-tuple move, line without move
def FilterMoveFromEntry(line):
	line = TrimBeginningWhiteSpace(line)

	j = line.find(moveDexString)
	if j == -1:
		return line,''
	else:
		j += len(moveDexString)

	#move is of form /dex/techdex/### so we parse out ###
	move = ''
	while  j < len(line) and not TagTokenEnd(line[j]):
		if line[j] >= '0' and line[j] <= '9':
			move += line[j]
			j += 1
		else:
			break;

	

	if j < len(line):
		if TagTokenEnd(line[j]):
			j += 1
		move = TrimEndingWhiteSpace(move)
		move = RidOfBeginningZeroes(move)
		return move,line[j:]
	else:
		line = TrimEndingWhiteSpace(line)
		line = RidOfBeginningZeroes(move)
		return line,''



def ExistsMoveTagInLine(line):
	i = 0
	#as of right now, it may accept all tags, when necessary change to just move tags
	while i < len(line) and line[i] != '<':
		i += 1
	if i < len(line):
		return True
	else:
		return False

def IsBetweenItemAndNature(ch):
	if ch == '\n':
		return True
	else:
		return False

def FilterItemFromEntry(line):
	line = TrimBeginningWhiteSpace(line)
	i = 0
	while i < len(line) and not IsBetweenItemAndNature(line[i]): # '\n' separates the Item from the Nature
		i += 1
	if i < len(line):
		item = line[0:i]
		item = TrimEndingWhiteSpace(item)
		return item, line[i:]
	else:
		line = TrimEndingWhiteSpace(line)
		return line,''

def IsEVStart(ch):
	if ch >= '0' and ch <= '9':
		return True
	else:
		return False

def IsNatureEnd(ch):
	if ch.isspace():
		return True
	else:
		return False

def FilterNatureFromEntry(line):
	line = TrimBeginningWhiteSpace(line)
	i = 0
	while i < len(line) and not IsNatureEnd(line[i]):
		i += 1
	
	if i < len(line):
		item = line[0:i]
		item = TrimEndingWhiteSpace(item)
		return item, line[i:]
	else:
		line = TrimEndingWhiteSpace(line)
		return line,''

def ExistsEVInLine(line):
	i = 0
	while i < len(line) and not IsEVStart(line[i]):
		i += 1
		#print i
	if i < len(line):
		return True
	else:
		return False

def IsBetweenEVs(ch):
	if ch == '\n':
		return True
	else:
		return False

def FilterEVFromEntry(line):
	i = 0
	line = TrimBeginningWhiteSpace(line)
	while i < len(line) and not IsBetweenEVs(line[i]):
		i += 1
	if i < len(line):
		EV = line[0:i]
		EV = TrimEndingWhiteSpace(EV)
		return EV, line[i:]
	else:
		line = TrimEndingWhiteSpace(line)
		return line,''

def ParsePokemon(line):
	result = ''
	name, line = FilterNameFromEntry(line) #get name
	line = DiscardTagTokenFromEntry(line)
	typeData,line = FilterTypeFromEntry(line) #get type

	result = name + '\n'
	result += (typeData + '\n')

	while ExistsMoveTagInLine(line): 
		move,line = FilterMoveFromEntry(line)
		#line = DiscardTagTokenFromEntry(line)
		result += (move + '\n')


	item, line = FilterItemFromEntry(line)
	nature, line = FilterNatureFromEntry(line)

	#print nature
	result += (item + '\n')
	result += (nature + '\n')


	while ExistsEVInLine(line):
		EV, line = FilterEVFromEntry(line)
		result += (EV + '\n')
		
	return result




def NotFinishedEntry(line): #TODO
	if line != '\n':
		return True
	else:
		return False

def FilterFile(inputFileName,outputFileName):
	fin = open(inputFileName,'r')
	fout = open(outputFileName, 'w')
	ProcessFinished = False
	
	while not ProcessFinished:
		line = fin.readline()
		entry = line
		while line != '' and NotFinishedEntry(line):
			entry += line
			line = fin.readline()
		if line != '':
			fout.write( ParsePokemon(entry) + '\n')
		else: #line == '' therefore no more entries
			ProcessFinished = True


for entry in fullNameInputFileList:
	print entry, fullNameInputFileList[entry]
	FilterFile(entry,fullNameInputFileList[entry])






