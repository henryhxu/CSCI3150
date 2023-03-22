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
Click on the topic to access the slides, on the superscript to access the corresponding chapters in the textbook, and on the ► to watch the recording.

Midterm quiz will be held on Thur, Feb 23, during our lecture time.

### Lectures

| Week | Wed Lecture | Thu Lecture | PDFs | Optional readings |
| :-----------: | :-----------------: |  :------------: | :------------: | :------------: |
| 1 | [Intro](lecture/lec1_intro.pptx), [Arch support](lecture/lec2_arch.pptx) | [Arch support](lecture/lec2_arch.pptx) | [lec1](lecture/lec1_intro.pdf), [lec2](lecture/lec2_arch.pdf)
| 2 | [Processes](lecture/lec3_processes.pptx)<sup>[4](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-intro.pdf), [5](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf)</sup> | [Processes](lecture/lec3_processes.pptx) | [lec3](lecture/lec3_processes.pdf) | [A fork() in the road](https://www.microsoft.com/en-us/research/uploads/prod/2019/04/fork-hotos19.pdf) <br />[The Evolution of the Unix Time-sharing System](https://www.bell-labs.com/usr/dmr/www/hist.html)
| 3 | [Threads](lecture/lec4_threads.pptx)<sup>[25](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-intro.pdf)</sup>, [Synchronization 1](lecture/lec5_sync.pptx)<sup>[28](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf)</sup> | [Synchronization 1](lecture/lec5_sync.pptx) | [lec4](lecture/lec4_threads.pdf), [lec5](lecture/lec5_sync.pdf)
| 4 | [Sync 2: Condition Variables](lecture/lec6_cv.pptx)<sup>[30](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf)</sup> | [Sync 3: Semaphore](lecture/lec7_sema.pptx)<sup>[31](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf)</sup> ([►](https://cuhk.zoom.us/rec/share/yuyeZJMrIlh5WQwHqBqrxM6WrCuRteAldP9xrof5Ai9i1yWpytZdq-YVrdODcls.KglAjWI29muOW6wW?startTime=1675913119000)) | [lec6](lecture/lec6_cv.pdf), [lec7](lecture/lec7_sema.pdf) | [The Little Book of Semaphores](https://greenteapress.com/wp/semaphores/), <br />[Hierarchical ordering of sequential processes](https://www.cs.utexas.edu/users/EWD/ewd03xx/EWD310.PDF)
| 5 | [Deadlock](lecture/lec8-deadlock.pptx)<sup>[32](https://pages.cs.wisc.edu/~remzi/Classes/537/Fall2021/Book/threads-bugs.pdf)</sup> ([►](https://cuhk.zoom.us/rec/share/a9_nFd1e78MmC6MmcG63ls5ZM5CNUbDm0uOdGBE24WM9MKanc38bbPQH_RqYDPzf.2UL914b4Rw3rdQlI?startTime=1676442659000)) | [CPU Scheduling](lecture/lec9_sched.pptx)<sup>[7](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched.pdf), [8](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-mlfq.pdf), [9](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-lottery.pdf)</sup> ([►](https://cuhk.zoom.us/rec/share/JABX_hYk8L8gOSrPGhf6GKYIFFP_OKvqSpycRoSEtsWuef-4KeK-WHwAhpiIhMWN.biqtKWk1c4MVcmaq)) | [lec8](lecture/lec8-deadlock.pdf), [lec9](lecture/lec9_sched.pdf)
| 6 | [CPU Scheduling](lecture/lec9_sched.pptx)<sup>[7](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched.pdf), [8](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-mlfq.pdf), [9](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-lottery.pdf)</sup> ([►](https://t.ly/WlJEa)) | [Midterm](exam/midterm_sol.pdf)
| 7 | [Memory Management 1](lecture/lec10_mem.pptx)<sup>[13](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-intro.pdf)-[16](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-segmentation.pdf)</sup> ([►](https://t.ly/vXCh)) | [MM 2: Paging](lecture/lec11_paging.pptx)<sup>[18](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-paging.pdf), [19](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-tlbs.pdf), [20](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-smalltables.pdf)</sup> ([►](https://t.ly/VJcx)) | [lec10](lecture/lec10_mem.pdf), [lec11](lecture/lec11_paging.pdf)
| 8 <br>Mar 15-16 | [MM 2: Paging](lecture/lec11_paging.pptx)<sup>[18](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-paging.pdf), [19](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-tlbs.pdf), [20](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-smalltables.pdf)</sup> ([►](https://t.ly/vbDI)) | [MM 3: Swapping](lecture/lec12_swapping.pptx)<sup>[21](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-beyondphys.pdf), [22](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-beyondphys-policy.pdf)</sup> ([►](https://t.ly/XRO5)) | [lec12](lecture/lec12_swapping.pdf)
| 9 <br>Mar 22-23 | [I/O Devices, HDD](lecture/lec13_io.pptx)<sup>[36](https://pages.cs.wisc.edu/~remzi/OSTEP/file-devices.pdf), [37](https://pages.cs.wisc.edu/~remzi/OSTEP/file-disks.pdf)</sup> | | [lec13](lecture/lec13_io.pdf)
| 10 <br>Mar 29-30 | File Systems 2
| 11 <br>Apr 12-13* | File Systems 3
| 12 <br>Apr 19-20 | Distributed Systems | Final Review |

\*: No class on Apr 6.

### Tutorials and Assignments

| Week | Topic | Link | TA | Assignment | Due |
| :---: | :------------------: | :-----: | :-----: | :-------------: | :-------------: |
| 1 | [Linux, gcc, git, and C](tutorial/T01/tut01.pptx) | [tutorial 1](https://cuhk.zoom.us/rec/share/GEVKNpggSubf1AC2g69JJW0ObC5RUIyQ-_Nwc8UbnugL4lEoqa8F09GnW0mTLgQd.kgEuaH_RMddgmK7F?startTime=1673515811000%20Passcode:%20$Xq+fY6?)<br />Passcode: $Xq+fY6? | Shaofeng | [Assignment 1](assignment/assign1) | 18:00:00 p.m., Mon, Feb 13th |
| 2 | [Assignment 1: Background and Code Walkthrough](tutorial/T02/tut02.pptx) | [tutorial 2](https://cuhk.zoom.us/rec/share/X3-6qBKu-wuBuxGmBX6pdPg9blXWHB_XGno89tHnhV9Rv9pU7p78V-IQSJgUBOwU.oj8ylLp93FrGJ8CU?startTime=1674120628000)<br />Passcode: R+F6sah$ | Shaofeng |  |  |
| 3 | [Assignment 1: System Calls in C](tutorial/T03/tut03.pptx) | [tutorial 3](https://cuhk.zoom.us/rec/share/AChkaeM1HL_qjCGlgpCNso5y8pO0Q2lnmrmBx4GA8FBqgrcUMSI1HKBICoAWkC0I.zDn3X3KwnKxBjp3j?startTime=1675330422000)<br />Passcode: 628F%d.v | Shaofeng |  |  |
| 4 | [Mutex, Semaphore and Condition Variables](tutorial/T04/tutorial04.pptx) | [tutorial 4](https://cuhk.zoom.us/rec/share/__6p_nBPjvjwHpwccJoWNa6CsFWWHqFDVG3GXv5YJubu9Q6ByURU6JgsxpHINqgK.gFL2iaQ_tkuN5gHm?startTime=1675935564000)<br /> Passcode: W%2PNB9! | Xin, Shaofeng |  | |
| 5 | [Assignment 1 Review & Deadlocks](tutorial/T05/tut05.pptx) | [tutorial 5](https://cuhk.zoom.us/rec/share/5lIxzEoenQPB_9ml0bQfe0BDb34YkTGNZrUbfPYY67iHQllJmGcZOnTwX5RJ51KD.8sEabfJJTzygX7kJ)<br /> Passcode: euZW3fO+ |  Shaofeng |  | |
| 6 | [RR and MLFQ Scheduling](tutorial/T06/tutorial_06.pptx) | [tutorial 6](https://cuhk.zoom.us/rec/share/ptGM0EEdyjCcHZS26ig-4BLBWFt11TKNHqeOPHcuNUjPaiHGhoiFjstI5jhVvPwT.C9qroL2MIc-YTqWx?startTime=1677144881000)<br /> Passcode: 2xcj#@JW |  Xin | [Assignment 2](assignment/assign2) | 18:00:00 p.m., Mon, ~~Mar 6th~~ Mar 13th|
| 7 | [Virtual Memory and Address Translation](tutorial/T07/Tutorial7.pptx) | [tutorial 7](https://cuhk.zoom.us/rec/share/r5rKPjwnREkufuQVkcyqarDeCz7QbZ_Wltt4S7IcitWK35l38XLbvJn_WJE_LSlH.RQsFSVKHGWhOdmrI?startTime=1677749452000)<br /> Passcode: 7HTy9KE^ | Qin | | |
| 8 | [Review on Assignment2 && Implementation of Page Replacement Algorithms](tutorial/T08/tutorial08.pptx) |  [tutorial 8](https://cuhk.zoom.us/rec/share/uvC3y79suXBuMClDQMvPyXSSBgSwHw_vrbXWg7CPVr0gqQTpupxmFNPG-Uq7HqCi.IC38cRuONT_vy9Tc) <br /> Passcode: *#X1!W?w |  Xin| | |
| 9 | [Assignment 3 Preliminaries and Hints](/tutorial/T09/Tutorial9.pptx) |  | Qin| [Assignment 3](assignment/assign3) | 00:00:00 p.m., Mon, Apr 17th|
| 10 |  |  |  | | |
| 11 |  |  |  | | |
| 12 |  |  |  | | |





### Assignment Submission(Github Classroom) and Contact
| Assignment Classroom | Due | Contact TA |
| :-------------: | :-------------: | :-----: |
| [assignment one](https://classroom.github.com/a/33LJk-O2) | 18:00:00 p.m., Mon, Feb 13th | [Shaofeng](mailto:sfwu22@cse.cuhk.edu.hk) |
| [assignment one grace token](https://classroom.github.com/a/-vtYT42w)| 18:00:00 p.m., Tues, Feb 14th | [Shaofeng](mailto:sfwu22@cse.cuhk.edu.hk) |
| [assignment two](https://classroom.github.com/a/cvljyRld)| 18:00:00 p.m., Mon, Mar 13th | [Xin](mailto:xtan22@cse.cuhk.edu.hk) |
| [assignment two grace token](https://classroom.github.com/a/s8XL0ADA)| 18:00:00 p.m., Tues, Mar 14th | [Xin](mailto:xtan22@cse.cuhk.edu.hk) |
| [assignment three](https://classroom.github.com/a/2KHPqmOP)| 00:00:00 p.m., Mon, Apr 17th | [Qin](mailto:qluo22@cse.cuhk.edu.hk) |

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
