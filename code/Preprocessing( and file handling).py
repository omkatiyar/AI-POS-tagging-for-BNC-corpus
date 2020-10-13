# -*- coding: utf-8 -*-
"""
Created on Tue Oct 13 15:23:51 2020

@author: Om Katiyar
"""
import xml.etree.ElementTree as ET
from os.path import isdir
from os.path import isfile
from os import mkdir
from os import listdir
# function filehandle_mk = handles "a" single xml file
def filehandler (source, dest) :

	# xmlfile is the file to be handled
	xmlfile = open (source, "r",encoding= "utf-8")
	# we get the text into a variable
	xmlfiletext = xmlfile.read();

	#close xmlfile
	xmlfile.close()

	# make am xml tree from that text
	tree = ET.fromstring(xmlfiletext)

	# make list of word tags
	wlist = tree.iter('w')

	#open dest file with overwriting mode
	destfile = open (dest[:-4]+".txt", "w+", encoding = "utf-8")

	# put the data in the dfile
	for word in wlist :
		text = word.get('hw')
	#	text = text.rstrip()
		pos = word.get('pos')

		word_tag = "("+text+","+pos+")"
		
		destfile.write(word_tag + " ")


	#close file
	destfile.close()

def extractWordTags(source, dest) :

	#check if the source is a file
	if isfile(source):
		# if yes, then process the file 
		# if destination is not there , the function will create it, and if it is there, it will overrite it.
		filehandler(source,dest)
	else:
		# so the source is a folder, we need to make corresponding folder in the dest 
		#check if dest has the folder
		if not isdir(dest):
			mkdir(dest)
		
		# now enumerate all the items in the source directory    
		for item in listdir(source):
			extractWordTags(source+'/'+item,dest+'/'+item)



# source = "given_data"
# dest = "processed_data"

s = "./Train-corups"
d = "./Processed_train_corpus"

extractWordTags(s,d)