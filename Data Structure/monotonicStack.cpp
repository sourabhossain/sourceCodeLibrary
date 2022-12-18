#include <bits/stdc++.h>

using namespace std;

vector<int> increasingStack(vector<int> data, int length) {
    stack<int> s;
    
    for(int i = 0; i < length; i++) {
        while(s.size() > 0 && s.top() > data[i]) {
            s.pop();
        }
        
        s.push(data[i]);
    }
    
    vector<int> ans(s.size(), 0);
    int j = s.size() - 1;
    
    while(!s.empty()) {
        ans[j] = s.top();
        s.pop();
        j--;
    }
    
    return ans;
}

vector<int> decreasingStack(vector<int> data, int length) {
    stack<int> s;
    
    for(int i = 0; i < length; i++) {
        while(s.size() > 0 && s.top() < data[i]) {
            s.pop();
        }
        
        s.push(data[i]);
    }
    
    vector<int> ans(s.size(), 0);
    int j = s.size() - 1;
    
    while(!s.empty()) {
        ans[j] = s.top();
        s.pop();
        j--;
    }
    
    return ans;
}

int main() 
{
    vector<int> data = { 1, 4, 5, 3, 12, 10, 25, 6000 };
 
    data = increasingStack(data, data.size());
    data = decreasingStack(data, data.size());
    
    for(int i : data) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
