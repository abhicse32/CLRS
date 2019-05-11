class TernaryST:
    class Node:
        def __init__(self, ch=None):
            self.data = ch
            self.left = None
            self.middle = None
            self.right = None
            self.end_of_word = None

    def __init__(self):
        self.root = None
    
    def find_first_node(self, node, ch):
        prev = node 
        while node:
            if node.data < ch:
                node = node.right

    def insert_recursive(self, node, string, l):
        if l < len(string):
            if not node:
                node = self.Node(string[l])
            if node.data > string[l]: 
                node.left = self.insert_recursive(node.left, string, l)
            elif node.data < string[l]: 
                node.right = self.insert_recursive(node.right, string, l)
            else:
                if l == len(string) - 1:
                    node.end_of_word = True
                else:
                    node.middle = self.insert_recursive(node.middle, string, l+1)
        return node 

    def insert(self, string):
        self.root = self.insert_recursive(self.root, string, 0)
   
    def print_level_wise(self):
        if self.root:
            tmp = self.root
            st = [tmp]
            while st:
                tmp_st = []
                for node in st:
                    print node.data,
                    if node.left: tmp_st.append(node.left)
                    if node.middle: tmp_st.append(node.middle)
                    if node.right: tmp_st.append(node.right)
                st = tmp_st
                print

    def search_util(self, node, string, l): 
        if node:
            if node.data == string[l]:
                if l + 1 == len(string):
                    return node.end_of_word
                else: return self.search_util(node.middle, string, l+1)
            elif string[l] < node.data:
                return self.search_util(node.left, string, l)
            else:
                return self.search_util(node.right, string, l)
        return False
        
    def search(self, string):
        return self.search_util(self.root, string, 0)

