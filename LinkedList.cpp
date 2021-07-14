#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*head, *tail, *temp, *current, *previous;

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

    void addNodeBegin(int val){
        temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if(isEmpty()){
            head = temp;
            tail = temp;
        }else{
            temp->next = head;
            head = temp;
        }
    }

    void addNodeMid(int val, int key){
        temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if(isEmpty()){
            head = temp;
            tail = temp;
        }else{
            current = head;
            while(current != NULL){
                if(current->data == key){
                    temp->next = current->next;
                    current->next =temp;
                }
                current = current->next;
            }
        }
    }

    void deleteNode(int val){
        if(isEmpty()){
            cout << "Error: LinkedList is Empty" << endl;
        }else{
            temp = head;
            while(temp != NULL){
                if(temp->data == val){
                    previous->next = temp->next;
                }
                previous = temp;
                temp = temp->next;
                
            }
        }
    }

    void deleteNodeBegin(){
        if(isEmpty()){
            cout << "Error: LinkedList is empty" << endl;
        }else{
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteNodeEnd(){
        if(isEmpty()){
            cout << "Error: LinkedList is empty" << endl;
        }else{
            temp = head;
            while(temp != tail){
                previous = temp;
                temp = temp->next;
            }
            if(temp == tail){
                previous->next = NULL;
                tail = previous;
            }
        }
    }

    int search(int key){
        int count = 0;
        if(isEmpty()){
            cout<<"Error: LinkedList is empty"<<endl;
        }else{
            temp = head;
            while(temp != NULL){
                if(temp->data == key){
                    return count;
                }
                temp = temp->next;
                count++;
            }
        }
        return -1;
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
    L.addNodeBegin(9);
    L.addNodeBegin(8);
    L.addNodeBegin(7);
    L.addNodeMid(11,10);
    L.addNodeMid(12,11);
    L.addNodeMid(13,12);
    L.display();
    L.deleteNode(12);
    L.deleteNode(13);
    L.deleteNodeBegin();
    L.display();
    L.deleteNodeEnd();
    L.display();
    if(L.search(255) > -1){
        cout << "Element is present at:" <<L.search(255) <<endl;
    }else{
        cout<< "Element is not present in LinkedList"<<endl;
    }
}