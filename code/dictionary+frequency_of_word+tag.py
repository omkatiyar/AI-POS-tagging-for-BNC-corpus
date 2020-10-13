# -*- coding: utf-8 -*-
"""
Created on Wed Oct 14 01:29:27 2020

@author: Om Katiyar
"""

import collections
import pandas as pd
import matplotlib.pyplot as plt

file = open('./Processed_train_corpus/Combined_train_corpus.txt', encoding="utf8")
a= file.read()

word_tag = {}
word = {}
tag = {}
for wordtag in a.lower().split():
    if wordtag not in word_tag:
            word_tag[wordtag] = 1
    else:
            word_tag[wordtag] += 1
    if "_" not in wordtag:
      continue
    part=wordtag.split("_")
    if part[0] not in word:
        word[part[0]]=1
    else:
        word[part[0]]+=1    
    if part[1] not in tag:
        tag[part[1]] =1
    else:
        tag[part[1]]+=1
        
freqword=10
word_counter = collections.Counter(word)
for word, count in word_counter.most_common(freqword):
    print(word, ": ", count)           

tag_counter = collections.Counter(tag)
for word,count in tag_counter.most_common(freqword):
    print(tag, ": ",count)
    
file.close()

lst = word_counter.most_common(freqword)
df = pd.DataFrame(lst, columns = ['Word', 'Count'])
df.plot.bar(x='Word',y='Count')

pst = tag_counter.most_common(freqword)
df = pd.DataFrame(pst, columns = ['Tag', 'Count'])
df.plot.bar(x='Tag',y='Count')    