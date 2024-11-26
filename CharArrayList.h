/*
 *  CharArrayList.h
 *  Name: Leo Kim
 *  Date: 1/27/2022
 *
 *  Purpose: Class declaration for the CharArrayList class. A CharArrayList is
 *           an array list made up of char variables that can be altered and 
 *           accessed by a variety of functions.
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H

#include <string>

class CharArrayList {
public:
    CharArrayList();    // Default Constructor
    CharArrayList(char c);  // Constructor with initial char variable
    CharArrayList(char arr[], int size);    // Constructor with intial arr 
    CharArrayList(const CharArrayList &other);  // Copy Constructor
    ~CharArrayList();   // Destructor
    CharArrayList &operator=(const CharArrayList &other);   // deepcopy
    // assignent operator

    // Other Member functions
    bool isEmpty() const;
    void clear();
    int size() const;
    char first() const;
    char last() const;
    char elementAt(int index) const;
    std::string toString() const;
    std::string toReverseString() const;
    void pushAtBack(char c);
    void pushAtFront(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);
    void popFromFront();
    void popFromBack();
    void removeAt(int index);
    void replaceAt(char c, int index);
    void concatenate(CharArrayList *other);
    void shrink();

private:
    int numItems;
    int capacity;
    char *data;

    // helper functions
    void expand();    
};

#endif
