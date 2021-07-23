#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main(){

     /* 
     Take in the first four lines of code, discarding the initial lines.
     

     
     Creates vector with vectors where the index is matched to the person as the zero index is n.
    
      */
    string line;
    vector< vector<int> > people;
    while(getline(cin, line)){
        if (line[0] == 'n'){
            line.erase(0,3);
            int _n = stoi(line);

        if(line[1] = ':'){
            
        }
        
        }
    }



    return 0;
}