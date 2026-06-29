class Solution {
public:
    vector<string> result;
    int N;
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){

            if(ch == '(') st.push(ch);

            else{ // yaha isiliye aaye ha kyunki ch = ')' hai
                if(st.empty()) return false; //cannot push ')' into an empty stack , it would never find as pair and will always be an invalid parantheses.

                if(st.top() == '(') st.pop();
                else st.push(ch);
            }
        }
        return st.empty();
        
    }
    void solve(string curr, int N){
        if(curr.size() == 2*N){
            if(isValid(curr)){
                result.push_back(curr);
            }
            return;
        }
    
        curr.push_back('(');
        solve(curr,N);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,N);
        curr.pop_back();
    }
     vector<string> generateParenthesis(int n) {
        N = n;
        solve("", n);
        return result;
    }
};