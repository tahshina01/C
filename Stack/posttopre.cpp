#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const std::string& str) {
    std::queue<char> charQueue;
    std::string reversedStr;

    // Enqueue each character from the string into the queue
    for (char c : str) {
        charQueue.push(c);
    }

    // Dequeue each character from the queue and build the reversed string
    while (!charQueue.empty()) {
        reversedStr += charQueue.front();
        charQueue.pop();
    }

    // Compare the original string with the reversed string
    return (str == reversedStr);
}
bool palindrome(string s){
    queue<char> q;
    for(char c:s){
        q.push(c);
    }
    string w;
    while(!q.empty()){
        w=w+q.front();
        q.pop();
    }
    return (s==w);
}

int main() {
    string pre_exp = "abcbc";
    cout<<isPalindrome(pre_exp)<<endl;
    return 0;
}