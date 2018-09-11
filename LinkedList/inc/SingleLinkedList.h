#ifndef CXX_SINGLELINKEDLIST_H
#define CXX_SINGLELINKEDLIST_H

#ifndef __cplusplus
#   error ERROR: This file requires C++ compilation (use a .cpp suffix)
#endif

#include <iostream>
#include <stdio.h>
#ifndef CXX_NODETYPE_H
#include "NodeType.h"
#endif // CXX_NODETYPE_H

class CSingleLinkedList
{
public:
    CSingleLinkedList();
    ~CSingleLinkedList();

public:
    LinkedList* HeadCreateLinkedList();
    LinkedList* TailCreateLinkedList();
    void InsertLinkedList(Node* head, int iData, int iPos);
    void DeleteDataFromLinkedList(Node* head, int iData);
    void DeleteAllLinkedList(Node* head);
    void  SearchDataFromLinkedList(Node* head, int iData, int &iFirstPos, int &iCount);
    void PrintLinkedList(Node* head);
    bool IsEmptyLinkedList(Node* head);
};

#endif // CXX_NODETYPE_H
