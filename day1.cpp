#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int partA(vector<string>&input){
    int ans = 0;
    int curr = 50;
    for(string line : input){
        int num = stoi(line.substr(1));
        if(line[0] == 'R'){
            curr = (curr + num)%100;
        }
        else{
            curr = curr - num;
            while(curr < 0){
                curr += 100;
            }
        }
        if(!curr) ans++;
    }

    return ans;
}

int partB(vector<string>&input){
    int ans = 0;
    int curr = 50;
    for(string line : input){
        int num = stoi(line.substr(1));
        if(line[0] == 'R'){
            curr = (curr + num);

            while(curr > 100){
                curr = curr - 100;
                ans++;
            }

        }
        else{
            bool alreadyZero = false;
            if(!curr) alreadyZero = true;

            curr = curr - num;
            while(curr < 0){
                curr += 100;
                if(!alreadyZero)ans++;
                alreadyZero = false;
            }
        }
        if(!curr) ans++;
        if(curr == 100){
            curr = 0;
            ans++;
        }
    }

    return ans;
}
int main(){
    ifstream fin("day1.txt");

    string line;
    vector<string>input;

    while(getline(fin,line)){
        input.push_back(line);
    }
    cout << partA(input) << endl;
    return 0;

}