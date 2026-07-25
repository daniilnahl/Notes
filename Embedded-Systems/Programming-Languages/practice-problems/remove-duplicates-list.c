/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.

Example 1:

Input: head = [1, 1, 2]
Output: [1, 2]
Example 2:

Input: head = [1, 1, 2, 3, 3]
Output: [1, 2, 3]
*/
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


//BAD SOLUTION:
/*
Flaws:
Incorrect Memory Management: The line free(curr) is a major bug. 
It attempts to free the node before the duplicate node it has found. This breaks the linked list structure and can lead to crashes or unpredictable behavior.
Overly Complex: The use of four variables to manage state (val, head_tmp, curr, temp) makes the logic very difficult to follow and prone to errors.
Doesn't Terminate the List: It fails to set the next pointer of the last unique node to NULL. 
For an input like [1, 2, 3, 3], the resulting list's last node (3) will still point to the old memory location of the second 3, which is a dangling pointer.
*/

// struct ListNode* deleteDuplicates(struct ListNode* head) {
//     //step 1:
//     //get a node: val and *next
//     //step 2:
//     //keep iterating until a different val is found 
//     //case 1: if new value is its *next do nothing go to step 1
//     //case 2: if value is not its neighbor re-assign the struct's next then got to step 1
//     if (head == NULL) return NULL;

//     struct ListNode *head_tmp = head;
//     struct ListNode *curr = head;

//     while(curr != NULL){
//         if (curr->next == NULL) break;
        
//         if (head_tmp->val == curr->next->val){
//             struct ListNode *temp = curr->next;
//             curr=temp;
//             if (curr != head && curr !=head_tmp) free(curr);
//         } 
//         else if(head_tmp->val != curr->next->val){
//             head_tmp->next = curr->next; 
//             head_tmp = head_tmp->next;
//             curr=curr->next; 
//         }
//     }

//     return head;
// }

// Better solution because re-assigns curr->next safely breaking the linkage and then freeing the dangling node. 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode *head_tmp = head;
    struct ListNode *curr = head;

    while (curr != NULL && curr->next != NULL){
        if (curr->val != curr->next->val) curr = curr->next;
        else {
            struct ListNode *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
    }

    return head;
}

/****** 
 * WHAT WAS CORE IDEA?
    The core idea was to compare the current value with the next and if the same skip that node and free its assigned memory safely by first assigning that node to a temp ptr, then re-assigning the next value of 
    current and only the freeing the temp memory. Basically, first you make it a dangling ptr and then free its memory.
 * The DSA/PATTERN I used was just simple pointer methodology with a node struct.

 * WHAT TIME COMPLEXITY? Time complexity is O (N) where N is number of elements in the list.
 * 
 * WHAT SPACE COMPLEXITY? Space complexity is O (1) as only a fixed amount of variables are created.
 *
 *  ***/


// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
    }
    current->next = NULL;
    return head;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(", ");
        }
        head = head->next;
    }
    printf("]\n");
}

int main(){
  // Test Case 1: Simple case with duplicates at the start and end
    printf("--- Test Case 1: Simple Case ---\n");
    int arr1[] = {1, 1, 2, 3, 3};
    struct ListNode* list1 = createList(arr1, 5);
    printf("Original: "); printList(list1);
    list1 = deleteDuplicates(list1);
    printf("Result:   "); printList(list1); // Expected: [1, 2, 3]
    printf("\n");

    // Test Case 2: Edge case with no duplicates
    printf("--- Test Case 2: No Duplicates ---\n");
    int arr2[] = {1, 2, 3, 4, 5};
    struct ListNode* list2 = createList(arr2, 5);
    printf("Original: "); printList(list2);
    list2 = deleteDuplicates(list2);
    printf("Result:   "); printList(list2); // Expected: [1, 2, 3, 4, 5]
    printf("\n");

    // Test Case 3: Edge case with an empty list
    printf("--- Test Case 3: Empty List ---\n");
    struct ListNode* list3 = NULL;
    printf("Original: "); printList(list3);
    list3 = deleteDuplicates(list3);
    printf("Result:   "); printList(list3); // Expected: []
    printf("\n");

    return 0;
}