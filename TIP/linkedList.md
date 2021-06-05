# LinkedList

## Deleting a node in singlyLL in O(1) when given pointer to it

The trick here is to

```c++
node -> val = node-> next -> val;
node -> next = node -> next -> next;
```

Else you will have to traverse to get the previous node.

Reversing (in O(n)) - reversing pointer at each node.

```c++
nextNode = node-> next;
while(nextNode){
    node = nextNode;
    nextNode = node -> next;
    node -> next = prev;
}
```
