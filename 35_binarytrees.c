/*
# What is a Binary Tree?

    A tree is made up of nodes and edges.
    The topmost node is called the Any node which points to another node, is the parent of that node and the node which the parent is
    pointing at is the child of that parent node. And nodes having the same parents are called siblings of each other.
    Nodes having zero children are the leaf nodes or the external nodes, and nodes having at least one child are the internal nodes.
    Ancestors of a node are the nodes accessible by traversing upwards along the edges. They are either the parents or the parents of the parents.
    Descendants of a node are the nodes accessible by traversing downwards along the edges. They are either the children or the children of the children.
    Height of a node is the number of edges in between the deepest leaf and that node. And depth of a node is the number of edges between the root and that node.

Apart from these, there are a few additional points that I would like to add.
1) A tree with n nodes has n-1 edges
    Why n-1?
    Because in a tree, there is one and only edge corresponding to all the nodes except the root node. 
    The root node has no parent, hence no edge pointing to it. Therefore, a total of n-1 edges.
2) The degree of a node in a tree is the 'number of children' of a node.
3) The degree of a tree is the highest degree of a node among all the nodes present in the tree.

Binary Tree
A binary tree is a special type of tree where each node has a degree equal to or less than two which means each node should have at most two children.
Few examples of a binary tree are mentioned below:

    9->1

        7
       / \
      4   5->8->3 

    Example 1 has nodes 9 and 1 , having degrees 1 each, hence a binary tree. Similarly, example 2 has nodes 7 4 5 8 3  with degrees {2, 0, 1, 1, 0} respectively which satisfies the conditions for a binary tree.


#Representation of a Binary Tree

Binary tree can be represented using:
1) Array representation
2) Linked representation


*/
