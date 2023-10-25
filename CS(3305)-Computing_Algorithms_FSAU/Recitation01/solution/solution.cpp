#include <bits/stdc++.h>

using namespace std;

bool isPalindromeHelper(const string &str, int left, int right) {
    if (left >= right)
        return true;
    if (str[left] != str[right])
        return false;
    return isPalindromeHelper(str, left + 1, right - 1);
}

bool isPalindrome(const string &str) {
    return isPalindromeHelper(str, 0, str.size() - 1);
}

template<typename T>
T ArraySum(vector<T> &arr, int length) {
    if (length == 0)
        return 0;
    return arr[length - 1] + ArraySum(arr, length - 1);
}

template<typename T>
int binarySearch(vector<T> &arr, T &val, int low, int high) {
    if (low > high)
        return -1;

    int mid = low + ((high - low) / 2);
    if (arr[mid] == val)
        return mid;
    if (arr[mid] > val)
        return binarySearch(arr, val, low, mid - 1);
    return binarySearch(arr, val, mid + 1, high);
}

void swap(char &a, char &b) {
    char tempChar = a;
    a = b;
    b = tempChar;
}

void reverseString(string &str, int left, int right) {
    if (left >= right || right > str.length())
        return;

    swap(str[left], str[right]);
    reverseString(str, left + 1, right - 1);
}

int minCoins(vector<int>& coins, int target) {
    vector<int> dp(target + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= target; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : dp[target];
}

void hanoi(int n, const string &source, const string &auxiliary, const string &destination) {
    if (n == 1)
        cout << "Move disk " << n << " from " << source << " to " << destination << '\n';
    else {
        hanoi(n - 1, source, destination, auxiliary);
        cout << "Move disk " << n << " from " << source << " to " << destination << '\n';
        hanoi(n - 1, auxiliary, source, destination);
    }
}

int main() {
    int n;
    string source, auxiliary, destination;

    cout << "Number of disks: \n";
    cin >> n;

    cout << "Source: \n";
    cin >> source;

    cout << "Auxiliary: \n";
    cin >> auxiliary;

    cout << "Destination: \n";
    cin >> destination;

    hanoi(n, source, auxiliary, destination);

    return 0;
}
