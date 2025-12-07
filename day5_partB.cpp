#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;
unordered_map<ll,int> mp;

ll MAX = 1;

void mergeOverlappingRanges(vector<vector<ll>>& ranges) {
    if (ranges.empty()) return;

    sort(ranges.begin(), ranges.end());

    vector<vector<ll>> merged;
    merged.push_back(ranges[0]);

    for (size_t i = 1; i < ranges.size(); ++i) {
        if (ranges[i][0] <= merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], ranges[i][1]);
        } else {
            merged.push_back(ranges[i]);
        }
    }

    ranges = merged;
}

int main(){
    string line;
    freopen("day5.txt", "r", stdin);
    bool partA = true;
    vector<vector<ll>>ranges;
    ll ans = 0;
    while(getline(cin,line)){
        if(line == ""){
            partA = false;
            break;
        }
        if(partA){
            ll low = stoll(line.substr(0,line.find('-')));
            ll high = stoll(line.substr(line.find('-')+1));
            MAX = MAX > high ? MAX : high;
            ranges.push_back({low,high});
        }
    }
    mergeOverlappingRanges(ranges);
    for(auto &r:ranges){
        ans += (r[1]-r[0]+1);
    }
    cout << ans << endl;
    return 0;
}