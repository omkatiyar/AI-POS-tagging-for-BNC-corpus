#create basic dictionaries

import pickle

# this file will make three dictionaries and will save them in the pickle folder
# first dictionary has word_tag as key and it's count as the value
# second dictionary will have word as key and it's count as value
# third dictionary will have tag as key and it's count as value

#also this file pickles the dictionaries as well.

def pickleTheFile_mk(src ,dest1 ,dest2 ,dest3) :
	# create three empty dictionaries for the execution
	wordtag = {} # handles the wordtag records
	word  = {} # handles the word records
	tag = {}  # handles the tag records


	# open the file on which dictioaries are to be made
	# to be more clear, open "processed_data/train_combine.txt"
	file = open(src, "r", encoding= "utf-8")

	# run the for loop for the same
	for cnt, line in enumerate(file):
		#split the  line into word_tag pairs
		lis = line.split()
		# work on individual item in the list we have obtained
		for item in the lis :
			# check wordtag pair
			if item is not in the wordtag :
				wordtag[item] = 1
			else :
				wordtag[item] = wordtag[item] +1

			parts = item.split("_")

			if parts[0] in word :
				word[parts[0]] = word[parts[0]] + 1
			else :
				word[parts[0]] = 1

			if parts[1] in tag :
				tag[parts[1]] = tag[parts[1]] + 1
			else :
				tag[parts[1]] = 1


	# now the dictionaries have been made
	# we need to pickle them

	#pickling first the wordtag dictionary
	pickling_on = open(dest1,"wb")
	pickle.dump(wordtag, pickling_on)
	pickling_on.close()

	print("Successfull dumping in the : ", dest1)

 	#pickling word dictionary
	pickling_on = open(dest2,"wb")
	pickle.dump(word, pickling_on)
	pickling_on.close()

	print("Successfull dumping in the : ", dest2)

	#pickling tag dictionary
	pickling_on = open(dest3,"wb")
	pickle.dump(tag, pickling_on)
	pickling_on.close()

	print("Successfull dumping in the : ", dest3)

	#function ends here





# src = "processed_data/train_combine.txt"


