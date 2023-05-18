#include "DSString.h"

// default constructor
DSString::DSString() {
    str = NULL;
}
// constructor
DSString::DSString(const char* s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}
//  copy constructor
DSString::DSString(const DSString& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}
// destructor
DSString::~DSString() {
    delete[]str;
    str = NULL;
}
// assignment operator
DSString& DSString::operator= (const char* s) {
    delete[] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    return *this;
}
// assignment operator
DSString& DSString::operator= (const DSString& s) {
    delete[] str;
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
    return *this;
}
// comparison operator
bool DSString::operator< (const DSString& s) const{
    return strcmp(str, s.str) < 0;
}
// comparison operator
bool DSString::operator< (const char* s) const{
    return strcmp(str, s) < 0;
}
// comparison operator
bool DSString::operator> (const DSString& s) const{
    return strcmp(str, s.str) > 0;
}
// comparison operator
bool DSString::operator> (const char* s) const{
    return strcmp(str, s) > 0;
}
// comparison operator
bool DSString::operator== (const char* s) const {
    return strcmp(str, s) == 0;
}
// comparison operator
bool DSString::operator== (const DSString& s) const{
    return strcmp(str, s.str) == 0;
}
DSString DSString::operator+ (const DSString& s) {
    DSString temp;
    temp.str = new char[strlen(str) + strlen(s.str) + 1]; // allocates memory for the concatenated 
    strcpy(temp.str, str); // copies the contents of the first string (str) into temp.
    strcat(temp.str, s.str); //concatenates the second string (s.str) onto temp.
    return temp;
}
//returns a reference to the character at the specified index in the string. If the index is out of bounds, the operator returns the first character of the string
char& DSString::operator[] (const int i) {
    // return first char if index is out of bounds
    if (i > strlen(str))
        return str[0]; //returns the first character of the string if the index is out of bounds.
    return str[i]; //returns the character at the specified index in the string
}
int DSString::getLength() {
    return strlen(str);
}
DSString DSString::substring(int start, int numChars) {
    DSString temp;
    // return object invoker if index is out of bounds
    if (start > strlen(str) + 1)
        return *this;

    temp.str = new char[numChars + 1];

    for (int i = 0; i < numChars; i++)
        temp.str[i] = str[start + i];

    temp.str[numChars] = '\0';
    return temp;
}
char* DSString::c_str() {
    char* s = str;
    return s;
}
std::ostream& operator<< (std::ostream& os, const DSString& s) {
    os << s.str;
    return os;
}
