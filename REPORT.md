# Project 2: User-Level Thread Library Report

### **Summary**
This project consists of 4 parts in which queue, uthread, semaphore, and 
preemption all contribute to form a user-level thread library. The programs 
all together manages the creation, termination, and manipulation aspect of 
threads. The programs also dictate which order they are processed and what 
get processed via priority.

### **Implementation Phases**
The implementation of this program is done through four phase: 

1. Implementing a FIFO queue
Below we couldn't get to: 
2. Creation, deletion, manipulation of threads
3. Controlling threads and managing them
4. Disable/Enable preemption to avoid resource depletion from 
uncooperating threads or never block on a semaphore

### **FIFO Queue** 
In simple words, this phase was simply implementing a FIFO queue using 
linked lists. There are total of seven functions and one struct. The 
struct is for initalizing a node and all its respective components to
operate in a linked list. We have the usual enqueue and dequeue for 
adding and deleting components from the list. We have a function which 
creates a queue and other functions regrading the destruction, 
iteration, and length of the queue. 

### **Phases I was unable to get to**
The creation, deletion, manipulation of threads, and management of threads
was something we could not get into as we were busy implementing queue and 
configuring complications with the Makefile. Although, if we were to 
implement uthread, sem, and preempt, we would use the pthread library,
figure out a way to keep track of threads using the semphore topic we 
learned in lecture, and utilize signals respectively. 

### **Implementation choices**
1. Linked List as queue.c looked as if it was set to have this implementation.

### **Testing**
Due to a lack of communication and cirucumstances regarding time, we weren't 
able to test our FIFO queue implementation. However, we are confident that if 
tested, our FIFO queue implementation would work and that if it weren't for 
the communication and time issue, we would know if our queue worked. As a 
group of two, both of us were boggled down by midterms and other class 
assignments.

### **Any External Sources**
We used a queue implementation from another university as a reference to 
figure out how we would tackle the FIFO queue problem. We formulated some 
ideas around aspects of the original implementation and hence, you can 
probably see some similarites. The lack of comments was also a lack of 
time on our end. 

The link to the reference is in queue.c. 