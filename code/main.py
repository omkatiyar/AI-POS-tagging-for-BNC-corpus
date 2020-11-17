"""
author: sritam
date: 15th october 2020
time: 6:00 pm

"""
import os,sys
from probability_of_words_given_tags import probability
from preprocessor import makeWordTags_mk
from predict_tags import predict
from prediction_accuracy import accuracy
from confusion_matrix import matrix

# #preprocessing the xml files  
# makeWordTags_mk("given_data","processed_data")

# #calculating the probability of words given tags
tmp="pickle/"
# probability(tmp+"words_train",tmp+"tags_train",
#     tmp+"wordtag_train",tmp+"word_probability")

# predict(tmp+"words_test",tmp+"tags_train",
#     tmp+"word_probability",tmp+"tag_predict")

accuracy(tmp+"words_test",tmp+"wordtag_test",tmp+"tag_predict")

matrix("processed_data/test_combine.txt",tmp+"tag_predict",
    tmp+"tags_train",tmp+"tags_test")

