/*
* Heap [https://www.youtube.com/watch?v=HqPJF2L5h9U]
It is a complete binary tree structure.
For a Max Heap, all children node below a parent node are smaller (or equal to)
than the parent node. For a Min Heap, all children node below a parent node are
larger (or equal to) than the parent node.

Complete binary tree - A complete binary tree is a binary tree in which every
level, except possibly the last, is completely filled, and all nodes in the last
level are as far left as possible. [https://en.wikipedia.org/wiki/Binary_tree]
In the array representation, there will be no empty nodes in list between the
first and last node.

                1
        2               3
    4       5       6       x

array representation = [1, 2, 3, 4, 5, 6]
No empty node in between, and elements in last level filled from left to
right -> complete binary tree.

For node i (starting 1) => Left child is at 2*i, Right child is at 2*i+1, in the
array representation.

** Insertion in Heap
The properties of the Heap - that it is complete binary tree must be respected
during the process of insertion So when a new element is inserted, it is
inserted in the left most available empty space For an array representation, it
will be the end of the array.

NOTE: The swapping algorithm is done from leaf to root in case of insertion

        100
    25        30
4

max heap = [100, 25, 30, 4]

Q. Insert 60 into the heap

1. Insert into the available spot => end of list


        100
    25        30
4       60

max heap = [100, 25, 30, 4, 60]

2. Compare with parent node, if parent node is smaller, swap the two nodes.

        100
    60        30
4       25

max heap = [100, 60, 30, 4, 25]

3. If parent exists, repeat Step 2.

*** Complexity of Insertion
Step 2 will be performed height times at max, height = log(n)
Time complexity - O(log(n))

** Deletion in Heap
The properties of the Heap - that it is complete binary tree must be respected
during the process of deletion.
Always, the root is deleted in case of a heap. (The max or min element).

The root is deleted, and replaced by the last element in the heap.
Now, we move from the root to the children and swap children as needed.

NOTE: The swapping algorithm is done from root to leaf in case of deletion.

        100
    25        30
4

max heap = [100, 25, 30, 4]

Q. Pop from the heap

1. Replace root with the last element, and remove the last element

         4
    25        30

max heap = [4, 25, 30]

2. Compare root with the children
Take the biggest child, if it bigger than the root, swap root with it

         30
    25        4

max heap = [30, 25, 4]

3. Repeat step 2 if there are more children

*** Complexity of Deletion
Step 2 will be performed height times at max, height = log(n)
Time complexity - O(log(n))

* Heap Sort

Consider the following, if instead of removing the root during deletion, we put
it at the end of the array

        100
    25        30
4

max heap = [100, 25, 30, 4]

> pop root, but put at the end, consider it outside of the scope (not in the
heap)

         30
    25        4

max heap = [30, 25, 4] | [100]

> repeat

         25
    4

max heap = [25, 4] | [30, 100]

> repeat

         4

max heap = [4] | [25, 30, 100]

> repeat

max heap = [] | [4, 25, 30, 100]

WE HAVE SORTED THE ARRAY!

This is the idea behind heap sort.

We first transform the array into a max heap, then pop elements from the heap
and make our sorted array.

* Heapify

We can convert an array directly into a heap instead of pushing elements into an
empty heap.

The idea is that - Assume the array is a complete binary tree
representation. The leaf nodes are valid heaps in themselves.
For the a particular node, we assume that their children are valid heaps, and we
see if their can be a swap possible, we swap it.
For this to work, we start from the bottom and move up and swap when needed.

Example -

Array - [4, 25, 100, 30]
Complete Binary Tree representation of the array -
         4
    25      100
30

1. At 30 (i = 3)
There are no left and right child, this is a valid heap, move on.

2. At 100 (i = 2)
There are no left and right child, this is a valid heap, move on.

3. At 25 (i = 1)
Left child = 30, No right child
25 is smaller than the left child, so we should swap 25 and 30.

         4
    30      100
25

NOTE: Now 30 and its subtree is a valid heap, we can use this logic for
heapification of 4

4. At 4 (i = 0)
Left child = 30, Right child = 100
Biggest child => 100
4 is smaller than 100 so, we should swap 4 with 100.

         100
    25          4
30

Array = [100, 25, 4, 30]
Now the array is converted into a valid max heap.

** Complexity
Time Complexity - O(n) => we visit each node once

* Heap Sort
1. Convert the array into a max heap (using heapify)
2. Pop from the max heap and put it at the end of the array, reduce the length
of the usable array
3. Repeat step 2 until length of the usable array does not reach 0

*/
