/*linked Lists*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node {
    int val ;
    struct Node *next ;
}Node ;


typedef struct CDLLNode {
    int val ;
    struct CDLLNode *next ;
    struct CDLLNode *previous ;
}CDLLNode ;


/* Basic Linked List Operations */


// 1. Create Singly Linked List
// Creates a linked list from user input.
Node* createLinkedList( int size ) {
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    
    printf("Enter numbers (-1000 to stop): ") ;

    while(1) {

        scanf("%d", &data);

        if(data == -1000){
            break ;
        } 
        
        Node* newNode = (Node*)malloc(sizeof(Node)) ;
        newNode->val = data;
        newNode->next = NULL;
        
        if(head == NULL ){
            head = tail = newNode ;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Prints the linked list.
void printList(Node* head) {
    Node *p=head ;

    while (p != NULL){
        printf ("[ %d ] " , p->val );
        p = p->next ;
    }
    
}

// Inserts a node at the beginning.
Node* insertAtBeginning(Node *head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)) ;
    newNode->val = data;
    newNode->next = head ;
    return newNode ;
}

// Inserts a node at the end.
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)) ;
    newNode->val = data;
    newNode->next = NULL ;

    if (head == NULL) {
        return newNode ;
    }

    Node* current = head;

    while (current->next != NULL) {
        current = current->next ;
    }

    current-> next = newNode ;
    return head ;
}

// Inserts a node at a specific position.
Node* insertAtPosition(Node* head, int data, int pos) {

    Node* newNode = (Node*)malloc(sizeof(Node)) ;
    newNode->val = data;
    newNode->next = NULL ;

    if (pos == 0 || head == NULL) {
        newNode -> next=head;
        return newNode;
    }

    Node* current = head;

    for (int i=0 ; i<pos-1 && current->next != NULL ; i++){
        current = current->next ;
    }

    newNode->next = current->next ;
    current-> next = newNode ;
    return head ;
}

// Deletes the first occurrence of a value.
Node* deleteByValue(Node* head, int value) {

    if (head->val == value) {
        Node* temp = head->next ;
        free(head) ;
        return temp ;
    }

    Node *current ;
    current = head ;
    while (current->next != NULL && current->next->val != value) {
        current = current->next ;
    }

    if(current->next != NULL ){       
        Node* temp = current->next ;
        current->next = temp->next ;
        free(temp) ;
    }

    return head ;
}

// Deletes a node at a given position.
Node* deleteByPosition(Node* head, int pos) {
    if (head == NULL) {
        return NULL ;
    }

    if (pos == 0 ) {
        Node* temp = head->next ;
        free(head) ;
        return temp ;
    }

    Node *current ;
    current = head ;
    for(int i = 0 ; i<pos-1 && current->next != NULL  ; i++){
        current = current->next ;
    }

    if(current->next != NULL ){       
        Node* temp = current->next ;
        current->next = temp->next ;
        free(temp) ;
    }

    return head ;
    
}

// Searches for a node by value.
Node* findByValue(Node* head, int value) {
    Node *current ;
    current = head ;
    while (current != NULL ){
        if (current->val == value) {
            return current ;
        }
        current = current->next ;
    }
    return NULL ;
    
}

// Searches for a node by position.
Node* findByPosition(Node* head, int pos) {
    Node* current = head;
    for (int i = 0; current != NULL && i < pos; i++) {
        current = current->next;
    }
    return current;
}



/* Intermediate Linked List Operations */
// Finds the number of nodes.
int lengthOfLLL(Node* head) {
    Node *current = head ;
    int count ;
    while (current != NULL){
        count ++ ;
        current = current->next ;
    }
    return count ;
}

// Reverses the linked list.
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next ;
        current->next = prev ;
        prev = current ;
        current = next ;
    }
    return prev ;
}

// Finds the most frequently occurring element.
int mostFrequent(Node* head) {
    if (head == NULL) {
        return -999 ;
    }
    int maxval = head->val , maxcount=0 ;
    Node *current = head ;
    while (current != NULL ){
        int count = 0 ;
        Node *temp = head ;
        while (temp != NULL){
            if (temp ->val == current->val){
                count ++ ;
            }
            temp=temp->next ;
        }
        if(maxcount < count){
            maxcount = count ;
            maxval = current->val ;
        }
        current = current->next ;
    }

    return maxval ;
}




/* Sorting Algorithms */

// Bubble Sort for linked list.
Node* bubbleSort(Node* head) {

    if (head ==NULL ||head->next==NULL) {
        return head ;
    }

    bool swapped ;
    Node *ptr = head ;
    Node *lastptr = NULL ;

    do {
        swapped = false ; 
        ptr = head;

        while (ptr->next != lastptr) {
            if (ptr->val > ptr->next->val) {
                int temp = ptr-> val ;
                ptr-> val = ptr-> next -> val ;
                ptr->next-> val = temp ;
                swapped = true ;
            }
            ptr = ptr -> next;
        }
        lastptr =ptr ;
    }while (swapped ==true ) ;

    return head;
}

