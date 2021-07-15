#include<iostream>
using namespace std;
#define MAX 100
int arr[MAX];
int top = -1;

class Stack{
public:
    void push(int val){
        if(isFull()){
            cout << "Error: Stack Overflow!" << endl;
        }else{
            top++;
            arr[top] = val;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
        }else{
            top--;
        }
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFull(){
        if(top >= MAX)
            return true;
        else
            return false;
    }

    int getTop(){
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
            return 0;
        }else{
            return arr[top];
        }
    }

    int getSize(){
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
            return 0;
        }else{
            int temp = top;
            int count = 0;
            while(temp != -1){
                count++;
                temp--;
            }
            return count;
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Error: Stack Underflow!" << endl;
        }else{
            int temp = top;
            while(temp != -1){
                cout<<arr[temp]<<endl;
                temp--;
            }
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
        cout<<"6) Check if its Full"<<endl;
        cout<<"7) Display Stack"<<endl;
        cout<<"8) Quit"<<endl;
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
            case 6: cout<<"Stack Full: "<<s.isFull()<<endl;
                    break;
            case 7: cout<<"Stack Elements:"<<endl;
                    s.display();
                    break;
            case 8: cout<<"Exiting..."<<endl;
                    exit(0);
                    break;
            default: cout<<"Wrong Choice please enter valid choice:"<<endl;
                    break;
        }
    }
    
     
    return 0;
}