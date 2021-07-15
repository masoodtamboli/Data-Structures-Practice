#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
}*top=NULL, *temp;

class Stack{
public:
    void push(int val){
        temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if(isEmpty()){
            top = temp;
        }else{
            temp->next = top;
            top = temp;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
        }else{
            top = top->next;
        }
    }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }else{
            return false;
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
        }else{  
            temp = top;
            while(temp != NULL){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }    
            cout<<"Null"<<endl;
        }
    }

    int getTop(){
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
            return 0;
        }else{
            return top->data;
        }
    }

    int getSize(){
        int count = 0;
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
            return 0;
        }else{
            temp = top;
            while(temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
};

int main(){
    Stack s;
    int choice, val;
    while(choice != 8){
        cout<<"***************************************"<<endl;
        cout<<"Enter your choice:"<<endl;
        cout<<"1) Push"<<endl;
        cout<<"2) Pop"<<endl;
        cout<<"3) Get Top of Stack"<<endl;
        cout<<"4) Get Size of stack"<<endl;
        cout<<"5) Check if its Empty"<<endl;
        cout<<"6) Display Stack"<<endl;
        cout<<"7) Quit"<<endl;
        cout<<"***************************************"<<endl;
        cin>>choice;   

        switch(choice){
            case 1: cout<<"Enter element to add"<<endl;
                    cin>>val;
                    s.push(val);
                    break;
            case 2: cout<<"Performing Pop"<<endl;
                    s.pop();
                    break;
            case 3: cout<<"Top: "<<s.getTop()<<endl;
                    break;
            case 4: cout<<"Size of Stack: "<<s.getSize()<<endl;
                    break;
            case 5: cout<<"Stack Empty: "<<s.isEmpty()<<endl;
                    break;
            case 6: cout<<"Stack Elements:"<<endl;
                    s.display();
                    break;
            case 7: cout<<"Exiting..."<<endl;
                    exit(0);
                    break;
            default: cout<<"Wrong Choice please enter valid choice:"<<endl;
                    break;
        }
    }
    
     
    return 0;
}