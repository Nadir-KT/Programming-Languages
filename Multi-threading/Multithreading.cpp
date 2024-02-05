// C++ Program to implement 
// the working of Multi-threading 
/* In general, there are two sorts of multitasking: process-based and thread-based.
Process-based multitasking handles the concurrent execution of programs. Thread-based multitasking deals with the multiprogramming of pieces of an equivalent program. */

#include <cstdlib> 
#include <iostream> 
#include <pthread.h> 

using namespace std; 

#define NUM_THREADS 5 

// Function to print Hello with 
// the thread id 
void* PrintHello(void* threadid) 
{ 
	// Thread ID 
	long tid; 
	tid = (long)threadid; 

	// Print the thread ID 
	cout << "Hello World! Thread ID, "
		<< tid << endl; 

	pthread_exit(NULL); 
} 

// Driver Code 
int main() 
{ 

	// Create thread 
	pthread_t threads[NUM_THREADS]; 
	int rc; 
	int i; 

	for (i = 0; i < NUM_THREADS; i++) { 

		cout << "main() : creating thread, "
			<< i << endl; 

		rc = pthread_create(&threads[i], 
							NULL, 
							PrintHello, 
							(void*)&i); 

		// If thread is not created 
		if (rc) { 
			cout << "Error:unable to"
				<< " create thread, "
				<< rc << endl; 

			exit(-1); 
		} 
	} 

	pthread_exit(NULL); 
} 
