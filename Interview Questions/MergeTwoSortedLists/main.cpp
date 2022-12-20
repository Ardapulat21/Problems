#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        val=0;
        next=NULL;
    }
    ListNode(int key){
        val=key;
        next=NULL;
    }

};
struct ListNode* newNodes(ListNode* node,int key){
    struct ListNode* newNode=new ListNode(key);
    struct ListNode* temp2=node;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=newNode;
    return node;
}
void printAllNodes(ListNode* node){
    struct ListNode* temp=node;
    while(temp!=NULL){
        cout<<temp->val<<endl;
        temp=temp->next;
    }
}
struct ListNode* deleteAtTheEnd(ListNode* node){
    struct ListNode* temp=node;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    return node;
}

int main()
{
    struct ListNode* n1=new ListNode(1);
    newNodes(n1,2);
    newNodes(n1,4);
    struct ListNode* n2=new ListNode(1);
    newNodes(n2,3);
    newNodes(n2,4);
    struct ListNode* rList=new ListNode();
    struct ListNode* temp=rList;
    while(true){
        cout<<"x"<<endl;
        if(n1==NULL || n2==NULL){
            cout<<"Stop!"<<endl;
            break;
        }
        if(n1->val>n2->val){
        cout<<n2->val<<" eklendi"<<endl;
         rList->next=n2;
         rList=rList->next;
         n2=n2->next;
        }
        else if(n1->val<n2->val){
            cout<<n1->val<<" eklendi"<<endl;
            rList->next=n1;
            rList=rList->next;
            n1=n1->next;

        }
        else if(n1->val==n2->val){
            cout<<n1->val<<" eklendi"<<endl;
            cout<<n2->val<<" eklendi"<<endl;
            newNodes(rList,n1->val);
            rList=rList->next;
            newNodes(rList,n1->val);
            rList=rList->next;
            n1=n1->next;
            n2=n2->next;
        }
    }
    temp=temp->next;
    deleteAtTheEnd(temp);
    printAllNodes(temp);

    return 0;
}
