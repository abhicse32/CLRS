class AvlTree:
    class Node:
        def __init__(self,val):
            self.data = val
            self.height = 0
            self.left = None
            self.right = None
    
    def __init__(self):
        self.root = None

    @staticmethod
    def get_height(node):
        if not node: return -1
        return node.height 

    def print_inorder(self, node):
        if node:
            self.print_inorder(node.left)
            print "%d:%d"%(node.data, node.height),
            self.print_inorder(node.right)
    
    def print_preorder(self, node):
        if node:
            print "%d:%d"%(node.data, node.height)
            self.print_preorder(node.left)
            self.print_preorder(node.right)

    def print_levelwise(self):
        if not self.root: return
        lst = [self.root]
        while lst:
            tmp = []
            for node in lst:
                print "%d:%d"%(node.data,node.height),
                if node.left: tmp.append(node.left)
                if node.right: tmp.append(node.right)
            lst = tmp
            print 

    def rotate_right(self, node):
        new_parent = node.left 
        node.left = new_parent.right
        new_parent.right = node
        node.height = max(AvlTree.get_height(node.left), AvlTree.get_height(node.right)) + 1
        return new_parent 
    
    def rotate_left(self, node):
        new_parent = node.right 
        node.right = new_parent.left
        new_parent.left = node 
        node.height = max(AvlTree.get_height(node.left), AvlTree.get_height(node.right)) + 1
        return new_parent 

    def rotate_left_right(self, node):
        node.left = self.rotate_left(node.left)
        return self.rotate_right(node)

    def rotate_right_left(self, node):
        node.right = self.rotate_right(node.right)
        return self.rotate_left(node)

    def get_node_after_rotation(self, node):
        rh, lh = AvlTree.get_height(node.right), AvlTree.get_height(node.left)
        if lh - rh > 1:
            if AvlTree.get_height(node.left.left) > AvlTree.get_height(node.left.right):
                node = self.rotate_right(node)
            else: node = self.rotate_left_right(node)
        elif lh -rh < -1:
            if AvlTree.get_height(node.right.right) > AvlTree.get_height(node.right.left):
                node = self.rotate_left(node)
            else: node = self.rotate_right_left(node)

        node.height = max(AvlTree.get_height(node.left), AvlTree.get_height(node.right)) + 1
        return node

    def insert_util(self, node, val):
        if node:
            if node.data < val: node.right = self.insert_util(node.right, val)
            elif node.data > val: node.left = self.insert_util(node.left, val)
            else: return node 
            return self.get_node_after_rotation(node)
        return self.Node(val)

    def insert_recursive(self, val):
        self.root = self.insert_util(self.root, val)

    # using stack to avoid max_recursion_depth reached type of error
    # from the platform 
    def insert_iterative(self, val):
        if self.root:
            #print val,
            stack, curr_node = [], self.root 
            while curr_node:
                stack.append(curr_node)
                if val > curr_node.data:
                    curr_node = curr_node.right
                elif val < curr_node.data:
                    curr_node = curr_node.left
                else: return 
            curr_node = self.Node(val)

            while stack:
                p_node = stack.pop()
                if p_node.data < curr_node.data: p_node.right = curr_node
                else: p_node.left = curr_node
                curr_node = self.get_node_after_rotation(p_node)
            self.root = curr_node 
        else: self.root = self.Node(val)
    
    def del_successor(self, node):
        if not node.left:
            return node.data, node.right 
        n_data, node.left = self.del_successor(node.left)
        return n_data, self.get_node_after_rotation(node)

    def del_util(self, node, val):
        if node:
            if val > node.data: node.right = self.del_util(node.right, val)
            elif val < node.data: node.left = self.del_util(node.left, val)
            else:
                if (not node.left) or (not node.right):
                    node = node.left or node.right 
                else: 
                    node.data, node.right = self.del_successor(node.right)

            if node: return self.get_node_after_rotation(node)
        else:
            raise Exception("Node not found")

    def delete_recursive(self, val):
        self.root = self.del_util(self.root, val) 
    
    def delete_iterative(self, val):
        if self.root:
            stack, curr_node = [], self.root
            while curr_node:
                prev_node = curr_node
                if val < curr_node.data: curr_node = curr_node.left
                elif val > curr_node.data: curr_node = curr_node.right
                else: break
                stack.append(prev_node)

            if not curr_node: raise Exception("Value not found")
            if (not curr_node.left) or (not curr_node.right):
                curr_node = curr_node.left or curr_node.right
            else:
                curr_node.data, curr_node.right = self.del_successor(curr_node.right)
            curr_node = self.get_node_after_rotation(curr_node)
            while stack:
                p_node = stack.pop()
                if p_node.data < curr_node.data: p_node.right = curr_node
                else: p_node.left = curr_node 
                curr_node = self.get_node_after_rotation(p_node)
            self.root = curr_node
        else: raise Exception("Delete operation on an empty Tree")


