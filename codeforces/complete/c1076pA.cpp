//
//  c1076pA.cpp
//  codeforces
//
//  Created by Victor Ignacio Jr. Sawal on 2018-11-22.
//  Copyright © 2018 Victor Ignacio Jr. Sawal. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    string s, lex="";
    cin >> s;
    
    bool removed = false;
    for(int i=0; i < n-1; i++) {
        if(!removed && (int(s[i]) > int(s[i+1]))) {
            removed = true;
        } else {
            lex += s[i];
        }
    }
    if(removed) {
        lex += s[n-1];
    }
    cout << lex;
}
