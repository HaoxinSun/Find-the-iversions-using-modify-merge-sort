#include<iostream>
#include<string>
#include<string>
#include<map>
#include"Find_inversions.h"

using namespace std;
int main()
{
	//let A[1...n] be a array of n distinct numbers, if the subscript i <j , having A[i]>A[j],then the pair(i,j)
	// is called an inversion of A. 
	//author:haoxinsun Date:10-18-2014
	cout << "Enter the array A's nmubers" << endl;
	double innumber;
	vector<double> ievc;
	map<double, int> imap;
	while (cin>>innumber)
	{
		ievc.push_back(innumber);
	}
	vector<double>::iterator beg = ievc.begin();
	vector<double>::iterator end = ievc.end()-1;
	//call the Find_inversion function to calculate the inversions 
	Find(imap,beg,end);
	//output the total inversions in vector container A
	long int sum = 0;
	for (map<double, int>::iterator beg = imap.begin(); beg != imap.end(); ++beg)
	{
		sum += beg->second;
	}
	cout << "The total inversions number are : " << sum << endl;
	system("pause");
	return 0;
}