

baseStatOutputDir = "../BASE/STATS/"
baseStatInputDir = "../BASE/UNREFINED/UNFILTERED_BASE_STATS/"
baseStatFileName = "bulbapediastats.txt"

def ParsePokemon(fin):



	FL = fin.readline().split() #first line split into tokens
	SL = fin.readline().split() #second line split into tokens

	index = int(FL[1][0:3]) #the pokemon ID number

	outputName = '' #the name of the pokemon may or may not include a parentheses suffix indicating that it is special
	i = 3 #magic value of 3 because first line format is *418* 	418 </wiki/Buizel_(Pok%C3%A9mon)> 	Buizel

	#retrieve main part of name
	while i < len(FL):
		outputName += FL[i]
		i += 1
		if i < len(FL): 
			outputName += ' '


	outputData = '' #the stats to be output

	i = 1 #magic value of 1 because second line format always has one useless token in the beginning

	#if the pokemon is special, the 2nd token starts with a parentheses, and we keep processing tokens until we reach the closing paren.
	#
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

	print outputName #debug statement to make sure outputName is correct
	


	counter = 0

	#go through the 8 stats and
	#retrieve the 6 important stats
	while i < len(SL) and counter < 8:
		if counter < 6:
			outputData += SL[i]
			outputData += '\n'
		i += 1
		counter += 1

	#The 8 stats may not have all been gone through
	if counter < 8:
		TL = fin.readline().split()
		c = 0
		while counter < 8:
			if counter < 6:
				outputData += TL[c]
				outputData += '\n'
			counter += 1
			c += 1

	#print outputName	

	

	fout = open(baseStatOutputDir + outputName, 'w')	
	fout.write(outputData)
	return index

def TopLevel():
	fin = open(baseStatInputDir + baseStatFileName,'r')
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
