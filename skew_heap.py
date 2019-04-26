class SkewHeap:
    class Node:
        def __init__(self, val):
            self.data = val
            self.left = None
            self.right = None
    
    def __init__(self):
        self.root = None

    def merge(self, node1, node2): 
        if (not node1) or (not node2):
            return node1 or node2
        new_root, node_next = node1, node2
        if node1.data > node2.data:
            new_root, node_next = node_next, new_root 
        new_root.right = self.merge(new_root.right, node_next)
        new_root.right, new_root.left = new_root.left, new_root.right
        return new_root

    def insert(self, val):
        self.root = self.merge(self.root, self.Node(val))
    
    def print_levelwise(self):
        if not self.root: return
        lst = [self.root]
        while lst:
            tmp = []
            for node in lst:
                print node.data,
                if node.left: tmp.append(node.left)
                if node.right: tmp.append(node.right)
            lst = tmp
            print 

    def delete_min(self):
        self.root = self.merge(self.root.left, self.root.right)

