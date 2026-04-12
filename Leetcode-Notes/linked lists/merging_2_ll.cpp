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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;
        ListNode* temp;

        //add check for if empty
        if(list1 == nullptr){
          res = list2;  
          return res;
        } 
        if(list2 == nullptr){
            res = list1;
            return res;
        }

        if (list1->val < list2->val){
            temp = list1;
            list1 = list1->next;
            res = temp;
         }else{ //less than or equal to
            temp = list2;
            list2 = list2->next;
            res = temp;
        } 

        while (list1 != nullptr && list2 != nullptr){
            if ((list1->val < list2->val)){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }else{ //less than or equal to
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        if (list1 == nullptr){
            temp->next=list2;
        }else if(list2 == nullptr){
            temp->next=list1;
        }
        return  res;
    }
};

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to loop until either ends of linked lists is met and re-linking into a temporary linked list
  based on the current nodes' values in ascending order.
 * WHAT PATTERN/DSA DID THIS USE? I utilized a very vague version of a 2 pointer and simple manipulation of linked lists.
 * The DSA/PATTERN I used linked lists.
 * Key concepts that I learned were reinforcing my understanding on how to traverse linked lists.
 *  
 * WHAT TIME COMPLEXITY? time complexity is O (n+m) n and m are sizes of linked lists.
 * 
 * WHAT SPACE COMPLEXITY? space complexity is O (1) because I am only re-ordering the nodes instead of creating new ones.
 * 
 * WHAT IS THE SUMMARY OF THIS?
 * 
 *  ***/

