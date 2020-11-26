#Sentence.py
#author : mohit kumar
#date of creation : 26 oct 2020
#time : morning, 11 45 am

import xml.etree.ElementTree as xmltree

from os.path import isdir
from os.path import isfile
from os import mkdir
from os import listdir


# function
# this will detemrine all the sectences and store them .
def filehandle_mk_Sentences (source, dest) :

	# xmlfile is the file to be handled
	xmlfile = open (source, "r",encoding= "utf-8")
	# we get the text into a variable
	xmlfiletext = xmlfile.read();

	#close xmlfile
	xmlfile.close()

	# make am xml tree from that text
	tree = xmltree.fromstring(xmlfiletext)

	# make list of sentences
	slist = tree.iter('s')

	#open dest file with overwriting mode
	dfile = open (dest[:-4]+"_sentence.txt", "w+", encoding = "utf-8")

	# put the data in the dfile
	for sentence in slist :

		# declare a line variable to store the sentence
		line = ""

		# iterate over every variable in sentence
		for elem in sentence :
			# fetch pos tag of this elem
			pos = elem.get('c5')
			# if the child doesnot contains c5 then it is of no use for us
			if pos is None :
				continue
			# if I am here it  means pos has c5 tag available so we need to find the text of it.	
			txt = elem.text
			if txt is None : 
				continue
			txt = txt.strip()	
			# append in the sentence this word
			line = line + txt + "_"+ pos +" "

		# for word loop finshes

		# write the sentence to the file
		dfile.write(line+"\n")	

	# for sentence loop finished 


	#close file
	dfile.close()




# function
# this will fetch all the files and generate corresponding files
# this takes source folder and 
def makeSentences_mk(source, dest) :

	#check if the source is a file
	if isfile(source):
		# if yes, then process the file 
		# if destination is not there , the function will create it, and if it is there, it will overrite it.
		filehandle_mk_Sentences(source,dest)
	else:
		# so the source is a folder, we need to make corresponding folder in the dest 
		#check if dest has the folder
		if not isdir(dest):
			mkdir(dest)
		
		# now enumerate all the items in the source directory    
		for item in listdir(source):
			makeSentences_mk(source+'/'+item,dest+'/'+item)



# source = "given_data"
# dest = "processed_data"

# # testing data which will be processed
# source = "A1A.xml"
# dest = "processed_data/A1A.xml"
# makeSentences_mk(source,dest)


# real data to be tested 
s = "given_data"
d = "processed_data"

makeSentences_mk(s,d)


