# CSCI3150 Intro to Operating Systems, Spring 2026

## Administrivia

### Schedule
- Lectures: 
  * Wed 2:30pm – 4:15pm, LSB LT-5
  * Thu 4:30pm – 5:15pm, LSK LT-2 
- Tutorials:
  * L01, Thu 2:30pm - 3:15pm, SHB 924 
  * L02, Thu 5:30pm - 6:15pm, SHB 123

### Team
| Member | Role | Office Hours |
| :---------------- | :--- | :----------- |
| [Xu, Hong](https://henryhxu.github.io/) | Prof | Tue 9:00-11:00 pm, SHB 914. **By appointment** |
| [Deng, Yangtao](TA_pics/yangtao.jpg) (ytdeng25@cse) | Head TA | Thu 9:30am - 11:30am, SHB 117 |
| [Wu, Shaofeng](TA_pics/shaofeng.jpg) (sfwu22@cse) | TA | Fri 2:00pm - 4:00pm, SHB 117  |
| [Feng, Yicheng](TA_pics/yicheng.jpg) (ycfeng@cse) | TA | Fri 2:30pm - 4:30pm, SHB 904 |
| [Jia, Chaobo](TA_pics/chaobo.jpg) (cbjia25@cse) | TA | Tue 3:00pm -5:00pm, SHB 117 |

**[NOTE]**: Due to the large class size, please do **not** email us individually. Piazza should be used for all Q&A.

### Piazza
The Piazza page for this course is [here](https://piazza.com/cuhk.edu.hk/spring2026/csci3150).
**All** communication about this course is done over Piazza. This includes questions, discussions, announcements, as well as private messages. 
The self-signup code is "3150 rocks!".

## Course outline

This course discusses the principles in the design and implementation of operating systems (OS). Main topics include: OS concepts and abstractions, process management, memory management, file systems, and virtualization.

### Textbook (optional)
The course materials are partly based upon the following classic textbook:
- Operating Systems: Three Easy Pieces, Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau
- The book is free online: http://pages.cs.wisc.edu/~remzi/OSTEP/ 

The following textbook (CSAPP) serves as a very good source of reference:
- [Computer Systems: A Programmer's Perspective, 3rd edition](https://csapp.cs.cmu.edu/3e/home.html), Randal E. Bryant and David R. O'Hallaron

### Grading
| Assessment item | CSCI Weight 
| :---------------- | :--- | 
| Assignments | 50% | 
| Lab quizzes* | 10% |
| Final Exam | 40% | 

\*: To encourage tutorial participation, quiz or simple programming task will be conducted at the tutorials randomly. We will randomly pick 5 tutorials and perform this at the end of the tutorial. Each quiz/programming task is worth one mark. There will also be a midterm written quiz worth 5 marks; the date will be announced in a later time.

## Schedules
Click on the topic to access the slides, and on the superscript to access the corresponding chapters in the textbook.

### Lectures

| Week | Wed Lecture |  Thu Lecture | PDFs | Optional readings |
| :-----------: | :-----------------: |  :------------: | :------------: | :------------: |
| 1 | [Intro](lectures/lec1_intro.pptx), [Arch support](lectures/lec2_arch.pptx) | [Arch support](lectures/lec2_arch.pptx) | [Intro](lectures/lec1_intro.pdf), [Arch](lectures/lec2_arch.pdf)
| 2 | [Processes](lectures/lec3_processes.pptx)<sup>[4](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-intro.pdf), [5](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf)</sup> | [Processes](lectures/lec3_processes.pptx) | [Processes](lectures/lec3_processes.pdf) | [A fork() in the road](https://www.microsoft.com/en-us/research/uploads/prod/2019/04/fork-hotos19.pdf) <br />[The Evolution of the Unix Time-sharing System](https://www.bell-labs.com/usr/dmr/www/hist.html)
| 3 | [Threads](lectures/lec4_threads.pptx)<sup>[26](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-intro.pdf)</sup>, [Sync 1: Locks](lectures/lec5_sync.pptx)<sup>[28](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf)</sup> | [Sync 1: Locks](lectures/lec5_sync.pptx) | [Threads](lectures/lec4_threads.pdf),<br />[Sync 1](lectures/lec5_sync.pdf) | [Why Threads Are A Bad Idea (for most purposes)](https://web.stanford.edu/~ouster/cgi-bin/papers/threads.pdf)
| 4 | [Sync 2: Condition Variables](lectures/lec6_cv.pptx)<sup>[30](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf)</sup>  | [Sync 3: Semaphore](lectures/lec7_sema.pptx)<sup>[31](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf)</sup> | [Sync 2](lectures/lec6_cv.pdf),<br /> [Sync 3](lectures/lec7_sema.pdf)| [The Little Book of Semaphores](https://greenteapress.com/wp/semaphores/), <br />[Hierarchical ordering of sequential processes](https://www.cs.utexas.edu/users/EWD/ewd03xx/EWD310.PDF)
| 5 | 

The following material provides a nice overview of microkernels and kernel architecture, an intriguing topic I wish I had time to teach.
- [Section 1: Kernel architecture, CS161, Harvard](https://read.seas.harvard.edu/cs161/2024/sections/section1/)

### Tutorials and Assignments

| Week | Date | Topic | TA | Assignment | Due |
| :---: | :---: | :------------------: | :-----: | :-------------: | :-------------: |
| 1 | Jan 8 | [Basic Review: Linux, Git, and C](tutorial/T01/tut01.pptx) |  Shaofeng | [Assignment 1](assignment/assignment-1) | 23:59:59 p.m., Jan. 26 |
| 2 | Jan 15 | [Assignment One: Background Knowledge and Code Walk](tutorial/T02/tut02.pptx) |  Shaofeng |  |  |
| 3 | Jan 22 | [Assignment One: System Calls in C Programming ](tutorial/T03/tut03.pptx) |  Shaofeng |  |  |
| 4 | Jan 29 | [Mutex Lock Implementation via pthread Library in C](tutorial/T04/tut04.pptx) | Chaobo | [Assignment 2]() | 23:59:59 p.m., Mar. 1st |
| 5 | Feb 5 |  [Condition Variables via pthread Library in C](tutorial/T05/tut05.pptx) |  Yicheng |  |  |
| 6 | Feb 12 | [Semaphores in C](tutorial/T06/tut06.pptx) |  Yicheng |  |  |
|  | Feb 19 | Holiday |  |  |  |
| 7 | Feb 26 | [Multilevel Feedback Queue](tutorial/T07/tut07.pptx) |  Yicheng |  |  |
|  | Mar 5 | Reading Week |  | [Assignment 3]() | TBA |
| 8 | Mar 12 | [Midterm Solution](tutorial/T08/tut08.pptx) |  Yangtao |  |  |
| 9 | Mar 19 | [Swapping Algorithms](tutorial/T09/tut09.pptx) | Yangtao |  |  |
| 10 | Mar 26 | [Paging (Address Translation)](tutorial/T10/tut10.pptx) | Yangtao | [Assignment 4]() | TBA |
| 11 | Apr 2 | [File System API](tutorial/T11/tut11.pptx) | Chaobo |  |  |
| 12 | Apr 9 | [FAT File System](tutorial/T12/tut12.pptx) | Chaobo |  |  |
| 13 | Apr 16 | TBA | TBA |  |  |

### Assignment Submission(Github Classroom) and Contact

| Assignment Classroom | Due | Contact TA |
| :-------------: | :-------------: | :-----: |
| [Assignment 1](https://classroom.github.com/a/YnSDVcuC) | 23:59:59 p.m., Jan. 26 | Shaofeng |
| [Assignment 1 Grace Token]() | 23:59:59 p.m., Jan. 27 | Shaofeng |
| [Assignment 2]() | 23:59:59 p.m., Mar. 1st | Yicheng |
| [Assignment 2 Grace Token]() | 23:59:59 p.m., Mar. 2nd | Yicheng |
| [Assignment 3]() | TBA | Yangtao |
| [Assignment 3 Grace Token]() | TBA | Yangtao |
| [Assignment 4]() | TBA | Chaobo |
| [Assignment 4 Grace Token]() | TBA | Chaobo |

## Course policies
- Assignments: 
  * No late submission.
  * Grace tokens: You have **2** grace tokens, each can be used to give you a 24-hr extension on one assignment. You can apply at most 1 grace token on each assignment at your own discretion. This gives you some flexibility to cope with your own schedule.
  * According to the University’s regulation, every assignment must be accompanied by a signed declaration of originality; submissions without it will receive zero mark.
  * The declaration form is available [here](https://www.cuhk.edu.hk/policy/academichonesty/Eng_htm_files_(2013-14)/declaration_en.doc).
- Use of AI tools:
  * The University's guide is [here](https://www.aqs.cuhk.edu.hk/documents/A-guide-for-students_use-of-AI-tools.pdf).
  * Our approach is **Approach 1 – Prohibit all use of AI tools**.
- Lectures and tutorials:
  * Be on time. Set your mobile device to vibration/silent mode.
  * Feel free to ask questions and raise comments during the lecture, but we can only entertain short questions and discussions in-class.
  * Longer and deeper discussion and questions can happen in tutorials.
  * Follow University's regulations on COVID, including use of masks, hand sanitization, seating with social distance, etc.

### Announcement regarding assignment submissions.

We understand that certain circumstances, such as severe illness requiring hospitalization or other force majeure events, may prevent you from submitting your assignments on time.

Should you find yourself in such a situation, and upon providing appropriate documentation as proof of the circumstances, you will be permitted to use the average score of all your other assignments as a replacement for the missed assignment. This policy is designed to ensure fairness while maintaining grade standards in light of uncontrollable events.
