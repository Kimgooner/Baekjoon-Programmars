#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    else return p1.second > p2.second;
}

bool cmp2(pair<string,int> p1, pair<string,int> p2){
    if(p1.second == p2.second) return p1.first > p2.first;
    else return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> genres_total;
    map<string, vector<pair<int, int>>> genres_items;
    vector<int> answer;
    
    for(int i = 0; i < genres.size(); i++){
        genres_total[genres[i]] += plays[i];
        genres_items[genres[i]].emplace_back(i, plays[i]);
    }
    
    vector<pair<string, int>> sorted_total(genres_total.begin(), genres_total.end());
    sort(sorted_total.begin(), sorted_total.end(), cmp2);
    
    for(pair<string,int> p : sorted_total){
        string genre = p.first;
        vector<pair<int, int>> sorted_items = genres_items[genre];
        sort(sorted_items.begin(), sorted_items.end(), cmp);
        
        if(sorted_items.size() == 1){
            answer.push_back(sorted_items[0].first);
        }
        else{
            answer.push_back(sorted_items[0].first);
            answer.push_back(sorted_items[1].first);
        }
    }
    return answer;
}