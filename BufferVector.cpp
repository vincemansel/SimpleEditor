//
//  BufferVector.cpp
//  editorBuffer
//
//  Created by Vince Mansel on 10/25/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

#include "Buffer.h"

/*
 * Buffer layered on Vector
 */

/* Implementation Note:
 private:
    // for Buffer class
    Vector<char> chars;
    int cursor;
 */

Buffer::Buffer() {
    
    cursor = 0;
    
}

Buffer::~Buffer() {}

void Buffer::moveCursorForward() {
    if (cursor < chars.size()) {
        cursor++;
    }
    
}

void Buffer::moveCursorBackward() {
    if (cursor > 0) {
        cursor--;
    }
}


void Buffer::moveCursorToStart() {
    cursor = 0;
}

void Buffer::moveCursorToEnd() {
    cursor = chars.size();
}

void Buffer::insertCharacter(char ch) {
    
    chars.insertAt(cursor,ch);
    cursor++;
}

void Buffer::deleteCharacter() {
    if (cursor != 0) {
        chars.removeAt(cursor - 1);
        cursor--;
    }
}

// This is the extension.

void Buffer::moveCursorToWordBegin() {
    if (cursor > 0) {
        if (isspace(chars[cursor-1])) {
            cursor--;
        }
    }
    while (cursor > 0 && !isspace(chars[cursor-1])) {
        cursor--;
    }
}

void Buffer::display() {
    
    for (int i = 0; i < cursor; i++) {
        cout << chars[i];
    }
    cout << "|";
    for (int i = cursor; i < chars.size(); i++) {
        cout << chars[i];
    }
    cout << endl;
    cout << "Cursor=" << cursor << endl;
}



