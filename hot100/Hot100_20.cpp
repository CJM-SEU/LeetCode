//example: ({}{}[()])()[],  [({()})]
#include <iostream>
#include <string>
#include <stack>    
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
                cout << c << " has been push" << endl;
            }
            else{
                if(st.empty()){
                    cout << "stack is empty" << endl;
                    return false;
                }
                else{
                    char front = st.top();
                    st.pop();
                    cout << front << " <---> " << c << endl;
                    if(!IsPair(front, c)){
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
            

    

private:
    bool IsPair(char front, char behind){
        int siginal = (front == '(' && behind == ')') || 
                (front == '{' && behind == '}') || 
                (front == '[' && behind == ']');
        if(siginal) cout << "pair" << endl;
        else cout << "not pair" << endl;
        return siginal;
    }
    
};
int main(){
    Solution sol;
    string testCases[] = {
         "({}{}[()])()[",
        // "[({()})]",
        // "()",
        // "()[]{}",
        // "(]",
         "([)]",
         "{()}"
    };
    
    cout << "=== 括号匹配测试 ===" << endl;
    for (const string& test : testCases) {
        bool result = sol.isValid(test);
        cout << "result: " << result << endl;
        cout << "输入: " << test << " => " 
             << (result ? "有效" : "无效") << endl;
    }
    return 0;
}