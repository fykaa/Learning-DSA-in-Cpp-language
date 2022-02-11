/*
Introduction to Sorting Algorithms
Following our discussion on data structures as queues and linked lists, one of the most important topics,
we, now delve into a new one from the arena of algorithms named sorting!

// What is sorting? //
Even though you are familiar with sorting, allow me to reiterate the basics.
So, sorting is a method to arrange a set of elements in either increasing or decreasing order according to some basis/relationship among the elements.
Sorting are of two types, as you could deduce from the definition:
Sorting in ascending order, and
Sorting in descending order.


// Why do we need sorting? //
To make you understand the reason why we need sorting in the simplest of ways,
I would show some real-life applications of sorting that you might encounter almost daily-
EXAMPLES:
    1) There are social media applications, news applications, even your emails or file managers, where you want things to be arranged according to dates.
        You want the newest on top and oldest at the end. And this feature uses the method of sorting.
        And more specifically, sorting based on the date of publishing/modification.
    2) Another example is the product delivery applications, be it delivering food like Swiggy, Zomato, or other shopping applications such as Amazon and Flipkart.
        You want the top-rated products on the top for your convenience. Sometimes you would need the products to be sorted according to their prices,
        be it the cheapest at first or the costliest at first. So, every one of these uses the sorting algorithm.
    3) The third and most useful application is the dictionary.  In a dictionary, the words are sorted lexicographically for you to find any word easily.
    4) Another easy concept is that of binary search. If you remember, we discussed in the beginning that searching in a sorted array takes at most O(log N) time.
        And when it's not sorted, it can take up to O(n). So, when an array is sorted, it minimizes the effort to find an element. Retrieval becomes much faster.
    5) School assembly. If you recall the days of your high school, you stood height-wise during your morning assembly. The basis of sorting here is your height.


// Criteria For Analysis of Sorting Algorithms //
We'll learn how to come up with criteria for analyzing different sorting algorithms and why one differs from the other,
Efficiency is judged On Basis of:
1) Time Complexity
2) Space Complexity
3) Stability
4) Internal & External Sorting Algorithms
5) Adaptivity
6) Recursiveness


1) Time Complexity:
We observe the time complexity of an algorithm to see which algorithm works efficiently for larger data sets and which algorithm works faster with smaller data sets.
In general, O(nlogn) is considered a better algorithm time complexity than O(n^2), and most of our algorithms’ time complexity revolves around these two.
Note: Lesser the time complexity, the better is the algorithm.

2) Space Complexity:
The space complexity criterion helps us compare the space the algorithm uses to sort any data set.
If an algorithm consumes a lot of space for larger inputs, it is considered a poor algorithm for sorting large data sets.
In some cases, we might prefer a higher space complexity algorithm if it proposes exceptionally low time complexity, but not in general.
And when we talk about space complexity, the term in-place sorting algorithm arises.
The algorithm which results in constant space complexity is called an in-place sorting algorithm.
Inplace sorting algorithms mostly use swapping and rearranging techniques to sort a data set.

3) Stability:
The stability of an algorithm is judged by the fact
whether the order of the elements having equal status when sorted on some basis is preserved or not.
It probably sounded technical, but let me explain.
Suppose you have a set of numbers, 6, 1, 2, 7, 6, and we want to sort them in increasing order by using an algorithm.
Then the result would be 1, 2, 6, 6, 7. But the key thing to look at is whether the 6s follow the same order as that given in the input or they have changed.
That is, whether the first 6 still comes before the second 6 or not. If they do, then the algorithm we followed is called stable, otherwise unstable.
 6, 1, 2, 7, 6 ---after sorting--> 1, 2, 6, 6, 7
 a  b  c  d  e ---after sorting--> b  c  a  e  d THIS WILL BE CALLED STABLE - 6 follows the same order as that given in the input
 a  b  c  d  e ---after sorting--> b  c  e  a  d THIS WILL BE CALLED UNSTABLE
Example:
Stable-  Bubble sort, Insertion sort,
Unstable- Selection sort,

4) Internal & External Sorting Algorithms
When the algorithm loads the data set into the memory (RAM),
we say the algorithm follows internal sorting methods.
In contrast, we say it follows the external sorting methods when the data doesn’t get loaded into the memory.

5) Adaptivity:
Algorithms that adapt to the fact that if the data are already sorted and it must take less time are called adaptive algorithms.
  And algorithms which do not adapt to this situation are not adaptive.
Example:
Adaptive-  Insertion sort,
Not Adaptive- Bubble sort, Selection sort,

6) Recursiveness:
If the algorithm uses recursion to sort a data set, then it is called a recursive algorithm.
Otherwise, non-recursive.

And these were the most general criteria to analyze our sorting algorithms.

We'll study some of the Sorting Algorithms as follows:
1) Bubble Sort
2) Insertion Sort
3) Selection Sort
4) Quick Sort
5) Merge Sort
6) Count Sort


*/