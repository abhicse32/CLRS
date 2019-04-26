class LeftistHeap:
    class Node:
        def __init__(self, val):
            self.data = val
            self.npl = 0  # null path length of the node
            self.left = None
            self.right = None 
    def __init__(self):
        self.root = None 
    
    @staticmethod
    def get_npl(node):
        if not node: return -1
        return node.npl

    def merge(self, node1, node2):
        if (not node1) or (not node2):
            return node1 or node2
        new_root, node_right = node1, node2
        if new_root.data > node_right.data:
            new_root, node_right = node_right, new_root
        new_root.right = self.merge(new_root.right, node_right)
        l_npl = LeftistHeap.get_npl(new_root.left)
        r_npl = LeftistHeap.get_npl(new_root.right)
        if l_npl < r_npl:
            new_root.left, new_root.right = new_root.right, new_root.left
        new_root.npl = min(l_npl, r_npl)+1
        return new_root
    
    def insert(self, val):
        self.root = self.merge(self.root, self.Node(val))

    def print_levelwise(self):
        if not self.root: return
        lst = [self.root]
        while lst:
            tmp = []
            for node in lst:
                print "%d:%d"%(node.data, node.npl),
                if node.left: tmp.append(node.left)
                if node.right: tmp.append(node.right)
            lst = tmp
            print 

    def delete_min(self):
        self.root = self.merge(self.root.right, self.root.left)

