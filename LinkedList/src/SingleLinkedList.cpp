#include "SingleLinkedList.h"

CSingleLinkedList::CSingleLinkedList()
{

}

CSingleLinkedList::~CSingleLinkedList()
{

}

LinkedList CSingleLinkedList::HeadCreateLinkedList()
{
    Node* head;
    head = new Node;
    head->next = NULL;

    int iLength;
    printf("Please enter the number of linked list:");
    scanf("%d", &iLength);

    Node *p = head;
    for (int i = 0; i< iLength; ++i) {
        Node *pNewNode = new Node;
        printf("Please enter the data of new node %d:", i);
        scanf("%d", &pNewNode->data);
        pNewNode->next = p->next;
        p->next = pNewNode;
    }

    return head;
}

LinkedList CSingleLinkedList::TailCreateLinkedList()
{
    Node* head;
    head = new Node;
    head->next = NULL;

    int iLength;
    printf("Please enter the number of linked list:");
    scanf("%d", &iLength);

    Node *p = head;
    for (int i = 0; i< iLength; ++i) {
        Node *pNewNode = new Node;
        printf("Please enter the data of new node %d:", i);
        scanf("%d", &pNewNode->data);
        p->next = pNewNode;
        p = pNewNode;
    }
    p->next = NULL;

    return head;
}

void CSingleLinkedList::InsertLinkedList(Node* head, int iData, int iPos)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    Node* pNewNode = new Node;
    pNewNode->data = iData;

    int iCount = 0;
    while (head->next) {
        ++iCount;
        if (iPos == iCount) {
            pNewNode->next = head->next;
            head->next = pNewNode;
            printf("The data %d is inserted successfully!\n", iData);
            break;
        }
        head = head->next;
    }

    if (iCount < iPos) {
        printf("The position %d to be inserted is across the border of list!\n", iPos);
        printf("The data %d is inserted in the tail of list!\n", iData);

        pNewNode->next =head->next;
        head->next = pNewNode;
    }
}

void CSingleLinkedList::DeleteDataFromLinkedList(Node* head, int iData)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    Node* pDeleteNode;
    bool bDeleteFlag = false;
    while (head->next) {
        if (head->next->data == iData) {
            pDeleteNode = head->next;
            head->next = head->next->next;

            delete pDeleteNode;
            pDeleteNode = NULL;

            bDeleteFlag = true;
            continue;
        }
        head = head->next;
    }

    if (bDeleteFlag) {
        printf("The data %d is deleted successfully!\n", iData);
    }
    else {
        printf("The data %d is non-existent in the list!\n", iData);
    }
}

void CSingleLinkedList::ClearLinkedList(Node* head)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    Node* pDeleteNode;
    while (head->next) {
        pDeleteNode = head->next;
        head->next = head->next->next;

        delete pDeleteNode;
        pDeleteNode = NULL;
    }
}

void CSingleLinkedList::SearchDataFromLinkedList(Node* head, int iData, int &iFirstPos, int &iCount)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    if (0 == iFirstPos) {
        iFirstPos = 0;
    }
    if (0 == iCount) {
        iCount = 0;
    }

    int iPos = 0;
    while (head->next) {
        ++iPos;
        if (head->next->data == iData) {
            ++iCount;

            if (0 == iFirstPos) {
                iFirstPos = iPos;
            }
        }

        head = head->next;
    }
}

void CSingleLinkedList::ReverseLinkedList(Node* head)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    ListNode *pPrev = NULL;
    ListNode *pNext = NULL;
    ListNode *p = head->next;
    head->next = NULL;

    while (p) {
        pNext = p->next;
        p->next = pPrev;
        pPrev = p;
        p = pNext;
    }

    head->next = pPrev;
}

void CSingleLinkedList::PrintLinkedList(Node* head)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return;
    }

    // The header node has not data which is not required to printed.
    while (head->next) {
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}

int CSingleLinkedList::GetLinkedListLength(Node* head)
{
    int iLength = 0;
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return -1;
    }

    while (head->next) {
        ++iLength;
        head = head->next;
    }

    return iLength;
}

bool CSingleLinkedList::IsEmptyLinkedList(Node* head)
{
    if (NULL == head) {
        printf("The linked list is non-existent!\n");
        return false;
    }

    if (NULL == head->next) {
        return true;
    }
    else {
        return false;
    }
}
