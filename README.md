# CSCI3150 Intro to Operating Systems, Fall 2024

## Administrivia

### Schedule
- Lectures: 
  * Tue 12:30pm – 2:15pm, ERB LT
  * Wed 10:30am – 11:15am, ERB LT 
- Tutorials:
  * L01, Thu 10:30am - 11:15am, SHB 123 
  * L02, Thu 11:30am - 12:15pm, SHB 123
  * L03, Thu 2:30pm - 3:15pm, SHB 924
  * L04, Thu 4:30pm - 5:15pm, SHB 123
  * L05, Thu 5:30pm - 6:15pm, SHB 123

### Team
| Member | Role | Office Hours |
| :---------------- | :--- | :----------- |
| [Xu, Hong](https://henryhxu.github.io/) (hongxu@cuhk) | Prof | Tue 2:30-4:30 pm, SHB 914. **By appointment** |
| [Wu, Shaofeng](TA_pics/shaofeng.jpg) (sfwu22@cse) | Head TA | Thu 12:30-2:30 pm, SHB 117. |
| [Yang, Yitao](TA_pics/yitao.jpg) (ytyang@cse) | TA | Fri 1:00-3:00 pm, SHB 121 |
| [Li, Jianqiang](TA_pics/jianqiang.jpg) (jqli1@cse) | TA | Wed 2:30-4:30 pm, SHB 904. |
| [Chen, Kaiwen](TA_pics/kaiwen.jpg) (kwchen24@cse) | TA | Fri 10:00-12:00 am, SHB 904. |
| [Chen, Yuetao](TA_pics/yuetao.jpg) (ytchen24@cse) | TA | TUE 1:00-3:00 pm, SHB 904 |
| [Feng, Yicheng](TA_pics/yicheng.jpg) (ycfeng@cse) | TA | Wed 2:00-4:30 pm, SHB 904 |

**[NOTE]**: Due to the large class size (200+ students), please do **not** email us individually. Piazza should be used for all Q&A.

### Piazza
The Piazza page for this course is [here](https://piazza.com/cuhk.edu.hk/fall2024/csci3150).
**All** communication about this course is done over Piazza. This includes questions, discussions, announcements, as well as private messages. 
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
Click on the topic to access the slides, and on the superscript to access the corresponding chapters in the textbook.

### Lectures

| Week | Tue Lecture | Wed Lecture | PDFs | Optional readings |
| :-----------: | :-----------------: |  :------------: | :------------: | :------------: |
| 1 | [Intro](lectures/lec1_intro.pptx), [Arch support](lectures/lec2_arch.pptx) | [Arch support](lectures/lec2_arch.pptx) | [Intro](lectures/lec1_intro.pdf), [Arch](lectures/lec2_arch.pdf)
| 2 | [Processes](lectures/lec3_processes.pptx)<sup>[4](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-intro.pdf), [5](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf)</sup> | [Processes](lectures/lec3_processes.pptx) | [Processes](lectures/lec3_processes.pdf) | [A fork() in the road](https://www.microsoft.com/en-us/research/uploads/prod/2019/04/fork-hotos19.pdf) <br />[The Evolution of the Unix Time-sharing System](https://www.bell-labs.com/usr/dmr/www/hist.html)
| 3 | [Threads](lectures/lec4_threads.pptx)<sup>[26](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-intro.pdf)</sup> | Mid-autumn Festival | [Threads](lectures/lec4_threads.pdf) | [Why Threads Are A Bad Idea (for most purposes)](https://web.stanford.edu/~ouster/cgi-bin/papers/threads.pdf)
| 4 | [Sync 1: Locks](lectures/lec5_sync.pptx)<sup>[28](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf)</sup> | [Sync 2: Condition Variables](lectures/lec6_cv.pptx)<sup>[30](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf)</sup> | [Sync 1](lectures/lec5_sync.pdf), <br />[Sync 2](lectures/lec6_cv.pdf)|
| 5 | National Day | [Sync 2: Condition Variables](lectures/lec6_cv.pptx) | [Sync 2](lectures/lec6_cv.pdf)
| 6 | [Sync 3: Semaphore](lectures/lec7_sema.pptx)<sup>[31](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf)</sup> | [Deadlock](lectures/lec8_deadlock.pptx)<sup>[32](https://pages.cs.wisc.edu/~remzi/Classes/537/Fall2021/Book/threads-bugs.pdf)</sup> | [Sync 3](lectures/lec7_sema.pdf), [Deadlock](lectures/lec8_deadlock.pdf) | [The Little Book of Semaphores](https://greenteapress.com/wp/semaphores/), <br />[Hierarchical ordering of sequential processes](https://www.cs.utexas.edu/users/EWD/ewd03xx/EWD310.PDF)
| 7 | [CPU <br />Scheduling](lectures/lec9_sched.pptx)<sup>[7](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched.pdf), [8](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-mlfq.pdf), [9](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-lottery.pdf)</sup> | [Midterm] | [Scheduling](lectures/lec9_sched.pdf)


### Tutorials and Assignments

| Week | Topic | TA | Assignment | Due |
| :---: | :------------------: | :-----: | :-------------: | :-------------: |
| 1 | [Basic Review: Linux, Git, and C](tutorial/T01/tut01.pptx) |  Shaofeng | [Assignment 1](https://classroom.github.com/a/rrprBsu4) | 18:00:00 p.m., Mon, Oct 7th |
| 2 | [Assignment One: Background Knowledge and Code Walk](tutorial/T02/tut02.pptx) |  Shaofeng |  |  |
| 3 | [Assignment One: System Calls in C Programming ](tutorial/T03/tut03.pptx) |  Shaofeng |  |  |
| 4 | [Mutex Lock Implementation via pthread Library in C](tutorial/T04/tut04.pptx) |  Jianqiang |  |  |
| 5 | [Condition Variables via pthread Library in C](tutorial/T05/tut05.pptx) |  Jianqiang | [Assignment 2](https://classroom.github.com/a/ECgb6vfZ) | 18:00:00 p.m., Mon, Nov 4th |
| 6 | [Semaphores in C](tutorial/T06/tut06.pptx) |  Yuetao |  |  |
| 7 | [Multilevel Feedback Queue](tutorial/T07/tut07.pptx) |  Yuetao |  |  |


### Assignment Submission(Github Classroom) and Contact
| Assignment Classroom | Due | Contact TA |
| :-------------: | :-------------: | :-----: |
| [assignment-one](https://classroom.github.com/a/rrprBsu4) | 18:00:00 p.m., Mon, Oct 7th | Shaofeng |
| [assignment-one-grace-token](https://classroom.github.com/a/De3qyMyL) | 18:00:00 p.m., Mon, Oct 8th | Shaofeng |
| [assignment-two](https://classroom.github.com/a/ECgb6vfZ) | 18:00:00 p.m., Mon, Nov 4th | Jianqiang & Yuetao |

## Course policies
- Assignments: 
  * No late submission.
  * Grace tokens: You have **2** grace tokens, each can be used to give you a 24-hr extension on one assignment. You can apply at most 1 grace token on each assignment at your own discretion. This gives you some flexibility to cope with your own schedule.
  * According to the University’s regulation, every assignment must be accompanied by a signed declaration of originality; submissions without it will receive zero mark.
  * The declaration form is available [here](https://www.cuhk.edu.hk/policy/academichonesty/Eng_htm_files_(2013-14)/declaration_en.doc).
- Use of AI tools:
  * Our approach is "Use only with prior permission".
  * In the assignments, we will explicitly specify which parts can be done with AI tools, and which parts can't.
  * Instructions will be given to properly cite/acknowledge the use of AI tools.
  * The University's guide is [here](https://www.aqs.cuhk.edu.hk/documents/A-guide-for-students_use-of-AI-tools.pdf).
- Lectures and tutorials:
  * Be on time. Set your mobile device to vibration/silient mode.
  * Feel free to ask questions and raise comments during the lecture, but we can only entertain short questions and discussions in-class.
  * Longer and deeper discussion and questions can happen in tutorials.
  * Follow University's regulations on COVID, including use of masks, hand sanitization, seating with social distance, etc.
