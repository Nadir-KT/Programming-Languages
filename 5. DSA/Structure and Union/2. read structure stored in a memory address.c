/* An array of structures is stored in memory at address 0x00102000. Write a function to print the information stored in each element of this array. The length of the array is 10.
 
The structure looks like the following:-
 
struct data {
	int info1;
	int info2;
	char info3[10];
	int info4;
}; */
#include <stdio.h>  
#include <string.h>
// Define a structure 
 struct data {
	int info1;
	int info2;
	char info3[24];
	int info4;
} data1;
   
void print_structure_array(void)
{
	// Assign values to the structure members
	data1.info1=4;
	data1.info2=5;
	strcpy(data1.info3, "Bjarne Stroustrup");
	data1.info4=8;
	struct data *structure_pointer = &data1;
	//struct data *structure_pointer = (struct data *)structure_address_in_hex; // Cast the pointer to the structure
	//Difference between Dot(.) and Arrow(->) operator:  
    //The Dot(.) operator is used to normally access members of a structure or union.
    //The Arrow(->) operator exists to access the members of the structure or the unions using pointers.
    // Code to read the structure from memory and print the value of info1, info2, info3 and info4 
    printf("info1: %d\n", structure_pointer->info1);  
    printf("info2: %d\n", structure_pointer->info2); 
    int i;
    for(i=0;i<12;i++) {
        printf("info3[%d]: %d\n", i,structure_pointer->info3[i]); 
    }
	printf("info3: %s\n", structure_pointer->info3); 
    printf("info4: %d\n", structure_pointer->info4); 
    
    // Declare a variable of type struct data  
    struct data data2;
    data2.info3[0]=0;
	data2.info3[1]=1;
	data2.info3[2]=2;
	data2.info3[3]=3;
	data2.info3[4]=4;
	data2.info3[5]=5;
	data2.info3[6]=6;
	data2.info3[7]=8;
	data2.info3[8]=8;
	data2.info3[9]='\0';
	// Accessing the structure members  // A structure's members can be accessed by using the dot (.) operator.
    for(i=0;i<12;i++) {
    printf("info3[%d]: %d\n", i,data2.info3[i]); 
    }
}

int main() {  

    print_structure_array();
   
    return 0;  
}  