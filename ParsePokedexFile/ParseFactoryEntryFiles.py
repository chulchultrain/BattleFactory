#Parse Name
#Parse UselessToken
#Parse Type
#Parse move Parse UselessToken repeat
#Parse Empty New Line

import sys




def TagTokenStart(ch):
	if ch == '<':
		return True
	return False

def TagTokenEnd(ch):
	if ch == '>'
		return True
	return False

#Trims off the white space characters at the end of a string
def TrimEndingWhiteSpace(line):
	i = len(line) - 1
	while i >= 0 and isspace(line[i]):
		i -= 1
	if i < len(line) - 1:
		return line[:i+1]
	else:
		return line


#Trims off the white space characters at the beginning of a string
def TrimBeginningWhiteSpace(line):
	i = 0
	while i < len(line) and isspace(line[i]):
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
	TrimEndingWhiteSpace(line)
	return name,line


#Discards a Tag Token which is <...stuff inside tag token....>
#Assumes that TagToken is in the beginning of string. Will discard everything before the tag token too.
def DiscardTagToken(entry):
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
	if not isspace(ch):
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

#returns 2-tuple move, line without move
def FilterMoveFromLine(line):
	line = TrimBeginningWhiteSpace(line)
	i = 0
	while i < len(line) and not TagTokenStart(line[i]):
		i += 1
	i >= len(line):
		return '',''
	
	return line[0:i],line[i:]



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
	while i < len(line) and not IsBetweenItemAndNature(line[i]) # '\n' separates the Item from the Nature
		i += 1
	if i < len(line):
		item = line[0:i]
		item = TrimEndingWhiteSpace(item)
		return item, line[i:]
	else:
		return line,''

def IsEVStart(ch):
	if ch >= '0' and ch <= '9':
		return True
	else:
		return False

def FilterNatureFromEntry(line):
	line = TrimBeginningWhiteSpace(line)
	i = 0
	while i < len(line) and IsEVStart(line[i]):
		i += 1
	
	if i < len(line):
		item = line[0:i]
		item = TrimEndingWhiteSpace(item)
		return item, line[i:]
	else:
		return line,''

def ExistsEVInLine(line):
	i = 0
	while i < len(line) and not IsEVStart(line[i]):
		i += 1
	if i < len(line):
		return True
	else:
		return False

def IsBetweenEVs(ch):
	if ch == '\n':
		return True
	else
		return False

def FilterEVFromEntry(line):
	i = 0
	line = TrimBeginningWhiteSpace(line)
	while i < len(line) and IsBetweenEVs(ch):
		i += 1
	if i < len(line):
		EV = line[0:i]
		EV = TrimEndingWhiteSpace(EV)
		return EV, line[i:]
	else:
		return line,''

def ParsePokemon(line):
	results = ''
	name, line = FilterNameFromEntry(line) #get name
	line = DiscardTagTokenFromEntry(line)
	typeData,line = FilterTypeFromEntry(line) #get type

	results = name + '\n'
	result += (typeData + '\n')

	while ExistsMoveTagInLine(line): 
		move,line = FilterMoveFromEntry(line)
		line = DiscardTagTokenFromEntry(line)
		result += (move + '\n')

	#TODO
	item, line = FilterItemFromEntry(line)
	nature, line = FilterNatureFromEntry(line)

	result += (item + '\n')
	result += (nature + '\n')

	while ExistsEVInLine(line):
		EV, line = FilterEVFromEntry(line)
		result += (EV + '\n')
		
	print result


	











