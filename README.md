🎓 Academix Hub — Student Database Management System (C Project)
Designed and developed by Exception Elites (Group-15) | C.V. Raman Global University, Bhubaneswar, Odisha

📖 Overview
Academix Hub is a C-based console application crafted to manage essential academic records of students. This project serves as a comprehensive Student Database Management System (SDMS), supporting both Admin and Student operations. It simulates a real-world university data portal, offering features such as student registration, project tracking, internship records, results, fee management, and even internal messaging!

🛠️ Features
👨‍💼 Admin Functionalities
🔐 Login System with credentials

➕ Add/Modify/Delete Student Records

📁 Add Projects and Internships

💰 Manage College Fees (Add, Modify, Delete)

📈 Add/Delete/View CGPA Results

📩 Send Messages to Students

🧹 Clear All Data (Admin-only)

🎯 View university Vision, Mission, Contact, and About Us

👩‍🎓 Student Functionalities
🔐 Login using Reg. No and Phone

🔍 View own Profile, Results, and Fee Details

📂 Access to Project & Internship Records

📧 Check Messages sent by Admin

🎯 Browse Subjects Info, Vision, Mission, etc.

🗃️ Modules & Structures
The system handles:

Student Info (with performance & attendance)

Projects (with year, topic & language)

Internships (with company, position & duration)

College Fees (paid, pending, course fees)

Results (semester-wise CGPA)

Messages (admin-to-student)

Each module is backed by its own struct and managed via arrays.

💾 Data Persistence
All data is stored using binary files (students.dat). It supports:

Auto Save on Exit

Auto Load on Startup

👨‍💻 Tech Stack
Language: C

UI: Console-Based

Data Storage: File Handling with Binary I/O

🎯 Motivation
This project was developed as part of our academic journey to simulate a real-time educational database environment that supports a wide range of academic operations. It showcases how C can be used effectively for structured, real-world software solutions.

🏁 How to Run
Compile the project using a C compiler 
Use login credentials:

Admin: Username: admin, Password: 12345

Student: Use Reg No & Phone

🗃️ Modules & Structures
The system handles:

Student Info (with performance & attendance)

Projects (with year, topic & language)

Internships (with company, position & duration)

College Fees (paid, pending, course fees)

Results (semester-wise CGPA)

Messages (admin-to-student)

Each module is backed by its own struct and managed via arrays.

💾 Data Persistence
All data is stored using binary files (students.dat). It supports:

Auto Save on Exit

Auto Load on Startup

👨‍💻 Tech Stack
Language: C

UI: Console-Based

Data Storage: File Handling with Binary I/O

🎯 Motivation
This project was developed as part of our academic journey to simulate a real-time educational database environment that supports a wide range of academic operations. It showcases how C can be used effectively for structured, real-world software solutions.


🧵 The Story Behind Academix Hub — A C-Based Student Management System
🛫 It All Started With a Vision…
At the heart of a bustling university campus, students juggle lectures, assignments, internships, and projects. Admins, on the other hand, handle a sea of records. Our team, Exception Elites (Group-15), set out on a journey to simplify that chaos by building a console-based system in C — and thus, Academix Hub was born.

🏗️ Structuring the Foundation
We started by laying the groundwork with data structures. Like organizing shelves in a library, we defined different structs to hold essential information:

Student – Holds everything: name, reg no, phone, address, gender, course, subjects, performance, and more.

Project – Records students’ academic projects with topic, language, and year.

Internship – Logs where students interned, their position, and duration.

CollegeFee – Tracks total fee, paid amount, and remaining dues.

Result – Stores semester-wise CGPA data.

Message – Allows admins to send messages to students (a mini inbox system).

All these are stored in global arrays with counters — like keeping track of how many books are in each library section.

🔐 Enter the Portal — Login System
The application opens with a warm welcome banner from C.V. Raman Global University, followed by a login menu:

Admins log in with a fixed username (admin) and password (12345) to unlock full control.

Students log in using their registration number and phone number.

Once logged in, each user gets their own menu tailored to their role.

🎛️ Admin Dashboard — The Control Center
Admins are the true wizards here. They can:

Add, view, search, or delete student records.

Assign projects and internships.

Track academic fees and update or remove them.

Send direct messages to students.

Enter and delete results (CGPA per semester).

Wipe all data in one go if needed (admin-only).

Access static pages like Vision, Mission, Contact, and About Us.

Behind the scenes, functions like addStudent(), addProject(), addResult(), and sendMessageToStudent() handle each task with clean prompts and validations.

🎓 Student Dashboard — A Personal Kiosk
Students get their own simplified but powerful dashboard:

View their own profile, projects, internships, and CGPA.

Check messages sent by admins.

Review college fee status.

Explore their subjects and university vision.

The studentMenu() function ensures they never see anything beyond their scope — a clean separation of roles.

🧮 Validation, Because Details Matter
We knew that a single digit could break the system — so we added:

validateRegNo() → Checks if reg no is exactly 10 digits.

validatePhone() → Ensures correct phone number format.

validatePercentage() → Keeps performance and attendance between 0–100.

validateEmail() → Ensures email is in correct format using a custom check.

💾 Data That Lasts — File Handling
We didn't want our data to vanish when the program closed. So we created:

saveData() – Writes all arrays (students, projects, fees, etc.) into a binary file students.dat.

loadData() – Loads that data when the system restarts.

This gives the system memory — like a brain that never forgets.

📚 Subjects Library — Ready to Explore
To help students understand their academic structure, we built a subject listing:

Displays subject names and credits.

Structured in a table format for neat reading.

🧹 Just In Case — Clear All Function
Sometimes, a fresh start is needed. clearAllData() resets all counters and deletes the binary file. This option is locked away in the admin menu — guarded, like a vault key.

🧾 The Result — Easy, Efficient, Empowering
After months of planning, debugging, and testing, we created a full-fledged system that lets:

Students feel empowered

Admins stay organized

Records remain secure

And data stays persistent

All using just pure C programming and file handling.

🌟 Final Words
This wasn’t just a coding project — it was a lesson in design, logic, validation, collaboration, and problem-solving.

Academix Hub may run in a console, but behind those black-and-white screens is a world of academic possibilities.



🤝 Contributions
Created by Exception Elites (Group-15) as a team effort. We believe this project can be a great starting point for beginners interested in building management systems in C.
