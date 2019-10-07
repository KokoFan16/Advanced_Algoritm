import math 

class Node:       
    # Constructor to create a new node   
    def __init__(self, data):   
        self.data = data   
        self.left = None
        self.right = None


def inorder(node):
    left = []
    order = []
    min_dis = math.inf
    while(node != None):
        left.append(node)
        node = node.left
    #return left
    
    while(left):
        node = left.pop()
        order.append(node.data)
        if (node.right != None):
            left.append(node.right)
    print(order)    
    for i in range(len(order) - 1):
       min_dis = min(abs(order[i] - order[i + 1]), min_dis)


    return min_dis 
 
root=Node(5) 
root.left =  Node(2) 
root.right = Node(7)  
root.left.right = Node(4)
root.left.left = Node(0)

print(inorder(root))
