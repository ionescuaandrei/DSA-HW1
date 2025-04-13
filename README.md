# Data Structures and Algorithms - BigHW 1
## Stacks, Queues & Lists Implementation

This repository contains solutions for the Data Structures and Algorithms Homework 1, focusing on the implementation and application of stacks, queues, and lists.

## Team Members - GROUP 1211ED
- Ionescu Andrei
- Stancu Stefanita-Ionut

## General Information

- Each exercise is implemented in a separate folder
- Each exercise uses a different data structure type (stack, queue, or list)
- Implementation is based on custom data structures (not standard C++ containers)
- All implementations utilize classes and separate header files with structs for better organization and code readability

## Exercise 1: Text Editor with Undo/Redo Functionality

### Summary
This exercise implements a text editor with undo and redo capabilities. The editor allows inserting and deleting text at specified positions and keeps track of operations to enable undo and redo functionality.

### Data Structure Used
**Stack** - Chosen because the undo/redo operations follow a Last-In-First-Out pattern, where the most recent operation is the first to be undone.

### Features
- **INSERT**: Add text at a specified position
- **DELETE**: Remove a substring from a specified position
- **UNDO**: Revert the last operation
- **REDO**: Reapply an operation that was undone

### Implementation Details
- Operations are tracked using a custom data structure
- Each operation record contains:
  - Operation type (INSERT or DELETE)
  - Position in the text
  - The text that was inserted or deleted
- Two stack instances store the undo and redo operations

### Usage Example
```
INSERT 0 Article
DELETE 1 2
UNDO
REDO
```

## Exercise 2: Hospital Management System

### Summary
This exercise implements a patient management system for a hospital with multiple wards. The system efficiently manages patient admissions, transfers, and discharges across wards while maintaining specific occupancy rules.

### Data Structure Used
**Linked List** - Selected for its flexibility in dynamic insertion, deletion, and rearrangement of patients across wards, which is essential for the transfer and discharge operations.

### Features
- Initialize a hospital management system
- Admit patients with their name and medical condition
- Discharge patients from specific beds
- Transfer patients between beds
- Display the current occupancy status of all wards
- Retrieve patient information by bed index

### Implementation Details
- Each ward has a maximum of 4 beds
- System maintains the "no-empty-beds" requirement by shifting patients as needed
- New wards are created when existing ones reach full capacity

### Usage Example
```
admitPatient("Sergiu", "Pneumonia")
admitPatient("Rares", "Broken Arm")
displaySystem()
getPatientInfo(0)
dischargePatient(0)
transferPatient(1, 3)
```

## Exercise 3: Dynamic Playlist Manager

### Summary
This exercise implements a dynamic playlist manager for a DJ, allowing priority-based song management. The system tracks song history and allows various operations to modify the playlist based on preferences.

### Data Structure Used
**Queue** - Utilized because song playback follows a First-In-First-Out order within each preference level, with songs being processed in the sequence they were added.

### Features
- Add songs with different preference levels (VIP, Regular, Low)
- Play songs starting with the highest preference
- Skip a portion or entire songs
- Replay the last played song
- Remove specific songs from the playlist
- Show the current playlist in order of play
- Display play history

### Implementation Details
- Songs are structured with preference level, duration, and name
- Uses file I/O for input and output operations
- Maintains separate data structures for different preference levels and history

### MOSS PROBLEM
We have encountered some issues regarding ex3 and the AI detection
- We made 3 cases for this exercise DeepSeek, Claude.ai and ChatGBT
- Claude.ai and our main.cpp file had a 38% similarity, because the test in the main.cpp could not be written in a different way, like:
```c++
else if (command == "PLAY") {
            pm.play(output);
        }
```
- Another thing will be that our main.cpp file is 63 lines long, the claude.ai file has ~370 lines of code and because of this: the same amount of matching code (around 22-24 lines) represents a much larger portion of the smaller file (38% of 62 lines) than of the larger file (7% of 348 lines).
- In conclusion ex3 had a 7% match with claude.ai.

### Usage Example
```
ADD 2 210 BlindingLights
ADD 1 180 ShapeOfYou
ADD 3 240 Memories
PLAY
SKIP 90
REPLAY
REMOVE Memories
SHOW
HISTORY
```

## How to Compile and Run

### Prerequisites
- C++ compiler (g++ recommended)
- Make (optional, if Makefile is provided)

### Compilation Instructions
Navigate to the exercise directory and compile:

```bash
cd ex1
g++ -o textEditor *.cpp
```

```bash
cd ex2
g++ -o hospitalManagementSystem *.cpp
```

Repeat for each exercise directory.

### Running the Programs
For Exercise 1 (console I/O):
```bash
./textEditor
```

For Exercise 2 (console I/O):
```bash
./hospitalManagementSystem
```

For Exercise 3 (file I/O):
```bash
./playlistManager input.txt output.txt
```

## Notes
- Each exercise uses a different custom data structure implementation
- All implementations handle edge cases and validation
- The code uses classes and separate header files with structs for better organization and readability
- The code is designed for educational purposes to demonstrate understanding of basic data structures
