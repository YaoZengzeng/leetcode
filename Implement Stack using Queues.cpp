class Stack {
    queue<int> q1,q2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(q1.empty()){
            q2.push(x);
        }else{
            q1.push(x);
        }
        return ;
    }

    // Removes the element on top of the stack.
    void pop() {
        int t;
        if(q1.empty()){
            while(!q2.empty()){
                t=q2.front();
                q2.pop();
                if(q2.empty()){
                    break;
                }
                q1.push(t);
            }
        }else{
            while(!q1.empty()){
                t=q1.front();
                q1.pop();
                if(q1.empty()){
                    break;
                }
                q2.push(t);
            }
        }
        return;
    }

    // Get the top element.
    int top() {
        int t;
        if(q1.empty()){
            while(!q2.empty()){
                t=q2.front();
                q2.pop();
                q1.push(t);
            }
        }else{
            while(!q1.empty()){
                t=q1.front();
                q1.pop();
                q2.push(t);
            }
        }
        return t;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
