

def ParsePokemon(fin):
	line = fin.readline()

	line2 = fin.readline()

	
	FL = line.split()
	SL = line2.split()
	#print FL
	#print SL

	index = int(FL[1][0:3])

	outputName = ''
	i = 3

	while i < len(FL):
		outputName += FL[i]
		i += 1
		if i < len(FL): 
			outputName += ' '

	outputData = ''

	i = 1
	if SL[1][0] == '(':
		#print "mega"
		megaEnd = 2
		while megaEnd < len(SL) and SL[megaEnd][-1] != ')':
			megaEnd += 1
		
		while i < megaEnd:
			outputName += (' ' + SL[i])
			i += 1
		outputName += (' ' + SL[megaEnd])
		i += 1

	print outputName
	
	counter = 0
	while i < len(SL) and counter < 8:
		if counter < 6:
			outputData += SL[i]
			outputData += '\n'
		i += 1
		counter += 1

	if counter < 8:
		line3 = fin.readline()
		TL = line3.split()
		c = 0
		while counter < 8:
			if counter < 6:
				outputData += TL[c]
				outputData += '\n'
			counter += 1
			c += 1

	#print outputName	

	

	fout = open("../BASE/STATS/" + outputName, 'w')	
	fout.write(outputData)
	return index

def TopLevel():
	fin = open("bulbapediastats.txt",'r')
	line = fin.readline()
	while line.find("# </wiki/National_Pok%C3%A9dex>") < 0:
		line = fin.readline()


	line = fin.readline()
	i = 0
	while i < 721:
		i = ParsePokemon(fin)
		

	fin.close()

#	IgnoreFirstPart


	#while < 721 parse pokemon

TopLevel()
