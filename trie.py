class Node:

    def __init__(self, alpha_size):
        self.end_of_word = False
        self.node_refs = [None for i in range(alpha_size)]

class Trie:
    def __init__(self, alphabet_site=26):
        self.root = None
        self.al_size = alphabet_site 

    def insert(self, string):
        if not self.root:
            self.root = Node(self.al_size)
        int_a, curr_node = ord('a'), self.root
        for c in string:
            index = ord(c) - int_a
            if not curr_node.node_refs[index]:
                curr_node.node_refs[index] = Node(self.al_size)
            curr_node = curr_node.node_refs[index]
        curr_node.end_of_word = True


    def print_trie_util(self, node, string):
        if node:
            if node.end_of_word:
                print string
            for i in range(self.al_size):
                if node.node_refs[i]:
                    self.print_trie_util(node.node_refs[i], string+chr(ord('a')+i))
    
    def print_trie(self):
        self.print_trie_util(self.root, "")
    
    def search(self, string):
        if not self.root:
            raise Exception("Query in an empty trie")
        int_a, curr_node = ord('a'), self.root 
        for c in string:
            index = ord(c) - int_a
            if not curr_node.node_refs[index]:
                return False
            curr_node = curr_node.node_refs[index]
        return (curr_node and curr_node.end_of_word)
    
    def has_children(self, node):
        for i in range(self.al_size):
            if node.node_refs[i]: return True
        return False

    def remove_util(self, node, string):
        if string:
            index = ord(string[0]) - ord('a')
            if node.node_refs[index]:
                node.node_refs[index] = self.remove_util(node.node_refs[index], string[1:])
        elif node.end_of_word:
            node.end_of_word = False
        if not self.has_children(node) and not node.end_of_word:
            node = None
        return node

    def remove(self, string):
        if not self.root:
            raise Exception("Delete operation on Empty Trie")
        self.root = self.remove_util(self.root, string)

if __name__ == '__main__':
    string = "there are multiple multi words in this sentence aree"
    trie = Trie()
    for s in string.split():
        trie.insert(s)
    trie.print_trie()
    trie.remove("multi")
    print 
    trie.print_trie()
    #print trie.search("are")
