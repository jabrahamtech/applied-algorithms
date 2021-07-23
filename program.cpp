#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){

     /* 
     Take in the first four lines of code, discarding the initial lines.
     

     
     Creates vector with vectors where the index is matched to the person as the zero index is n.
    
      */
    string line;
    int person = 1;
    while(getline(cin, line)){
        if (line[0] == 'n'){
            line.erase(0,3);
            int _n = stoi(line);
            int people[2 * _n][_n];



        if(line[1] = ':'){
            line.erase(0,2);
            for(int i; i < line.length(); i++){
                if (i%2-1 == 0){
                    
                }
            }
        }
        
        }
    }



    return 0;
}