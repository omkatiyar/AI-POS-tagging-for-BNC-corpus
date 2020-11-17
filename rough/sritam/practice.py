from xml_to_text import word_tag
import os,sys

sys.stdin = open('input.txt', 'r')
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

# practice(src,dest)
a=[[0 for i in range(5)] for j in range(5)]
a[0][0] +=1
a[1][2] +=6

b={}
b[0]=1
b[1]=0
print(len(b))
for i in b:
    print(b[i])
# print(a)


