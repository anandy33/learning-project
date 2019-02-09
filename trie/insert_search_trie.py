class trieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEnd = False

class trie:
    def __init__(self):
        self.root = self.getNode()

    def char_to_index(self, char1):
        return ord(char1) - ord('a')

    def getNode(self):
        return trieNode()

    def insert(self, key):
        crawl = self.root
        length = len(key)
        for level in range(length):
            index = self.char_to_index(key[level])
            if not crawl.children[index]:
                crawl.children[index] = self.getNode()
            crawl = crawl.children[index]

        crawl.isEnd = True
    
    def search(self, key):
        crawl = self.root
        length = len(key)
        for level in range(length):
            index = self.char_to_index(key[level])
            if not crawl.children[index]:
                return False
            crawl = crawl.children[index]
        return crawl != None and crawl.isEnd

def main():
    keys = ["the", "keys", "a", "there", "answer", "by"]
    output = ["Not present in trie", "Present in trie"]

    t = trie()

    for key in keys:
        t.insert(key)

    print("{}------{}".format("their", output[t.search("their")]))

if __name__ == "__main__":
    main()
