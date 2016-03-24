/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <cmath>

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if((l1==NULL)&&(l2==NULL)) {
            return NULL;
        }
        unsigned long long sum1 = 0;
        unsigned long long sum2 = 0;
        unsigned long long sum3 = 0;
        int count1=0;
        int count2=0;
        
        while(l1 != NULL)
        {
            sum1+=pow(10,count1) * (l1->val);
            count1++;
            l1=l1->next;
         }
        //std::cout<<"sum1:"<<sum1<<std::endl;
        
        while(l2 != NULL)
        {
            sum2+=pow(10,count2) * (l2->val);
            count2++;
            l2=l2->next;
        }
        //std::cout<<"sum2:"<<sum2<<std::endl;
        
        sum3 = sum1+sum2;
        //std::cout<<"sum3:"<<sum3<<std::endl;
        
        unsigned long tmp_digit = sum3- (sum3/10)*10;
        ListNode* p = new ListNode((int)tmp_digit);
        ListNode* start = p;
        sum3=sum3/10;
        
        while(sum3>0) {
            tmp_digit = sum3- (sum3/10)*10;
            p->next = new ListNode((int)tmp_digit);
            p = p->next;
            sum3=sum3/10;
        }
        return start;
        
    }
};
