/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 1, 2010, 11:04 AM
 * Modified on January 18, 2016
 * MOdified October 2021
 *
 * Please note: the definition of capacity in c++ string
 * and ours is different. Ours is always one more than that of c++ string
 * as ours includes the terminating null character and theirs is the number
 * of characters can be stored.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

// comment out to use string class, now use Mystring class
#define string Mystring

using namespace std;

/*
 * Check function from the previous lab.
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

/*
 * Check-obj function is similar to check, except we will check the object
 * instead of the copy of the object built by the copy constructor.
 */
void check_obj (const string& s, const string name)
{
    cout << "checking " << name << " the object" << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}



int main()
{
    const char *s1 = {"test1"};

    string s2("test2");

    if(s1 != s2)
        cout << "They aren't equal!" << endl;
    else
        cout << "They are equal!" << endl;
}