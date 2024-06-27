/***********
 * Advanced Attendance Calculator
 * In this Program we will calculate the attendance of a student in each subject.
 * We will take the total number of classes conducted and the number of classes attended by the student as input.
 * We will then calculate the attendance percentage of the student in each subject.
 * We will then display the attendance percentage of the student in each subject.
 * The file will be saved as "___attendance.txt" and where ___ is replaced with roll number of the student.
 * Author : G. Venkata Sai Ram
 **********/

#include <bits/stdc++.h>
using namespace std;

string roll_number;
int total_courses_opted;

class AdvancedAttendanceCalculator {
private:
    int total_courses_opted; //total number of courses opted by the student
    map<string, pair<pair<int,int>,bool>> attendance; //map to store the attendance details of each course

public:
    AdvancedAttendanceCalculator() {
        //initialize the total courses opted to 0
        total_courses_opted = 0;
        //create a file to store the attendance details
        ifstream file;
        file.open(roll_number+"attendance.txt");
        read_file();
        file.close();
    }

    //parameterized constructor to initialize the total courses opted
    AdvancedAttendanceCalculator(int total_courses_opted) {
        this->total_courses_opted = total_courses_opted;
    }
    
    //takes content in file to store in map
    void read_file() {
        ifstream file;
        file.open(roll_number+"attendance.txt");
        string course_name;
        int total_classes_conducted, classes_attended;
        bool is_honors;
        while(file >> course_name >> classes_attended >> total_classes_conducted >> is_honors) 
            attendance[course_name] = {{classes_attended, total_classes_conducted}, is_honors};
        file.close();
    }

    //function to input the attendance details of each course and alternativlely update in file
    void input() {
        //if file is not empty then prompt to use update function
        ifstream check_file(roll_number + "attendance.txt");
        if(check_file.peek() != ifstream::traits_type::eof()) {
            cout << "Attendance details found, please use the update function\n";
            check_file.close();
            return;
        }
        ofstream file;
        file.open(roll_number+"attendance.txt", ios::app);
        cout << "Enter the total number of courses opted: ";
        cin >> total_courses_opted;
        for(int i=0; i<total_courses_opted; i++) {
            string course_name;
            int total_classes_conducted, classes_attended;
            bool is_honors;
            cout << "Enter the course name(without space): ";
            cin >> course_name;
            if(attendance.find(course_name) != attendance.end()) {
                cout << "Course already exists, please update the attendance details\n";
                return;
            }
            input_lol:
            cout << "Enter the total classes conducted: ";
            cin >> total_classes_conducted;
            cout << "Enter the classes attended: ";
            cin >> classes_attended;
            if(classes_attended > total_classes_conducted) {
                cout << "Classes attended cannot be greater than total classes conducted\n";
                goto input_lol;
            }
            cout << "Is Honors? (1/0): ";
            cin >> is_honors;
            attendance[course_name] = {{classes_attended, total_classes_conducted}, is_honors};
            file << course_name << " " << classes_attended << " " << total_classes_conducted << " " << is_honors << "\n";
        }
        file.close();
    }

    //function to update the attendance details of each course and alternativlely update in file no need to update honors
    void update() {
        ifstream check_file(roll_number + "attendance.txt");
        // Check if the file is empty
        if(check_file.peek() == ifstream::traits_type::eof()) {
            cout << "No attendance details found, please input the attendance details\n";
            input(); // Ensure input() function is defined and correctly updates the attendance
            return;
        }
        check_file.close(); // Close the ifstream after checking

        // Read the attendance details from the file
        ofstream file(roll_number + "attendance.txt", ios::out); // Open in overwrite mode, use ios::app for append mode
        for(auto it = attendance.begin(); it != attendance.end(); ++it) {
            //this below inputs taken are used to add it to previous attendance details
            string course_name = it->first;
            int total_classes_conducted, classes_attended;
            bool is_honors;
            cout << "Enter the total classes conducted for " << course_name << ": ";
            cin >> total_classes_conducted;
            cout << "Enter the classes attended for " << course_name << ": ";
            cin >> classes_attended;
            if(classes_attended > total_classes_conducted) {
                cout << "Classes attended cannot be greater than total classes conducted\n";
                return;
            }
            //add it to previous values
            attendance[course_name].first.first += classes_attended;
            attendance[course_name].first.second += total_classes_conducted;
            is_honors = attendance[course_name].second;

            // Write updated values to file
            file << course_name << " " << attendance[course_name].first.first << " " << attendance[course_name].first.second << " " << is_honors << "\n";
        }
        file.close();
    }

