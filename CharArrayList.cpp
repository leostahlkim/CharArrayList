/*
 *  CharArrayList.cpp
 *  Name: Leo Kim
 *  Date: 1/27/2022
 *
 *  Purpose: Implementation of the character array list class. A 
 *           CharArrayList is an array list made up of char variables
 *           that can be altered and accessed by a variety of functions.  
 *
 */

#include "CharArrayList.h"
#include <iostream>

/*
 * name:      CharArrayList default constructor
 * purpose:   initialize an empty CharArrayList
 * arguments: none
 * returns:   none
 * effects:   numItems to 0 (also updates capacity and data array)
 */
CharArrayList::CharArrayList() {
    // initializing all the private member variables
    numItems = 0;
    capacity = 0;
    data = nullptr;
}

/*
 * name:      CharArrayList single character constructor
 * purpose:   initialize an CharArrayList with a single character
 * arguments: a single character variable
 * returns:   none
 * effects:   numItems to 1 (also updates capacity and data array)
 */
CharArrayList::CharArrayList(char c) {
    // initializing all the private member variables
    numItems = 1;
    capacity = 1;
    
    // adding the first char to the list
    data = new char[1];
    data[0] = c;
}

/*
 * name:      CharArrayList char array constructor
 * purpose:   initialize an CharArrayList with an array of chars
 * arguments: a char array and an int var for its size
 * returns:   none
 * effects:   numItems to size (also updates capacity and data array)
 */
CharArrayList::CharArrayList(char arr[], int size) {
    // initializing the private member variables and allocating heap space for
    // the array list
    numItems = 0;
    capacity = size;
    data = new char[size];
    
    // Adding each member of the given array to the array list
    for (int i = 0; i < size; i++){
        pushAtBack(arr[i]);
    }
}

/*
 * name:      CharArrayList copy constructor
 * purpose:   copy constructor for the CharArrayList class
 * arguments: Address of another CharArrayList
 * returns:   none
 * effects:   makes a deep copy of the given CharArrayList
 */
CharArrayList::CharArrayList(const CharArrayList &other) {
    // initializing the private member variables and allocating heap space for
    // the array list
    numItems = 0;
    capacity = other.size();
    data = new char[capacity];

    // adding each member of the given CharArrayList to the newly created array 
    // list
    for (int i = 0; i < capacity; i++) {
        pushAtBack(other.elementAt(i));
    }
}

/*
 * name:      CharArrayList assignment operator definition
 * purpose:   used to make a deepcopy when assigning CharArrayLists to eachother
 * arguments: address of the other CharArrayList
 * returns:   none
 * effects:   makes a deep copy of the given CharArrayList
 */
CharArrayList &CharArrayList::operator=(const CharArrayList &other) {
    // Check to see if the assignment operator is assigning two equivalent
    // CharArrayLists
    if (this == &other) {
        return *this;
    }

    // Setting the private member variables equal to the given CharArrayList,
    // making sure to deep copy the neccesary elements
    capacity = other.size();
    numItems = 0;
    char *temp = data;
    data = new char[capacity];
    delete [] temp;
    
    // adding each member of the given CharArrayList to the newly assigned 
    // array list
    for (int i = 0; i < capacity; i++) {
        pushAtBack(other.elementAt(i));
    }
        
    return *this;
}


/*
 * name:      CharArrayList destructor
 * purpose:   free memory associated with the CharArrayList
 * arguments: none
 * returns:   none
 * effects:   frees memory allocated by CharArraylist instances
 */
CharArrayList::~CharArrayList() {
    // Deallocating the heap memory used in the CharArrayList
    delete [] data;
}

/*
 * name:      size
 * purpose:   determine the number of items in the CharArrayList
 * arguments: none
 * returns:   number of elements currently stored in the CharArrayList
 * effects:   none
 */
int CharArrayList::size() const {
    return numItems;
}

/*
 * name:      isEmpty
 * purpose:   determines if the CharArrayList is empty or not
 * arguments: none
 * returns:   true if CharArrayList contains no elements, false otherwise
 * effects:   none
 */
bool CharArrayList::isEmpty() const {
    return numItems == 0;
}

/*
 * name:      clear
 * purpose:   clears a CharArrayList
 * arguments: none
 * returns:   none
 * effects:   reverts a CharArrayList to an empty state
 */
void CharArrayList::clear() {
    // clear existing heap memory
    if (data != nullptr){
        delete [] data;
    }
    

    // reset private member variables
    data = nullptr;
    numItems = 0;
    capacity = 0;
}

