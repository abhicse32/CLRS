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
        if new_root.data > node_next.data:
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
    
    
    def decrease_key_util(self, node, key):
        if node:
            if node.data == key: return node, node
            ret_node = None 
            l_node, ret_node = self.decrease_key_util(node.left, key) 
            if ret_node:
                if ret_node == l_node: node.left = None 
            else:
                r_node, ret_node = self.decrease_key_util(node.right, key)
                if ret_node:
                    if ret_node == r_node: node.right = None

            return node, ret_node

        return node, None

    def decrease_key(self, curr_key, new_key):
        if new_key >= curr_key:
            raise Exception("New key is greater than or equal to the existing key")
        _, node = self.decrease_key_util(self.root, curr_key)
        if not node:
            raise Exception("Key to be decreased not found!")
        node.data = new_key
        if self.root != node:
            self.root = self.merge(self.root, node)

if __name__ == '__main__':
    arr = [-9, 12, 45, 21, 54, 32, 59, 76, -32]
    heap = SkewHeap()
    for el in arr:
        heap.insert(el)
    heap.print_levelwise()
    print 
    heap.decrease_key(45, -33)
    heap.print_levelwise()
