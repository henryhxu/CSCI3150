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
| [Xu, Hong](https://henryhxu.github.io/) | Prof | Tue 2:30-4:30 pm, SHB 914. **By appointment.** |


### Piazza
The Piazza page for this course is [here](https://piazza.com/cuhk.edu.hk/fall2024/csci3150).
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
| 9 <br>Mar 22-23 | [I/O Devices, HDD](lecture/lec13_io.pptx)<sup>[36](https://pages.cs.wisc.edu/~remzi/OSTEP/file-devices.pdf), [37](https://pages.cs.wisc.edu/~remzi/OSTEP/file-disks.pdf)</sup> ([►](https://t.ly/MrFI))| I/O Devices, HDD ([►](https://t.ly/rjXG)) | [lec13](lecture/lec13_io.pdf)
| 10 <br>Mar 29-30 | [A Simple FS](lecture/lec14_fsapi.pptx)<sup>[39](https://pages.cs.wisc.edu/~remzi/OSTEP/file-intro.pdf), [40](https://pages.cs.wisc.edu/~remzi/OSTEP/file-implementation.pdf), [41](https://pages.cs.wisc.edu/~remzi/OSTEP/file-ffs.pdf)</sup> ([►](https://t.ly/0_fF)) | [LFS](lecture/lec15_lfs.pptx)<sup>[43](https://pages.cs.wisc.edu/~remzi/OSTEP/file-lfs.pdf)</sup> ([►](https://cuhk.zoom.us/rec/share/T6hdZbbs44RMyeDees6mv-lcyTlFc2_9jQDeqJQsEwQxpYzij3mpEMZ1cOZyxA-g.rGbbRZrh2CPHuZxr)) | [lec14](lecture/lec14_fsapi.pdf), [lec15](lecture/lec15_lfs.pdf)  
| 11 <br>Apr 12-13* | [SSD](lecture/lec16_ssd.pptx)<sup>[44](https://pages.cs.wisc.edu/~remzi/OSTEP/file-ssd.pdf)</sup> ([►](https://t.ly/agWS)) | SSD ([►](https://t.ly/MLt0)) | [lec16](lecture/lec16_ssd.pdf) 
| 12 <br>Apr 19-20 | [Virtualization](lecture/lec17_virtualization.pptx)<sup>[vmm](https://pages.cs.wisc.edu/~remzi/OSTEP/vmm-intro.pdf)</sup> ([►](https://t.ly/BWB5)) | [Networking](lecture/lec18.pdf),<br> [Final Review](lecture/lec_final.pptx) ([►](https://t.ly/3h6mP)) |

\*: No class on Apr 6.

### Tutorials and Assignments

| Week | Topic | Link | TA | Assignment | Due |
| :---: | :------------------: | :-----: | :-----: | :-------------: | :-------------: |
| 1 | [Linux, gcc, git, and C](tutorial/T01/tut01.pptx) | [tutorial 1](https://cuhk.zoom.us/rec/share/GEVKNpggSubf1AC2g69JJW0ObC5RUIyQ-_Nwc8UbnugL4lEoqa8F09GnW0mTLgQd.kgEuaH_RMddgmK7F?startTime=1673515811000%20Passcode:%20$Xq+fY6?)<br />Passcode: $Xq+fY6? | Shaofeng | [Assignment 1](assignment/assign1) | 18:00:00 p.m., Mon, Feb 13th |


### Assignment Submission(Github Classroom) and Contact
| Assignment Classroom | Due | Contact TA |
| :-------------: | :-------------: | :-----: |
| [assignment one](https://classroom.github.com/a/33LJk-O2) | 18:00:00 p.m., Mon, Feb 13th | [Shaofeng](mailto:sfwu22@cse.cuhk.edu.hk) |

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
