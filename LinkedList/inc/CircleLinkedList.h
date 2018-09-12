#ifndef CXX_CIRCLELINKEDLIST_H
#define CXX_CIRCLELINKEDLIST_H

#ifndef __cplusplus
#   error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include <iostream>
#include <stdio.h>
#ifndef CXX_NODETYPE_H
#include "NodeType.h"
#endif // CXX_NODETYPE_H

class CCircleLinkedList
{
public:
    CCircleLinkedList();
    ~CCircleLinkedList();

public:
    void InitLinkedList();
    LinkedList HeadCreateLinkedList();
    LinkedList TailCreateLinkedList();
    void InsertLinkedList(Node* head, int iData, int iPos);
    void DeleteDataFromLinkedList(Node* head, int iData);
    void ReverseLinkedList(Node* head);
    void PrintLinkedList(Node* head);
    bool IsLinkedListLoop(Node* head);

private:
    ListNode* m_pHead;
    int       m_iLength;

};

#endif // CXX_CIRCLELINKEDLIST_H
