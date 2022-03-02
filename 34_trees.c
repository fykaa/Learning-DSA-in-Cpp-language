/*

#Introduction to Trees

In the wake of such an extensive and lengthy study of sorting algorithms, we would now like to move on to the study of some more advanced 
data structures. Today, we’ll begin discussing trees. It is unlikely that I won't be able to explain trees to you after I finish this lecture.
The flow of the concept will remain the same, first the theory and then their applications and problems.

A tree usually represents the hierarchy of elements and depicts the relationships between the elements. 
Trees are considered as one of the largely used facets of data structures. 
To give you a better idea of how a tree looks like, let me give an example:

            7
           / \
         34   56->45->6
        /\\
       1 3 9   

Every circle represents a node, and every arrow represents the hierarchy. 

Now, you can very easily say that node 56 is the child of node 7 or node 34 is the parent of node 1 3 and 9. 
You would be wondering what a parent or child is. I was coming to that only.


#Terminologies used in trees:

1) Root: The topmost node of a tree is called the root. 
    There is no edge pointing to it, but one or more than one edge originating from it. Here, 7 is the root node.
2) Parent: Any node which connects to the child. Node which has an edge pointing to some other node. Here, C is the parent of H.
3) Child: Any node which is connected to a parent node. Node which has an edge pointing to it from some other node. 
    Here, 1 is the child of 34.
4) Siblings: Nodes belonging to the same parent are called siblings of each other. 
    Nodes 1 3 and 9 are siblings of each other, since they have the same parent node 34.
5) Ancestors: Nodes accessible by following up the edges from a child node upwards are called the ancestors of that node. 
    Ancestors are also the parents of the parents of …… that node. Here, nodes 7, 56, 45 are the ancestors of node 6.
6) Descendants: Nodes accessible by following up the edges from a parent node downwards are called the descendants of that node. 
   Descendants are also the child of the child of …… that node. Here, nodes 45 and 6 are the descendants of node 56.
7) Leaf/ External Node: Nodes which have no edge originating from it, and have no child attached to it.
    These nodes cannot be a parent. Here, nodes 1,3,9,6 are leaf nodes.
8) Internal node: Nodes with at least one child. Here, nodes 34, 56 are internal nodes.
9) Depth: Depth of a node is the number of edges from root to that node. 
    Here, the depth of nodes 7, 56, 45 and 6 are 0, 1, 2 and 3 respectively.
10) Height: Height of a node is the number of edges from that node to the deepest leaf. 
    Here, the height of node 7 is 3, since the deepest leaf from this node is node 6. And similarly, height of node 56 is 2.

_____________________________________________________________________________________________________________________________________________________
_____________________________________________________________________________________________________________________________________________________
*/