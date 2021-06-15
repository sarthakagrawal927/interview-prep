# Heap

Partially sorted binary tree. Each node is smaller than its kids.
Useful to get minimum.

Removing the top element would take logn.

Useful when you need to top k elements. klogn is always faster than other algorithms.

## Building

Initial Impression : nlogn
But in reality as there is no tree in beginning there is no height so because of this asymptotic nature it only takes O(n) which is op. If not for linear then we could have just sorted XD.

Using an array is more efficient for building the heap.

Usually no one asks to implement it, but its good to know. It is essentially a priority queue. It is also recommended to know the library by which you can use an heap.
