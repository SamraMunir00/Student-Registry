# StudentsRegistry

A simple C++ console application for managing student records using a `struct` and file handling. It is designed as a beginner-friendly first-semester programming project.

## Features

- Add a student record
- View all student records
- Update a student's details
- Delete a student record
- Save records in a text file so they remain available after the program closes
- Prevent duplicate roll numbers

## Student Information

Each student record contains:
- First name
- Last name
- Roll number
- Grade

## Project Structure

```text
StudentsRegistry/
├── main.cpp
├── students.txt
└── README.md
```

## Requirements

- A C++ compiler such as `g++`
- A terminal or command prompt

## How to Run

Open a terminal in the project folder and compile the program:

```bash
g++ main.cpp -o StudentsRegistry
```

Run it on Windows:

```bash
StudentsRegistry.exe
```

Run it on Linux or macOS:

```bash
./StudentsRegistry
```

The program reads from and writes to `students.txt`. Run the program from the project folder so it can find this file.

## File Format

Each line in `students.txt` stores one student in this order:

```text
rollNumber|firstName|lastName|grade
```

Example:

```text
101|Ali|Khan|A
102|Sara|Ahmed|B
```

## Concepts Used

- C++ structures (`struct`)
- Functions
- Vectors
- Loops and conditional statements
- Text file input and output (`ifstream`, `ofstream`)
- Basic CRUD operations

## Limitations

This is a beginner-level project. Names and grades should not contain the `|` character because it separates fields in the text file.