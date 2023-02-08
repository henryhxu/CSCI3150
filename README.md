# CSCI3150 Intro to Operating Systems, Spring 2023

## Administrivia

### Schedule
- Lectures: 
  * Wed 2:30pm – 4:15pm, MMW LT1 
  * Thu 11:30am – 12:15pm, MMW LT1 
- Tutorials:
  * Thu 2:30pm – 3:15pm, SHB 904 
  * Thu 5:30pm – 6:15pm, SHB 123

### Team
| Member | Role | Office Hours |
| :---------------- | :--- | :----------- |
| [Xu, Hong (Henry)](https://henryhxu.github.io/) | Prof | Mon 3-5 pm, SHB 914. **By appointments only.** |
| [Wu, Shaofeng](mailto:sfwu22@cse.cuhk.edu.hk) | Head TA | Mon 3-5 pm, SHB 117. |
| [Tan, Xin](mailto:xtan22@cse.cuhk.edu.hk) | TA | Mon 3-5 pm, SHB 117. |
| [Luo, Qin](mailto:qluo22@cse.cuhk.edu.hk) | TA | Tue 1-3 pm, SHB 913. |

### Piazza
The Piazza page for this course is [here](https://piazza.com/cuhk.edu.hk/spring2023/csci3150).
All communication about this course is done over Piazza. This includes questions, discussions, announcements, as well as private messages. 
The self-signup code is "3150 rocks!".

## Course outline

This course discusses the principles in the design and implementation of operating systems (OS). Main topics include: OS concepts and abstractions, process management, memory management, file systems, and virtualization.

### Textbook (optional)
The course materials are partly based upon the following classic textbook:
- Operating Systems: Three Easy Pieces, Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau
- The book is free online: http://pages.cs.wisc.edu/~remzi/OSTEP/ 

### Grading
| Assessment item | CSCI Weight 
| :---------------- | :--- | 
| Assignments | 50% | 
| Lab quizzes* | 10% |
| Final Exam | 40% | 

\*: To encourage tutorial participation, quiz or simple programming task will be conducted at the tutorials randomly. We will randomly pick 5 tutorials and perform this at the end of the tutorial. Each quiz/programming task is worth one mark. There will also be a midterm written quiz worth 5 marks; the date will be announced in a later time.

## Schedules
Click on the topic to access the slides. 

### Lectures
| Week | Wed Lecture | Thu Lecture | PDF version | Optional readings |
| :-----------: | :-----------------: |  :------------: | :------------: | :------------: |
| 1 | [Intro](lecture/lec1_intro.pptx), [Arch support](lecture/lec2_arch.pptx) | [Arch support](lecture/lec2_arch.pptx) | [lec1](lecture/lec1_intro.pdf), [lec2](lecture/lec2_arch.pdf)
| 2 | [Processes](lecture/lec3_processes.pptx) | [Processes](lecture/lec3_processes.pptx) | [lec3](lecture/lec3_processes.pdf) | [A fork() in the road](https://www.microsoft.com/en-us/research/uploads/prod/2019/04/fork-hotos19.pdf) <br />[The Evolution of the Unix Time-sharing System](https://www.bell-labs.com/usr/dmr/www/hist.html)
| 3 | [Threads](lecture/lec4_threads.pptx), [Synchronization 1](lecture/lec5_sync.pptx) | [Synchronization 1](lecture/lec5_sync.pptx) | [lec4](lecture/lec4_threads.pdf), [lec5](lecture/lec5_sync.pdf)
| 4 | [Sync 2: Condition Variables](lecture/lec6_cv.pptx) |  | [lec6](lecture/lec6_cv.pdf) |



### Tutorials and Assignments

| Week | Topic | Link | TA | Assignment | Due |
| :---: | :------------------: | :-----: | :-----: | :-------------: | :-------------: |
| 1 | [Basic reviews: Linux, gcc, git and C programming](tutorial/T01/tut01.pptx) | [tutorial 1](https://cuhk.zoom.us/rec/share/GEVKNpggSubf1AC2g69JJW0ObC5RUIyQ-_Nwc8UbnugL4lEoqa8F09GnW0mTLgQd.kgEuaH_RMddgmK7F?startTime=1673515811000%20Passcode:%20$Xq+fY6?)<br />Passcode: $Xq+fY6? | Shaofeng | [Assignment 1](assignment/assign1) | 18:00:00 p.m., Mon, Feb 13th |
| 2 | [Tutorial for Assignment One: Background Knowledge and Code Walk](tutorial/T02/tut02.pptx) | [tutorial 2](https://cuhk.zoom.us/rec/share/X3-6qBKu-wuBuxGmBX6pdPg9blXWHB_XGno89tHnhV9Rv9pU7p78V-IQSJgUBOwU.oj8ylLp93FrGJ8CU?startTime=1674120628000)<br />Passcode: R+F6sah$ | Shaofeng |  |  |
| 3 | [Tutorial for Assignment One: System Calls in C Programming ](tutorial/T03/tut03.pptx) | [tutorial 3](https://cuhk.zoom.us/rec/share/AChkaeM1HL_qjCGlgpCNso5y8pO0Q2lnmrmBx4GA8FBqgrcUMSI1HKBICoAWkC0I.zDn3X3KwnKxBjp3j?startTime=1675330422000)<br />Passcode: 628F%d.v | Shaofeng |  |  |
| 4 | [Semaphore, Conditional Variables and Mutex](tutorial/T04/tutorial04.pptx) | Link | Xin |  | 18:00:00 p.m., Mon, Mar 6th |

### Assignment Github Classroom and Contact
| Assignment Classroom | Due | Contact TA |
| :-------------: | :-------------: | :-----: |
| [assignment one](https://classroom.github.com/a/33LJk-O2) | 18:00:00 p.m., Mon, Feb 13th | [Wu, Shaofeng](mailto:sfwu22@cse.cuhk.edu.hk) |
| [assignment one grace token]() (To be released) | 18:00:00 p.m., Tues, Feb 14th | [Wu, Shaofeng](mailto:sfwu22@cse.cuhk.edu.hk) |


## Course policies
- Assignments: 
  * No late submission.
  * Grace tokens: You have **2** grace tokens, each can be used to give you a 24-hr extension on one assignment. You can apply at most 1 grace token on each assignment at your own discretion. This gives you some flexibility to cope with your own schedule.
  * According to the University’s regulation, every assignment must be accompanied by a signed declaration of originality; submissions without it will receive zero mark.
  * The declaration form is available [here](https://www.cuhk.edu.hk/policy/academichonesty/Eng_htm_files_(2013-14)/declaration_en.doc).
- Lectures and tutorials:
  * Be on time. Set your mobile device to vibration/silient mode.
  * Feel free to ask questions and raise comments during the lecture, but we can only entertain short questions and discussions in-class.
  * Longer and deeper discussion and questions can happen in tutorials.
  * Follow University's regulations on COVID, including use of masks, hand sanitization, seating with social distance, etc.
