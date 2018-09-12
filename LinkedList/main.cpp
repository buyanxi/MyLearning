#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

CSingleLinkedList g_cSingleLinkedList;
int main()
{
//    LinkedList *head_Head;
//    head_Head = g_cSingleLinkedList.HeadCreateLinkedList();
//    g_cSingleLinkedList.PrintLinkedList(head_Head);

    LinkedList *head_Tail;
    head_Tail = g_cSingleLinkedList.TailCreateLinkedList();
    g_cSingleLinkedList.PrintLinkedList(head_Tail);

    g_cSingleLinkedList.InsertLinkedList(head_Tail, 5, 8);
    g_cSingleLinkedList.PrintLinkedList(head_Tail);

    g_cSingleLinkedList.DeleteDataFromLinkedList(head_Tail, 2);
    bool bFlag = g_cSingleLinkedList.IsEmptyLinkedList(head_Tail);
    if (!bFlag) {
        g_cSingleLinkedList.PrintLinkedList(head_Tail);
    }

    int iFirstPos = 0, iCount = 0;
    g_cSingleLinkedList.SearchDataFromLinkedList(head_Tail, 3, iFirstPos, iCount);

    g_cSingleLinkedList.ClearLinkedList(head_Tail);
    bool bFlag1 = g_cSingleLinkedList.IsEmptyLinkedList(head_Tail);
    if (!bFlag1) {
        g_cSingleLinkedList.PrintLinkedList(head_Tail);
    }
    else {
        printf("The linked list is deleted successfully!\n");
    }

    return 0;
}
