#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;

int main(){
    string x, y, w; 
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        ss >> x >> y >> w;
        cout << x << ' ' << y << ' ' << w << endl;
    }
}
