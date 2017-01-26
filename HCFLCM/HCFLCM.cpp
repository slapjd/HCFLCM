#include "FindPrimeAPI.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

int main() {
	unsigned iNum1;
	cout << "Please enter a positive whole number: ";
	cin >> iNum1;
	cin.clear();

	unsigned iNum2;
	cout << endl << "And again: ";
	cin >> iNum2;
	cin.clear();

	vector<unsigned> vPFNum1 = primefactors(iNum1);
	vector<unsigned> vPFNum2 = primefactors(iNum2);
	vector<unsigned> vPFBoth;

//	cout << endl << "[DEBUG] " << var;
//	cout << endl << "[DEBUG] FLAG!";

	for (unsigned iCounter = 0; iCounter < vPFNum1.size(); ++iCounter) {
		for (unsigned iCounter2 = 0; iCounter2 < vPFNum2.size(); ++iCounter2) {
			if (vPFNum1[iCounter] == vPFNum2[iCounter2]) {
				vPFBoth.push_back(vPFNum2[iCounter2]);
				
				vPFNum1.erase(vPFNum1.begin() + iCounter);
				iCounter -= 1;
				vPFNum2.erase(vPFNum2.begin() + iCounter2);
				break;
			}
		}
	}

	unsigned HCF = 1;
	unsigned LCM = 1;

	cout << endl << "[DEBUG] " << (0 < vPFBoth.size());

	for (unsigned iCounter = 0; iCounter < vPFBoth.size(); ++iCounter) {
		HCF *= vPFBoth[iCounter];
	}

	for (unsigned iCounter = 0; iCounter < vPFNum1.size() && !vPFNum1.empty(); ++iCounter) {
		LCM *= vPFNum1[iCounter];
	}
	for (unsigned iCounter = 0; iCounter < vPFNum2.size() && !vPFNum2.empty(); ++iCounter) {
		LCM *= vPFNum1[iCounter];
	}
	if (HCF != 0) {
		LCM *= HCF;
	}

	cout << endl << "Highest Common Factor: " << HCF;
	cout << endl << "Lowest Common Multiple: " << LCM;

	std::string tmp;
	cin.clear();
	cin >> tmp;

	return 0;
}