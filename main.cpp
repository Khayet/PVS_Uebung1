# include <stdio.h> //fuer input-output, inkl. std::cout
# include <omp.h> //fuer openMP 

int main(int argc, char* argv[]) 
{
  int numThreads; //Anzahl der Threads
  int threadID; //Identifikation des konkreten Threads
  float start, end; //start: Anfangszeit, end: Endzeit

  start = omp_get_wtime(); //weisst start die systemzeit zu

  /* Startet n Threads, num_threads(n) */
  #pragma omp parallel num_threads(1)
  {
    threadID = omp_get_thread_num(); //weisst threadID den Index des aktuellen Threads zu
    printf("Hello from thread %d\n", threadID);

    /* Falls dies der Master-, bzw. der erste Thread ist */
    if (threadID == 0)
    {
      numThreads = omp_get_num_threads(); //weise numThreads die Anahl der momentan laufenden threads zu
      printf("Number of threads: %d\n", numThreads);
    }
  }

  end = omp_get_wtime(); //weise end die Systemzeit zu
  printf("This task took %f seconds\n", end-start);

  return 0;
}