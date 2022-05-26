#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int Find_Set(vector<set<int>> sets, int a){
    for(int i=0; i<sets.size(); i++) {
        if(sets.at(i).find(a) != sets.at(i).end()) {
            return i;
        }
    }
    return -1;
}

void Union(vector<set<int>> sets, int u, int v){
    sets.at(Find_Set(sets, v)).erase(v);
    sets.at(Find_Set(sets, u)).insert(v);
}

int Kruskal(vector<vector<int>> G){
    vector<set<int>> sets;
    for(vector<int> tmp : G) {
        set<int> s;
        s.insert(tmp.at(1));
        sets.push_back(s);
    }

    sort(G.begin(), G.end());

    int ans = 0;
    for(vector<int> tmp : G) {
        int w = tmp.at(0);
        int u = tmp.at(1);
        int v = tmp.at(2);

        if(Find_Set(sets, u) != Find_Set(sets, v)) {
            ans += w;
            cout<<"w->"<<w<<" u->"<<u<<"" <<endl;
            Union(sets, u, v);
        }
    }

    cout<<ans;
}

int main(){
    vector<vector<int>> G;
    G.push_back({1 , 7, 6});
    G.push_back({2 , 8, 2});
    G.push_back({2 , 6, 5});
    G.push_back({4 , 0, 1});
    G.push_back({4 , 2, 5});
    G.push_back({6 , 8, 6});
    G.push_back({7 , 2, 3});
    G.push_back({7 , 7, 8});
    G.push_back({8 , 0, 7});
    G.push_back({8 , 1, 2});
    G.push_back({9 , 3, 4});
    G.push_back({10, 5, 4});
    G.push_back({11, 1, 7});
    G.push_back({14, 3, 5});

    Kruskal(G);
    return 0;
}