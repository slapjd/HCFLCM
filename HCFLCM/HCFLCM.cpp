#include "FindPrimeAPI.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

int main() {
	int iNum1;
	cout << "Please enter a whole number: ";
	cin >> iNum1;
	cin.clear();

	int iNum2;
	cout << endl << "And again: ";
	cin >> iNum2;
	cin.clear();

	vector<int> vPFNum1 = primefactors(iNum1);
	vector<int> vPFNum2 = primefactors(iNum2);
	vector<int> vPFBoth;

	for (int iCounter = 0; iCounter < vPFNum1.size(); ++iCounter) {
		for (int iCounter2 = 0; iCounter2 < vPFNum2.size(); ++iCounter2) {
			if (vPFNum1[iCounter] == vPFNum2[iCounter2]) {
				vPFBoth.push_back(vPFNum2[iCounter2]);

				vPFNum1.erase(vPFNum1.begin() + iCounter);
				iCounter -= 1;
				vPFNum2.erase(vPFNum2.begin() + iCounter2);
				break;
			}
		}
	}

	int HCF = 1;
	int LCM = 1;

	for (int iCounter = 0; iCounter < vPFBoth.size(); ++iCounter) {
		HCF *= vPFBoth[iCounter];
	}


	for (int iCounter = 0; iCounter < vPFNum1.size(); ++iCounter) {
		LCM *= vPFNum1[iCounter];
	}
	for (int iCounter = 0; iCounter < vPFNum2.size(); ++iCounter) {
		LCM *= vPFNum1[iCounter];
	}
	if (HCF != 0) {
		LCM *= HCF;
	}

	cout << endl << "Highest Common Factor: " << HCF;
	cout << endl << "Lowest Common Multiple: " << LCM;

	cin.get();
	return 0;
}