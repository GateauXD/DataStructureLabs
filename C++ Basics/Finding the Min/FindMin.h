#ifndef FindMin_h
#define FindMin_h

// Declare and define the findMin function hereint 
int findMin(int numbers[], int start, int end)
{
	int index = start;
	int smallest = numbers[start];

	for (int i = start; i < end; i++)
	{
		if(smallest > numbers[i])
		{
			smallest = numbers[i];
			index = i;
		}
	}
	return index;
}

// Do not write any code below this line
#endif
