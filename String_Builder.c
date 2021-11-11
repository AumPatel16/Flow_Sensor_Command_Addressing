#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#include "String_Builder.h"

char globalArray[50] = "\0";

//declare functions

/*
int main (){
	//input parameters
	
	//int p = setRamp(4932,235);
	int p = readRamp();
	printf("the size was %d", p);
	printf("\nthe global array is: ");
	int i;
	for (i = 0; i<p; i++){
		printf("%c",globalArray[i]);
	}
    return 0;
}//*/

//SET RAMP function takes the flowrate you want to go to and the transition time.
//flow and time will be a 3 or 4 digit ints ex. 1234 and assumed to function as 12.34 or 537 is 5.37
int setRamp(int flow, int time){
	int flowW = flow/100; int flowF = flow%100;

	int timeW = time/100; int timeF = time%100;

	//set the global string back to nulls
	int j;
	for (j = 0; j<50; j++){
		globalArray[j]='\0';
	}
	
	char cmd[4] = "ASS";
	strcat(globalArray,"@02"); strcat(globalArray,cmd);

	//parse the int flow into strings.
	char flowWhole[3] = "\0"; itoa(flowW, flowWhole,10);
	char flowFloat[3] = "\0"; itoa(flowF, flowFloat, 10);
	//append the flow on to global string
	strcat(globalArray,flowWhole); 
	strcat(globalArray,"."); 
	strcat(globalArray,flowFloat); 
	strcat(globalArray,",");
	//parse the time into strings
	char timeWhole[3] = "\0"; itoa(timeW, timeWhole,10);
	char timeFloat[3] = "\0"; itoa(timeF, timeFloat,10);
	//append the time on to the global array
	strcat(globalArray,timeWhole);
	strcat(globalArray,".");
	strcat(globalArray,timeFloat);
	strcat(globalArray,"");

	//BCC calcuation and append
	int size = strlen(globalArray);
	int sum = 0;
	int i;
	for (i = 4; i<size; i++)
	{
		sum +=(int)(globalArray[i]);
	}
	sum %= 128;
	char BCC = (char)sum;
	globalArray[size] = BCC;

	return size+1;//add one to account for the null termination.
}

//execute function just starts whatever ramp has been set.
int executeRamp(){
	//set the global string back to nulls
    int j;
	for (j = 0; j<50; j++){
		globalArray[j]='\0';
	}

	char cmd[4] = "IST";
	strcat(globalArray,"@02"); strcat(globalArray,cmd);
	strcat(globalArray,"");

	//BCC calcuation and append
	int size = strlen(globalArray);
	int sum = 0;
	int i;
	for (i = 4; i<size; i++)
	{
		sum +=(int)(globalArray[i]);
	}
	sum %= 128;
	char BCC = (char)sum;
	globalArray[size] = BCC;

	return size+1;//add one to account for the null termination.
}

int readFlowRate(){
	//set the global string back to nulls
    int j;
	for (j = 0; j<50; j++){
		globalArray[j]='\0';
	}

	char cmd[4] = "RFV";
	strcat(globalArray,"@02"); strcat(globalArray,cmd);
	strcat(globalArray,"");

	//BCC calcuation and append
	int size = strlen(globalArray);
	int sum = 0;
	int i;
	for (i = 4; i<size; i++)
	{
		sum +=(int)(globalArray[i]);
	}
	sum %= 128;
	char BCC = (char)sum;
	globalArray[size] = BCC;

	return size+1;//add one to account for the null termination.
}


int readFullScaleFlowRate(){
	//set the global string back to nulls
    int j;
	for (j = 0; j<50; j++){
		globalArray[j]='\0';
	}

	char cmd[4] = "RFS";
	strcat(globalArray,"@02"); strcat(globalArray,cmd);
	strcat(globalArray,"");

	//BCC calcuation and append
	int size = strlen(globalArray);
	int sum = 0;
	int i;
	for (i = 4; i<size; i++)
	{
		sum +=(int)(globalArray[i]);
	}
	sum %= 128;
	char BCC = (char)sum;
	globalArray[size] = BCC;

	return size+1;
}

int readRamp(){
	//set the global string back to nulls
    int j;
	for (j = 0; j<50; j++){
		globalArray[j]='\0';
	}

	char cmd[4] = "RSS";
	strcat(globalArray,"@02"); strcat(globalArray,cmd);
	strcat(globalArray,"");

	//BCC calcuation and append
	int size = strlen(globalArray);
	int sum = 0;
	int i;
	for (i = 4; i<size; i++)
	{
		sum +=(int)(globalArray[i]);
	}
	sum %= 128;
	char BCC = (char)sum;
	globalArray[size] = BCC;

	return size+1;
}


































//ARCHIVE CODE

	/*
	//base command string
	char cmd[4] = "ASS";
	//Assign the number as string and split it into two strings.
	char input[5];
	itoa(in,input,10);
	char numWhole[3] = "\0";
	numWhole[0] = input[0]; numWhole[1] = input[1]; numWhole[2] = '\0';
	char numFloat[3] = "\0";
	numFloat[0] = input[2]; numFloat[1] = input[3]; numFloat[2] = '\0';
	char timeStr[3] = "\0";
	itoa(time,timeStr,10);

	char ETX[2] = "";

	strcat(globalArray,"@02");
	strcat(globalArray,cmd);
	strcat(globalArray,numWhole);
	strcat(globalArray,".");
	strcat(globalArray,numFloat);
	strcat(globalArray,",");
	strcat(globalArray,timeStr);
	strcat(globalArray,ETX);

	printf("this is the string %s", globalArray);
	//get the size of the total string (without BCC);
	int size = strlen(globalArray);
	int sum = 0;
	for (int i = 4; i<size; i++)
	{
		sum +=(int)(globalArray[i]);

	}
	printf("the sum was %d", sum);

	sum %= 128;

	char BCC = (char)sum;

	//int k = (int)'';
	printf("\nthe sum was %d", sum);
	printf("\nthe BCC was %c", BCC);

	globalArray[size] = BCC;

	printf("\nthe final global array is %s", globalArray);
	//*/
