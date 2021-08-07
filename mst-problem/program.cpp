#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>

using namespace std;

//int Prim(G, c, V);

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
            
        }
    }

    return 0;
}

// int Prim(G, c, _n){
//     int a[_n];
//     for(int i; i < _n; i++){
//         a[i] = INFINITY;
//     }
//     priority_queue<int> Q;
//     for(int i; i < _n; i++){
//         Q.push(i);
//     }
//     vector<int> S;
//     while(Q.size() != 0){
//         u = Q.pop();
//         S.push_back(u);
//     }
// }
