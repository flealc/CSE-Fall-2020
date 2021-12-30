1)How much time does it take for each thread to complete its task?

single-threaded version: main thread: 3.530000 seconds
multi-threaded version: main thread: 3.840000 seconds, thread 1: 3.840000 seconds and thread 2: 2.670000 seconds

2)In the multi-threaded version does main thread time == thread 1 time + thread 2 time?

No. Main time == thread 2 time. The thread that takes the longest determined the time for main, since the join instruction forced main to wait for each thread to finish their job.

3)Which method (single-thread or multi-thread) results in a faster execution time? Explain why the given version is faster than the other.

In this case the single-threaded version was slightly faster than the multi-threaded one. I assume that the difference was caused by the multi-threaded version having to go through the process of creating the threads and passing arguments etc., plus each thread having to read the arguments and open/close the files. 

4)In the Compile and Execute section below why are there two possible outputs for the same code?

Because one thread could finish before the other one and there is no way to predict it, unless we sepcifically make a thread take longer, by some mechanism like using sleep()


