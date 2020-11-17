"""
author: sritam
date: 15th november 2020
time: 9:00 pm

"""
import pickle

#little bit difficult to determine the 
#matrix but soon will update
def matrix(wordtag_src,prediction_src,tagtrain_src,tagtest_src):

    file = open(wordtag_src, "r", encoding= "utf-8")

    pickled_prediction=open(prediction_src,"rb")
    prediction_dict=pickle.load(pickled_prediction)
    pickled_prediction.close()

    pickled_tagtrain=open(tagtrain_src,"rb")
    tagtrain_dict=pickle.load(pickled_tagtrain)
    pickled_tagtrain.close()

    pickled_tagtest=open(tagtest_src,"rb")
    tagtest_dict=pickle.load(pickled_tagtest)
    pickled_tagtest.close()

    index={}

    i=0
    for tag in tagtrain_dict:
        if tag not in index:
            index[tag]=i
            i +=1

    for tag in tagtest_dict:
        if tag not in index:
            index[tag]=i
            i +=1

    mat=[[0 for i in range(len(index))] for j in range(len(index))]

    for cnt, line in enumerate(file):
        arr = line.split()

        for pair in arr:
            if "_" not in pair:
                continue 

            item = pair.split("_")

            actual=item[1]
            predictd=prediction_dict[item[0]]
            # print(index[actual])
            # print(index[predictd])
            mat[index[actual]][index[predictd]] +=1
    print(mat)