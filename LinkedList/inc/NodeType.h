#ifndef CXX_NODETYPE_H
#define CXX_NODETYPE_H

#ifndef __cplusplus
#   error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif


typedef struct Node
{
    int data;
    Node* next;
}ListNode, *LinkedList;


typedef struct DoublyNode
{
    int data;
    DoublyNode* next;
    DoublyNode* pre;
}DoublyListNode, *DoublyLinkedList;

#endif // CXX_NODETYPE_H
