#ifndef LINKEDLIST_LIB_H
#define LINKEDLIST_LIB_H

#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Doubly Linked List Node
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// 1. Create Singly Linked List
Node* createLinkedList();

// 2. List Length
int listLength(Node* head);

// 3. Find Most Frequent
int findMostFrequent(Node* head);

// 4. Find Node by Value
Node* findNodeByValue(Node* head, int value);

// 5. Get Node by Position
Node* getNodeAtPosition(Node* head, int pos);

// 6. Delete by Value
Node* deleteByValue(Node* head, int value);

// 7. Delete by Position
Node* deleteByPosition(Node* head, int pos);

// 8. Insert by Position
Node* insertByPosition(Node* head, int data, int pos);

// 9. Merge Sorted Lists
Node* mergeSortedLists(Node* l1, Node* l2);

// 10. Split List by Criterion
void splitList(Node* head, Node** pass, Node** fail, int (*test)(int));

// 11. Find Minimum Node
Node* findMinNode(Node* head);

// 12. Merge Without New Memory (same as 9)
// 13. Delete All Occurrences
Node* deleteAllOccurrences(Node* head, int value);

// 14. Reverse List
Node* reverseList(Node* head);

// 15. Check Palindrome
int isPalindrome(Node* head);

// 16. Remove Duplicates
void removeDuplicates(Node* head);

// 17. Add to Empty List
Node* addIfEmpty(Node* head, int data);

// 18. Selection Sort
void selectionSort(Node* head);

// 19. Reverse in Groups of K
Node* reverseKGroup(Node* head, int k);

// 20. Rotate List
Node* rotateRight(Node* head, int k);

// 21. Delete Below Threshold
Node* deleteBelowThreshold(Node* head, int threshold);

// 22. Create Doubly Linked List
DNode* createDoublyLinkedList();

// 23. Insert into Doubly Linked List
DNode* insertDNode(DNode* head, int data, int pos);

// 24. Delete from Doubly Linked List
DNode* deleteDNode(DNode* head, int pos);

// 25. Create Circular Linked List
Node* createCircularLinkedList();

// 26. Doubly Linked List Operations (same as 22-24)
// 27. Circular Doubly Linked List
DNode* createCircularDoublyLinkedList();

#endif // LINKEDLIST_LIB_H
