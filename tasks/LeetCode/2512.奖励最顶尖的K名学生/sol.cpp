#include "debug.h"
#include <string>

int main() {
    string s;
    char cs[100];
    
    // getline(cin, s);
    cin.getline(cs, 100);
    cout << strlen(cs) << endl;
    return 0;
}
