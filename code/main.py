"""
author: sritam
date: 15th october 2020
time: 6:00 pm

"""
import os,sys
from probability_of_words_given_tags import probability
from preprocessor import makeWordTags_mk


#preprocessing the xml files
makeWordTags_mk("given_data","processed_data")

#calculating the probability of words given tags
tmp="pickle/"
probability(tmp+"words_train",tmp+"tags_train",
    tmp+"wordtag_train",tmp+"word_probability")

