#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_PROJECTS 100
#define MAX_INTERNSHIPS 100
#define MAX_MESSAGES 100

// Structure to store student details
typedef struct {
    char name[50];
    char regNo[11]; 
    char parentName[50];
    char phone[11];
    char gender[10];
    char email[50];
    char course[30];
    float performance;
    float attendance;
    int year;
    char address[100];
    char department[50];
    int semester;
    char subjects[5][30];
} Student;

// Project structure
typedef struct {
    char studentRegNo[11];
    int year;
    char topic[100];
    char language[50];
} Project;

// Internship structure
typedef struct {
    char studentRegNo[11];
    char companyName[50];
    char position[50];
    int duration;
} Internship;

// College fee structure
typedef struct {
    char studentRegNo[11]; // Unique identifier for the student
    char studentName[50];
    char course[30];
    int year;
    float courseFee;
    float paidAmount;
    float remainingAmount;
} CollegeFee;

// Message structure
typedef struct {
    char studentRegNo[11];
    char message[200];
} Message;
// Structure to store student results
typedef struct {
    char regNo[11]; // Registration number to link with the student
    int semester;   // Semester number
    float cgpa;     // CGPA for the semester
} Result;

// Global array to store results
Result results[MAX_STUDENTS * 10]; // Assuming a student can have up to 10 semesters
int resultCount = 0; // Counter for result records

// Global arrays to store data
Student students[MAX_STUDENTS];
Project projects[MAX_PROJECTS];
Internship internships[MAX_INTERNSHIPS];
CollegeFee collegeFees[MAX_STUDENTS];
Message messages[MAX_MESSAGES];

// Counters for records
int studentCount = 0;
int projectCount = 0;
int internshipCount = 0;
int collegeFeeCount = 0;
int messageCount = 0;

// Function Prototypes
void displayHeader();
void login();
void adminLogin();
void studentLogin();
void adminMenu();
void studentMenu();
void addStudent();
void showStudents();
void searchStudent();
void deleteStudent();
void validatePhone(char *phone);
void validateRegNo(char *regNo);
void validatePercentage(float *value, char *field);
void validateEmail(char *email);
void visionMission(); 
void contactUs();
void aboutUs();
void addProject();
void showProjects();
void addInternship();
void showInternships();
void showSubject();
void saveData();
void loadData();
void modifyStudentRecord();
void addCollegeFee();
void showCollegeFee();
void modifyCollegeFee();
void sendMessageToStudent();
void checkMessages();
void clearAllData();
void viewResult();
void deleteResult();
void addResult();

// Main function
int main() {
    loadData();
    login();
    return 0;
}

// Function for display header
void displayHeader() {
    system("cls");
    printf("*=========================================================================*\n");
    printf("|                     C.V. Raman Global University                        |\n");
    printf("|                         Bhubaneswar, Odisha                             |\n");
    printf("|_________________________________________________________________________|\n");
    printf("|                             Academix Hub                                |\n");
    printf("|                                                                         |\n");
    printf("|                 A Student Database Management System                    |\n");
    printf("|             ~ Designed By :- Exception Elites(Group-15)                 |\n");
    printf("*=========================================================================*\n");
    printf("|                _/\\_ Welcome to our Dashboard _/\\_                       |\n");
    printf("***************************************************************************\n");
}

