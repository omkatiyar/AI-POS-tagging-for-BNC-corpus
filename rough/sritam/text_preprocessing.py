"""
This file contains the codes that will be splitted into parts in future for specific functions.
This is a more or less prototype file of combined methods for preprocessing of xml files into
required format

"""

import sys
import os
import string
import nltk
import re
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from nltk.stem import WordNetLemmatizer
from bs4 import BeautifulSoup
import xml.etree.ElementTree as ET

#for processing input and output manually
sys.stdin = open('input.txt', 'r') 
sys.stdout = open('output.txt', 'w')

#sample code for parsing xml file and extracting neccessary data from it
mytree =ET.parse('sample.xml')
myroot =mytree.getroot()
for x in myroot:
    for y in x:
        print(y.text)

#reading manual input
s=input()

# converting the input string into lower case letters
s = s.lower()

# removing the numericals 0-9
s = re.sub(r'\d+', '',s)

# removing punctuations
s=s.translate(str.maketrans('','',string.punctuation))

# removing white spaces from starting and ending
s= s.strip()

#removing stopwords like the,or,int etc.
stop_words = set(stopwords.words('english'))
tokens = word_tokenize(s)
result =[]
for i in tokens:
    if not i in stop_words:
        result.append(i)

#stemming the words  
stemmer =PorterStemmer()
result1=[]
for i in result:
    result1.append(stemmer.stem(i));

#bringing words into their original form
result2=[]
lemmatizer = WordNetLemmatizer()
for i in result:
    result2.append(lemmatizer.lemmatize(i))

tagged_list=nltk.pos_tag(result2)

# showing the processed result
print(tagged_list)