// Selection Sort for linked list.
Node* selectionSort(Node* head) {
   Node *minnode , *curernt = head , *tempnode; 
   int tempval ; 

   while (curernt != NULL){
        tempnode = curernt -> next ;
        minnode = curernt ;

        while (tempnode != NULL ){
            if (tempnode->val < minnode->val){
                minnode = tempnode ;
            }

            tempnode = tempnode->next ;
        }

        tempval = minnode ->val ;
        minnode ->val = curernt ->val ;
        curernt->val = tempval ;

        curernt = curernt->next ;
    }
   return head ;
}

// Insertion Sort for linked list.
Node* insertionSort(Node* head) {
    
}

// Merge Sort for linked list.
Node* mergeSort(Node* head) {
    
}

// Quick Sort for linked list.
Node* quickSort(Node* head) {
    
}




/* Advanced Linked List Operations */

// Checks if the list is a palindrome.
bool isPalindrome(Node *head) {
    if (head == NULL || head->next == NULL){
        return true;
    }


    int halfLen = lengthOfLLL(head) / 2;
    

    Node *dupHead = NULL, *dupTail = NULL;
    Node *current = head;
    for (int i = 0; i < halfLen; i++) {

        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->val = current -> val ;
        newNode->next = NULL ;
        

        if( dupHead == NULL) {
            dupHead =newNode ;
            dupTail =newNode ;
        }else{
            dupTail->next = newNode;
            dupTail = newNode;
        }
        current = current-> next;
    }
    

    head = reverseList (head) ;
    Node *dupCurrent = dupHead ;
    current = head ;

    while (dupCurrent != NULL ){
        if (current->val != dupCurrent ->val){
            return false ;
        }
        current = current->next ;
        dupCurrent = dupCurrent -> next ;
    }

    return true ; 
}

// Rotates the list by k positions.
Node* rotateList(Node* head, int k) {
    if (head == NULL ||k ==0){
        return head ;
    }

    int len =lengthOfLLL(head) ;
    Node* tail = head ;

    while (tail->next != NULL){
        tail = tail->next ; 
    }

    k=k % len  ;
    if (k==0) {
        return head ;
    }

    Node* newtail = head ;
    for (int i = 0; i < len - k - 1; i++){
        newtail = newtail-> next ;
    }

    Node* newhead = newtail->next ;
    newtail->next = NULL ;
    tail -> next = head ;

    return newhead ;
}

// Reverses nodes in groups of k.
Node* reverseInGroups(Node* head, int k) {
    Node* current = head ,*next = NULL , *prev = NULL ;
    int count= 0 ;

    while (current != NULL && count<k ) {
        next = current->next ;
        current -> next = prev ;
        prev = current ;
        current = next ;
        count++ ;
    }

    if (next != NULL) {
        head -> next = reverseInGroups(next, k);
    }

    return prev;
}

// Deletes nodes with values below a threshold.
Node* deleteBelowThreshold(Node* head, int threshold) {
    
}

// Converts a linked list into a circular list.
Node* convertToCircular(Node* head) {
    
}

// Converts a singly linked list into a doubly linked list.
Node* convertToDoubly(Node* head) {
    
}

// Merges two lists without extra memory.
Node* mergeListsNoExtraMemory(Node* list1, Node* list2) {
    
}



/* Circular Doubly Linked List Operations */

// Creates a new node for a circular doubly linked list.
CDLLNode* createCDLLNode(int data) {
    
}

// Constructs a circular doubly linked list from an array.
CDLLNode* createCircularDoublyLinkedList(int arr[], int size) {
    
}

// Prints a circular doubly linked list.
void printCDLL(CDLLNode* head) {
    
}

// Inserts a node at the beginning of a CDLL.
CDLLNode* insertCDLLAtBeginning(CDLLNode* head, int data) {
    
}

// Inserts a node at the end of a CDLL.
CDLLNode* insertCDLLAtEnd(CDLLNode* head, int data) {
    
}

// Inserts a node at a specific position in a CDLL.
CDLLNode* insertCDLLAtPosition(CDLLNode* head, int data, int pos) {
    
}

// Deletes a node with a given value in a CDLL.
CDLLNode* deleteCDLLByValue(CDLLNode* head, int value) {
    
}

// Deletes a node at a specific position in a CDLL.
CDLLNode* deleteCDLLByPosition(CDLLNode* head, int pos) {
    
}

// Reverses a circular doubly linked list.
CDLLNode* reverseCDLL(CDLLNode* head) {
    
}

// Merges two circular doubly linked lists into one.
CDLLNode* mergeCDLL(CDLLNode* list1, CDLLNode* list2) {
    
}