/*
 * name:      first
 * purpose:   determines the first element of the CharArrayList
 * arguments: none
 * returns:   the first element of the CharArrayList or an error if the list
 *            is empty
 * effects:   none
 */
char CharArrayList::first() const {
    if (isEmpty()){
        // if the CharArrayList is empty throw an error message
        throw std::runtime_error("cannot get first of empty ArrayList");
    } else {
        return data[0];
    }
}

/*
 * name:      last
 * purpose:   determines the last element of the CharArrayList
 * arguments: none
 * returns:   the last element of the CharArrayList or an error if the list
 *            is empty
 * effects:   none
 */
char CharArrayList::last() const {
    if (isEmpty()){
        // if the CharArrayList is empty throw an error message
        throw std::runtime_error("cannot get last of empty ArrayList");
    } else {
        return data[numItems - 1];
    }
}

/*
 * name:      elementAt
 * purpose:   determines the element at a given index in the CharArrayList
 * arguments: index of element
 * returns:   the corresponding element of the CharArrayList or an error if the 
 *            list is empty
 * effects:   none
 */
char CharArrayList::elementAt(int index) const {
    if (index >= numItems or index < 0){
        // if the index is out of range of the CharArrayList, throw an error 
        // message
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + ")" );
    } else {
        return data[index];
    }
}


/*
 * name:      pushAtFront
 * purpose:   push the provided integer into the front of the CharArrayList
 * arguments: a char to add to the front of the list
 * returns:   none
 * effects:   increases num elements of CharArrayList by 1,
 *            adds element to list
 */
void CharArrayList::pushAtFront(char c) {
    // if the array list is at capacity, expand it
    if (capacity <= numItems) {
        expand();
    }
    
    // Add the given char to the start of the array list and shift every other 
    //element one place back
    char temp1 = c;
    char temp2;
    for (int i = 0; i <= numItems; i++) {
        temp2 = data[i];
        data[i] = temp1;
        temp1 = temp2;
    }
    numItems++;
}

/*
 * name:      pushAtBack
 * purpose:   push the provided integer into the back of the CharArrayList
 * arguments: a char to add to the back of the list
 * returns:   none
 * effects:   increases num elements of CharArrayList by 1,
 *            adds element to list
 */
void CharArrayList::pushAtBack(char c) {
    // if the array list is at capacity, expand it
    if (numItems >= capacity) {
        expand();
    }
    // add the given char to the end of the array list
    data[numItems] = c;
    numItems++;
}

/*
 * name:      expand
 * purpose:   increase the capacity of the CharArrayList
 * arguments: none
 * returns:   none
 * effects:   creates a larger array on heap, copies over elements,
 *            and recycles the old array
 */
void CharArrayList::expand() {
    // increase the array list capacity and allocate new space on the heap
    capacity = (capacity * 2) + 2;
    char *new_data = new char[capacity];
    
    // copy all the elements over to the newly allocated array
    for (int i = 0; i < numItems; i++){
        new_data[i] = data[i];
    }

    // deallocate the old array memory and reassign the array pointer
    delete [] data;
    data = new_data;
}

/*
 * name:      toString
 * purpose:   Express a CharArrayList in a string
 * arguments: none
 * returns:   A string representing the CharArrayList
 * effects:   none
 */
std::string CharArrayList:: toString() const {
    // string statement framework
    std::string s = "[CharArrayList of size " + std::to_string(numItems) 
                    + " <<";

    // add each element to the string
    for (int i = 0; i < numItems; i++){
        s += data[i];
    }

    s += ">>]";

    return s;
}

/*
 * name:      toReverseString
 * purpose:   Express a CharArrayList in a reverse string
 * arguments: none
 * returns:   A reverse string representing the CharArrayList
 * effects:   none
 */
std::string CharArrayList:: toReverseString() const {
    // string statement framework
    std::string s = "[CharArrayList of size " + std::to_string(numItems) 
                    + " <<";

    // add each element to the string in reverse order
    for (int i = numItems - 1; i > -1; i--){
        s += data[i];
    }

    s += ">>]";

    return s;
}

/*
 * name:      insertAt
 * purpose:   insert an element at a given index
 * arguments: element and its index
 * returns:   none
 * effects:   adds the element at the given index in the CharArrayList
 */
