//
//  Buffer.h
//  editorBuffer
//
//  Created by Vince Mansel on 10/25/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

#ifndef editorBuffer_Buffer_h
#define editorBuffer_Buffer_h

#include <iostream>
#include "genlib.h"
//#include "vector.h"
#include "stack.h"



class Buffer {
public:
    Buffer();
    ~Buffer();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();
    void display();
    
    void moveCursorToWordBegin();
    
//private:
//    // for BufferVector.cpp implementation class
//    Vector<char> chars;
//    int cursor;
    
//private:
//    // for BufferList.cpp implementation class
//    struct cellT {
//        char ch;
//        cellT *next;
//    };
//    cellT *head, *cursor; 

private:
    // for BufferStack.cpp implementation class
    Stack<char> before, after; 

};
#endif
