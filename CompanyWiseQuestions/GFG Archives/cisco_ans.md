# Answers

## CN

1. TCP vs UDP - with TCP we first establish the connection between the sender and receiver via a 3way handshake, every packet it sends it waits for the acknowledgement whereas there is no such overhead in UDP, does it is faster but less reliable. TCP is used by SMTP, FTP, HTTPS whereas UDP is used by Video streaming, DNS etc.

   UDP is a connectionless transport protocol, whereas TCP uses 3 way handshake for establishing connection in which client sends a Synchronize Packet to server which server receives and replies back with ack & synchronize packet which client receives and again sends back an ack thereby establishing the connection.

2. Mac address - unique identification for each device (its network interface card) , works at the data link layer and allows computers to   uniquely identify them at low levels.

   IP - unique identification of a network, works at network/internet layer helps in routing of data to the correct device. It is used for network identification and location addressing.

   IP Header -Currently we are using IPV4 (slowly transitioning to IPV6) which takes 20 to 60 bytes of space depending upon the data it carries. Packets are also fragmented so that they can pass through links with smaller maximal unit transmission.

3. OSI -> Application layer - Human Computer Interaction layer - HTTP, FTP, DNS, FTP
          Presentation layer - Ensure data is in usable form, decrypts, encrypts as necessary.
          Session Layer - Maintains connections and responsible for controlling ports and sessions

          Transport Layer - Transmits data using transmission protocols like UDP, TCP.

          Network Layer - Decides the physical path the data will take, the route. Packets, IP, ICMP, Routers

          Data Link - Defines raw format of data on the network, frames. Switches, bridges etc

          Physical - Wires, wireless, ethernet. NIC

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

3. CPU Scheduling - process generally involves both I/O time and processing time. So to prevent CPU time getting wasted we have CPU scheduling so that we can execute another process when needed in place of it.

   Non-preemptive:
   First Come First Serve - schedules them according to their arrival time. DS used Q. Suffers from convoy effect (1 time taking process causes starvation to following processes)

   Shortest Job first / Longest Job first - according to their burst time, if same BT then FCFS. Uses PQ as DS.

   Priority Based - process with higher priority taken before, can lead to starvation.

   Highest response ratio next - processes scheduled with highest response rate. (Waiting time + Burst Time)/ Burst Time.

   Preemptive:
   Shortest Time Remaining First/ Longest Time remaining first - sorts them in order to their remaining time. PQ.

   Round Robin - Each process is given a fixed slice of time, after which it is preempted and next process is given the chance. In this the number of context switches is high but every process gets equal priority. Circular Q.

   Multilevel queue - In this different types of processes (depending upon their utility) use different queues. Some queue might use Round Robin some may use FCFS. Deciding which queue to choose for next process we can again go for either priority scheduling or RoundRobin.

   Multilevel feedback q - Same as above, but in this processes can move between the queues based on time of execution and priority of the process.

4. Processes - memory divided into heap,stack,data and text. States - ready, suspended, waiting ,running, blocked, suspended ready etc.

   Process can talk to each other through shared memory (Producer-Consumer problem) and message passing (if 2 processes want to communicate they will have to form some link).

5. Deadlock
   More than 1 resource is non-shareable, and is needed multiple processes and one of the processes is holding it, no preemption, circular wait.
   Avoidance - Banker's Algorithm - like banking system it checks whether the resources can be loaned to the process or not.
   Prevention - Avoiding one of the conditions
   Recovery - Preemption

6. Priority inversion is a special scenario, suppose there is a resource R, and three processes L,M and H, such L < M < H in priority. Suppose L has a lock on resource R such that H has to wait for L to finish because of mutex lock but then M arrives and it does not requires resource R it pauses L and does it job, after M finishes then L finishes causing starvation to H. Windows handles this by random boosting, it boosts the priority of the process which has locked the resource so that it finishes asap.
