#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
    string line;
    long long ans = 0;
    while(getline(cin,line)){
        stack<char>s;
        int removals_left = line.size() - 12;
        for(char c : line){
            if(s.empty()) s.push(c);
            else{
                while(removals_left && !s.empty() && s.top() < c){
                    s.pop();
                    removals_left--;
                }
                s.push(c);
            }
        }
        while(removals_left--){
            s.pop();
        }
        string result;
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());
        cout << result << endl;
        ans+=stoll(result);
    }
    cout << ans << endl;
    return 0;
}