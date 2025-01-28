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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
int cnt=0;
        while(temp){
cnt++;
temp=temp->next;
        }
        cnt--;

        temp=head;
int res=0;
while(temp)
{
    res=res+ (temp->val<<cnt);
    cnt--;
    temp=temp->next;
}  
return res; 
    }
};
