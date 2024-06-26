#include <bits/stdc++.h>
using namespace std;


vector<int> nearest_smaller_values(vector<int> &arr){
    stack<int> s;
    vector<int> result(arr.size(), 0);

    for(size_t i = 0; i < arr.size(); i++){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }

        if(!s.empty()){
            result[i] = s.top()+1;
        } else{
            result[i] = 0;
        }

        s.push(i);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nearest_smaller_values(arr);
    
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
 
    return 0;
}