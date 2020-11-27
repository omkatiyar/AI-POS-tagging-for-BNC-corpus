# -*- coding: utf-8 -*-
"""
Created on Thu Nov 26 14:20:04 2020

@author: Om Katiyar
"""

import collections
import pandas as pd
import matplotlib.pyplot as plt
# import nltk
import os
import numpy as np
import itertools


print("Opening the train sentences files...")

train_file = open('processed_data/train_combine.txt', "r", encoding="utf8")

print("File successfully loaded into memory....")
print("processing file into list") 

#  train_tagged_words = [tup for sentence in train_set for tup in sentence]
train_tagged_words = []
# train_tagged_tokens = []
# train_tagged_pos_tokens = []


count = 0
for line in train_file :
	# split the line into elements
	pairs = line.split()
	count = count + len(pairs)
	

	
print(count)


print("close file")

print("Opening the train sentences files...")

train_file = open('processed_data/train_combine.txt', "r", encoding="utf8")

print("File successfully loaded into memory....")
print("processing file into list") 



for line in train_file :
	# split the line into elements
	pairs = line.split()

	# iterate over each element
	for elem in pairs :
		# split the word tag 
		lis = elem.split("_")
		if len(lis) < 2 :
			continue
		train_tagged_words.append((lis[0],lis[1]))
	
print("file successfully changed into list")
	
# print(train_tagged_words)









# tokens in the train set - train_tagged_words
train_tagged_tokens = [tag[0] for tag in train_tagged_words]
print("word tokens created")

train_tagged_pos_tokens = [tag[1] for tag in train_tagged_words]
print("tag tokens created")
training_vocabulary_set = set(train_tagged_tokens)
training_pos_tag_set = set(train_tagged_pos_tokens)
# compute emission probability for a given word for a given tag
def word_given_tag(word, tag, dataSetToUse = train_tagged_words):
    tag_list = [pair for pair in dataSetToUse if pair[1] == tag]
    tag_count = len(tag_list)    
    word_given_tag_list = [pair[0] for pair in tag_list if pair[0] == word]    
    word_given_tag_count = len(word_given_tag_list)    
    
    return (word_given_tag_count, tag_count)

# compute transition probabilities of a previous and next tag
def tag2WhenTag1Given(t2, t1, dataSetToUse = train_tagged_words):
    tags = [pair[1] for pair in dataSetToUse]
    
    t1_tags_list = [tag for tag in tags if tag == t1]
    t1_tags_count = len(t1_tags_list)
    
    tag2WhenTag1Given_list = [tags[index+1] for index in range(len(tags)-1) if tags[index] == t1 and tags[index+1] == t2]
    tag2WhenTag1Given_count = len(tag2WhenTag1Given_list)
    
    return(tag2WhenTag1Given_count, t1_tags_count)

len_pos_tags = len(training_pos_tag_set)
len_vocab = len(training_vocabulary_set)

tags_matrix = np.zeros((len_pos_tags, len_pos_tags), dtype='float32')
for i, t1 in enumerate(list(training_pos_tag_set)):
    for j, t2 in enumerate(list(training_pos_tag_set)): 
        tags_matrix[i, j] = tag2WhenTag1Given(t2, t1)[0]/tag2WhenTag1Given(t2, t1)[1]
        
tags_df = pd.DataFrame(tags_matrix, columns = list(training_pos_tag_set), index=list(training_pos_tag_set))       


print("transition matrix created")

try :

	compression_opts = dict(method='zip', archive_name = 'tm.csv')
	tags_df.to_csv('out.zip',index = False, compression = compression_opts)
	print("transition matrix saved into csv")

except :
	print("couldnot save transition matrix as csv")










































# Viterbi Algorithm
def Vanilla_Viterbi(words, dataSetToUse = train_tagged_words):
    state = []
    
    T = list(set([pair[1] for pair in dataSetToUse]))
    
    for key, word in enumerate(words):
        #initialise list of probability column for a given observation
        p = [] 
        for tag in T:
            if key == 0:
                transition_p = tags_df.loc['.', tag]
            else:
                transition_p = tags_df.loc[state[-1], tag]
                
            # compute emission and state probabilities
            emission_p = word_given_tag(words[key], tag)[0]/word_given_tag(words[key], tag)[1]
            state_probability = emission_p * transition_p    
            p.append(state_probability)
            
        pmax = max(p)
        # getting state for which probability is maximum
        state_max = T[p.index(pmax)] 
        state.append(state_max)
    return list(zip(words, state)) 


print("Opening the test sentences files...")

test_file = open('./Test_data_sentences/test_sentences_combined.txt', "r", encoding="utf8")

print("File successfully loaded into memory....")
print("processing file into list") 

test_set = []

for line in test_file :
	# split the line into elements
	pairs = line.split()

	# iterate over each element
	sent =[]
	for elem in pairs :
		# split the word tag 
		lis = elem.split("_")
		if len(lis) < 2 :
			continue
		sent.append((lis[0],lis[1]))

	test_set.append(sent)
	
print("file successfully changed into list")


# list of tagged words
test_run_base = [tup for sent in test_set for tup in sent]

# list of untagged words
test_tagged_words = [tup[0] for sent in test_set for tup in sent]
tagged_seq = Vanilla_Viterbi(test_tagged_words)

# accuracy
vanilla_viterbi_word_check = [i for i, j in zip(tagged_seq, test_run_base) if i == j] 
vanilla_viterbi_accuracy = len(vanilla_viterbi_word_check)/len(tagged_seq) * 100
print('Vanilla Viterbi Algorithm Accuracy: ', vanilla_viterbi_accuracy)