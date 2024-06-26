#include <bits/stdc++.h>
using namespace std;
vector<int> slideMedian(vector<int> & arr, int n; int k){
    int left = 0; 
    int 
}

int main() {
    int n ;
    cin >> n;
    int k;
    cin >> k;

    vector<int> arr(n);
    for(size_t i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    vector<int> result = slideMedian(arr, n, k);

    for(size_t i = 0; i < n-k+1; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}