// Login function
void login() {
    int choice;
    displayHeader();
    printf("\n \n   <*> | Welcome to our Student Database Management System | <*> \n");

    while (1) {
    	printf("*--------------------*\n");
        printf("\n1. Admin Login\n");
        printf("2. Student Login\n");
        printf("*--------------------*\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear buffer

        if (choice == 1) {
            adminLogin();
            break;
        } else if (choice == 2) {
            studentLogin();
            break;
        } else {
            printf("Invalid choice! Please enter 1 or 2.\n");
        }
    }
}

// Admin login function
void adminLogin() {
    char username[20], password[20];
    char correctUsername[] = "admin";
    char correctPassword[] = "12345";

    displayHeader();
    printf("\n \n   <*> | Admin Login | <*> \n");

    while (1) {
        printf("\nUsername: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);

        if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
            printf("\nLogin Successful...!\n");
            system("pause");
            adminMenu();
            break;
        } else {
            printf("\nInvalid Username or Password! Try again.\n");
        }
    }
}

void addResult() {
    if (resultCount >= MAX_STUDENTS * 10) {
        printf("Result database is full!\n");
        return;
    }

    Result r;
    printf("Enter Registration Number: ");
    scanf("%s", r.regNo);
    getchar();

    // Check if the student exists
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].regNo, r.regNo) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found! Please add the student first.\n");
        system("pause");
        return;
    }

    printf("Enter Semester: ");
    scanf("%d", &r.semester);
    getchar();

    printf("Enter CGPA: ");
    scanf("%f", &r.cgpa);
    getchar();

    results[resultCount++] = r;
    printf("Result added successfully!\n");
    saveData();
    system("pause");
}

void deleteResult() {
    char regNo[11];
    int semester;
    printf("Enter Registration Number: ");
    scanf("%s", regNo);
    getchar();

    printf("Enter Semester to Delete: ");
    scanf("%d", &semester);
    getchar();

    for (int i = 0; i < resultCount; i++) {
        if (strcmp(results[i].regNo, regNo) == 0 && results[i].semester == semester) {
            for (int j = i; j < resultCount - 1; j++) {
                results[j] = results[j + 1];
            }
            resultCount--;
            printf("Result deleted successfully!\n");
            saveData();
            system("pause");
            return;
        }
    }

    printf("Result not found!\n");
    system("pause");
}

