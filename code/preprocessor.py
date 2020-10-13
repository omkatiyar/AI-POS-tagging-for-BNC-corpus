#preprocessor.py

# this updates all the files

from fileprocessor import filehandle_mk


from os.path import isdir
from os.path import isfile
from os import mkdir
from os import listdir


# this takes source folder and 
def makeWordTags_mk(source, dest) :

	#check if the source is a file
	if isfile(source):
		# if yes, then process the file 
		# if destination is not there , the function will create it, and if it is there, it will overrite it.
		filehandle_mk(source,dest)
	else:
		# so the source is a folder, we need to make corresponding folder in the dest 
		#check if dest has the folder
		if not isdir(dest):
			mkdir(dest)
		
		# now enumerate all the items in the source directory    
		for item in listdir(source):
			makeWordTags_mk(source+'/'+item,dest+'/'+item)



# source = "given_data"
# dest = "processed_data"

s = "given_data"
d = "processed_data"

makeWordTags_mk(s,d)