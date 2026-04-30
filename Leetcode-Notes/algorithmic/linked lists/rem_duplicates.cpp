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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        if (ptr == nullptr || ptr->next == nullptr) return ptr;
        else{
            ListNode* temp = ptr->next;
            ListNode* res = ptr;

            while (temp != nullptr){
                if (ptr->val == temp->val){
                    temp = temp->next; 
                    if (temp == nullptr) ptr->next = nullptr;
                }else {
                    ptr->next = temp;
                    ptr = temp;
                    temp=temp->next;
                }
            }

            return res;
        }

    }
};
/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to address the edge cases of nullptr at the start and afterwards iterate through the linked list using two pointers:
 ptr and temp. 'ptr' acts as the base while 'temp' acts as the one that goes forwards and seeks out nodes that have repeating values.
 Whenever 'ptr' and 'temp' nodes are equal temp moves foward and whenever they are not a link between 'ptr' and 'temp' are created.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used was traversing Linked list using a 2 pointer approach.
 * WHAT TIME COMPLEXITY? Time complexity is O (N) for traversal of the original linked list.
 * 
 * WHAT SPACE COMPLEXITY? Space complexity is O (1) for the linked nodes created with the code. The rest of the nodes already exist in memory and only references to them (links) are being setup.
 * WHAT IS THE SUMMARY OF THIS?
 * 
 *  ***/

