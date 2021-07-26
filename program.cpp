#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> string_to_vector(string str){
    vector<int> split_str;
    int j = 0;
    for (int i = 0; i < str.size(); i++) {
        //cout << str[i] << endl;
        //cout << "test" <<endl;
      if (str[i] == ' ' && j == 0){
          j = i;
      }

      if (str[i] == ' ' && j != i) {
          //cout << i << endl;
          //cout << str.substr(j,i) << endl;
          int n = stoi(str.substr(j,i));
          split_str.push_back(n);
          // cout << arr[k] << endl;
          j = i;
      }
      if(i == str.size() - 1){
        int n = stoi(str.substr(j));
        split_str.push_back(n);
        //cout << arr[k] << endl;
      }
    }
    return split_str;
}


void print_vector(const std::vector<int> numbers){
    for(int x = 0 ; x < numbers.size() ; x++){
        if(x == numbers.size() - 1){
            cout << numbers[x] << endl;
        }else{
            cout << numbers[x] << ' ';
        }
    }
}

int main(){

     /* 
     Take in the first four lines of code, discarding the initial lines.
     

     
     Get n
    
      */
     
    string line;
    int person = 1;
    int _n;
    vector<vector<int> > men_list;
    vector<vector<int> > women_list;
    while(getline(cin, line)){
        if (line[0] == 'n'){
            line.erase(0,3); 
            //cout << "test" << endl;
            _n = stoi(line);
            break;  
        }
    }


    /*

    Split line into array and then add array to array of arrays.

    */   
    vector<int> spl_str;
    while(getline(cin, line)){
        if(line[0] != '#' && line[0] != 'n'){
            int count = 1;
            if (count % 2 ==0){
                //cout << line << endl;
                spl_str = string_to_vector(line);
                print_vector(spl_str);
                count++;
            }
            else{
                spl_str = string_to_vector(line);
                print_vector(spl_str);
                count++;
            }
        }
    }

    vector < vector<int> > S;
    vector<int> empty_matching {0, 0};
    for(int i = 1; i < _n; i++){
        S.push_back(empty_matching);
        print_vector(empty_matching);
    }

    

    return 0;
}





