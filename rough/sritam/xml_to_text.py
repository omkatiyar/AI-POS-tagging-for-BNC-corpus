import os
import sys
import xml.etree.ElementTree as ET


def word_tag(source,destination):

    file=open(source,'r',encoding="utf8")
    data=file.read()
    file.close()

    tree=ET.fromstring(data)
    word_list=tree.iter('w')

    dest_file=open(destination[:-3]+"txt","w+",encoding="utf8")

    for word in word_list:
        dest_file.write(word.text.strip()+"_"+word.get('c5')+" ")

    dest_file.close()








