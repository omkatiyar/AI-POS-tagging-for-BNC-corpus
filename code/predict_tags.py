"""
author: sritam
date: 15th november 2020
time: 9:00 pm

"""
import pickle

def predict(word_src,tag_src,prob_src,destination):

    ##unpickling the words dictionary of the test data
    pickled_words=open(word_src,"rb")
    word_dict=pickle.load(pickled_words)
    pickled_words.close()

    #unpickling the tags dictionary of the train data
    pickled_tag=open(tag_src,"rb")
    tag_dict=pickle.load(pickled_tag)
    pickled_tag.close()

    #unpickling the probability dictionary to predict tags
    pickled_prob=open(prob_src,"rb")
    prob_dict=pickle.load(pickled_prob)
    pickled_prob.close()

    #predicting the tags for words
    ''' the predicted tag is the tag which has the highest
        probability among all tags''' 

    predict_tag={}
    
    for word in word_dict:
        x=0
        for tag in tag_dict:
            if word+"_"+tag in prob_dict :
                if prob_dict[word+"_"+tag]>x:
                    x=prob_dict[word+"_"+tag]
                    predict_tag[word]=tag
        if x==0 :
            predict_tag[word]= "NN1"

    #pickling the computed results
    pickling_into=open(destination,"wb")
    pickle.dump(predict_tag,pickling_into)
    pickling_into.close()

