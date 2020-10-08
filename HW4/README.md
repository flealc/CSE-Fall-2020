
1.- How many characters do you see printed on screen?

	Two characters: A and B.

2.- What happened to the executing program?

	Since the semaphore was initialized to 2, the first two threads decreased its value to 0. Once the third thread reached the sem_wait instruction, the value of the semaphore was decreased to -1 and the program stalled. That is the reason why the character C did not print on the screen.
 
3.- You are allowed to add a single line which is a semaphore related function to the code to make sure your code prints all three characters. Add that line and comment it with // FIX for code issue.

	Line was added to the code. It is a sem_post instruction before the end of the second thread, so the semaphore value gets increased to 1 before the execution of the third thread.
