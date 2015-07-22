#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Odometer {

set<int> odometerReadings;

private:
	int* convertToIntArray(string str) {
		int *arr = new int[10];
		for (int i=0; i<str.length(); i++ ) {
			arr[i] = str.at(i) - '0';
		}
		return arr;
	}
	
public:

int* nextReading (string meterReading) {
	int len = meterReading.length();
	int *mReading = convertToIntArray(meterReading);
	cout<< len-1 << endl;
	mReading[len] = 10;

	for (int i=len-1; i>=0 ; i--) {
		if (mReading[i+1] - mReading[i] != 1) {
			mReading[i]++;
			for (int j=i+1; j<len; j++) {
				mReading[j] = mReading[j-1] + 1;
			}
			for(int k=0; k<len; k++) {
				cout<< mReading[k];
			}
			
			return mReading;
		}
	}
	
	int startReset;
	if(mReading[0] == 1) {
		startReset = 9 - len;
	} else {
		startReset = 1;
	}
	for (int i=0;i < len; i++) {
		mReading[i] = startReset++;
	}
	return mReading;
}

};

int main(int argc, char** argv) {

	Odometer od;
	od.nextReading("1234");
	return 0;
}
