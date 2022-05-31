#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;            //value in each node
    ListNode *next;     //pointer to the next node in list
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;                  //create a temp listnode to remember which node was the first later
        unordered_map<int, ListNode*> umap;     //create unordered map to store the nodes with their position as the key

        int i = 1;          //iterator to keep track of each nodes position

        if(head->next == nullptr){      //if the first node.next is empty
            head = NULL;                //set head to null and return
        } 
        else{                           //otherwise 
            while (head->next != nullptr)       
            {
                umap[i] = head;         //place nodes into map
                head = head->next;      //move through nodes once until end of linked list is reached
                i++;
                // cout<< (*head).val <<endl;
            }
        
            int keyToRemove = i-n+1;    //i is now the length of the linked list, minus the given n, +1 to keep our math straight
                                        //gives us the node to remove, or the key to search for
            
            if(n==1)                    //if the node to remove is the very last node node
            {
                (umap[keyToRemove-1])->next = nullptr;      //change the second to last nodes .next to null using the map
            }
            else if(i==n){              //if the first node is the node to be removed, simply return the original heads .next
                temp = temp->next;      
            }
            else{
                (*umap[keyToRemove-1]).next = (*umap[keyToRemove]).next;    //point the node prior to the node to be removed, to the node to be removeds .next
            }
            head = temp;        //reset the original head to our new temp linked list.
        }
        return head;
        
    }
};

int main(){
    ListNode* h1 = new ListNode();
    h1->val = 1;

    ListNode* h2 = new ListNode();
    h2->val = 2;

    ListNode* h3 = new ListNode();
    h3->val = 3;

    ListNode* h4 = new ListNode();
    h4->val = 4;

    ListNode* h5 = new ListNode();
    h5->val = 5;

    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;

    Solution s;

    ListNode* temp = new ListNode();

    //test output
    temp = h1;
    cout<<"\nBefore Removal: "<<endl;
    cout<< temp->val;
    while (temp->next != nullptr)
        {
            temp = temp->next;
             cout<< " -> "<< temp->val;
        }
    s.removeNthFromEnd(h1, 2);

//test output
    temp = h1;
    cout<<"\nAfter Removal: "<<endl;
    cout<< temp->val;
    while (temp->next != nullptr)
        {
            temp = temp->next;
             cout<< " -> "<< temp->val;
        }
    cout<<"\nDone"<<endl;

}