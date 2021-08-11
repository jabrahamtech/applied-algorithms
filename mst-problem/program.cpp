#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

void kruskal(vector< vector <int> > G, int _n);
bool sortcol( const vector<int>& v1, const vector<int>& v2 );
int find_p(int v);
void union_set(int u, int v);
void sets(int v);
vector<int> T, R;

int main(){
    string line;
    int _n;
    vector<int> spl_str;
    vector<vector<int> > G;
    while(getline(cin, line)){
        if (line[0] == 'n'){
            line.erase(0,3); 
            _n = stoi(line);
        }
        else if(line[0] != '#' && line[0] != 'n'){
            string x, y, w;
            stringstream ss(line);
            ss >> x >> y >> w;
            if (stoi(x) > stoi(y)){
                continue;
            }
            //cout << x << ' ' << y << ' ' << w << endl;
            vector <int> temp; temp.push_back(stoi(x)); temp.push_back(stoi(y)); temp.push_back(stoi(w));
            G.push_back(temp);
        }

    }
    sort(G.begin(), G.end(), sortcol);
    kruskal(G, _n);
    return 0;
}

bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
    bool v = v1[2] < v2[2];
    //cout << v1[2] << ' ' << v2[2] << ' ' << v << endl;
    return v;
}

int find_p(int v){
    //cout << v << endl;
    if (v == T[v]){
        return v;
    }
    return T[v] = find_p(T[v]);
}

void union_set(int u, int v){
    // cout << u << endl;
    if (u != v){
        swap(u,v);
        // cout << u << endl;
    }
    T[v] = u;
    if (R[u] == R[v]){
        // cout << R[u] << endl;
        R[u]++;
    }
}

void kruskal(vector< vector <int> > G, int _n){
    
    // cout << G.size() << endl;
    int e = 0;
    //cout << e << endl;
    T.resize(_n+1);
    R.resize(_n+1);
    for (int i = 1; i < _n+1; i++){
        T[i] = i;
        R[i] = 0;
        //cout << T[i] << endl;
    }
    //cout << G.size() << endl;
    int count = 0;
    int i = 0;
    while(count != _n - 1){
        //cout << G[i][0] << endl;
        int u = find_p(G[i][0]);
        //cout << u << endl;
        int v = find_p(G[i][1]);
        //cout << v << endl;
        if(u != v){
            e += G[i][2];
            //cout << e << endl;
            union_set(u, v);
            count += 1;
        }
        //cout << i << endl;
        i += 1;
    }
    cout << e << endl;  
}