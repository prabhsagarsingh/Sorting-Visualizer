void swap(int arr[],int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp; 
}

void selectionSort(){
    int minIdx;
    
	for(int i=0; i<n-1; i++){
        
		minIdx = i;
        
		for(int j=i+1; j<n; j++){
        
			if (arr[j] < arr[minIdx])
            	minIdx = j;
    	}
        
		swap(arr,minIdx,i);
    	
		draw();
	}
}

void bubbleSort(){
    for (int i=0; i<n-1; i++){    
    	
		for (j = 0; j < n-i-1; j++){
        	
			if (arr[j] > arr[j+1]){
            	swap(arr,j,j+1);
			}
		
		}
		draw();
	}
}
