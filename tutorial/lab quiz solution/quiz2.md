### CSCI3150 Fall2024 Lab Quiz 2: Thread Synchronization

#### Question

Which of the following statements is **incorrect**?

A. The `join()` function makes the calling thread run in parallel with the specified thread.

B. The `signal()` function on a condition variable tries to wake up at least one waiting thread.

C. The `wait()` function must be called while holding the associated mutex lock, and it atomically releases the mutex and suspends the thread until it is signaled.

D. When a thread attempts to acquire a mutex lock that is already held by another thread, the thread will be put to sleep until the lock becomes available.

#### Solution

1/A.

**Explanations**: join() is used by the calling thread to wait until the specified thread completes its execution.