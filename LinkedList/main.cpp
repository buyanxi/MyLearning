#include <iostream>
#include "SingleLinkedList.h"
#include "CircleLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;

CSingleLinkedList  g_cSingleLinkedList;
CCircleLinkedList  g_cCircleLinkedList;
CDoublyLinkedList  g_cDoublyLinkedList;
int main()
{
//    LinkedList *head_Head;
//    head_Head = g_cSingleLinkedList.HeadCreateLinkedList();
//    g_cSingleLinkedList.PrintLinkedList(head_Head);

#if 0
    ListNode* head_Tail;
    head_Tail = g_cSingleLinkedList.TailCreateLinkedList();
    g_cSingleLinkedList.PrintLinkedList(head_Tail);

    g_cSingleLinkedList.ReverseLinkedList(head_Tail);
    g_cSingleLinkedList.PrintLinkedList(head_Tail);

    g_cSingleLinkedList.InsertLinkedList(head_Tail, 5, 1);
    g_cSingleLinkedList.PrintLinkedList(head_Tail);

    g_cSingleLinkedList.DeleteDataFromLinkedList(head_Tail, 2);
    bool bFlag = g_cSingleLinkedList.IsEmptyLinkedList(head_Tail);
    if (!bFlag) {
        g_cSingleLinkedList.PrintLinkedList(head_Tail);
    }
    int iLength = g_cSingleLinkedList.GetLinkedListLength(head_Tail);
    printf("The length of linked list is %d.\n", iLength);

    int iFirstPos = 0, iCount = 0;
    g_cSingleLinkedList.SearchDataFromLinkedList(head_Tail, 3, iFirstPos, iCount);

    bool bLoopFlag = g_cSingleLinkedList.IsLinkedListLoop(head_Tail);
    if (bLoopFlag) {
        printf("The linked list has loop!\n");
    }
    else {
        printf("The linked list has not loop!\n");
    }

    g_cSingleLinkedList.ClearLinkedList(head_Tail);
    bool bFlag1 = g_cSingleLinkedList.IsEmptyLinkedList(head_Tail);
    if (!bFlag1) {
        g_cSingleLinkedList.PrintLinkedList(head_Tail);
    }
    else {
        printf("The linked list is cleared successfully!\n");
    }
#endif

#if 0
//    ListNode* head_Head;
//    head_Head = g_cCircleLinkedList.HeadCreateLinkedList();
//    g_cCircleLinkedList.PrintLinkedList(head_Head);

    ListNode* head_Tail;
    head_Tail = g_cCircleLinkedList.TailCreateLinkedList();
    g_cCircleLinkedList.PrintLinkedList(head_Tail);

    g_cCircleLinkedList.ReverseLinkedList(head_Tail);
    g_cCircleLinkedList.PrintLinkedList(head_Tail);

    g_cCircleLinkedList.InsertLinkedList(head_Tail, 5, 5);
    g_cCircleLinkedList.PrintLinkedList(head_Tail);

    g_cCircleLinkedList.DeleteDataFromLinkedList(head_Tail, 4);
    g_cCircleLinkedList.PrintLinkedList(head_Tail);

    bool bLoopFlag = g_cCircleLinkedList.IsLinkedListLoop(head_Tail);
    if (bLoopFlag) {
        printf("The linked list has loop!\n");
    }
    else {
        printf("The linked list has not loop!\n");
    }
#endif

    DoublyListNode* head_Head;
    head_Head = g_cDoublyLinkedList.HeadCreateLinkedList();
    g_cDoublyLinkedList.PrintLinkedList(head_Head);


    return 0;
}
