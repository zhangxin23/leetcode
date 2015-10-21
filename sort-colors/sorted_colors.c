void sortColors(int a[], int n) {
	int red = 0, blue = n - 1;

	for(int i = 0; i < blue + 1;) {
		if(a[i] == 0)
			swap(a[i++], a[red++]);
		else if(a[i] == 2)
			swap(a[i], a[blue--]);
		else
			i++;
	}
}