void viewResult() {
    char regNo[11];
    printf("Enter Registration Number: ");
    scanf("%s", regNo);
    getchar();

    int found = 0;
    printf("\n+=============================================+\n");
    printf("| %-15s | %-8s | %-10s |\n", "Semester", "CGPA", "Status");
    printf("+=============================================+\n");

    for (int i = 0; i < resultCount; i++) {
        if (strcmp(results[i].regNo, regNo) == 0) {
            found = 1;
            printf("| %-15d | %-8.2f | %-10s |\n", results[i].semester, results[i].cgpa, (results[i].cgpa >= 5.0) ? "Pass" : "Fail");
        }
    }

    if (!found) {
        printf("| No results found for this student!       |\n");
    }
    printf("+=============================================+\n");
    system("pause");
}
// Student login function
void studentLogin() {
    char regNo[11], phone[11];
    int found = 0;

    displayHeader();
    printf("\n \n   <*> | Student Login | <*> \n");

    while (1) {
        printf("\nEnter Registration Number: ");
        scanf("%s", regNo);
        printf("Enter Phone Number: ");
        scanf("%s", phone);

        for (int i = 0; i < studentCount; i++) {
            if (strcmp(students[i].regNo, regNo) == 0 && strcmp(students[i].phone, phone) == 0) {
                found = 1;
                printf("\nLogin Successful...!\n");
                system("pause");
                studentMenu();
                return;
            }
        }

        if (!found) {
            printf("\nInvalid Registration Number or Phone Number! Try again.\n");
        }
    }
}
// Admin menu function
void adminMenu() {
    int choice;
    while (1) {
        displayHeader();
        printf("\n");
        printf("+===========| Admin Menu |============+\n");
        printf("|_____________________________________|\n");
        printf("|    1. Add Student Details           |\n");
        printf("|    2. Show All Students             |\n");
        printf("|    3. Search Student                |\n");
        printf("|    4. Delete Student                |\n");
        printf("|    5. Add projects                  |\n");
        printf("|    6. Display Project Records       |\n");
        printf("|    7. Add Internship                |\n");
        printf("|    8. Display Intership Records     |\n");
        printf("|    9. Display All Subject Info      |\n");
        printf("|    10. Vision and Mission           |\n");
        printf("|    11. Contact Us                   |\n");
        printf("|    12. About Us                     |\n");
        printf("|    13. Modify Student Record        |\n");
        printf("|    14. Add College Fee              |\n");
        printf("|    15. Show College Fee             |\n");
        printf("|    16. Modify/Delete College Fee    |\n");
        printf("|    17. Send Message to Student      |\n");
        printf("|    18. Clear All Data               |\n");
		printf("|    19. Add Student Result           |\n");
		printf("|    20. Delete Student Result        |\n"); 
        printf("|    21. Exit                         |\n");
        printf("+-------------------------------------+\n");
        printf("\n|==> Enter your choice:-  ");
        scanf("%d", &choice);
        getchar();  // Handle newline input issue

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: addProject(); break;
            case 6: showProjects(); break;
            case 7: addInternship(); break;
            case 8: showInternships(); break;
            case 9: showSubject(); break;            
            case 10: visionMission(); break;
            case 11: contactUs(); break;
            case 12: aboutUs(); break;
            case 13: modifyStudentRecord(); break;
            case 14: addCollegeFee(); break;
            case 15: showCollegeFee(); break;
            case 16: modifyCollegeFee(); break;
            case 17: sendMessageToStudent(); break;
            case 18: clearAllData(); break; 
            case 19: addResult(); break;
            case 20: deleteResult(); break;
            case 21: printf("Exiting Program...\n"); saveData(); exit(0);
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
// Student menu function
void studentMenu() {
    int choice;
    while (1) {
        displayHeader();
        printf("\n");
        printf("+==========| Student Menu |===========+\n");
        printf("|_____________________________________|\n");
        printf("|    1. Show All Students             |\n");
        printf("|    2. Search Student                |\n");
        printf("|    3. Display Project Records       |\n");
        printf("|    4. Display Intership Records     |\n");
        printf("|    5. Display All Subject Info      |\n");
        printf("|    6. Vision and Mission            |\n");
        printf("|    7. Contact Us                    |\n");
        printf("|    8. About Us                      |\n");
        printf("|    9. Modify Student Record         |\n");
        printf("|    10. Show College Fee             |\n");
        printf("|    11. Modify/Delete College Fee    |\n");
        printf("|    12. Check Messages               |\n");
        printf("|    13. View Result                  |\n");
        printf("|    14. Exit                         |\n");
        printf("+-------------------------------------+\n");
        printf("\n|==> Enter your choice:-  ");
        scanf("%d", &choice);
        getchar();  // Handle newline input issue

        switch (choice) {
            case 1: showStudents(); break;
            case 2: searchStudent(); break;
            case 3: showProjects(); break;
            case 4: showInternships(); break;
            case 5: showSubject(); break;            
            case 6: visionMission(); break;
            case 7: contactUs(); break;
            case 8: aboutUs(); break;
            case 9: modifyStudentRecord(); break;
            case 10: showCollegeFee(); break;
            case 11: modifyCollegeFee(); break;
            case 12: checkMessages(); break;
            case 13: viewResult(); break;
            case 14: printf("Exiting Program...\n"); saveData(); exit(0);
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

// Function to clear all data
void clearAllData() {
    // Reset all counters
    studentCount = 0;
    projectCount = 0;
    internshipCount = 0;
    collegeFeeCount = 0;
    messageCount = 0;

    // Clear the data file
    if (remove("students.dat") == 0) {
        printf("All data cleared successfully!\n");
    } else {
        printf("No data file found or error deleting the file.\n");
    }

    system("pause");
}
// Send message to student
void sendMessageToStudent() {
    char regNo[11];
    char message[200];
    int found = 0;

    printf("Enter Student Registration Number: ");
    scanf("%s", regNo);
    getchar();

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].regNo, regNo) == 0) {
            found = 1;
            printf("Enter Message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';

            // Save the message
            strcpy(messages[messageCount].studentRegNo, regNo);
            strcpy(messages[messageCount].message, message);
            messageCount++;

            printf("Message sent successfully!\n");
            system("pause");
            return;
        }
    }

    if (!found) {
        printf("Student Not Found!\n");
        system("pause");
    }
}
// Check messages
void checkMessages() {
    char regNo[11];
    int found = 0;

    printf("Enter Your Registration Number: ");
    scanf("%s", regNo);
    getchar();

    for (int i = 0; i < messageCount; i++) {
        if (strcmp(messages[i].studentRegNo, regNo) == 0) {
            found = 1;
            printf("\nMessage: %s\n", messages[i].message);
        }
    }

    if (!found) {
        printf("No messages found!\n");
    }
    system("pause");
}
// Save data to file
void saveData() {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);
    fwrite(&projectCount, sizeof(int), 1, file);
    fwrite(projects, sizeof(Project), projectCount, file);
    fwrite(&internshipCount, sizeof(int), 1, file);
    fwrite(internships, sizeof(Internship), internshipCount, file);
    fwrite(&collegeFeeCount, sizeof(int), 1, file);
    fwrite(collegeFees, sizeof(CollegeFee), collegeFeeCount, file);
    fwrite(&messageCount, sizeof(int), 1, file);
    fwrite(messages, sizeof(Message), messageCount, file);
    fwrite(&resultCount, sizeof(int), 1, file);
    fwrite(results, sizeof(Result), resultCount, file);
    fclose(file);
}

// Load data from file
void loadData() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No existing data found. Starting with empty records.\n");
        return;
    }
    fread(&studentCount, sizeof(int), 1, file);
    fread(students, sizeof(Student), studentCount, file);
    fread(&projectCount, sizeof(int), 1, file);
    fread(projects, sizeof(Project), projectCount, file);
    fread(&internshipCount, sizeof(int), 1, file);
    fread(internships, sizeof(Internship), internshipCount, file);
    fread(&collegeFeeCount, sizeof(int), 1, file);
    fread(collegeFees, sizeof(CollegeFee), collegeFeeCount, file);
    fread(&messageCount, sizeof(int), 1, file);
    fread(messages, sizeof(Message), messageCount, file);
    fread(&resultCount, sizeof(int), 1, file);
    fread(results, sizeof(Result), resultCount, file);
    fclose(file);
}
//---------------
// Function to add student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    Student s;
    
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Registration Number (10 digits): ");
    validateRegNo(s.regNo);

    printf("Enter Parent's Name: ");
    getchar(); // Clear buffer
    fgets(s.parentName, sizeof(s.parentName), stdin);
    s.parentName[strcspn(s.parentName, "\n")] = '\0';

    printf("Enter Phone Number (10 digits): ");
    validatePhone(s.phone);

    printf("Enter Gender (Male/Female/Other): ");
    getchar(); // Clear buffer
    fgets(s.gender, sizeof(s.gender), stdin);
    s.gender[strcspn(s.gender, "\n")] = '\0';

    printf("Enter Email: ");
    validateEmail(s.email);

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';

    printf("Enter Performance (0-100): ");
    validatePercentage(&s.performance, "Performance");

    printf("Enter Attendance (0-100): ");
    validatePercentage(&s.attendance, "Attendance");

    printf("Enter Year of Study: ");
    scanf("%d", &s.year);
    getchar(); // Clear buffer

    printf("Enter Address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(s.department, sizeof(s.department), stdin);
    s.department[strcspn(s.department, "\n")] = '\0';

    printf("Enter Semester: ");
    scanf("%d", &s.semester);
    getchar(); // Clear buffer

    printf("Enter 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        fgets(s.subjects[i], sizeof(s.subjects[i]), stdin);
        s.subjects[i][strcspn(s.subjects[i], "\n")] = '\0';
    }

    students[studentCount++] = s;
    printf("\nStudent record added successfully!\n");
    saveData();
    system("pause");
}

