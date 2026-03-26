#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {    
    unordered_set<string> hashMap;    
    
    for(string phone : phone_book){
        hashMap.insert(phone);
    }
    
    for(string phone : phone_book){
        int size = phone.size();
        for(int i = 1; i < size; i++){
            string current = phone.substr(0,i);
            if(hashMap.find(current) != hashMap.end()) return false;  
        }
    }
    return true;
}