### CSCI3150 Fall2024 Lab Quiz 3: Memory Management

#### Question

Please read through the following code blocks and figure out the output of them.

Block 1:

int *x = malloc(20 * sizeof(int));

printf("%d ", sizeof(x));

Block 2:

int x[20];

printf("%d", sizeof(x));

Which of the following statements is the output of the above code blocks.

A.4 40

B.40 40

C.4 80

D.80 80

#### Solution

3/C.

**Explanations**: 

For the first block, the actual size of ‘x’ is known at run-time.
For the second block, the actual size of ‘x’ is known at compile-time.