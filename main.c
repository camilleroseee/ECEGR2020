#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// global ptr filePointer will be used to read and write to files 
FILE *filePointer; 

// Function declarations before main 
void readStudentRecords(void);
void printList(void);
void releaseList(void); 
void saveList(void);

void updateStud(int id_in);
void removeStud(int id_in);

void showMenu(void); 
void showUpdateMenu(char first[30], char last[30]);

// student struct from previous lab -- will be referred to as 'Student' throughout program 
typedef struct student {
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
	struct student* next; // next ptr used to implement as linked list 
} Student;

// makes a student node for each student in the original Student struct 
Student* makeStudNode(int id_input, char first_input[30], char last_input[30], float gpa_input){ 

	Student* newStud = (Student*) malloc(sizeof(Student)); // allocate memory for each new student 	
	if(newStud != NULL){
		newStud->ID = id_input;
		strcpy(newStud->firstName, first_input);
		strcpy(newStud->lastName, last_input);
		newStud->GPA = gpa_input;
		newStud->next = NULL;
	}
	return newStud; // returns the newly created student 
}

// adds a student to LL 
void addStudNode(Student* newStud){ 
	Student* currentStud = initialStud; 
	if(initialStud == NULL){ 
		initialStud = newStud; 
		return; 
	}
	while(currentStud->next != NULL){ 
		currentStud = currentStud->next; 
	}
	currentStud->next = newStud; 
	newStud->next = NULL;  
}

// inserts student input into linked list & sorts student GPAs
void insertNode(Student* newStud){  
	Student* node = initialStud;
    // while loop goes through linked list 
	while(node->next != NULL){ 
		Student* nextStud = node->next; 
        // logic to compare student GPAs
		if((node->GPA > newStud->GPA) && (newStud->GPA >= nextStud->GPA)){ 
			newStud->next = node->next; 
			node->next = newStud; 
			return; // leaves the logic
		}		
		else if(node->GPA <= newStud->GPA){ // Second check for GPA if first one fails 
			newStud->next = node;
			initialStud = newStud;
			return; // leaves the logic 
		}
		node = node->next;
	}
	node->next = newStud; 
	newStud->next = NULL;
	return;	
}

// deletes a student based on specific info 
void deleteStudent(Student* deleteStudent){
	Student* currentStud = firstStudent; 
	Student* previousStud = NULL; 
    // logic to decide if selected student is the first student 
	if(initialStud == deleteStudent){ 
		initialStud = initialStud->next; 
		free(deleteStudent); // freeing up the memory 
		return; 
	}
    // goes through the linked list until selected student is identified 
	while(currentStud != NULL && currentStud != deleteStudent){ 
		previousStud = currentStud; 
		currentStud = currentStud->next; 
	}
	if(currentStud != NULL){ 
		previousStud->next = currentStud->next; 
	}
	
	free(deleteStudent); // Deletes the desired student and frees the its memory.
}

void readStudentRec(){ 
	char first_output[30], last_output[30];
	int num_output, id_output;
	float gpa_output;
	
	filePointer = fopen("StudentRecords.txt", "r"); 
	fscanf(filePtr, "Number of students: %d", &num_output); 
	
	for(int i=0; i<num_output; i++){
		fscanf(filePtr, "\n\nStudent ID: %d", &id_output);
		fscanf(filePtr, "\nStudent First Name: %s", first_output);
		fscanf(filePtr, "\nStudent Last Name: %s", last_output);
		fscanf(filePtr, "\nStudent GPA: %f", &gpa_output);
		
		Student* anotherNode = addStudNode(id_out, first_out, last_out, gpa_out); 
		addStudNode(anotherNode); 
	}
}

// reads the linked list and prints out contents
void printList(){ 
	Student* node = initialStud; 
	printf("\n---STUDENT LINKED LIST---"); 
	while(node != NULL){ 
		printf("\n\nStudent ID: %d", node->ID);
		printf("\nStudent First Name: %s", node->firstName);
		printf("\nStudent Last Name: %s", node->lastName);
		printf("\nStudent GPA: %f", node->GPA);
		node = node->next;
	}
	printf("\n\n----"); 
}
// goes through the linked list and deletes all the students
void releaseList(){ 
	Student* node = initialStud; 
	Student* nextNode = initialStud->next; 
	while(node != NULL){ 
		deleteStudent(node); 
		node = nextNode; 
		nextNode = nextNode->next; 
	}
}

// writes student details into linked list 
void saveList(){
	filePointer = fopen("StudentRecords.txt", "w+"); 
	Student* node = initialStud; 
	int studentNum = 0; 
	while(node != NULL){ 
		studentNum++; 
		node = node->next; 
	}
	fprintf(filePointer, "Number of students: %d ", studentNum); 
	node = initialStud; 
	while(node != NULL){ 
		fprintf(filePtr, "\n\nStudent ID: %d", node->ID);
		fprintf(filePtr, "\nStudent First Name: %s", node->firstName);
		fprintf(filePtr, "\nStudent Last Name: %s", node->lastName);
		fprintf(filePtr, "\nStudent GPA: %f", node->GPA);
		node = node->next; // Iterate.
	}
	fclose(filePointer); // Close the file.
}

// gets rid of a student based on their ID 
void removeStud(int id_input){
	Student* node = initialStud; 
	int checker = 0; 
	while(node != NULL){ 
		if(id_input == node->ID){
			char first[30];
			char last[30];
			strcpy(first, node->firstName);
			strcpy(last, node->lastName);
			deleteStudent(node); 
			checker = 1; 
			printf("\n%s %s was successfully deleted.", first, last); 
			return; 
		}
		node = node->next; 
	}
	if(checker == 0){
		printf("\nThere is no student with that specific ID."); 
		return; 
	}
	return; 
}

