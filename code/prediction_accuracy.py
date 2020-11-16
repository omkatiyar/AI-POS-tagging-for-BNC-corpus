"""
author: sritam
date: 16th october 2020
time: 2:30 pm

"""
import pickle

def accuracy(word_src,wordtag_src,prediction_src):

    pickled_words=open(word_src,"rb")
    word_dict=pickle.load(pickled_words)
    pickled_words.close()

    pickled_wordtag=open(wordtag_src,"rb")
    wordtag_dict=pickle.load(pickled_wordtag)
    pickled_wordtag.close()

    pickled_prediction=open(prediction_src,"rb")
    prediction_dict=pickle.load(pickled_prediction)
    pickled_prediction.close()

    ans=0
    count=0
    for word in word_dict:
        tag=prediction_dict[word]

        if word+"_"+tag in wordtag_dict:
            ans = ans + wordtag_dict[word+"_"+tag]

        count =count + word_dict[word]

    print(round((ans*100)/count,2))