// Function to show all student records in tabular format
void showStudents() {
    displayHeader();
    if (studentCount == 0) {
        printf("No records found!\n");
        system("pause");
        return;
    }

    // Print table header
    printf("=======================================================================================================================================\n");
    printf("| %-10s | %-15s | %-10s | %-8s | %-4s | %-10s | %-6s | %-10s | %-10s |\n",
           "Reg No", "Name", "Phone", "Course", "Year", "Dept.", "Sem.", "Perf.", "Attend.");
    printf("=======================================================================================================================================\n");

    // Print student records
    for (int i = 0; i < studentCount; i++) {
        printf("| %-10s | %-15s | %-10s | %-8s | %-4d | %-10s | %-6d | %-10.2f | %-10.2f |\n",
               students[i].regNo, students[i].name, students[i].phone, students[i].course, students[i].year,
               students[i].department, students[i].semester, students[i].performance, students[i].attendance);
    }

    // Print table footer
    printf("=======================================================================================================================================\n");

    system("pause");
}


// our function for searching
void searchStudent() {
    char regNo[11]; 
    int found = 0;

    printf("\nEnter Registration Number to Search: ");
    scanf("%s", regNo);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].regNo, regNo) == 0) {
            found = 1;
            printf("\n+===========================================================================================+\n");
            printf("| %-15s | %-10s | %-15s | %-10s | %-10s | %-25s |\n",
                   "Name", "Reg No", "Parent's Name", "Phone", "Gender", "Email");
            printf("+===========================================================================================+\n");
            printf("| %-15s | %-10s | %-15s | %-10s | %-10s | %-25s |\n",
                   students[i].name, students[i].regNo, students[i].parentName,
                   students[i].phone, students[i].gender, students[i].email);
            printf("+===========================================================================================+\n");

            printf("\n+============================================================================+\n");
            printf("| %-10s | %-10s | %-15s | %-10s | %-12s | %-12s |\n",
                   "Course", "Year", "Department", "Semester", "Performance", "Attendance");
            printf("+----------------------------------------------------------------------------+\n");
            printf("| %-10s | %-10d | %-15s | %-10d | %-12.2f | %-12.2f |\n",
                   students[i].course, students[i].year, students[i].department,
                   students[i].semester, students[i].performance, students[i].attendance);
            printf("+============================================================================+\n");

            printf("\n+-------------------------------+\n");
            printf("| Subjects Enrolled             |\n");
            printf("+-------------------------------+\n");
            for (int j = 0; j < 5; j++) {
                printf("| %-30s |\n", students[i].subjects[j]);
            }
            printf("+-------------------------------+\n");

            system("pause");
            return;
        }
    }
    if (!found) {
        printf("\nStudent Record Not Found!\n");
        system("pause");
    }
}

