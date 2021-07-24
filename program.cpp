#include <iostream>
#include <string>

using namespace std;

int* string_to_array(int arr[], string str){
    

}


int main(){

     /* 
     Take in the first four lines of code, discarding the initial lines.
     

     
     Get n
    
      */
     
    string line;
    int person = 1;
    int _n;
    while(getline(cin, line)){
        if (line[0] == 'n'){
            line.erase(0,3);
            _n = stoi(line);  
            break;  
        }
    }


    /*

    Split line into array and then add array to array of arrays.

    */   

    int people[2*_n][_n]; //created outside of IF statement
    while(getline(cin, line)){
        if(line[1] == ':'){
            line.erase(0,2);
            int pref_list[_n];
            string_to_array(pref_list, line);

        }
    }

    return 0;
}