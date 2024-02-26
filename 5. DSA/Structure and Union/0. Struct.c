#include <stdio.h>  
#include <string.h>   
// A structure is a list of variables, (they can be of different data types), which are grouped together under one data type.
// Define a structure 
 struct data {
	int info1;
	int info2;
	char info3[10];
	int info4;
} data1;
   
void print_structure_array(void)
{
    // Declare a variable of type struct data  
    struct data data2;
	//unsigned char *structure_array_address = 0x00102000;
	//struct data *current_structure = (struct data *)structure_array_address;
	// Write the code here to read the structure from memory and print the value of 
	// info1, info2, info3 and info4 
	// Assign values to the structure members
	data1.info1=4;
	data1.info2=5;
	strcpy(data1.info3, "Bjarne Stroustrup");
	data1.info4=8;
	// Accessing the structure members  // A structure's members can be accessed by using the dot (.) operator.
    printf("info1: %d\n", data1.info1);  
    printf("info2: %d\n", data1.info2); 
    int i;
    for(i=0;i<12;i++) {
        printf("info3[%d]: %d\n", i,data1.info3[i]); 
    }
	printf("info3: %s\n", data1.info3); 
    printf("info4: %d\n", data1.info4); 
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
    for(i=0;i<12;i++) {
        printf("info3[%d]: %d\n", i,data2.info3[i]); 
    }
}

int main() {  

    print_structure_array();
   
    return 0;  
}  