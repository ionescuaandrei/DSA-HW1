# DSA-HW1

Exercise 1: 
✨ Features Overview

1. INSERT
Inserts a substring into the text at a specific position.

2. DELETE
Deletes a specific number of characters from the text, starting at a given position.

4. UNDO
Reverts the last operation (either an insert or a delete).

4. REDO
Re-applies the last operation that was undone.

In order to use them, syntaxes must be defined.

INSERT [POSITION] [TEXT_TO_BE_INSERTED]
DELETE [POSITION] [NUMBER_OF_CHARS] (the number of chars must be provided by a digit or by a sequence of letters which can be random, the number of letters matters)
UNDO 
REDO

Unsolved corner case: Deleting past the length of the string: 
Mainly, this works, but it delets '/0' too, so if you UNDO or insert again, it will behave unexpectedly. 
Solution: ensure that when deleting past the length of the string, it deletes until '/0'.
