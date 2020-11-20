"""
author: sritam
date: 15th october 2020
time: 6:00 pm

"""

import os,sys
from probability_of_tags_given_words import probability
from preprocessor import makeWordTags_mk
from predict_tags import predict
from prediction_accuracy import accuracy
from confusion_matrix import matrix

#preprocessing the xml files  
# makeWordTags_mk("given_data","processed_data")

tmp="pickle/"

#calculating the probability of words given tags

# probability(tmp+"words_train",tmp+"tags_train",
#     tmp+"wordtag_train",tmp+"word_probability")

# predict(tmp+"words_test",tmp+"tags_train",
#     tmp+"word_probability",tmp+"tag_predict")

# accuracy(tmp+"words_test",tmp+"wordtag_test",tmp+"tag_predict")

matrix("processed_data/test_combine.txt",tmp+"tag_predict",
    tmp+"tags_train",tmp+"tags_test")

