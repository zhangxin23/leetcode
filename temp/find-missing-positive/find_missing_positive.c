void bucket_sort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		while(a[i] != i + 1) {
			if(a[i] <= 0 || a[i] > n || a[i] == a[a[i] - 1])
				break;
			swap(a[i], a[a[i] - 1]);
		}
	}
}

int findMissingPositive(int a[], int n) {
	bucket_sort(a, n);

	for(int i = 0; i < n; i++) {
		if(a[i] != i + 1)
			return i + 1;
	}
	return n + 1;
}