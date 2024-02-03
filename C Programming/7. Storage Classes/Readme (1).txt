The C view of memory divide the memory up into five areas: 
	code and constants (TEXT), 
	initialized data (DATA), 
	uninitialized data (BSS), 
	temporary variables (STACK),
	the heap.

	Text
	****
	Code contains the instructions for the program as well as any constants used by the program.
	The data in this segment never changes and on UNIX systems the entire segment is marked read-only.
	
	Data
	****
	The Data segment contains all the initialized permanent variables.  This consists of all initialized global and 
	static variables.

	BSS
	***
	The BSS (Block Storage Segment) contains all the global and static variables that haven't been initialized.

	Stack
	******
	Temporary data or local data is stored in the Stack segment.

	Heap
	****
	The heap is the area of memory that is unallocated...  For instance, when you use malloc() to dynamically allocate 
	memory, that memory (usually) comes from the heap. 
	