// updates student info based on ID input 
void updateStud(int id_input){ 

	Student* node = initialStud; 
	Student* previousNode = node; 
	int check = 0; 
	int userIn = 0; 
	while(node != NULL){
		if(id_in == node->ID){ 
			do{ 
				updateStudentMenu(node->firstName, node->lastName); 
				scanf("%d", &userIn ); 
				int newID, oldID;
				char newFirst[30], oldFirst[30];
				char newLast[30], oldLast[30];
				float newGPA, oldGPA;
				Student* idChecker = initialStud;
				
				switch(userIn) {
					case 1 : //1) Updating the ID 
						printf("\nEnter the new ID: "); 
						scanf("%d", &newID); 
						while(idChecker!= NULL){
							if(newID== idChecker->ID) {
								printf("\nThis ID already exists");
								idChecker = initialStud; 
								printf("\nEnter the ID of the student: "); 
								scanf("%d", &newID); 
							}
							idChecker = idChecker->next; 
						}
						oldID = node->ID; 
						node->ID = newID; 
						printf("\n%d was sucessfully updated to %d", oldID, newID); 
						break; 
					case 2 : // 2) Updating first name 
						printf("\nEnter the new first name: "); 
						scanf("%29s", newFirst); 
						strcpy(oldFirst, node->firstName); 
						strcpy(node->firstName, newFirst); 
						printf("\n%s was sucessfully updated to %s", oldFirst, newFirst); 
						break; 
					case 3 : // 3) Updating last name 
						printf("\nEnter the new last name: ");
						scanf("%29s", newLast); 
						strcpy(oldLast, node->lastName); 
						strcpy(node->lastName, newLast);
						printf("\n%s was sucessfully updated to %s", oldLast, newLast); 
						break; 
					case 4 : // 4) Updating GPA
						printf("\nEnter the new GPA: "); 
						scanf("%f", &newGPA); 
						while((newGPA > 4.0) || (newGPA < 1.0)){ 
							printf("\nPlease enter a GPA between 1.0 and 4.0");
							printf("\nEnter the GPA of the student: ");
							scanf("%f", &newGPA); 
						}
						oldGPA = node->GPA; 
						node->GPA = newGPA; 
						if(previousNode == node){
							node->next = NULL; 
							insertNode(node); 
						}
						else{
							previousNode->next = node->next; 
							insertNode(node); 
						}
						printf("\n%f was sucessfully updated to %f", oldGPA, newGPA); 
						break;
					
					case 5 : // 5) Quit
						break; 
					
					default : 
						printf("\nInvalid input\n");
				}
			} while(user_input != 5);
			return; 
		}
		previousNode = node; 
		node = node->next; 
	}
	if(checker == 0) // use for IDs that weren't found 
	{
		printf("\nInvalid ID entered."); 
		return;
	}
}

// displays default menu 
void showMenu(){
	printf("\n---STUDENT MENU---");
	
	printf("\n\n(1) List all entered students");
	printf("\n(2) Add a Student");
	printf("\n(3) Remove a Student");
	printf("\n(4) Update a Student");
	
	printf("\n\n(5) Exit the program");
	printf("\n\n-----");
	printf("\n\n");
}

// displays Update menu 
void showUpdateMenu(char first[30], char last[30]){ 
	printf("\n---UPDATE MENU---");
	printf("\nWhat would you like to update about %s %s?", first, last);
	printf("\n\n(1) Student ID");
	printf("\n(2)  Student First Name");
	printf("\n(3) Student Last Name");
	printf("\n(4) Student GPA");
	
	printf("\n\n(5) Exit the program");
	printf("\n\n-----");
	printf("\n\n");
}

int main(){
	int userIn; 
	
	readStudentRecords();
	do{ 
		int id_input;
		char first_input[30] = "";
		char last_input[30] = "";
		float gpa_input = 0.0;
		int userID_in; 
		Student* idCheck = initialStud; 
		showMenu(); 
		printf("\nWhat would you like to do? "); 
		scanf("%d", &userIn); 
		
		switch(userIn){ 
			case 1 : // 1) Reveals list of students
				readList(); 
				break; 
			case 2 : // 2) Adding a student 
				printf("\nEnter the ID of the student: "); 
				scanf("%d", &id_input); 
				while(idCheck != NULL){ 
					if(id_input == idCheck->ID){ 
						printf("\nEntered ID is currently used by and existing student."); 
						idCheck = initialStud; 
						printf("\nEnter the ID of the student: "); 
						scanf("%d", &id_input); 
					}
					idCheck = idCheck->next; 
				}
				printf("\nEnter the first name of the student: "); 
				scanf("%29s", first_input); 
				printf("\nEnter the last name of the student: "); 
				scanf("%29s", last_input); 
				printf("\nEnter the GPA of the student: "); 
				scanf("%f", &gpa_input); 
				while((gpa_input > 4.0) || (gpa_input < 1.0)){ 
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); 
					printf("\nEnter the GPA of the student: "); 
					scanf("%f", &gpa_input); 
				}
				Student* anotherPtr = addStudNode(id_input, first_input, last_input, gpa_input); 
				insertNode(anotherPtr); 
				break; 
			case 3: // 3) Removing a student 
				printf("\nEnter the ID of the student you wish to delete: "); 
				scanf("%d", &userID_in); 
				removeStud(userID_in);
				break; 
			case 4 : // 4) Update Student info 
				printf("\nEnter the ID of the student you wish to update: "); 
				scanf("%d", &userID_in); 
				updateStud(userID_in); 
				break; 
			case 5 : // 5) Exiting the program 
				printf("\nExiting Student Program..."); 
				break; 
			default : 
				printf("\nInvalid input\n"); 
		}
	}while(userIn != 5);
	saveList(); 
	releaseList(); 
}