// Our Function to delete a student record
void deleteStudent() {
    char reg[11];
    printf("Enter Registration Number to Delete: ");
    scanf("%s", reg);
    getchar();

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].regNo, reg) == 0) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student record deleted successfully!\n");
            saveData();  // Save the updated data to the file
            system("pause");
            return;
        }
    }
    printf("Student Not Found!\n");
    system("pause");
}

// Function to add project details
void addProject(){
    if (projectCount >= MAX_PROJECTS) {
        printf("Project database is full!\n");
        return;
    }

    Project p;
    printf("Enter Student Registration Number: ");
    scanf("%s", p.studentRegNo);
    getchar();

    printf("Enter Project Year: ");
    scanf("%d", &p.year);
    getchar();

    printf("Enter Project Topic: ");
    fgets(p.topic, sizeof(p.topic), stdin);
    p.topic[strcspn(p.topic, "\n")] = '\0';

    printf("Enter Programming Language Used: ");
    fgets(p.language, sizeof(p.language), stdin);
    p.language[strcspn(p.language, "\n")] = '\0';

    projects[projectCount++] = p;
    printf("Project added successfully!\n");
    saveData();
}

// Function to display all projects
void showProjects(){
    if (projectCount == 0) {
        printf("No project records found!\n");
        system("pause");
        return;
        
    }

    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("| Reg No     | Project Year | Project Topic                     | Language Used               |\n");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < projectCount; i++) {
        printf("| %-10s | %-12d | %-30s | %-25s |\n",
               projects[i].studentRegNo, projects[i].year,
               projects[i].topic, projects[i].language);
    }

    printf("----------------------------------------------------------------------------------------------\n");
    system("pause");
}

// Function to add internship record
void addInternship(){
    if (internshipCount >= MAX_INTERNSHIPS) {
        printf("Internship database is full!\n");
        return;
        system("pause");
    }

    Internship i;
    printf("Enter Student Registration Number: ");
    scanf("%s", i.studentRegNo);
    getchar();

    printf("Enter Company Name: ");
    fgets(i.companyName, sizeof(i.companyName), stdin);
    i.companyName[strcspn(i.companyName, "\n")] = '\0';

    printf("Enter Position: ");
    fgets(i.position, sizeof(i.position), stdin);
    i.position[strcspn(i.position, "\n")] = '\0';

    printf("Enter Internship Duration (months): ");
    scanf("%d", &i.duration);
    getchar();

    internships[internshipCount++] = i;
    printf("Internship record added successfully!\n");
    saveData();
}

