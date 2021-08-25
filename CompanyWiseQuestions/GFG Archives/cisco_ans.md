# Answers

## CN

1. TCP vs UDP

## OS

1. Paging - memory management scheme that eliminates the need for contiguous allocation of physical memory. Stores data in blocks of fixed size (pages) -> has high chances of page fault.

   Thrashing - We take processes in RAM by paging, if we do not find page in memory -> page fault (takes a lot of time), if a lot page fault occurs it results in thrashing. Usually happens once degree of multiprogramming(amount of process currently in RAM) threshold is reached. To prevent this we can decrease the threshold for degree of multiprogramming.

   Segmentation - memory management scheme that divides the program according to user point of view, segment sizes can be different, there is a segment table with 2 columns - segment size and start size.

   Main memory unit helps finding the right page / segment.

2. Multithreading - A process is a program being executed. A process can be further divided into independent units known as threads.

   Allows concurrent execution of different parts of the program. Improved performance through parallelism. Thread creation and termination is faster , communication between thread is faster. Context switching (process of storing the state of a process/thread) is faster.

   Mutex - mutual exclusion object - used to let all processes use the same resource but only at a time. It locks the resource with pid.
   Semaphore - non zero integer, use wait and signal to control access of common resources between processes.

   Mutex and Semaphore help in process synchronization (coordinating processes with shared data)

3. CPU Scheduling
