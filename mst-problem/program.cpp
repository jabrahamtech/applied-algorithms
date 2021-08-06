#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
vector<int> string_to_vector(string str);
void print_vector(vector<int> str);

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
            //cout<<line[0]<<endl;
            spl_str = string_to_vector(line);
            G.push_back(spl_str);  
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


vector<int> string_to_vector(string str){
    //cout << str << endl;
    vector<int> split_str;
    int j = 0;
    if(!isdigit(str[str.size()-1])){
        str.erase(str.end());
    }
    for (int i = 0; i < str.size(); i++) {
        //cout << str[i] << endl;
        //cout << "test" <<endl;

      if (str[i] == ' ' && j != i) {
          //cout << i << endl;
          //cout << str.substr(j,i) << endl;
          int n = stoi(str.substr(j,i));
          split_str.push_back(n);
          // cout << arr[k] << endl;
          j = i;
      }
      else if(i == str.size() - 1){
        int n = stoi(str.substr(j));
        split_str.push_back(n);
        //cout << arr[k] << endl;
      }
    }
    print_vector(split_str);
    return split_str;
}

void print_vector(vector<int> str){
    cout<< str[0] << ' ' << str[1] << ' ' << str[2]<< endl;
}