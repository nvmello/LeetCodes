#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        unordered_map<int, ListNode*> umap;

        int i = 1;
        if((*head).next == nullptr){
            head = NULL;
        } 
        else{
            while ((*head).next != nullptr)
            {
                umap[i] = head;
                head = (*head).next;
                i++;
                // cout<< (*head).val <<endl;
            }
        
            int keyToRemove = i-n+1;
            
            if(n==1)
            {
                (*umap[keyToRemove-1]).next = nullptr;
            }
            else if(i==n){
                temp = temp->next;
            }
            else{
                (*umap[keyToRemove-1]).next = (*umap[keyToRemove]).next;
            }
            head = temp;
        }
        return head;
        
    }
};

int main(){
    ListNode* h1;
    (*h1).val = 1;

    ListNode* h2;
    (*h2).val = 2;

    ListNode* h3;
    (*h3).val = 3;

    ListNode* h4;
    (*h4).val = 4;

    ListNode* h5;
    (*h5).val = 5;

    (*h1).next = h2;
    (*h2).next = h3;
    (*h3).next = h4;
    (*h4).next = h5;

    Solution s;
    s.removeNthFromEnd(h1, 1);
}



// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         unordered_map<int, ListNode*> umap;
//         cout<<"Start:"<<endl;
//         cout<< "Head: " << (*head).val <<endl;
//         int i = 1;
//         while ((*head).next != nullptr)
//         {
//             head = (*head).next;
//             i++;
//             cout<< (*head).val <<endl;
//         } 
//         return head;
        
//     }
// };