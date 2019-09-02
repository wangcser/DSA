
vector<int> ans;

void sumOfKNumber(int sum, int n) {
    if(n == 0 || sum <= 0) return;

    if(sum == n) {
        // cout the result
        print(ans);
    }

    ans.push_back(n);
    sumOfKNumber(sum-n, n-1); // have n
    ans.pop_back();
    sumOfKNumber(sum, n-1); // have no n
}