/*
 * unit_tests.h
 * Tests Added by Leo Kim on 1/31/22
 * 
 * Uses Matt Russell's unit_test framework to test the CharArrayList class.
 *
 * Instructions for using testing framework can be found at in CS 15's lab
 * 1 -- both in the spec and in the provided ArrayList_tests.h and Makefile.
 * More in-depth information for those who are curious as to how it works can
 * be found at http://www.github.com/mattrussell2/unit_test.
 */

#include "CharArrayList.h"
#include <cassert>

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/


// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() { 
    CharArrayList test_list;
    test_list.insertAt('a', 0);
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
                               
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
    
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
    
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
    
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
    
}

// Tests insertion into front, back, and middle of a larger list.
void insertAt_front_back_middle() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        // insertAt middle
        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() == 
        "[CharArrayList of size 9 <<abczdefgh>>]");

        // insertAt front
        test_list.insertAt('y', 0);

        assert(test_list.size() == 10);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() == 
        "[CharArrayList of size 10 <<yabczdefgh>>]");

        // insertAt back
        test_list.insertAt('x', 10);

        assert(test_list.size() == 11);
        assert(test_list.elementAt(10) == 'x');
        assert(test_list.toString() 
        == "[CharArrayList of size 11 <<yabczdefghx>>]");
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
}

// TEST GROUP CharArrayList default contructor

void defConstructor_Test1(){
    CharArrayList list;
}

void defConstructor_Test2(){
    CharArrayList list;
    assert(list.size() == 0);
}

// TEST GROUP CharArrayList single character constructor
 
void CharConstructor_Test1(){
    CharArrayList list('r');
}

void CharConstructor_Test2(){
    CharArrayList list('b');
    assert(list.size() == 1);
}

void CharConstructor_Test3(){
    CharArrayList list('s');
    assert(list.first() == 's');
}

// TEST GROUP expand

void Expand_Test1(){
    CharArrayList list;
    list.pushAtBack('q');
    list.pushAtBack('d');
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('a');
    list.pushAtBack('a');
    list.pushAtBack('a');
    list.pushAtBack('m');
    assert(list.first() == 'q');
    assert(list.last() == 'm');
}

void Expand_Test2(){
    CharArrayList list;
    list.pushAtBack('k');
    list.pushAtBack('d');
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('a');
    list.pushAtBack('a');
    list.pushAtBack('a');
    list.pushAtBack('r');
    assert(list.size() == 8);
}

// TEST GROUP push at front

void pushAtFront_Test1(){
    CharArrayList list('k');
    list.pushAtFront('s');
    assert(list.size() == 2);
    assert(list.first() == 's');
    assert(list.last() == 'k');
}

void pushAtFront_Test2(){
    CharArrayList list('k');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('w');
    assert(list.size() == 8);
    assert(list.first() == 'w');
    assert(list.last() == 'k');
}

void pushAtFront_Test3(){
    CharArrayList list;
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('a');
    list.pushAtFront('n');
    list.pushAtFront('9');
    list.pushAtFront('n');
    list.pushAtFront('a');
    list.pushAtFront('b');
    assert(list.toString() == "[CharArrayList of size 8 <<ban9nass>>]");
    //std::cout << list.toString();
}

void pushAtFront_Test4(){
    CharArrayList list;
    list.pushAtFront('s');
    assert(list.size() == 1);
    assert(list.first() == 's');
}


// TEST GROUP elementAt

void elementAt_Test1(){
    CharArrayList list('k');
    list.pushAtFront('s');
    assert(list.elementAt(0) == 's');
    assert(list.elementAt(1) == 'k');
}

void elementAt_Test2(){
    CharArrayList list('k');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('n');
    list.pushAtFront('s');
    list.pushAtFront('r');
    list.pushAtFront('s');
    list.pushAtFront('w');
    assert(list.elementAt(2) == 'r');
    assert(list.elementAt(4) == 'n');
}

void elementAt_Test3(){
    CharArrayList list('k');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.pushAtFront('n');
    list.pushAtFront('s');
    list.pushAtFront('r');
    list.pushAtFront('s');
    list.pushAtFront('w');
    //list.elementAt(0);
    //list.elementAt(9);
}

void elementAt_Test4(){
    CharArrayList list;
    //list.elementAt(0);
}

// TEST GROUP toString
void toString_Test1(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    assert(list.toString() == "[CharArrayList of size 8 <<bananass>>]");
    //std::cout << list.toString();
}

void toString_Test2(){
    CharArrayList list;
    assert(list.toString() == "[CharArrayList of size 0 <<>>]");
    //std::cout << list.toString();
}

void toString_Test3(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('9');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    assert(list.toString() == "[CharArrayList of size 8 <<ban9nass>>]");
    //std::cout << list.toString();
}

