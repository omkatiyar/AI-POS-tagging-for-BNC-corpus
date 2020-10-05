import os
import sys

def list_files(startpath):
    for root,dir,files in os.walk(startpath):
        if dir !='.git ':
            for f in files:
                print(f,end=" ")



sys.stdout = open('output.txt', 'w')

#printing all train files
os.chdir('given_files/train_corpus')
list_files(os.getcwd())

print(" ")
#printing all test files
os.chdir('..')
os.chdir('test_corpus')
list_files(os.getcwd())

# print (os.listdir())