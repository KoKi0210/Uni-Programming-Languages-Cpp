#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

class Stack{
private:
    char data[MAX_SIZE];
    int top;

public:
    Stack(){
        top =-1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(char item){
        if (isFull())
        {
            cout << "Error: Stack is full. Cannot push item." << endl;
            return;
        }
        top++;
        data[top] = item;        
    }

    char pop(){
        if(isEmpty()){
           cout << "Error: Stack is empty. Cannot pop item." << endl;
            return '\0'; 
        }
        char item = data[top];
        top--;
        return item;
    }
};

Stack loadStack(){
    Stack s;
    for (char c = 'a'; c <= 'z'; c++)
    {
        s.push(c);
    }
    return s;
}

Stack loadStack(int upper){
    Stack s;
    if (upper == 1){
        for (char c = 'A'; c <= 'Z'; c++){
        s.push(c);
        }
    }else{
    for (char c = 'a'; c <= 'z'; c++) {
            s.push(c);
        }
    } 
    return s;
}

int main(){

    cout << "--- Loading stack with loadstack() [lowercase] ---" << endl;
    Stack s1 = loadStack();

    cout << "Popping all items (LIFO order): ";
    while (!s1.isEmpty()) {
        cout << s1.pop(); 
    }
    cout << endl << endl;

    cout << "--- Loading stack with loadstack(1) [uppercase] ---" << endl;
    Stack s2 = loadStack(1);
    
    cout << "Popping all items (LIFO order): ";
    while (!s2.isEmpty()) {
        cout << s2.pop(); 
    }
    cout << endl << endl;

    cout << "--- Loading stack with loadstack(0) [lowercase] ---" << endl;
    Stack s3 = loadStack(0); 
    cout << "Popping all items (LIFO order): ";
    while (!s3.isEmpty()) {
        cout << s3.pop(); 
    }
    cout << endl;

    return 0;
}