// TEST GROUP toReverseString
void toReverseString_Test1(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    assert(list.toReverseString() == "[CharArrayList of size 8 <<ssananab>>]");
    //std::cout << list.toString();
}

void toReverseString_Test2(){
    CharArrayList list;
    assert(list.toReverseString() == "[CharArrayList of size 0 <<>>]");
    //std::cout << list.toString();
}

void toReverseString_Test3(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('9');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    assert(list.toReverseString() == "[CharArrayList of size 8 <<ssan9nab>>]");
    //std::cout << list.toString();
}

// TEST GROUP insertInOrder

void insertInOrder_Test1(){
    CharArrayList list;
    list.insertInOrder('d');
    assert(list.toString() == "[CharArrayList of size 1 <<d>>]");
    //std::cout << list.toString();
}

void insertInOrder_Test2(){
    CharArrayList list;
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('C');
    list.pushAtBack('E');
    list.pushAtBack('F');
    list.pushAtBack('G');
    list.insertInOrder('D');
    assert(list.toString() == "[CharArrayList of size 7 <<ABCDEFG>>]");
    //std::cout << list.toString();
}

void insertInOrder_Test3(){
    CharArrayList list;
    list.pushAtBack('B');
    list.pushAtBack('C');
    list.pushAtBack('C');
    list.pushAtBack('C');
    list.pushAtBack('F');
    list.pushAtBack('G');
    list.insertInOrder('C');
    assert(list.toString() == "[CharArrayList of size 7 <<BCCCCFG>>]");
}

void insertInOrder_Test4(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('c');
    list.pushAtBack('c');
    list.pushAtBack('c');
    list.pushAtBack('f');
    list.pushAtBack('g');
    list.insertInOrder('z');
    assert(list.toString() == "[CharArrayList of size 7 <<bcccfgz>>]");
}

void insertInOrder_Test5(){
    CharArrayList list;
    list.insertInOrder('a');
    list.insertInOrder('d');
    list.insertInOrder('e');
    list.insertInOrder('g');
    list.insertInOrder('f');
    list.insertInOrder('b');
    list.insertInOrder('c');
    assert(list.toString() == "[CharArrayList of size 7 <<abcdefg>>]");
}

// TEST GROUP popFromBack

void popFromBack_Test1(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    list.popFromBack();
    list.popFromBack();
    assert(list.toString() == "[CharArrayList of size 6 <<banana>>]");
}

void popFromBack_Test2(){
    CharArrayList list;
    //list.popFromBack();
}

// TEST GROUP popFromFront

void popFromFront_Test1(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    list.popFromFront();
    list.popFromFront();
    assert(list.toString() == "[CharArrayList of size 6 <<nanass>>]");
}

void popFromFront_Test2(){
    CharArrayList list;
    //list.popFromFront();
}

// TEST GROUP removeAt
void removeAt_Test1(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    list.removeAt(2);
    list.removeAt(5);
    list.removeAt(0);
    //list.removeAt(9);
    assert(list.toString() == "[CharArrayList of size 5 <<aanas>>]");
}

void removeAt_Test2(){
    CharArrayList list;
    //list.removeAt(0);
}

// TEST GROUP replaceAt
void replaceAt_Test1(){
    CharArrayList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    list.replaceAt('t', 2);
    list.replaceAt('i', 5);
    list.replaceAt('c', 0);
    list.replaceAt('t', 7);
    //list.replaceAt('t',-1);
    assert(list.toString() == "[CharArrayList of size 8 <<catanist>>]");
}

void replaceAt_Test2(){
    CharArrayList list;
    //list.replaceAt('t', 0);
}

// TEST GROUP CharArrayList ARRay constructor

void ArrConstructor_Test1(){
    char test_arr[0] = {};
    CharArrayList list(test_arr, 0);
    assert(list.toString() == "[CharArrayList of size 0 <<>>]");
}

void ArrConstructor_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list(test_arr, 5);
    assert(list.toString() == "[CharArrayList of size 5 <<abcde>>]");
}



// TEST GROUP copy constructor
void CopyConstructor_Test1(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    CharArrayList list2(list1);
    list1.popFromBack();
    assert(list1.size() == 4);
    assert(list2.size() == 5);
}

void CopyConstructor_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    CharArrayList list2(list1);
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharArrayList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharArrayList of size 6 <<abcdef>>]");
}

void CopyConstructor_Test3(){
    CharArrayList list1;
    CharArrayList list2(list1);
    list2.pushAtBack('f');
    assert(list1.toString() == "[CharArrayList of size 0 <<>>]");
    assert(list2.toString() == "[CharArrayList of size 1 <<f>>]");
}

