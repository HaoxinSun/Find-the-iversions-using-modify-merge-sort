#include"Find_inversions.h"
#include<iostream>
#include<cfloat>
using namespace std;

//define the function to find inversions in a vector container
//use the divide and conquer methdo(modify merge sort)
int Find(map<double,int>&imap,vector<double>::iterator beg,vector<double>::iterator end)
{
	//cout << "call the functin " << endl;
	if (beg != end)
	{
		vector<double>::iterator middle = beg + (end - beg) / 2;
		Find(imap, beg, middle);
		Find(imap, middle + 1, end);
		//caclulate the inversions 
		vector<double> l_ievc(beg, middle + 1);
		vector<double> r_ievc(middle + 1, end + 1);
		//insert the sentinel
		l_ievc.push_back(DBL_MAX);
		r_ievc.push_back(DBL_MAX);
		vector<double>::size_type k = 0;
		vector<double>::difference_type distance = end - beg + 1;
		vector<double>::iterator l_beg = l_ievc.begin();
		vector<double>::iterator r_beg = r_ievc.begin(), c_beg = r_beg;
		while (k!=distance)
		{
			if (*l_beg<*c_beg)
			{
				*(beg + k) = *l_beg;
				vector<double>::size_type pin = c_beg - r_beg;
				imap[(*l_beg)] += pin;
				++l_beg;
			}
			else
			{
				*(beg + k) = *c_beg;
				++c_beg;
			}
			++k;
		}
	}
	
	return 0;
}