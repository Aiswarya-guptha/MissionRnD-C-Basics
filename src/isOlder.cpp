/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	//initializing dates to 0
	int d1[3] = { 0, 0, 0 }, d2[3] = { 0, 0, 0 };
	for (int value = 0, iter = 0; iter < 10; iter++){
		if (iter == 2 || iter == 5){
			//if 3rd and 6th position is not '-'
			if (dob1[iter] != '-' || dob2[iter] != '-')
				return -1;
			else {
				iter++;
				value++;
			}
		}

		if (dob1[iter] < '0' || dob1[iter] > '9' || dob2[iter] < '0' || dob2[iter] > '9')
			//if it is not a integer between 0 and 9
			return -1;

		else{
			//computing values of dates
			d1[value] = (dob1[iter] - '0') + (d1[value] * 10);
			d2[value] = (dob2[iter] - '0') + (d2[value] * 10);
		}
	}

	if (d1[1] > 12 || d2[1]>12)
		//if not an appropriate month
		return -1;
	//if not an appropriate date
	if (d1[0] > 31 || d2[0] > 31)	return -1;	
	if ((d1[1] == 4 || d1[1] == 6 || d1[1] == 9 || d1[1] == 11 ) && d1[0] > 30)	return -1;
	if ((d2[1] == 4 || d2[1] == 6 || d2[1] == 9 || d2[1] == 11) && d2[0] > 30)	return -1;
	if (d1[1] == 2 && d1[0] > 28){
		if ((d1[2] % 4) == 0 && d1[0] == 29){}
		else	return -1;
	}
	if (d2[1] == 2 && d2[0] > 28){
		if ((d2[2] % 4) == 0 && d2[0] == 29){}
		else	return -1;
	}
	//finding the eldest person
	for (int iter = 2; iter >= 0; iter--){
		if (d1[iter] > d2[iter])
			return 2;
		else if (d1[iter] < d2[iter])
			return 1;
	}
	//if both are equal
	return 0;
}
