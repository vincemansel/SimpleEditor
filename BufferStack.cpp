//
//  BufferStack.cpp
//  editorBuffer
//
//  Created by Vince Mansel on 10/25/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

#include "Buffer.h"

/*
 * Buffer layered on a stack.
 */

/* Implementation Note:
    private:
        Stack<char> before, after; 
 */

Buffer::Buffer() {}

Buffer::~Buffer() {}

void Buffer::moveCursorForward() {
    if (!after.isEmpty())
        before.push(after.pop());
}

void Buffer::moveCursorBackward() {
    if (!before.isEmpty())
        after.push(before.pop());
}

void Buffer::moveCursorToStart() {
    while (!before.isEmpty())
        moveCursorBackward();
}

void Buffer::moveCursorToEnd() {
    while (!after.isEmpty())
        moveCursorForward();
}

void Buffer::insertCharacter(char ch) {
    before.push(ch);
}

void Buffer::deleteCharacter() {
    if (!before.isEmpty())
        before.pop();
}

// This is the extension.

void Buffer::moveCursorToWordBegin() {
    if (!before.isEmpty()) {
        if (isspace(before.peek())) {
            moveCursorBackward();
        }
    }
        
    while (!before.isEmpty() && !isspace(before.peek())) {
        moveCursorBackward();
    }
}

void Buffer::display() {
    
    Stack<char> printBefore;
    Stack<char> temp = before;
    
    while (!temp.isEmpty()) {
        printBefore.push(temp.pop());
    }
    
    while (!printBefore.isEmpty())
        cout << printBefore.pop();
    
    cout << "|";
    
    temp = after;
    
    while (!temp.isEmpty())
        cout << temp.pop();
    
    cout << endl;
}

                         
