# week2advance.py

# this file is used to recover the pickled objects and then, it analyses them
#author : mohit kumar
#date of creation : 13 oct 2020
#time : night 10 pm
import pickle
import operator

# this funciton takes src, a pickle file and then does our work.
def findMostFrequentElements(src) :
	
	#open the file in which pickled obejct is there
	file = open(src, 'rb')

	# convert pickle to dictionary
	words = pickle.load(file)

	#close file
	file.close()


	sorted_words = dict( sorted(words.items(), key=operator.itemgetter(1),reverse=True))

	count = 0
	for item in sorted_words.items():
		count = count + 1
		print("The Rank :", count, " ", item)
		if count == 10 : 
			break

 

#find most frequent 10 words in train data
print("The most frequent 10 words in train data : ")
src = 'pickle/words_train'
findMostFrequentElements(src)

#find most frequent 10 tags in train data
print("The most frequent 10 tags in train data : ")
src = 'pickle/tags_train'
findMostFrequentElements(src)

#find most frequent 10 words in train data
print("The most frequent 10 wordtag pairs in train data : ")
src = 'pickle/wordtag_train'
findMostFrequentElements(src)

