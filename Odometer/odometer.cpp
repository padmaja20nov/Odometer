#include <iostream>
#include <math.h>

using namespace std;
#define MAX 8

int readingIsValid(long int );
int isAscending(long int );
int anyZeroDigit(long int);
long int findPrevReading(long int);
long int findNextReading(long int );
long int distancec(long int, long int);

int readingIsValid(long int currentReading){
	return isAscending(currentReading) && anyZeroDigit(currentReading);	
}



int isAscending(long int currentReading){
	int prev;
	prev = currentReading % 10;
	currentReading /= 10;
	while(currentReading){
		if((currentReading % 10 < prev)) {
			prev = currentReading % 10;
			currentReading /= 10;
		}else{
			return 0;
		}
	}
	return 1;
}

int anyZeroDigit(long int currentReading){
	while(currentReading){
		if (currentReading % 10 != 0 ){
			currentReading /= 10;
		}else{
			return 0;
		}
	}	
	return 1;
}

long int findPrevReading(long int currentReading){
	while(1){
		currentReading--;
		if( readingIsValid(currentReading) )
			return currentReading;
	}
	
}

long int findNextReading(long int currentReading){
	while(1){
		currentReading++;
		if( readingIsValid(currentReading) )
			return currentReading;
	}
}

int countDigits(long int currentReading){
	int count = 0;
	while(currentReading){
		count++;
		currentReading /= 10;
	}
	return count;
}

int main(){
	long int currentReading;
	long int nextReading;
	long int prevReading;
	int digits = 0;
	cin >> currentReading;
	if( readingIsValid(currentReading) ){
		nextReading = findNextReading(currentReading);
		prevReading = findPrevReading(currentReading);
		
		digits = countDigits(currentReading);
		
		if( (nextReading % pow(10, digits)) > 0){
			cout << "Next Reading is: " << nextReading << endl;
		}else{
			 nextReading = generateLowerLimit(digits);
		}
		cout << "Previous Reading is: " << prevReading << endl;
	}else{
		cout << "Invalid input";
	}
	return 0;
}
