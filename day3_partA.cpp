#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;


int main(){
    string line;
    int ans = 0;

    while (getline(cin, line)) {
        int maxIndex = 0;
        int maxValue = 0;

        int temp = 0;

        for(int i=0;i<line.size();i++){
            if(line[i] > maxValue){
                maxValue = line[i];
                maxIndex = i;
            }
        }

        if(maxIndex != line.size() - 1){
            int maxValueAfterMaxIndex = 0;
            for(int j = maxIndex + 1; j < line.size(); j++){
                if(line[j] > maxValueAfterMaxIndex){
                    maxValueAfterMaxIndex = line[j];
                }
            }
            temp = (maxValue - '0') * 10 + (maxValueAfterMaxIndex - '0');
            cout << "if:" << temp << endl;
            ans += temp;
        }
        else{
            int maxValueBeforeMaxIndex = 0;
            for(int j = 0; j < maxIndex; j++){
                if(line[j] > maxValueBeforeMaxIndex){
                    maxValueBeforeMaxIndex = line[j];
                }
            }
            temp = (maxValueBeforeMaxIndex - '0') * 10 + (maxValue - '0');
            cout << "else:" << temp << endl;
            ans += temp;
        }
    }

    cout << ans << endl;

    return 0;
}