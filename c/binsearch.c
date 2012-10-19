int binsearch(int s[], int key, int low, int high)
{
	int middle;
	if (low > high) return -1;
	middle = (low+high)/2;
	if (key == s[middle]) 
		return middle;
	else if (key < s[middle]) 
		return binsearch (s, key, low, middle - 1);
	else
		return binsearch (s, key, middle + 1, high);
}

