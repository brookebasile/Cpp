void shellSort(vector<int>& V)
{
	bool flag = true;
	int i, numLength = V.size();

	int d = numLength;
	while (flag || (d>1))    // bool flag 
	{
		flag = false;  //reset flag to 0 to check for
		// future swaps     
		d = (d + 1) / 2;
		for (i = 0; i < (numLength - d); i++)
		{
			if (V[i + d] < V[i])
			{
				swapper(V[i], V[i + d]);

				flag = true;     //tells swap has occurred
			}
		}
	}
}
void swapper(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
