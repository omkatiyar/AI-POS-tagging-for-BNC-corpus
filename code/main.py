"""
author: sritam
date: 15th october 2020
time: 6:00 pm

"""

# changes by mohit on 26 Nov 2020

# importing system libraries 
import os,sys

# import module for basic probabilty system
from probability_of_tags_given_words import probability

# import file handling modules 
from preprocessor import makeWordTags_mk

# import predict function
from predict_tags import predict
from prediction_accuracy import accuracy
from confusion_matrix import matrix
# changes by mohit done


# mohit changes on 26 nov 2020
# importing the senntences module :)
from sentnces import makeSentences_mk
# changes by mohit done

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


# # EDITS BY :Mohit
# # FOR VITERBHI BASED HMM IMPLEMENTATION :)

# # code to make distribution based on sentences


# sourceForSentences = "given_data"
# print("Source Data for Sentences Selected")
# destForSentences = "processed_data"
# print("Dest Data for Sentences Selected")
# print("Processing started ...")
# makeSentences_mk(sourceForSentences, destForSentences)
# print("... processing finished!")

# # sentences formed

