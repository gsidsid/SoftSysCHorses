# On Parallel K-Means
We aim to explore the potential of efficiency of using C through multithreading a program.
We have chosen K means as an appropriate algorithm for this.
The MVP we plan to achieve is a working multithreaded function which successfully clusters points.
The stretch goal is to then expand by exploring the GPU implementation of the same algorithm using CUDA.

By working on this project, we hope to learn more about the general use and application of structs in C, as well as some more advanced techniques such as parallelism, semaphoresas, and GPU processing of the K-means algorithm.
After all, such performant techniques should suit a performant language such as C well.

We have looked at documentation and tutorials regarding multithreading and went through them.
The results are in the tutorials directory.
We then implemented K means on a single thread and have since successfully parallelized it and tested it with simple unit tests which are in the repository.
The parallel implementation is in `src/kmeans`.c.
We have also looked into documentation for the GPU implementation.

Right now, we have the MVP of a parallel implementation of K-means.
Thus, we have allotted new tasks.
Sid is setting up a CUDA development toolchain to begin looking into GPU acceleration.
The definition of done for Sid is a successful parallelized batch distance finder using CUDA.
Kawin will research benchmarks against single-thread and existing multi-threaded implementations.
The definition of done is a table of benchmarks.
Sreekanth is working on generating random datasets for testing as well as finding real world data for Kawin to test with.
Sreekanth's definition of done is having insights on dataset quality as well as a suite of datasets for Kawin to test on.
The last step will be generating a report with benchmarks of our multithreaded CPU and GPU implementations, with code to back them up.
<!-- Right now, we have a minimum viable product for our implementation of K-means. Three tasks we are currently working on are: -->
<!-- Sid: Setting up CUDA development toolchain  -->
<!-- Kawin: Researching how to conduct parallel processing in C -->
<!-- Sree: Refactoring original codebase to support parallel processing -->

