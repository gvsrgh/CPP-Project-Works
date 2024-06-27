---

# Advanced Attendance Calculator

The Advanced Attendance Calculator is a C++ program designed to calculate and manage student attendance across multiple courses. It takes the total number of classes conducted and the number of classes attended by the student as input, calculates the attendance percentage for each course, and displays the results. The attendance data is saved to a file named `___attendance.txt`, where `___` is replaced with the student's roll number.

## Features

- **Input Attendance Details:** Enter the total number of courses, classes conducted, and classes attended for each course.
- **Add New Course:** Add a new course to the existing attendance records.
- **Update Attendance Details:** Update the attendance details of existing courses.
- **Display Attendance Details:** Display the attendance details in a table format, showing the course name, classes attended, total classes conducted, attendance percentage, and whether the course is an honors course.
- **Display Attendance Percentage:** Display the total attendance percentage and the honors attendance percentage separately.
- **Reset Attendance Details:** Reset all attendance details for the current roll number.
- **Save Data to File:** Save the attendance details to a file for persistent storage.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++)
- Standard Template Library (STL) support

### Installation

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/your-repo/advanced-attendance-calculator.git
   ```

2. **Navigate to the Project Directory:**
   ```sh
   cd advanced-attendance-calculator
   ```

3. **Compile the Program:**
   ```sh
   g++ -o attendance_calculator attendance_calculator.cpp
   ```

### Usage

1. **Run the Program:**
   ```sh
   ./attendance_calculator
   ```

2. **Follow the On-Screen Prompts:**
   - Enter the roll number of the student.
   - Choose from the menu options to input, update, display, or reset attendance details.

### Menu Options

- **1. Update Roll Number you want to work on:** Enter the roll number to manage attendance for a different student.
- **2. Input the Attendance Details:** Enter the total number of courses, and for each course, enter the course name, total classes conducted, classes attended, and whether it's an honors course.
- **3. Add New Course:** Add a new course to the attendance records by entering the course name, total classes conducted, classes attended, and whether it's an honors course.
- **4. Update the Attendance Details:** Update the attendance details for existing courses.
- **5. Display the Attendance Details:** Display the attendance details in a table format.
- **6. Display the Attendance Percentage:** Display the total and honors attendance percentages.
- **98. Reset the Attendance Details:** Reset all attendance details for the current roll number.
- **99. Exit:** Exit the program.

### Example

```sh
Enter the Roll Number: 12345
------------------------Advanced Attendance Calculator------------------------
1. Update Roll Number you want to work on
2. Input the Attendance Details
3. Add New Course
4. Update the Attendance Details
5. Display the Attendance Details
6. Display the Attendance Percentage
98. Reset the Attendance Details
99. Exit
Enter your choice: 2
Enter the total number of courses opted: 3
Enter the course name(without space): Math101
Enter the total classes conducted: 30
Enter the classes attended: 28
Is Honors? (1/0): 0
...
```

## Author

G. Venkata Sai Ram

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspiration from real-world attendance management systems.
- Contributions and feedback from peers and mentors.

---
