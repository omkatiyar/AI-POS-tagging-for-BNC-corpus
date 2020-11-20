"""
author: sritam
date: 15th october 2020
time: 5:00 pm

"""
import pickle

def probability(word_src,tag_src,wordtag_src,destination):

    #unpickling the words dictionary
    pickled_words=open(word_src,"rb")
    word_dict=pickle.load(pickled_words)
    pickled_words.close()

    #unpickling the tag dictionary
    pickled_tag=open(tag_src,"rb")
    tag_dict=pickle.load(pickled_tag)
    pickled_tag.close()

    #unpickling the wordtag dictionary
    pickled_wordtag=open(wordtag_src,"rb")
    wordtag_dict=pickle.load(pickled_wordtag)
    pickled_wordtag.close()

    #creating a new dictionary for storing computed probability
    #for each words
    word_probability={}

    #computing the probability for each tags given word
    for word in word_dict:
        for tag in tag_dict:
            if word+"_"+tag in wordtag_dict:
                prob=wordtag_dict[word+"_"+tag]/word_dict[word]
                word_probability[word+"_"+tag]=prob

    #pickling the computed results to the destination
    pickling_into=open(destination,"wb")
    pickle.dump(word_probability,pickling_into)
    pickling_into.close()




