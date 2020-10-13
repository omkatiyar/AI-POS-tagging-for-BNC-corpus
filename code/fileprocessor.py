#fileprocessor.py

# this file will contain the code that will be used to preprocess the the xml file


import xml.etree.ElementTree as xmltree

# function filehandle_mk = handles "a" single xml file
def filehandle_mk (source, dest) :

	# xmlfile is the file to be handled
	xmlfile = open (source, "r",encoding= "utf-8")
	# we get the text into a variable
	xmlfiletext = xmlfile.read();

	#close xmlfile
	xmlfile.close()

	# make am xml tree from that text
	tree = xmltree.fromstring(xmlfiletext)

	# make list of word tags
	wlist = tree.iter('w')

	#open dest file with overwriting mode
	dfile = open (dest[:-4]+".txt", "w+", encoding = "utf-8")

	# put the data in the dfile
	for word in wlist :
		text = word.text
		text = text.rstrip()
		pos = word.get('pos')

		word_tag = text+"_"+pos
		
		dfile.write(word_tag + " ")


	#close file
	dfile.close()









