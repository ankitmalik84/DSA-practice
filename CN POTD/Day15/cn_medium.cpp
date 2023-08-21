
#include <stack>

vector<int> exclusiveTime(vector<vector<int>> &logs, int n, int l) {
    
    // Create a stack to push functions.
    stack<int> stack;
    
    // Array to store exclusive time of each function.
    vector<int> ans(n);

    stack.push(logs[0][0]);

    int i = 1;
    int prev = logs[2][0];

    while (i < l) {

        // If any function starts.
        if (logs[1][i] == 1) {
            
            // Update the time of previous executing function.
            if (!stack.empty()) {
                ans[stack.top()] += logs[2][i] - prev;
            }
            
            // Push the function into the stack.
            stack.push(logs[0][i]);
            prev = logs[2][i];
        } 
        
        // If it terminates.
        else {  

            // Remove it from stack, and update the time taken.
            ans[stack.top()] += logs[2][i] - prev + 1;
            stack.pop();
            prev = logs[2][i] + 1;
        }
        
        i++;
    }    
    return ans;
}