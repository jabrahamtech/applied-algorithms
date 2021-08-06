#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
bool preference(const std::vector<int> list, int m, int m_dash);
void stable_marriage(int n, vector< vector<int> > prefer_list);
vector<int> string_to_vector(string str);
int new_man(vector <int> married, int w);
int check_w(int w, vector<int> married);

int check_w(int w, vector<int> married){
    for(int i=0; i < married.size(); i++){
        if (married[i] == w){
            return i;
        }
    }
    return -1;
}

bool preference(const std::vector<int> w_list, int m, int m_dash){
    for (int j=0; j < w_list.size(); j++){
        if(w_list[j] == m){
            return true;
        }
        else if(w_list[j] == m_dash){
            return false;
        }
    }
    return false; 
}

int new_man(vector <int> married, int w){
    int m_dash;
    for(int i = 0; i < married.size(); i++){
        if(married[i] == w){
            m_dash = i*2+1;
            break;
        } 
    }
    return m_dash;
}

vector<int> string_to_vector(string str){
    vector<int> split_str;
    int j = 0;
    if(!isdigit(str[str.size()-1])){
        str.erase(str.end());
    }
    
    for (int i = 0; i < str.size(); i++) {
        //cout << str[i] << endl;
        //cout << "test" <<endl;

      if (str[i] == ' ' && j == 0){
          j = i;
      }

      else if (str[i] == ' ' && j != i) {
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
    return split_str;
}

void stable_marriage(int n, vector< vector<int> > prefer_list){
    vector <int> married;
    vector <int> women_list;
    vector <int> men_free;
    for(int i = 0; i<n; i++){
        married.push_back(-1);
        men_free.push_back((i*2)+1);
        //cout<<i<<endl;
    }


    int w;
    int count = 0;
    while(men_free.size()!=0){
        //cout << men_free.size() << endl;
        w = prefer_list[men_free[0]][count];
        if(check_w(w, married) == -1){
            //women_list(w/2)-1 = 0;
            married[(men_free[0]-1)/2] = w;
            men_free.erase(men_free.begin());
            count = 0;
        }
        else{
            int m_dash = new_man(married, w);
           
            if(preference(prefer_list[w], men_free[0], m_dash)){
                married[(men_free[0]-1)/2] = w;
                married[(m_dash-1)/2] = -1;
                men_free.push_back(m_dash);
                men_free.erase(men_free.begin());
                count = 0;
            }
            else{
                count++;
            }
        }
    }
    for(int a = 0; a < married.size(); a++){
        cout << (a*2)+1 << ' ' << married[a] << endl;
    }

}

int main(){
    string line;
    int _n;
    vector<int> empty;
    vector<vector <int> > prefer_list;
    prefer_list.push_back(empty);
    while(getline(cin, line)){
        if (line[0] == 'n'){
            line.erase(0,3); 
            _n = stoi(line);
            break;  
        }
    }
    
    vector<int> spl_str;
    int count = 1;
    while(getline(cin, line)){
        if(line[0] != '#' && line[0] != 'n'){
            spl_str = string_to_vector(line);
            prefer_list.push_back(spl_str);
        }
    }
    stable_marriage(_n, prefer_list);
    
    return 0;
}