# Student Course and Result Management System

## Data Structure and Algorithm Lab - Project Based Learning

### Project Title

**Student Course and Result Management System using C**

## Introduction

This project is developed for the Data Structure and Algorithm Lab.

The system is designed for a small educational institute to manage student information, fees, courses and results.

The program is developed using the C programming language and uses a **singly linked list** to store student records.

## Student Information

The system stores the following information:

* Student ID
* Student Name
* Fees
* Fee Payment Status
* Course
* Result

## Available Courses

Students can be allocated to one of the following courses after paying the fees:

1. DS - Data Structures
2. AI - Artificial Intelligence
3. ML - Machine Learning
4. Web - Web Development

## Available Results

After completion of the course, a student can receive:

* Excellent
* Good
* Fail

## Data Structure Used

### Singly Linked List

A singly linked list is used to store student records.

Each node contains:

* Student ID
* Name
* Fees
* Fee status
* Course
* Result
* Pointer to the next student

The linked list is suitable because the number of students can increase or decrease during program execution.

## Main Features

* User ID and password authentication
* Add student
* Display students
* Search student
* Check duplicate Student ID
* Fee payment
* Course allocation
* Result entry
* Delete student
* Count total students
* Persistent data storage
* Menu-driven interface

## Login Details

For demonstration:

**User ID:** `admin`

**Password:** `1234`

## File Handling

The program uses a file named:

```text
students.txt
```

Student information is saved in this file.

Therefore, the student data can be loaded again when the program is started.

## Technologies Used

* C Programming Language
* Structure
* Singly Linked List
* Dynamic Memory Allocation
* File Handling
* String Functions
* Menu Driven Programming

## How to Run

### Step 1

Compile the program:

```bash
gcc main.c -o student
```

### Step 2

Run the program:

```bash
./student
```

On Windows:

```bash
student.exe
```

## Project Flow

```text
Login
   |
   v
Main Menu
   |
   +---- Add Student
   |
   +---- Display Student
   |
   +---- Search Student
   |
   +---- Pay Fees
   |
   +---- Allocate Course
   |
   +---- Enter Result
   |
   +---- Delete Student
   |
   +---- Count Students
   |
   +---- Save Data
   |
   v
Exit
```

## Conclusion

This project demonstrates how data structures and file handling can be used to solve a real-world student management problem.

The project provides a simple and easy-to-use system for managing student records, fees, courses and results.