// Function to display all internships
void showInternships(){
    if (internshipCount == 0) {
        printf("No internship records found!\n");
        system("pause");
        
        return;
    }

    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("| Reg No     | Company Name                  | Position             | Duration (months) |\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < internshipCount; i++) {
        printf("| %-10s | %-30s | %-20s | %-17d |\n",
               internships[i].studentRegNo, internships[i].companyName,
               internships[i].position, internships[i].duration);
    }

    printf("---------------------------------------------------------------------------------------------\n");
    system("pause");
}
//displaying all subjects with credits
void showSubject() {
    printf("--------------------------------------------------------------\n");
    printf("| %-43s | %-6s |\n", "Subject Name", "Credit");
    printf("--------------------------------------------------------------\n");
    printf("| %-43s | %-6d |\n", "Industrial PLC (SDE23714)", 2);
    printf("| %-43s | %-6d |\n", "SCADA & DCS (SDE23718)", 2);
    printf("| %-43s | %-6d |\n", "Factory Automation with PLC & HMI", 2);
    printf("| %-43s | %-6s |\n", "(SDE23747)", " ");
    printf("| %-43s | %-6d |\n", "Embedded Systems & Robotics (SDE23755)", 2);
    printf("| %-43s | %-6d |\n", "UX Design (SDE23761)", 2);
    printf("| %-43s | %-6d |\n", "Programming using C++ (CSE21303)", 2);
    printf("| %-43s | %-6d |\n", "Computer Organization (CSE21308)", 3);
    printf("| %-43s | %-6d |\n", "Theory of Computation (CSE21310)", 3);
    printf("| %-43s | %-6d |\n", "Programming for Problem Solving", 4);
    printf("| %-43s | %-6s |\n", "(CSE23201)", " ");
    printf("| %-43s | %-6d |\n", "Data Structures (CSE23304)", 5);
    printf("| %-43s | %-6d |\n", "Data Communication & Computer Network", 5);
    printf("| %-43s | %-6s |\n", "(CSE23305)", " ");
    printf("| %-43s | %-6d |\n", "Database Engineering (CSE23306S)", 5);
    printf("| %-43s | %-6d |\n", "Design & Analysis of Algorithm", 5);
    printf("| %-43s | %-6s |\n", "(CSE23307S)", " ");
    printf("| %-43s | %-6d |\n", "Object Oriented Programming using Java", 5);
    printf("| %-43s | %-6s |\n", "(CSE23309S)", " ");
    printf("| %-43s | %-6d |\n", "Operating System (CSE23312)", 5);
    printf("| %-43s | %-6d |\n", "Machine Learning (CSE23317)", 5);
    printf("| %-43s | %-6d |\n", "Design of Web Applications (CSE23349)", 5);
    printf("| %-43s | %-6d |\n", "Internet of Things (CSE23421)", 5);
    printf("--------------------------------------------------------------\n");
    system("pause");
}

