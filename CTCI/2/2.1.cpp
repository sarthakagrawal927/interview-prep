#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *createNode(int data)
{
    Node *node;
    node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}
void insertNode(int data, Node *node)
{
    Node *newNode;
    newNode = createNode(data);
    if (newNode->next)
        node->next = newNode;
    else
    {
        Node *temp = node;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
Node *deleteNode(int data, Node *node)
{
    cout << "deleting   " << data << endl;
    Node *temp = node;
    Node *temp2 = node->next;
    if (node->data == data)
    {
        return node->next;
    }
    else
        while (temp)
        {
            if (temp2->data == data)
            {
                temp->next = temp2->next;
                break;
            }

            temp = temp->next;
            if (temp2->next)
                temp2 = temp2->next;
            else
            {
                cout << "not found";
                break;
            }
        }
    return node;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
int findLength(Node *head)
{
    int c = 0;
    for (Node *temp = head; temp != NULL; temp = temp->next)
        c++;
    return c;
}
//Remove Dups - Removing duplicates from unsorted list without temporary buffer
Node *removeDups(Node *head)
{
    Node *temp = head;
    Node *temp2 = head->next;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
        for (temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp->data == temp2->data && temp != temp2)
            {
                head = deleteNode(temp->data, head);
            }
        }
    }
    return head;
}
//do later with hash table

//Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
//Trivial Solutions : 1) Reverse and find kth from first, 2) Count the nodes and then return (n-k)th node
//Too easy to implement
//New - 3)Maintain two pointers – reference pointer and main pointer. Initialize both reference and main pointers to head. First, move reference pointer to n nodes from head. Now move both pointers one by one until the reference pointer reaches the end. Now the main pointer will point to nth node from the end. Return the main pointer.
Node *reverse(Node *node)
{
    Node *curr = node, *next, *prev;
    next = new Node();
    prev = new Node();
    next = NULL;
    prev = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}
//Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
void deleteMid(Node *mid)
{
    Node *temp;
    temp = mid->next;
    mid->data = temp->data;
    mid->next = temp->next;
}
//This won't work for last node

//Add 2 lists
Node *addLists(Node *l1, Node *l2)
{
    Node *sum, *l12, *l22;
    l12 = reverse(l1);
    printList(l12);
    l22 = reverse(l2);
    printList(l22);
    int s = 0, carry = 0;

    for (Node *temp = l12; temp != NULL; temp = temp->next)
    {
        s = l12->data + l22->data + carry;
        carry = s / 10;
        s = s % 10;
        insertNode(s, sum);
    }
    return sum;
}

//Partition : Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.
Node *Partition(Node *head, int p)
{
    Node *temp = head;
    int c = findLength(head);
    for (int i = 0; i < c; i++)
    {
        if (temp->data > p)
        {
            c++;
            int x = temp->data;
            temp = deleteNode(x, head);
            insertNode(x, head);
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    Node *head;
    int x;
    cin >> x;
    head = createNode(x);
    while (x != -1)
    {
        cin >> x;
        if (x != -1)
            insertNode(x, head);
    }
    printList(head);
    // head = removeDups(head);
    // head = reverse(head);
    // deleteMid(head->next->next->next);
    // head = Partition(head, 5);
    Node *temp = head;
    printList(addLists(head, temp));
    printList(head);
    return 0;
}