    //function to add a new course to the attendance details
    void add_course() {
        ofstream file;
        file.open(roll_number+"attendance.txt", ios::app);
        string course_name;
        int total_classes_conducted, classes_attended;
        bool is_honors;
        cout << "Enter the course name(Without space): ";
        cin >> course_name;
        if(attendance.find(course_name) != attendance.end()) {
            cout << "Course already exists, please update the attendance details\n";
            return;
        }
        add_course_lol:
        cout << "Enter the total classes conducted: ";
        cin >> total_classes_conducted;
        cout << "Enter the classes attended: ";
        cin >> classes_attended;
        if(classes_attended > total_classes_conducted) {
            cout << "Classes attended cannot be greater than total classes conducted\n";
            goto add_course_lol;
        }
        cout << "Is Honors? (1/0): ";
        cin >> is_honors;
        attendance[course_name] = {{classes_attended, total_classes_conducted}, is_honors};
        file << course_name << " " << classes_attended << " " << total_classes_conducted << " " << is_honors << "\n";
        file.close();
    }

    //function to display the attendance in table format with detailed attended and total classes from the file
    void display() {
        ifstream file;
        file.open( roll_number+"attendance.txt");
        if(file.peek() == ifstream::traits_type::eof()) {
            cout << "No attendance details found, please input the attendance details\n";
            return;
        }
        string course_name;
        int total_classes_conducted, classes_attended;
        bool is_honors;
        cout << "Course Name\tAttended\tTotal Classes\tAttendance Percentage\tIs Honors\n";
        while(file >> course_name >> classes_attended >> total_classes_conducted >> is_honors) 
            cout << course_name << "\t\t" << classes_attended << "\t\t" << total_classes_conducted << "\t\t" << (classes_attended*100.0)/total_classes_conducted << "%\t\t\t" << is_honors << "\n";
    }

    //function to display the attendance percentage of each course
    void display_attendance_percentage() {
        //display the total attendance percentage and the honors attendance percentage separately where honors attendance percentage is not included in the total attendance percentage
        ifstream file;
        file.open( roll_number+"attendance.txt");
        if(file.peek() == ifstream::traits_type::eof()) {
            cout << "No attendance details found, please input the attendance details\n";
            return;
        }
        string course_name;
        int ftotal_classes_conducted, fclasses_attended;
        bool fis_honors;
        double total_attendance = 0, total_honors_attendance = 0;
        int total_classes = 0, total_honors_classes = 0;
        int total_classes_attended = 0, total_honors_classes_attended = 0;
        while(file >> course_name >> fclasses_attended >> ftotal_classes_conducted >> fis_honors) {
            if(fis_honors) {
                total_honors_classes += ftotal_classes_conducted;
                total_honors_classes_attended += fclasses_attended;
            }else {
                total_classes += ftotal_classes_conducted;
                total_classes_attended += fclasses_attended;
            }
        }
        if(total_classes > 0) {
            total_attendance = (total_classes_attended * 100.0) / total_classes;
        } else {
            total_attendance = 0; // Or handle this case as needed
        }

        if(total_honors_classes > 0) {
            total_honors_attendance = (total_honors_classes_attended * 100.0) / total_honors_classes;
        } else {
            total_honors_attendance = 0; // Or handle this case as needed
        }
        cout << "Total Attendance Percentage: " << total_attendance << "%\n";
        cout << "Total Honors Attendance Percentage: " << total_honors_attendance << "%\n";
        file.close();
    }
    
    //function to reset the attendance details of each course
    void reset() {
        ofstream file;
        file.open(roll_number+"attendance.txt");
        file.close();
    }

};

int main(){
    cout << "Enter the Roll Number: ";
    cin >> roll_number;
    int choice;
    do
    {
        cout << "------------------------Advanced Attendance Calculator------------------------\n";
        cout << "1. Update Roll Number you want to work on\n";
        cout << "2. Input the Attendance Details\n";
        cout << "3. Add New Course\n";
        cout << "4. Update the Attendance Details\n";
        cout << "5. Display the Attendance Details\n";
        cout << "6. Display the Attendance Percentage\n";
        cout << "98. Reset the Attendance Details\n";
        cout << "99. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        AdvancedAttendanceCalculator obj;
        switch (choice)
        {
        case 1:
            cout << "Enter the Roll Number: ";
            cin >> roll_number;
            break;
        case 2:
            obj.input();
            break;
        case 3:
            obj.add_course();
            break;
        case 4:
            obj.update();
            break;
        case 5:
            cout << "------------------------Attendance Details------------------------\n";
            obj.display();
            break;
        case 6:
            cout << "------------------------Attendance Percentage------------------------\n";
            obj.display_attendance_percentage();
            break;
        case 98:
            obj.reset();
            break;
        case 99:
            cout << "Thanks for using the Advanced Attendance Calculator - GVSR, Exiting...\n";
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    } while (choice != 99);

    return 0;
}