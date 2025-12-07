#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

ll MAX = 1;

int main(){
    string line;
    freopen("day5.txt", "r", stdin);
    bool partA = true;
    vector<vector<ll>>ranges;
    ll ans = 0;
    while(getline(cin,line)){
        if(line == ""){
            partA = false;
            continue;
        }
        if(partA){
            ll low = stoll(line.substr(0,line.find('-')));
            ll high = stoll(line.substr(line.find('-')+1));
            MAX = MAX > high ? MAX : high;
            ranges.push_back({low,high});
        }
        else{
            bool isContained = false;
            ll num = stoll(line);
            for(auto &r:ranges){
                if(num >= r[0] && num <= r[1]){
                    isContained = true;
                    break;
                }
            }
            if(isContained){
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}