void CopyConstructor_Test4(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    CharArrayList list2(list1);
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharArrayList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharArrayList of size 6 <<abcdef>>]");
}

// TEST GROUP Overload assignment operator
void AssignOp_Test1(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    CharArrayList list2;
    list2 = list1;
    //list2 = list1;
    list1.popFromBack();
    assert(list1.size() == 4);
    assert(list2.size() == 5);
}

void AssignOp_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    CharArrayList list2;
    list2 = list1;
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharArrayList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharArrayList of size 6 <<abcdef>>]");
}


void AssignOp_Test3(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    CharArrayList list2;
    CharArrayList list3('r');
    list2 = (list3 = list1);
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharArrayList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharArrayList of size 6 <<abcdef>>]");
}

void AssignOp_Test4(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    //CharArrayList list1(test_arr, 5);
    CharArrayList list1;
    CharArrayList list2(test_arr, 5); 
    list2 = list1;
    list2.pushAtBack('f');
    list1.pushAtBack('d');
    list2.pushAtBack('b');
    assert(list1.toString() == "[CharArrayList of size 1 <<d>>]");
    assert(list2.toString() == "[CharArrayList of size 2 <<fb>>]");
    //assert(list2.toString() == "[CharArrayList of size 7 <<abcdefb>>]");
}

void AssignOp_Test5(){
    char test_arr1[5] = { 'a', 'b', 'c', 'd', 'e'};
    char test_arr2[5] = { 'f', 'g', 'h', 'i', 'j'};
    CharArrayList list1(test_arr1, 5);
    CharArrayList list2(test_arr2, 5);
    list2 = list1;
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharArrayList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharArrayList of size 6 <<abcdef>>]");
}

// TEST GROUP shrink

void Shrink_Test1(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    list1.shrink();
    assert(list1.size() == 5);
}

void Shrink_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    list1.pushAtBack('f');
    list1.shrink();
    assert(list1.toString() == "[CharArrayList of size 6 <<abcdef>>]");
}

void Shrink_Test3(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharArrayList list1(test_arr, 5);
    list1.pushAtBack('f');
    list1.pushAtBack('f');
    list1.pushAtBack('f');
    list1.pushAtBack('f');
    list1.pushAtBack('f');
    list1.pushAtBack('f');
    list1.pushAtBack('f');
    list1.pushAtBack('f');
    list1.shrink();
    assert(list1.toString() == "[CharArrayList of size 13 <<abcdeffffffff>>]");
    //assert(list1.toString() == "[CharArrayList of size 5 <<abcde>>]");
}

void Shrink_Test4(){
    CharArrayList list1;
    list1.shrink();
    assert(list1.size() == 0);
}

// TEST GROUP concatenate

void concatenate_Test1() {
    CharArrayList list1('f');
    CharArrayList list2('o');
    list1.concatenate(&list2);
    assert(list1.toString() == "[CharArrayList of size 2 <<fo>>]");
}

void concatenate_Test2() {
    CharArrayList list1;
    CharArrayList list2;
    list1.pushAtBack('b');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('s');
    list2.pushAtBack('s');
    list1.concatenate(&list2);
    assert(list1.toString() == "[CharArrayList of size 8 <<bananass>>]");
    assert(list2.toString() == "[CharArrayList of size 3 <<ass>>]");
}


void concatenate_Test3() {
    CharArrayList list1;
    CharArrayList list2;
    list2.pushAtBack('b');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('s');
    list2.pushAtBack('s');
    list1.concatenate(&list2);
    assert(list1.toString() == "[CharArrayList of size 8 <<bananass>>]");
}

void concatenate_Test4() {
    CharArrayList list1;
    list1.pushAtBack('b');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list1.pushAtBack('a');
    list1.pushAtBack('s');
    list1.pushAtBack('s');
    list1.concatenate(&list1);
    assert(list1.toString() == 
    "[CharArrayList of size 16 <<bananassbananass>>]");
}

void concatenate_Test5() {
    CharArrayList list1;
    CharArrayList list2;
    list2.pushAtBack('b');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('s');
    list2.pushAtBack('s');
    list2.concatenate(&list1);
    assert(list2.toString() == "[CharArrayList of size 8 <<bananass>>]");
}

void concatenate_Test6() {
    CharArrayList list1;
    CharArrayList list2;
    list2.concatenate(&list1);
    assert(list2.toString() == "[CharArrayList of size 0 <<>>]");
}


// TEST GROUP clear

void clear_Test1() {
    CharArrayList list1;
    list1.pushAtBack('b');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list1.pushAtBack('a');
    list1.clear();
    assert(list1.size() == 0);
    assert(list1.toString() == 
    "[CharArrayList of size 0 <<>>]");
}

void clear_Test2() {
    CharArrayList list1;
    list1.clear();
}


