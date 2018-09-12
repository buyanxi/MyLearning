#ifndef CXX_DOUBLYLINKEDLIST_H
#define CXX_DOUBLYLINKEDLIST_H

#ifndef __cplusplus
#   error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include <iostream>
#include <stdio.h>
#ifndef CXX_NODETYPE_H
#include "NodeType.h"
#endif // CXX_NODETYPE_H

class CDoublyLinkedList
{
public:
    CDoublyLinkedList();
    ~CDoublyLinkedList();

public:
    DoublyLinkedList HeadCreateLinkedList();
//    LinkedList TailCreateLinkedList();
//    void InsertLinkedList(Node* head, int iData, int iPos);
//    void DeleteDataFromLinkedList(Node* head, int iData);
//    void ClearLinkedList(Node* head);
//    void SearchDataFromLinkedList(Node* head, int iData, int &iFirstPos, int &iCount);
//    void ReverseLinkedList(Node* head);
    void PrintLinkedList(DoublyNode* head);
//    int  GetLinkedListLength(Node* head);
//    bool IsEmptyLinkedList(Node* head);
//    bool IsLinkedListLoop(Node* head);
};

#endif // CXX_DOUBLYLINKEDLIST_H
