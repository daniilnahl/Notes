//Given the head of a linked list, remove the nth node from the end and return its head.
/*
Example 1:

Input: head = [1, 2, 3, 4, 5], n = 2
Output: [1, 2, 3, 5]
Example 2:

Input: head = [1], n = 1
Output: []
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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
//1st Approach
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (n <=0) return head;
    if (head==NULL) return head; //if empty list is passed return itself
    int counter = 2; //1 is the first index value of the collection (not 0 indiced)
    int rem_idx = 0; //what index must be removed (just declared for now)

    struct ListNode *curr = head;
    //loop to find full size of the list
    while(curr->next != NULL){
        curr=curr->next;
        counter++;
    }

    if (n > counter) return head; //nth node that must be removed is at an invalid location
    if (n == counter) {
        free(head);
        return NULL;
    }

    rem_idx = (counter+1) - n; //what element to remove from the head. Must add 1 to the counter so the correct node is removed. Eg n=2 and size is 5. It will remove node 3 instead of 4
    counter=1; //reset counter
    curr = head; //reset ptr

    while(counter!=rem_idx){
        if (counter == rem_idx-1){
            struct ListNode *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            break;
        }

        curr=curr->next;
        counter++;
    }

    return head;
}

//2nd Approach

int main() {
    // Test Case 1: Remove a middle node
    printf("--- Test Case 1: Remove a middle node ---\n");
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* list1 = createList(arr1, 5);
    printf("Original: "); printList(list1);
    list1 = removeNthFromEnd(list1, 2);
    printf("Result:   "); printList(list1); // Expected: [1, 2, 3, 5]
    printf("\n");

    // Test Case 2: Remove the head node
    printf("--- Test Case 2: Remove the head node ---\n");
    int arr2[] = {1, 2, 3, 4, 5};
    struct ListNode* list2 = createList(arr2, 5);
    printf("Original: "); printList(list2);
    list2 = removeNthFromEnd(list2, 5);
    printf("Result:   "); printList(list2); // Expected: [2, 3, 4, 5]
    printf("\n");

    // Test Case 3: Remove the only node in the list
    printf("--- Test Case 3: Remove the only node ---\n");
    int arr3[] = {1};
    struct ListNode* list3 = createList(arr3, 1);
    printf("Original: "); printList(list3);
    list3 = removeNthFromEnd(list3, 1);
    printf("Result:   "); printList(list3); // Expected: []
    printf("\n");

    return 0;
}