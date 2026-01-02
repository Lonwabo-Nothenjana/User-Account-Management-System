# User-Account-Management-System
Console-based C++ User Management System with authentication, profile management, and basic demographic analytics.
Console-Based User Account Management System (C++)

A lightweight, file-based User Account Management System built in C++, designed to simulate real-world user authentication, profile management, and basic demographic analysis using a console interface.

This project focuses on core software engineering principles such as structured data handling, file I/O, authentication logic, and clean program flow.

🎯 Project Purpose

The goal of this project is to model how a simple user management system works behind the scenes, without relying on databases or external frameworks.

It simulates scenarios commonly found in:

Small organizations

Internal tools

Learning and training systems

Legacy or resource-constrained environments

✨ Features
🔐 Authentication

Login using email and password

Credentials validated against stored user records

Prevents unauthorized access

👤 User Profile Management

View personal profile information

Update country details

Change account password

All updates are saved persistently

📊 Demographic Analytics

Calculate average age of all users

Display gender distribution

Demonstrates basic statistical analysis on real-like data

💾 File-Based Persistence

Reads user data from a text file at startup

Writes updates back to the same file

Simulates a simple database using flat-file storage

📦 Included Sample Data (Data.txt)

This repository includes an original sample dataset stored in Data.txt.

Why the Data Is Included

Allows the program to run immediately after cloning

Enables testing of authentication and analytics features

Provides realistic data for demonstration and review

The dataset was manually generated for educational purposes and does not contain real personal information.

📂 File Structure
UserManagement/
├── main.cpp
├── Data.txt
└── README.md


Data.txt must remain in the same directory as the executable.

📑 Data Format

Each line in Data.txt represents one user record:

email|age|country|password|gender


Example:

ethan.jenkins@gmail.com|31|South Africa|FgHjKlM678*|Male


Fields are separated using the pipe (|) delimiter

Names are derived programmatically from the email address

🔄 How the Program Accesses the Data

At runtime, the application:

Opens Data.txt using ifstream

Reads and parses each user record

Stores the data in memory using a User struct

Performs authentication and profile operations

Writes all updates back to Data.txt using ofstream

ifstream file("Data.txt");   // Load user data
ofstream file("Data.txt");   // Save updated data

▶️ How to Run the Program
1. Clone the repository
git clone https://github.com/Lonwabo-Nothenjana/user-management-system-cpp.git

2. Navigate into the project directory
cd user-management-system-cpp

3. Compile the program
g++ main.cpp -o user_manager

4. Run the program
./user_manager


Make sure Data.txt is present before running.

🧠 Learning Outcomes

This project demonstrates understanding of:

Struct-based data modeling

File input and output in C++

Authentication logic

Menu-driven program design

Input validation

Basic data analysis

Writing readable and maintainable C++ code

🔐 Security Disclaimer

Passwords are stored in plain text in Data.txt to keep the focus on:

File handling

Data parsing

Program logic

⚠️ In real-world applications:

Passwords must be hashed and salted

Databases should replace flat-file storage

Security improvements are listed under Future Improvements.

🚀 Future Improvements

Planned enhancements include:

Password hashing

Role-based access (Admin vs User)

Migration to std::vector

Modular design using header/source files

Unit testing

GUI or web-based interface

👨‍💻 Author

Lonwabo Nothenjana
Aspiring AI Engineer | Software Developer

📧 Email: liodenothenjana@gmail.com

💻 GitHub: Lonwabo-Nothenjana

📜 License

This project is intended for educational purposes and is open for learning, improvement, and experimentation.
