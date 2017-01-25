#pragma once
#include <cmath>
#include <vector>
#include <iostream>

using std::vector;

bool isprime(const unsigned iNumber) {
	if (iNumber == 1) {
		return false;
	}
	else if (iNumber == 2 || iNumber == 3) {
		return true;
	}
	else if (iNumber % 2 == 0 || iNumber % 3 == 0) {
		return false;
	}

	for (int iCounter = 6; (iCounter - 1) <= sqrt(iNumber); iCounter += 6) {
		if (iNumber % (iCounter - 1) == 0 || iNumber % (iCounter + 1) == 0) {
			return false;
		}
	}

	return true;
}

vector<unsigned> primefactors(unsigned iNumber) {
	vector<unsigned> vReturnVal;

	while (!isprime(iNumber)) {
		unsigned iPrev = iNumber;

		if (iNumber % 2 == 0) {
			iNumber /= 2;
		}
		else if (iNumber % 3 == 0) {
			iNumber /= 3;
		}
		else {
			for (unsigned iCounter = 6; (iCounter - 1) <= sqrt(iNumber); iCounter += 6) {
				if (iNumber % (iCounter - 1) == 0) {
					iNumber /= (iCounter - 1);
				}
				else if (iNumber % (iCounter + 1) == 0) {
					iNumber /= (iCounter + 1);
				}
			}
		}

		vReturnVal.push_back(iPrev / iNumber);
	}

	vReturnVal.push_back(iNumber);
	return vReturnVal;
}