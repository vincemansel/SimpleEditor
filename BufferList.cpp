//
//  BufferList.cpp
//  editorBuffer
//
//  Created by Vince Mansel on 10/25/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

#include "Buffer.h"

/*
 * Buffer layered on a singly linked list.
 */

/* Implementation Note:
    private:
        struct cellT {
            char ch;
            cellT *next;
        };
        cellT *head, *cursor; 
 */

Buffer::Buffer() {

    cellT * dummy = new cellT;
    dummy->next = NULL;
    dummy->ch = ""[0];
    head = dummy;
    cursor = dummy;
    
}

Buffer::~Buffer() {
    
    // Iteratively or recursively delete all cells of buffer

}

void Buffer::moveCursorForward() {
    if(cursor->next != NULL) {
        cursor = cursor->next;
    }
}

void Buffer::moveCursorBackward() {
    if (cursor != head) {
        cellT *cp = head;
        while (cp->next != cursor)
            cp = cp->next;
        cursor = cp;
    }
}


void Buffer::moveCursorToStart() {
    cursor = head;
}

void Buffer::moveCursorToEnd() {
    while(cursor->next != NULL) {
        cursor = cursor->next;
    }
}

void Buffer::insertCharacter(char ch) {
    
    cellT *cp = new cellT;
    cp->ch = ch;
    cp->next = cursor->next;
    cursor->next = cp;
    cursor = cp;    
    
}

void Buffer::deleteCharacter() {
    if (cursor->next != NULL) {
        cellT *old = cursor->next;
        cursor->next = old->next;
        delete old;
    }
}

// This is the extension.

void Buffer::moveCursorToWordBegin() {
    if (cursor != head) {
        if (isspace(cursor->ch)) {
            moveCursorBackward();
        }
    }
    while (cursor != head && !isspace(cursor->ch)) {
        moveCursorBackward();
    }
}

void Buffer::display() {
    cellT * cur;
    for (cur = head; cur != cursor && cur != NULL; cur = cur->next) {
        cout << cur->ch;
    }
    cout << cur->ch;
    cout << "|";
    for (cur = cur->next;  cur != NULL; cur = cur->next) {
        cout << cur->ch;
    }
    cout << endl;
    cout << "Head=" << head << endl;
    cout << "Cursor=" << cursor << endl;
}

