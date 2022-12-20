#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    struct node* next;   
    node(){
        data=0;
        next=NULL;
    }
    node(int key){
        data=key;
        next=NULL;
    } 
};
struct node* newNode(int data){
    struct node* node1=new node();
    node1->data=data;
    node1->next=NULL;
    return node1;        
}
void insert(struct node* node,int data){
    struct node* temp=node;
    while(temp->next!=NULL){
        temp=temp->next;        
    }
    temp->next=newNode(data);    
}
void deleted(struct node* node,int data){
    struct node* temp=node;
    while(temp->next->data!=data){
        temp=temp->next;
    }
    struct node* deleted1=temp->next;
    temp->next=temp->next->next;
    free(deleted1);
}
void printall(struct node* node){
    struct node* temp=node;
    while(temp->next!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }    
    cout<<temp->data<<endl;
}
struct node* swapPairs(struct node* head,int k){//1,2,3,4,5
    struct node* temp=head;
    struct node* result=new node();
    vector<int> datas;
    while(temp!=NULL){
        datas.push_back(temp->data);
        temp=temp->next;        
    }
    int cnt=0;int i=0;
    for(i;i<=datas.size()-k;i+=k){
        cnt++;        
        for(int x=cnt*k-1;x>=i;x--){
            insert(result,datas[x]);
        }
    }
    for(i;i<datas.size();i++){
        insert(result,datas[i]);
    }
    result=result->next;
    printall(result);
    return result;
}
int main(){
    struct node* head=new node(1);
    insert(head,2);   
    insert(head,3);   
    insert(head,4);   
    insert(head,5);   

    swapPairs(head,2);

}