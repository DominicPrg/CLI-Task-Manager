# Week 1

### Day 1 - 6/6/2025 - Getting Setup
What I accomplished: 
- Wrote an initial READ.md file with the goals and features tailored to this project.
- Created a developerlog.md file to track and share progress
- Outlined core task features (add, list, complete, delete)
- Practiced utilizng the basic features of GitHub

What I learned: 
- How to download Git
- How to create a cloned repository onto my desktop directory
- How to create a folder on a GitHub repository

What issues that I stumbled upon:
- Creating a C++ project on GitHub
- Familiarizing myself with actually linking the JSON library to this repository and project.


How I solved/plan to solve the issue:
- I could write down my C++ code onto VS and then once I figure out a more effective way to move my code onto this platform, I could do copy-and-paste my code onto here.
- Since I'm not emphasizing the JSON library this week, I can wait until next week to concern myself with linking it to this project.

### Day 2 - 6/7/2025 - Creating Task and TaskManager Classes
What I accomplished:
- Created the actual VS Code project for this project.
- Created the Task and TaskManager classes for the program.
- Created a skeleton outline of the two classes based on the suggestion from ChatGPT, including both member variables and functions (Cautionary note: I won't rely on ChatGPT to actually implement the code for the function members. That's where I'll showcase my knowledge and application.)
- Created constant data values for the member variables of class Task.
- Implemented the code for the parameterized constructor, default constructor, display(), toggleComplete(), and getStatus() functions for class Task.

What I learned:
- How to create a C++ project on VS Code (I've always used VS Studio for programming purposes).
- How to to link the repository for this project on my desktop to VS Code.

What issues that I stumbled upon:
- Creating a C++ project on VS Code, since I've never used VS Code for C++ purposes in the past
- Debugging the code on a driver program since the debugger can't access the project on my directory.

How I solved/plan to solve the issue:
- I installed a C++ compiler and extensions just to be safe. I also Google'd how to create a C++ project on VS Code. I solved this issue successfully.
- I'll have to figure out what exactly is missing between the IDE and VS Code itself to fail in debugging my code. I'll have to use Google and identify if I overlooked an important step while setting up the programming environment.

### Day 3 - 6/8/2025 - addTask() and displayTasks() Functions
What I accomplished: 
- Implemented the addTask() and displayTasks() functions of class TaskManager.
- Ensured that each Task object is stored in a vector named tasks in TaskManager.

What I learned:
- Nothing new. I have a lot of experience with implementing the code for classes, so the current work I did for today was straightforward and nothing suprising.

What issues that I stumbled upon:
- Same as yesterday: debugging the code on a driver program since the debugger can't access the project on my directory. More specifically, the files won't appear in the project folder when opening the project folder through VS Code itself, and it seems like the "cwd" of the launch.json file can't access the files that I specify.

How I solved/plan to solve the issue:
- I'm looking at the common problems for why the files won't appear in the project folder when accessing through VS Code itself, as provided by Google Overview AI. Until then, I'm writing and debugging all of my code on a VS Studio project as an alternative. If I can't resolve the debugging issue that I'm experiencing with VS Code, I'll need to figure out how to transfer the nlohmann/json library to VS Studio since I downloaded the nlohmann/json library from GitHub (which connects to VS Code for programming).

### Day 4 - 6/9/2025 - CLI Outputting and Formatting
What I accomplished:
- Completed the design for the formatting of Task objects in the displayTasks() function of TaskManager. When polishing my project during the final week, I'll look into using the iomanip library to potentially assist with cleaner formatting.

What I learned:
- I learned how to implement the ASCII color features in my C++ code to distinguish certain texts of the output apart from each other. I was completely unaware of this feature in C++.

What issues that I stumbled upon:
- None significant. The VS Code issue remains unresolved, but I didn't tinker with it today.

How I solved/plan to solve the issue:
- No significant issues occurred today. As for the VS Code issue, I should refer to advice from yesterday.

### Day 5 - 6/10/2025 - completeTask() and deleteTask()
What I accomplished:
- Implemented the code for the completeTask() function and deleteTask() functions. I haven't thoroughly tested each function yet, however.
- Added a custom exception class named DeleteNonexistentTaskError{} for dealing with input of invalid ID's.

What I learned:
- I re-learned how to create a simple custom exception class for handling exceptions.

What issues that I stumbled upon:
- It had been a while since I've programmed a custom exception class, so I was somewhat uncertain of how to move further with the information that I could remember at the time.
- Accessing the elements of the vector of Task objects properly based on the Task's ID. For example, the first task in the 'tasks' vector is set to 1 by default, but accessing the element of the first Task object through the 'tasks' vector would consist of doing so through 'tasks.at(0)'. Essentially, assuming that the first element Task object's ID is always initialized with 1, then the Task object's ID is equivalent to the element 1 number below it.
- Debugger encounterd an unreferenced local variable while catching a DeleteNonexistentTaskError object.

How I solved/plan to solve the issue:
- I did some Googling and reread through an example of a custom exception class from COMS-215.
- I simply needed to take a step back and process the equivalency between the Task object's ID and position as a vector element. More often that not, my mind can unncessarily amplify the intricacy of a problem if it's not putting the matter at full attention, which is what occured. Practicing mindfulness, though, is a rather beneficial remedy for instances like this.
- This issue was encounterd towards the end of the programming session, so I won't know for certain until my next session or afterwards.

### Day 6 - 6/11/2025 - Refining Code
What I accomplished:
- Created a printCommands() function to display the available commands for the program in the TaskManager class.
- Separated the implementation of class Task's code in the header file into a separate implementation file.
- Created the client file where the main program will operate for the user. This client file consists of two user-defined functions to simulate the task managing environment: runProgram() and processInput(). A short message is outputted towards the user where they have the option to type into the terminal the following commands: "help", "add", "delete", and "list". Once they've finished their business, they can type "exit" to close the program.

What I learned:
- I re-learned the properties of using constant values in classes. They can be rather tricky at first to implement on my own.
- I learned a little bit more about the error of passing an unreferenced local variable as an argument.

What issues that I stumbled upon:
- Initially, the debugger encountered an unreferenced local variable while catching a DeleteNonexistentTaskErrorObject (the issue that I encountered towards the conclusion of my previous coding session).
- Constants in user-defined classes can be quite tricky to deal with, which was one of the primary challenges that I faced today. For example, in my Task class, I originally had constant values for each of the data members for the default constructor. However, defining the constants in the class declaration of the header file (as I vaguley remembered from the past) leads to runtime errors if not written in a correct manner. I attempted declaring them in the header file and then initializng them with a value in the Task.cpp implementation file. However, my efforts didn't amount to the level of knowledge that I had at that point.
- In my client program, I accidentally overlooked the fact that I passed my TaskManager object by value (instead of by reference) in the parameter of the processInput() function, leading to unintended output when testing the program.

How I solved/plan to solve the issue:
- I simply had to remove the variable aspect of the argument in the catch block. For example, instead of "const DeleteNonexistTaskError& e" as the argument, I removed the 'e' and the argument then became "const DeleteNonexistTaskError&".
- I decided to refrain from utilizing any default constant values, instead opting to initialize the data members to their respective default values in the default constructor.
- I changed to passing the TaskManager object by reference for the processInput() function.

### Day 7 - 6/12/2025 - First Weekly Summary
What I've done this week:
- I finalized my SMART goal and 3-week project timeline.
- I defined core features of the program.
- I chose C++ and the nlohmann/json library for data storage.
- I designed the initital class structures for Task and TaskManager.
- I outlined expected CLI input/output format. Although, it's not polished, but I'll add the final touches during the third week of this project's timeline, which is reserved for polishing the program.
- I created the necessary program files (Task.h, Task.cpp, TaskManager.h, and main.cpp).

What I've learned this week:
- How to plan a project from scratch using SMART goals.
- How to break down abstract features into clear specifications that can be performed by the client user.
- Importance of documenting my thought process early.

Reflection: This week demonstrated the value of clear structure of a program before dividing it into code. I've come to realize that I can work more productively if I've visualized the stage of programming for each part of the software. It was satisfying being able to code and implement the functions for a Task object in TaskManager, since I was handling instructions on how to operate said custom objects. It helped to illuminate the power of object-oriented programming.

# Week 2 

### Day 8 - Learn JSON + Setup Library
What I accomplished:
- Successfully integrated the nlohmann/json library into my project.
- Tested creating an object of JSON to familiarize myself with the class.

What I learned:
- I learned what JSON (short for JavaScript Object Notation) is defined as: it's a lightweight data-interchange. It's indepedent of any programming language, but its conventions draw strong similiarites to the C family of languages (C, C++, C#, Java, etc.).
- I learned some basic features of the nlohmann/json library.
- I learned that I could copy-and-paste the "json.hpp" file, available on the GitHub nlohmann/json repository, into my VS Studio to run the code on that platform.

What issues that I stumbled upon:
- For VS Code, I tried following the instructions on the official VS Code webpage (https://code.visualstudio.com/docs/languages/cpp) to restart the process for running C++ successfully on the platform. However, when I installed MinGw-x64 for Windows and tried installig the tool chain in a terminal, I was met with an error that stated that the program couldn't lock the database. I haven't been able to overcome this blockade since.
- Initially, I endured great difficulty trying to read and understand all of the code, examples, and tutorials posted on the GitHub nlohmann/json library repository webpage. This is because I wasn't able to understand the majority of the code displayed at my current C++ proramming level.
- It was challenging trying to connect the nlohmann/json library to my VS Studio project, as I was bemused on how to approach doing so. 

How I solved/plan to solve the issue:
- For the MinGw-x64 tool chain blockade, I'm not entirely certain of what my next steps will be. I did follow the instructions on the webpage, so the error's origins can be assumed to pertain to my PC, rather than the software itself. I'll have to conduct some exploration to what said origins can be, but I don't have any ideas at the moment.
- For the uncertainity towards the advanced code, a lot of the misunderstanding can be attributed to being unaware of advanced programming techniques and concepts, which will take more time and learning to embrace. If I continue to consume more C++ content through books and other sources of media, I'll eventually reach such a stage.
- In order to connect the nlohmann/json library to my VS Studio project, after some brainstorming and reviewing my options, I concluded with copying-and-pasting the contents of the 'json.hpp' file into a header file for my VS Studio project.