void CharArrayList::insertAt(char c, int index) {
    // if the index is out of range of the CharArrayList, throw an error 
    // message
    if (index > numItems or index < 0){
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + "]" );
    } 
    // if the array list is at capacity, expand it
    if (capacity <= numItems) {
        expand();
    }

    // add the given element at the given index and shift all elements behind
    // it back one space
    char temp1 = c;
    char temp2;
    for (int i = index; i <= numItems; i++) {
        temp2 = data[i];
        data[i] = temp1;
        temp1 = temp2;
    }
    numItems++;
}

/*
 * name:      insertInOrder
 * purpose:   insert an element in the CharArrayList in alphabetical order
 * arguments: element
 * returns:   none
 * effects:   adds the element in order in the CharArrayList
 */
void CharArrayList::insertInOrder(char c) {
    // add a char element in its corresponding spot in an ordered array list
    for (int i = 0; i < numItems; i++){
        if (c >= data[i]){
            insertAt(c, i);
            std::exit(0);
        }
    }
    pushAtBack(c);
}

/*
 * name:      popFromBack
 * purpose:   remove the last element of the CharArrayList
 * arguments: none
 * returns:   error message if the list is empty
 * effects:   removes the last element in the CharArrayList
 */
void CharArrayList::popFromBack() {
    // if the CharArrayList is empty throw an error message
    if (isEmpty()){
        throw std::runtime_error("cannot pop from empty ArrayList");
    }

    // remove the last element of the array list
    numItems--;
    data[numItems] = 0;
}

/*
 * name:      popFromFront
 * purpose:   remove the first element of the CharArrayList
 * arguments: none
 * returns:   error message if the list is empty
 * effects:   removes the first element in the CharArrayList
 */
void CharArrayList::popFromFront() {
    // if the CharArrayList is empty throw an error message
    if (isEmpty()){
        throw std::runtime_error("cannot pop from empty ArrayList");
    }

    // remove the first element of the array list and shift all other elements
    // back one place
    numItems--;
    char temp1 = data[numItems];
    data[numItems] = 0;
    char temp2;
    for (int i = numItems - 1; i > -1; i--) {
        temp2 = data[i];
        data[i] = temp1;
        temp1 = temp2;
    }
}

/*
 * name:      removeAt
 * purpose:   remove the element at a given index in the CharArrayList
 * arguments: the element index
 * returns:   error message if the index is out of range
 * effects:   removes given element in the CharArrayList
 */
void CharArrayList::removeAt(int index) {
    // if the index is out of range of the CharArrayList, throw an error 
    // message
    if (index >= numItems or index < 0){
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + ")" );
    }

    // remove the element at the given index and shift all elements behind
    // it one place forward
    numItems--;
    char temp1 = data[numItems];
    data[numItems] = 0;
    char temp2;
    for (int i = numItems - 1; i >= index; i--) {
        temp2 = data[i];
        data[i] = temp1;
        temp1 = temp2;
    }
}

/*
 * name:      replaceAt
 * purpose:   replace the element at the given index in the CharArrayList
 * arguments: the element being added
 * returns:   error message if the index is out of range
 * effects:   replaces given element in the CharArrayList
 */
void CharArrayList::replaceAt(char c, int index) {
    // if the index is out of range of the CharArrayList, throw an error 
    // message
    if (index >= numItems or index < 0){
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + ")" );
    }
    // replace the element at the given index
    data[index] = c;
}

/*
 * name:      concatenate
 * purpose:   concatenates two CharArrayLists together
 * arguments: pointer to the CharArrayList being added
 * returns:   none
 * effects:   concatenates the given CharArrayList on the end of the original
 */
void CharArrayList::concatenate(CharArrayList *other) {
    // Create a temp CharArrayList var to store the list being added
    CharArrayList temp = *other;

    // Add each element of the provided list at the end of the original list
    for (int i = 0; i < temp.size(); i++) {
        pushAtBack(temp.elementAt(i));
    }
}


/*
 * name:      shrink
 * purpose:   reduces the CharArrayList memory usage to the bare minimum
 * arguments: none
 * returns:   none
 * effects:   reduces the CharArrayList memory usage to the bare minimum
 */
void CharArrayList::shrink() {
    // allocate space on the heap for a new array, exactly the size of the
    // array list
    char *temp = new char[numItems];

    // copy all the elements of the array list onto this new array
    for (int i = 0; i < numItems; i++) {
        temp[i] = data[i];
    }
    // deallocate the heap memory of the old array list
    delete [] data;
    data = temp;
    capacity = numItems;
}