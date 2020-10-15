from xml_to_text import word_tag
import os,sys


sys.stdout = open('output.txt', 'w')

def practice(source,destination):
    
    if os.path.isfile(source):
        word_tag(source,destination)

    else:
        if not os.path.isdir(destination):
            os.mkdir(destination)

        all_items=os.listdir(source)
        for item in all_items:
            practice(source+'/'+item,destination+'/'+item)

src="test_corpus"
dest="temp"

practice(src,dest)


