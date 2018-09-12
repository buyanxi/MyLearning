#include "CircleLinkedList.h"

CCircleLinkedList::CCircleLinkedList()
{
    m_pHead = NULL;
    m_iLength = 0;
}

CCircleLinkedList::~CCircleLinkedList()
{

}

void CCircleLinkedList::InitLinkedList()
{
    if (NULL == m_pHead) {
        m_pHead = new ListNode;
        m_pHead->next = m_pHead;
    }
}

LinkedList CCircleLinkedList::HeadCreateLinkedList()
{
    ListNode* head;
    head = new ListNode;
    head->next = head;

    int iLength;
    printf("Please enter the length of linked list:");
    scanf("%d", &iLength);

    ListNode* p = head;
    for(int i = 1; i <= iLength; ++i) {
        ListNode* pNewNode = new ListNode;
        printf("Please enter the data of new node %d:", i);
        scanf("%d", &pNewNode->data);
        pNewNode->next = p->next;
        p->next = pNewNode;
    }

    return head;
}

LinkedList CCircleLinkedList::TailCreateLinkedList()
{
    ListNode* head;
    head = new ListNode;
    head->next = head;

    int iLength;
    printf("Please enter the length of linked list:");
    scanf("%d", &iLength);

    ListNode* p = head;
    for(int i = 1; i <= iLength; ++i) {
        ListNode* pNewNode = new ListNode;
        printf("Please enter the data of new node %d:", i);
        scanf("%d", &pNewNode->data);
        p->next = pNewNode;
        p = pNewNode;
    }
    p->next = head;

    return head;
}

void CCircleLinkedList::InsertLinkedList(Node* head, int iData, int iPos)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    ListNode* pNewNode = new ListNode;
    pNewNode->data = iData;

    ListNode* p = head;
    int iCount = 0;
    while (p->next != head) {
        ++iCount;
        if (iCount == iPos) {
            pNewNode->next = p->next;
            p->next = pNewNode;
            break;
        }
        p = p->next;
    }

    if (iCount < iPos) {
        printf("The position %d to be inserted is across the border of list!\n", iPos);
        printf("The data %d is inserted in the tail of list!\n", iData);

        pNewNode->next =p->next;
        p->next = pNewNode;
    }

}

void CCircleLinkedList::DeleteDataFromLinkedList(Node* head, int iData)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    ListNode* pDeleteNode;
    bool bDeleteFlag = false;
    ListNode* p = head;
    while (p->next != head) {
        if (p->next->data == iData) {
            pDeleteNode = p->next;
            p->next = p->next->next;

            delete pDeleteNode;
            pDeleteNode = NULL;

            bDeleteFlag = true;
            continue;
        }
        p = p->next;
    }

    if (bDeleteFlag) {
        printf("The data %d is deleted successfully!\n", iData);
    }
    else {
        printf("The data %d is non-existent in the list!\n", iData);
    }
}

void CCircleLinkedList::PrintLinkedList(LinkedList head)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    // The header node has not data which is not required to printed.
    ListNode* p = head;

    while (p->next != head) {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");

}
