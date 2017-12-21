#ifndef InsertLookup_h
#define InsertLookup_h

bool find(long* list, long size, long value){
	int i = 0;
	int j = size - 1;
	int mid = (i + j) / 2;

	if (i <= j)
	{
		if (list[mid] == value) {
			return true;
		}

		if(list[mid] < value){
			i == mid + 1;
			mid = (i + j) / 2;
		}

		else {
			j = mid - 1;
			mid = (i + j) / 2;
		}
	}

   return false;
}

void insertion_sort(long list[], long size){
   long n = size;
   for (long i = 1; i < n; i++) {
       long j = i;
       while (j > 0 && list[j-1] > list[j]){
           long temp = list[j];
           list[j] = list[j-1];
           list[j-1] = temp;
           j = j - 1;
       }
   }
}

void insert(long* list, long size, long value){
   list[size-1] = value;
   insertion_sort(list, size);
}

#endif
