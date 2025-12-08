#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    vector<vector<long long>>column;
    string line;
    long long flag = 4;
    
    

    while(flag && getline(cin, line)){
        long long num = -1;
        vector<long long> temp;
        for(long long i=0;i<line.size();i++){
            if(line[i] == ' ') {
                if(num != -1) temp.push_back(num);
                num = -1;
            }
            else {
                if(num == -1) num = 0;
                num = num * 10 + (line[i] - '0');
            }
        }
        if(num != -1) temp.push_back(num);
        flag--;
        column.push_back(temp);
    }

    // for(vector<long long> v : column){
    //     for(long long n : v){
    //         cout << n << " ";
    //     }
    //     cout << endl;
    // }

    string operator_str;
    vector<char>op;
    getline(cin, operator_str);
    for(char c : operator_str){
        if(c == '+' || c == '*') op.push_back(c);
    }
    
    // for(vector<long long> v : column){
    //     for(long long n : v){
    //         cout << n << " ";
    //     }
    //     cout << endl;
    // }
    long long result = 0; 
    for(long long i = 0; i < op.size(); i++){
        long long temp = 0;
        if(op[i] == '+'){
            temp += (column[0][i] + column[1][i] + column[2][i] + column[3][i]);
        }
        else{
            temp += (column[0][i] * column[1][i] * column[2][i] * column[3][i]);
        }
        // cout << temp << endl;
        result += temp;
    }

    cout << result << endl;
    return 0;
}

// 20248722228
// 14999762972