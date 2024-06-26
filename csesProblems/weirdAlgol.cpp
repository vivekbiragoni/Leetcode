#include <iostream>
#include <vector>
using namespace std;

vector<long long> weirdo(long long n) {
    vector<long long> result;
    result.push_back(n);
    while (n != 1) {
        if (n % 2 == 1) {
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
        result.push_back(n);
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    vector<long long> result = weirdo(n);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
