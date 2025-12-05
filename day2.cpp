#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

bool palindromeType(ll num,int noParts){
    // len = 2; for partA
    string str = to_string(num);
    if(str.size()%noParts) return 0;

    int len = str.size()/noParts;

    vector<string>parts;
    for(ll i=0; i<str.size(); i+=len){
        parts.push_back(str.substr(i,len));
    }

    bool allSame = true;
    for(ll i=1; i<parts.size(); i++){
        if(parts[i] != parts[0]){
            allSame = false;
            break;
        }
    }

    if(allSame) {
        for(string s : parts){
            cout << s << " ";
        }
        cout << endl;
        return true;
    }
    else return false;
}

ll allNumbersInRange(ll low, ll high){
    ll sum = 0;
    for(ll i=low; i<=high; i++){
        int digits = to_string(i).size();
        for(int j=2;j<=digits;j++){
            int temp = palindromeType(i, j);
            if(temp){
                sum += i;
                break;
            }
        }
    }
    return sum;
}

int main() {
    string input;
    cin >> input;
    
    ll ans = 0;

    ll low=0,high=0;
    bool nowLow = true;
    for(char c : input){
        if(c == ','){
            ans += allNumbersInRange(low, high);
            low = 0;
            high = 0;
            nowLow = true;
            continue;
        }
        if(nowLow){
            if(c == '-') nowLow = false;
            else low = low * 10 + (c - '0');
        }
        else{
            high = high * 10 + (c - '0');
        }
    }
    
    ans += allNumbersInRange(low, high);

    cout << ans << endl;
    return 0;
}