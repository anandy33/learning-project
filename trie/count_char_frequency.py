
def char_freq(str1):
    dict = {}
    for n in str1:
        keys = dict.keys()
        if n in keys:
            dict[n] += 1
        else:
            dict[n] = 1
    return dict

def first_last(str1):
    if len(str1) < 2:
        return ""
    return str1[0:2] + str1[-2:]

def change_char(str1):
    char = str1[0]
    str1 = str1.replace(char, '$')
    print(str1)
    str1 = char + str1[1:]
    return str1

def char_mix_up(str1, str2):
    a = str2[:2] + str1[2:]
    b = str1[:2] + str2[2:]
    
    return a + " " + b

def adding(str1, rep):
    if rep in str1:
        str1 = str1 + "ly"
    else:
        str1 = str1 + "ing"
    
    return str1

def sequence(str1):
    f1 = str1.find("not")
    f2 = str1.find("poor")
    
    if f2 > f1 and f2 > 0 and f1 > 0 :
        str1 = str1.replace(str1[f1: f2+4], "good")
    return str1

def longest_word(str1):
    word_len = []
    for n in str1:
        word_len.append((len(n), n))

    word_len.sort()
    print(word_len)
    return word_len[-1][1]
    
def remove_char_at_index(str1, ind):
    left_str = str1[ : ind]
    right_str = str1[ind+1 : ]

    return left_str + right_str

def word_count(str1):
    counts = dict()
    words = str1.split()
    
    for word in words:
        if word in counts:
            counts[word] += 1
        else:
            counts[word] = 1
    return counts

def sort_unique():
    inp = input()
    #words = inp.split(",")
    words = [word for word in inp.split(",")]
    print(words)
    print(",".join(sorted(list(set(words)))))


if __name__ == "__main__": 
    print(sort_unique())
    print(word_count("hello i am good to see you again am good to hello and how are am"))
    print(char_freq("google.com"))
    print(first_last("hellohowareyou"))
    print(change_char("hello how are you hi"))
    print(char_mix_up("abc", "xyz"))
    print(adding("abc", "ing"))
    print(adding("playing", "ing"))
    print(sequence("this lyrics is that haing all how are movie poor name is"))
    print(longest_word(["hello", "exercide", "experimanet", "are"]))
    print(remove_char_at_index("helloiamgood", 6))
