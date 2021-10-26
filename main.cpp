/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 1, 2010, 11:04 AM
 * Modified on January 18, 2016
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

//#define string Mystring

using namespace std;

/*
 * Check function from the previous lab
 */
void check (const Mystring s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

int main()
{
    Mystring s1("Hi there!");
    check(s1, "s1");

    s1.push_back('!');
    cout << s1.capacity();

    
}
