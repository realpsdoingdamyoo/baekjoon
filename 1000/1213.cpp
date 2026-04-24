#include <iostream>
#include <vector>

using namespace std;

const int ALPHA_NUM = 26;

string palindrom(vector<int> freq){
    int oddIndex = -1;
    string result = "";
    for(int i=0; i<ALPHA_NUM; i++){
        if(freq[i] % 2 != 0){
            if(oddIndex != -1){
                return "I'm Sorry Hansoo";
            }
            oddIndex = i;
        }
        for(int j=0; j<freq[i]/2; j++){
            result += i + 'A';
        }
    }

    if(oddIndex != -1){
        result += oddIndex + 'A';
    }
    for(int i=ALPHA_NUM-1; i>=0; i--){
        for(int j=0; j<freq[i]/2; j++){
            result += i + 'A';
        }
    }
    
    return result;
}

int main(){
    vector<int> freq(26, 0);
    string input;
    cin >> input;
    for(int i=0; i<input.size(); i++){
        freq[input[i]-'A']++;
    }
    cout << palindrom(freq);
    return 0;
}
