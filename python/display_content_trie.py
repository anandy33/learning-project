
global alpha_size
alpha_size = 26

my_dict = {0: 'a', 1: 'b', 2: 'c', 3: 'd', 4: 'e', 5: 'f', 6: 'g', 7: 'h', 8:'i', 9:'j', 10: 'k', 11:'l',
           12: 'm', 13: 'n', 14: 'o', 15: 'p', 16: 'q', 17: 'r', 18: 's', 19: 't', 20: 'u', 21: 'v', 22: 'w',
           23: 'x', 24: 'y', 25: 'z'}
           
            

class trieNode:
    def __init__(self):
        self.children = [None]*26
        self.isEnd = False

class trie:
    def __init__(self):
        self.root = self.getNode()

    def getNode(self):
        return trieNode()
    
    def char_to_index(self, key):
        return ord(key) - ord('a')

    def insert(self, key):
        pCrawl = self.root
        length = len(key)
        for level in range(length):
            index = self.char_to_index(key[level])
            if not pCrawl.children[index]:
                pCrawl.children[index] = self.getNode()
            pCrawl = pCrawl.children[index]
        pCrawl.isEnd = True

    def complete_traversal(self, pRoot, str):
        if pRoot.isEnd == True:
            print(str)

        for i in range(alpha_size):
            if(pRoot.children[i]):
                str.append(my_dict.get(i))
                self.complete_traversal(pRoot.children[i], str)
                str.pop()

    def display(self):
        pRoot = self.root
        str=[]
        self.complete_traversal(pRoot, str)

def main():
    keys = ["the", "abcde", "their", "there", "answer", "any"]
    t = trie()
    
    for key in keys:
        t.insert(key)
        
    t.display()

if __name__ == "__main__":
    main()
