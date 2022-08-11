Implement a first in first out (FIFO) queue using only two stacks.
 The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
void push(int x)  Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top,
size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively.
You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 
 /*
 What we basially do here is use '2' stacks, we first push all the elements into a stack.
 When we have to pop or peek, we reverse the stack by pushing s1 to s2.
 Now automatically the reversed stack is a queue of FIFO now u can peek the top or pop it.
 --> Therefore when pop/peek operation occurs and if s2 is empty u push s1 to s2 and continue.
  If not empty just do top, pop operation. 
 */

 //Coming  to tc most of pop and peek cases it going to be O(1) but if the s2 is empty then its O(n) and O(n) for push
 // Therefore the TC of this is O(1) but *amonetixed time compl* [means we avoid the few instance of worst TC]
 // The SC will be O(2n) since we use 2 stacks of n size
#include<stack>
class MyQueue {
public:
    stack<int>s1,s2;
    //s1 is the stack u insert directly and s2 is where u pop elements from
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
             while(!s1.empty()){
            int x = s1.top();
            s2.push(x);
            s1.pop();
             }
        }
        int x= s2.top();
            s2.pop();
           return x;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */