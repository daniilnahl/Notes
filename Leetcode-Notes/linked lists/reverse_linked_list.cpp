//Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* currptr = head;
        ListNode* prevptr  = nullptr;
        ListNode* nextptr;

        while(currptr != nullptr){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
       
        return prevptr;
    }
};


/****** 
 * WHAT WAS CORE IDEA?
The core ideas was manipulating the pointers of a linked list in a intersting way to requires thinking outside the box.
Basically, you create 3 pointers: current, next and previous. 
First, you save the next pointer of the current pointer.
Second, you set the current pointer to point to the previous pointer.
Third, you set previous pointer to be the current pointer.
Fourth, you set the current pointer to be the next pointer from the first step.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was linked list.
 * 
 * Key concepts that I learned were:
 * 1. I learned how to get value from a node in a linked list: heat->val;
 * 2. I learned how to get next node in a linked list: head->next;
 * 3. I learned that there is no standard for linked list in C++, so in future I need to make my own following the linked list logic.
 * WHAT TIME COMPLEXITY?
 *  O (n) where n is number of nodes.
 * WHAT SPACE COMPLEXITY?
 *  O (1) 
 * WHAT IS THE SUMMARY OF THIS?
 *  In summary, reversing a linked list by manipulating pointers.
 *  ***/

