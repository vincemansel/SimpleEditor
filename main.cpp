//
//  main.cpp
//  editorBuffer
//
//  Created by Vince Mansel on 10/25/11.
//  Copyright (c) 2011 Wave Ocean Software. All rights reserved.
//

/* This program implements a simple low level editor buffer abstraction.
   There are 3 implementations that the buffer is layered on top of"
    Vector, Singly Linked List and Stack.
 
 Big-O Implementation Comparisons
 
                        Vector  Stack   List
 Buffer()               O(1)    O(1)    O(1)
 ~Buffer()              O(1)    O(1)    O(N)
 moveCursorForward()    O(1)    O(1)    O(1)
 moveCursorBackward()   O(1)    O(1)    O(N)
 moveCursorToStart()    O(1)    O(N)    O(1)
 moveCursorToEnd()      O(1)    O(N)    O(N)
 insertCharacter()      O(N)    O(1)    O(1)
 deleteCharacter()      O(N)    O(1)    O(1)
 moveCursorToWordBegin  O(1)    O(1)    O(N)
 Space used             1N      2N      5N 
 
 Stack is easiest to implement and debug.
 
 */

#include <iostream>
#include "simpio.h"
#include "Buffer.h"

void HandleCommand(Buffer &buffer, string command);

int main () {
    
    Buffer buffer;
    
    cout << "Editor Buffer" << endl;
    cout << "Enter h for help" << endl;
    cout << "************************************************" << endl;
    
    while (true) {
        buffer.display();
        string command = GetLine();
        
        if (command[0] == 'Q' || command[0] == 'q') {
            break;
        }
        else {
            HandleCommand(buffer, command);
        }
    }
    
    cout << "Editor: Quit - Goodbye" << endl;
    
    return 0;
}

void HandleCommand(Buffer &buffer, string command) {
    
    cout << "SIZE=" << command.size() << ":COMMAND=" << command << ":" << endl;
    if (command.size() > 1 && !(command[0] == 'i' || command[0] == 'I')) {
        cout << "Invalid editor command" << endl;
    }
    else {
        string commandMessage = 

"F       Move cursor forward one character position! \n\
B       Move cursor backward one character position \n\
J       Jump to start of buffer (before first character) \n\
E       Move cursor to end of buffer (after last character)! \n\
Ixxx    Insert characters xxx at current cursor position \n\
D       Delete character after current cursor position \n\
W       Move cursor to beginning of word or previous word \n\
Q       QUIT!";

        switch (command[0]) {
            case 'h':
            case 'H':
                cout << commandMessage << endl;
                break;
            case 'f':
            case 'F':
                buffer.moveCursorForward();
                break;
            case 'b':
            case 'B':
                buffer.moveCursorBackward();
                break;
            case 'j':
            case 'J':
                buffer.moveCursorToStart();
                break;
            case 'e':
            case 'E':
                buffer.moveCursorToEnd();
                break;
            case 'd':
            case 'D':
                buffer.deleteCharacter();
                break;
            case 'i':
            case 'I':
                for (int i = 1; i < command.size(); i++) {
                    buffer.insertCharacter(command[i]);
                }
                break;
            case 'w':
            case 'W':
                buffer.moveCursorToWordBegin();
                break;

            default:
                if (command.size() != 0)
                    cout << "Unknown Command" << endl;
                break;
        }
    }
}
