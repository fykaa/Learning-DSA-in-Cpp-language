
/*
So, the first way to represent a binary tree is by using arrays. We call this ‘array representation’. 
And this method is not very recommended for representing binary trees. You will very soon know why.

1) Array representation of Binary trees: 
    Arrays are linear data structures and for arrays to function, their size must be specified before elements are inserted into them.
    And this counts as the biggest demerit of representing binary trees using arrays. Suppose you declare an array of size 100, and after storing 100 nodes in it,
    you cannot even insert a single element further, regardless of all the spaces left in the memory. 
    Another way you’d say is to copy the whole thing again to a new array of bigger size but that is not considered a good practice.

Anyways, we will use an array to represent a binary tree. Suppose we have a binary tree with 7 nodes.

        11<--7-->2
       / \       / \
      7   1     11  9


And there are actually a number of ways to represent these nodes via an array. 
I’ll use the most convenient one where we traverse each level starting from the root node and from left to right and mark them 
with the indices these nodes would belong to.

            [0]
     [1]8<--7-->2[2]
       / \       / \
      7   1     3  9
     [3]  [4]  [5]  [6]


And now we can simply make an array of length 7 and store these elements at their corresponding indices.

            0 1 2 3 4 5 6
            7 8 2 7 1 3 9

And you might be wondering about the cases where the binary is just not perfect. What if the last level has distributed leaves?
 Then let me tell you, there is a way out for that as well. Let’s consider one case here.

             [0]
     [1]8<--7-->2[2]
       / \       / \
 8<---7   1     3  9------>4
     [3]  [4]  [5]  [6]

  A binary tree with 9 nodes, and the last two nodes on the extremities of the last level.

Here, while traversing we get stuck at the 8th index. We don’t know if declaring the last node as the 8th index element makes it a 
general representation of the tree or not. So, we simply make the tree perfect ourselves. We first assume the remaining vacant places to be NULL.
And now we can easily mark their indices from 0 to 14.

                        [0]
                [1]8<--7-->2[2]
                / \       / \
    NULL<-8<---7   1     3  9------>4->n
          |   [3]  [4]  [5]  [6]


And the array representation of the tree looks something like this. It is an array of length 15.

            0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
            7 8 2 7 1 3 9 8 n n nl nl nl nl 04

    But was this even an efficient approach? Like Binary Trees are made only for efficient traversal and insertion 
    and deletion and using an array for that really makes the process troublesome. 
    Each of these operations becomes quite costly to accomplish. And that size constraint was already for making things worse. 
    So overall, we would say that the array representation of a binary is not a very good choice. And what are the other options?

*/
