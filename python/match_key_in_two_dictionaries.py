

def match():
    dict1 = {"key1":1, "key2" : 2,"key3" : 3}

    dict2 = {"key1" :4, "key2": 2, "key3" : 5}
    
    for (key, value) in set(dict1.items()) & set(dict2.items()):
        print("key and value present in both dict   %s %s " %( key, value))



if __name__ == "__main__":
    match()
