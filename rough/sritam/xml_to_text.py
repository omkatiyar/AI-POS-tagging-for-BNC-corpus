import os
import sys
import xml.etree.ElementTree as ET


def to_text(file):

    mytree =ET.parse(file)
    myroot =mytree.getroot()
    print()
    for word in myroot.iter():
        print(word.tag)

def list_files(startpath):
    for root,dir,files in os.walk(startpath):
        for f in files:
            print(f)
            with open(root+'\\'+f,"rb") as data:
                to_text(data)

            break





sys.stdout = open('output.txt', 'w')

#printing all train files

os.chdir('train_corpus')
# print(os.getcwd())
list_files(os.getcwd())

print(" ")

#printing all test files
os.chdir('..')
os.chdir('test_corpus')
list_files(os.getcwd())

