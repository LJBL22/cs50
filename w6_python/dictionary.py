# compare to c , trad-off, performance
# others wrote the codes for you
# save human programmer time, but trade-off the performance
# N hours vs 60 sec :)


# words = dict() # return a hash table
words = set() # a collection of values with no duplicates
# in this case, just check if the word exist or not, so don't even need a key-value pair, only keys are needed

def check(word): # bool check(const char *word)
    if word.lower() in words:
        return True
    else:
        return False
def hash(word): # unsigned int hash(const char *word)
# ... doesn't even need to exist here lol
def load(dictionary): # bool load(const char *dictionary)
    file = open(dictionary, "r")
    # for line in file:
    #         words.add(line)
    for line in file:
        word = line.rstrip() # 刪除掉最後一個 \n 以判別 word （因為提供的字典中每行都是一個字）
        words.add(word)
    close(file)
    return True

def size(): # unsigned int size(void)
    return len(words) # c 是多個 node 的概念。而 python 的 set 已經是一串字了，所以直接回傳長度即可。
def unload(): # bool unload(void)
    return True # no more malloc & free... & memory control thing