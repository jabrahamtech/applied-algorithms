#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
void print_vector(const std::vector<int> numbers);
bool preference(const std::vector<int> list, int m, int m_dash);

void stable_marriage(int n, vector< vector<int> > prefer_list){
    vector <int> married;
    vector <int> women_list;
    vector <int> men_free;
    for(int i = 1; i<n*2+1; i++){
        if (i%2==0){
            women_list.push_back(-1);
            married.push_back(-1);
            //cout << i << endl;
        }
        else{
            men_free.push_back(i);
            //cout << i << endl;
        }
    }
    int w;
    int count = 0;
    while(men_free.size()!=0){
        //cout << men_free.size() << endl;
        w = prefer_list[men_free[0]][count];
        //cout<<(men_free[0]-1)/2<<endl;
        if (women_list[(w/2)-1]==-1){
            women_list[(w/2)-1] = 0;
            married[(men_free[0]-1)/2]= w;
            men_free.erase(men_free.begin());
            count = 0;
        }else{
            //cout<<(men_free[0]-1)/2<<endl;
            int m_dash;
            for(int i = 0; i < married.size(); i++){
                if(married[i] == w){
                    m_dash = i*2+1;
                    //cout << m_dash << endl;
                    break;
                } 
            }
            //cout<<m_dash<<endl;
            bool pref = preference(prefer_list[w], men_free[0], m_dash);
            if(pref){
                married[(men_free[0]-1)/2]= w;
                //cout << "check" << endl;
                married[(m_dash-1)/2]= -1;
                men_free.push_back(m_dash);
                men_free.erase(men_free.begin());
                //cout << count << endl;
                count=0;
            }else{
                count++;
            }
            //men_free.erase(men_free.begin());
        }
        //print_vector(married);
    }
    // for (int i =1; i<n*2; i++){
    //     if(i%2!=0){
    //     //cout<< i<< endl;
    //         memset(men_free, true, i);
    //     }
    // }

    //int manfree = n;

/*
    while(manfree != 0){
        //cout<<manfree<<endl;
        int man;
        //cout << men_free[man] << endl;
        //cout<< man<< endl;
        for(int i = 0; i<n && men_free[man] == true; i++){
            //cout<< i<< endl;
            //cout<<man<<endl;
            int w = prefer_list[man][i];
            //cout << w << endl;
            // cout << i << endl;
         
            if(women_partner[w] == -1){
                //cout << man << endl;
                women_partner[w] = man;
                //cout << women_partner[w] <<endl;
                men_free[man] = false;   
                manfree-=1;         
            }
            else{
                //cout<<man<<endl;
                int man_dash = women_partner[w];
                bool m_over_m1;
                for (int l =0; l<n; l++){
                    //cout<<man_dash<<endl;
                    if (prefer_list[w][l] == man_dash){
                        m_over_m1 = false;
                        //cout<<man_dash<<endl;
                        break;
                    }
                    else if(prefer_list[w][l] == man){
                        m_over_m1 = true;
                        break;
                    }
                    //cout<<m_over_m1<<endl;                
                }
            if(m_over_m1 == true){
                women_partner[w] = man;
                //cout<<man<<endl;
                men_free[man] = false;
                men_free[man_dash] = true;
                }
        
            }
            // int m = 2;
            // for (int i = 1; i < n+1; i++){
            //     cout << " " << m << "\t" << women_partner[i] << endl;
            //     m+=2;
            //}
        }
    }
*/
    for(int a = 0; a < married.size(); a++){
        cout << (a*2)+1 << ' ' << married[a] << endl;
    }
    // int print_array[n];
    // int man_num;
    // for(int i =1; i < n+1; i++){
    //     //man_num = women_partner[i];
    //     //cout << i << endl;
    //     //cout << women_partner[i] << endl;
    //     //print_array[man_num] = i*2;
    // }
    // int m = 1;
    // for(int i = 1; i<n+1; i++){
    //     cout << m << ' ' << print_array[m] << endl;
    //     m+=2;
    // }
       
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



int main(){

     /* 
     Take in the first four lines of code, discarding the initial lines.
     
    
     
     Get n
    
      */
     
    string line;
    int _n;
    vector<int> empty;
    vector<vector <int> > prefer_list;
    prefer_list.push_back(empty);
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
    int count = 1;
    while(getline(cin, line)){
        if(line[0] != '#' && line[0] != 'n'){
            spl_str = string_to_vector(line);
            //print_vector(spl_str);
            prefer_list.push_back(spl_str);
            //cout << line << endl;
        }
        // //cout<<count<<endl;
        // if(line[0] != '#' && line[0] != 'n'){
        //     if (count % 2 ==0){
        //         //cout << line << endl;
        //         spl_str = string_to_vector(line);
        //         women_list.push_back(spl_str);
        //         count++;
        //     }
        //     else{
        //         //cout<<line<<endl;
        //         spl_str = string_to_vector(line);
        //         men_list.push_back(empty);
        //         men_list.push_back(spl_str);
        //         count++;
        //     }
        // }
    }

    //vector < vector<int> > S;

    // for(int i = 1; i <= _n; i++){
    //     S.push_back(empty_matching);
    // }

    
    stable_marriage(_n, prefer_list);
    
    return 0;
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