// Vision and Mission function
void visionMission() {
    displayHeader();
        printf("========================================================================================\n");
    printf("| %-40s | %-40s |\n", "VISION", "MISSION");
    printf("========================================================================================\n");
    printf("| %-40s | %-40s |\n", 
           "To emerge as a global leader", 
           "To provide state-of-art technical");
    printf("| %-40s | %-40s |\n", 
           "in the arena of technical education", 
           "education in the undergraduate");
    printf("| %-40s | %-40s |\n", 
           "commensurate with the dynamic", 
           "and postgraduate levels.");
    printf("| %-40s | %-40s |\n", 
           "global scenario for the benefit", 
           "To work collaboratively with");
    printf("| %-40s | %-40s |\n", 
           "of mankind.", 
           "technical institutes/universities");
    printf("| %-40s | %-40s |\n", 
           "", 
           "/ industries of national and");
    printf("| %-40s | %-40s |\n", 
           "", 
           "international repute.");
    printf("| %-40s | %-40s |\n", 
           "", 
           "To keep abreast with latest");
    printf("| %-40s | %-40s |\n", 
           "", 
           "technological advancements.");
    printf("| %-40s | %-40s |\n", 
           "", 
           "To enhance the research and");
    printf("| %-40s | %-40s |\n", 
           "", 
           "development activities.");
    printf("========================================================================================\n");

    system("pause");
}
//contact Us function
void contactUs() {
    displayHeader();
    printf("Contact Us\n");
    printf("Bhubaneswar - 752054\n");
    printf("+91 9040272733 / +91 9040272755\n");
    printf("+91-674-663 6555 (Admission)\n");
    printf("9040021102 (Admission)\n");
    printf("info@cgu-odisha.ac.in\n");
    printf("admission@cgu-odisha.ac.in\n");
    system("pause");
}
// About Us function
void aboutUs() {
    displayHeader();
    printf("==== About Us ====\n\n");
    printf("Established in accordance with the Odisha Act 01 of 2020, C. V. Raman Global University, Odisha\n");
    printf("(CGU, Odisha) introduces students to new and innovative ways of learning. It is a vibrant community\n");
    printf("of students, faculty, and staff members committed to making a difference in society by leading with\n");
    printf("innovation and purpose.\n\n");
    printf("We take pride in our ethos and collaborative culture that foster intellectual engagement and growth.\n");
    printf("At CGU, Odisha, students learn to challenge the status quo and solve the most difficult problems\n");
    printf("with analytical rigor and creativity. We continue to add interdisciplinary courses to our existing\n");
    printf("portfolio to offer a truly global education in the field of science and technology.\n");

    printf("__________________________________________________________________________________________________________\n\n");
    
    printf("===== Evolution of leadership ==== \n\n ");
    printf("CGU, Odisha rests on the legacy and leadership of C.V. Raman College of Engineering (CVRCE)\n");
    printf("which began its transformative journey in 1997. It grew in record time imparting technical\n");
    printf("education with a larger purpose and impact through world-class laboratories, research-intensive\n");
    printf("learning pedagogy, unmatched Centres of Excellence and unhindered connectivity to some of the\n");
    printf("finest libraries in the world.\n\n");
    printf("CGU, Odisha imbibes the same institutional values of CVRCE and aims to offer a dynamic learning\n");
    printf("environment to students through its responsive support system, robust infrastructure and global\n");
    printf("exposure (enabled via international seminars, conferences and workshops.) Committed to offering\n");
    printf("quality education to all, it aims to push the frontiers of knowledge with cutting-edge research,\n");
    printf("innovation and unconventional thinking.\n");
    system("pause");
}
void modifyStudentRecord() {
    char regNo[11];
    printf("Enter Registration Number to Modify: ");
    scanf("%s", regNo);
    getchar();

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].regNo, regNo) == 0) {
            printf("Enter New Name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter New Phone Number (10 digits): ");
            validatePhone(students[i].phone);

            printf("Enter New Email: ");
            validateEmail(students[i].email);

            printf("Enter New Performance (0-100): ");
            validatePercentage(&students[i].performance, "Performance");

            printf("Enter New Attendance (0-100): ");
            validatePercentage(&students[i].attendance, "Attendance");

            printf("Student record modified successfully!\n");
            saveData(); // Save changes to file
            system("pause");
            return;
        }
    }
    printf("Student Not Found!\n");
    system("pause");
}
void addCollegeFee() {
    if (collegeFeeCount >= MAX_STUDENTS) {
        printf("Fee database is full!\n");
        return;
    }

    CollegeFee fee;
    printf("Enter Student Registration Number: ");
    scanf("%s", fee.studentRegNo);
    getchar();

    printf("Enter Student Name: ");
    fgets(fee.studentName, sizeof(fee.studentName), stdin);
    fee.studentName[strcspn(fee.studentName, "\n")] = '\0';

    printf("Enter Course: ");
    fgets(fee.course, sizeof(fee.course), stdin);
    fee.course[strcspn(fee.course, "\n")] = '\0';

    printf("Enter Year: ");
    scanf("%d", &fee.year);
    getchar();

    printf("Enter Course Fee: ");
    scanf("%f", &fee.courseFee);

    printf("Enter Paid Amount: ");
    scanf("%f", &fee.paidAmount);

    fee.remainingAmount = fee.courseFee - fee.paidAmount;

    collegeFees[collegeFeeCount++] = fee;
    printf("College fee record added successfully!\n");
    saveData(); // Save changes to file
    system("pause");
}
void showCollegeFee() {
    if (collegeFeeCount == 0) {
        printf("No fee records found!\n");
        system("pause");
        return;
    }

    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("| Reg No     | Student Name        | Course        | Year | Course Fee | Paid Amount | Remaining |\n");
    printf("----------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < collegeFeeCount; i++) {
        printf("| %-10s | %-18s | %-13s | %-4d | %-10.2f | %-11.2f | %-9.2f |\n",
               collegeFees[i].studentRegNo, collegeFees[i].studentName,
               collegeFees[i].course, collegeFees[i].year, collegeFees[i].courseFee,
               collegeFees[i].paidAmount, collegeFees[i].remainingAmount);
    }

    printf("----------------------------------------------------------------------------------------------\n");
    system("pause");
}
void modifyCollegeFee() {
    char regNo[11];
    int choice;
    printf("Enter Registration Number to Modify/Delete Fee: ");
    scanf("%s", regNo);
    getchar();

    for (int i = 0; i < collegeFeeCount; i++) {
        if (strcmp(collegeFees[i].studentRegNo, regNo) == 0) {
            printf("1. Modify Fee\n");
            printf("2. Delete Fee\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar();

            switch (choice) {
                case 1: {
                    printf("Enter New Paid Amount: ");
                    scanf("%f", &collegeFees[i].paidAmount);

                    collegeFees[i].remainingAmount = collegeFees[i].courseFee - collegeFees[i].paidAmount;

                    printf("College fee record modified successfully!\n");
                    saveData(); // Save changes to file
                    system("pause");
                    return;
                }
                case 2: {
                    for (int j = i; j < collegeFeeCount - 1; j++) {
                        collegeFees[j] = collegeFees[j + 1];
                    }
                    collegeFeeCount--;
                    printf("College fee record deleted successfully!\n");
                    saveData(); // Save changes to file
                    system("pause");
                    return;
                }
                default: {
                    printf("Invalid choice!\n");
                    system("pause");
                    return;
                }
            }
        }
    }
    printf("Fee Record Not Found!\n");
    system("pause");
}
//-------------------------------
// Validate phone number
void validatePhone(char *phone) {
    while (1) {
        scanf("%s", phone);
        if (strlen(phone) == 10) break;
        printf("Invalid! Enter a 10-digit phone number: ");
    }
}

// Validate registration number
void validateRegNo(char *regNo) {
    while (1) {
        scanf("%s", regNo);
        if (strlen(regNo) == 10) break;
        printf("Invalid! Enter a 10-digit registration number: ");
    }
}

// Validate percentage
void validatePercentage(float *value, char *field) {
    while (1) {
        scanf("%f", value);
        if (*value >= 0 && *value <= 100) break;
        printf("Invalid! Enter %s (0-100): ", field);
    }
}

// Validate email format
bool isValidEmailFormat(const char *email) {
    int atCount = 0, dotCount = 0;
    int atIndex = -1, dotIndex = -1;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            atIndex = i;
        } else if (email[i] == '.') {
            dotCount++;
            dotIndex = i;
        }
    }

    if (atCount != 1 || dotCount < 1) return false;
    if (atIndex == 0 || dotIndex == 0 || dotIndex == strlen(email) - 1) return false;
    if (dotIndex < atIndex) return false;

    return true;
}

void validateEmail(char *email) {
    while (1) {
        printf("Enter Email (format: abc12@gmail.com): ");
        fgets(email, 50, stdin);
        email[strcspn(email, "\n")] = '\0';

        if (isValidEmailFormat(email)) {
            break;
        } else {
            printf("Invalid email format! Please enter a valid email.\n");
        }
    }
}
