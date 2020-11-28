# -*- coding: utf-8 -*-
"""
Created on Thu Nov 26 15:55:32 2020

@author: Om Katiyar
"""

# -*- coding: utf-8 -*-
"""
Created on Thu Nov 26 15:33:10 2020

@author: Om Katiyar
"""

from os import listdir
from os.path import isfile


def dump_mk(source,dest):

	sfile = open(source, "r", encoding= "utf-8")
	dfile = open(dest, "a", encoding= "utf-8")

	#read entire sfile and then dump that  into the dfile as itis.
	dfile.write(sfile.read())
	dfile.write("\n")

	sfile.close()
	dfile.close()

def combine_mk(source, dest) :

	#check if the source is a file
	if isfile(source):
		# if yes, then process the file 
		# if destination is not there , the function will create it, and if it is there, it will overrite it.
		dump_mk(source,dest)
	else:
		# so the source is a folder, 
		# now enumerate all the items in the source directory  
		# and take appropriate actions  
		for item in listdir(source):
			combine_mk(source+'/'+item,dest)




# s = "./Desktop/ML/Test_data_sentences"
# d = "./Desktop/ML/Test_data_sentences/test_sentences_combined.txt"
# dfile = open(d, "w+", encoding= "utf-8")
# dfile.close()

# combine_mk(s,d)

# s = "./Desktop/ML/Test_data_sentences"
# d = "./Desktop/ML/Test_data_sentences/test_sentences_combined.txt"
# dfile = open(d, "w+", encoding= "utf-8")
# dfile.close()

# combine_mk(s,d)

s="processed_data"
d = "processed_data/test_combine"
dfile = open(d,"w+", encoding="utf-8")
dfile.close()

combine_mk(s,d)
