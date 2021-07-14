#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*head, *tail, *temp;

class LinkedList{
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        }else{
            return false;
        }
    }

    void addNode(int val){
        temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if(isEmpty()){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Error: LinkedList is empty"<<endl;
        }else{
            temp = head;
            while(temp != NULL){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"Null"<<endl;
        }
    }
};

int main(){
    LinkedList L;
    L.addNode(10);
    L.addNode(20);
    L.addNode(30);
    L.addNode(40);
    L.addNode(50);
    L.display();
}