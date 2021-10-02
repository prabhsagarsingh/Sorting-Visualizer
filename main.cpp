#include <conio.h>
#include <algorithm>
#include <time.h>
#include <stdlib.h> 
#include <graphics.h>

int arr[130];
int n = 130;

void randFill(){
	for(int i=0;i<130;i++){
		arr[i] = rand()%600;
	}
}

int page = 0; 

void draw(){
	delay(150);
	setactivepage(page);
	setvisualpage(1-page);   
	cleardevice();
	int a = 0 , b = 7 , d = 0;
	for(int i=0;i<n;i++){
		rectangle(a,0,b,arr[i]);
		a += 7;
		b += 7;
	}
	page = 1 - page;
}

void swap(int arr[],int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp; 
}

void selectionSort(){
    for(int i=0; i<n-1; i++){
        int min = i;
        
	for (int j=i+1; j<n; j++){
            if (arr[j] < arr[min]) {
                min = j;  
            }
        }
 
        swap(arr, min, i);
    	
		draw();
    	
	}
}

void bubbleSort(){
    for(int k=0; k<n-1; k++){

        for(int i=0; i<n-1-k; i++){
            if (arr[i] > arr[i + 1]){
                swap(arr,i,i+1);
            }
        }
 		
		draw();
        
    }
}

void insertionSort(){
    for (int i=1; i<n; i++){
        int value = arr[i];
        int j = i;
 
        while (j>0 && arr[j-1] > value){
            arr[j] = arr[j - 1];
            j--;
        }
 	   	
		arr[j] = value;
   		draw();
	}
}

void merge(int aux[], int low, int mid, int high){
    
	int k = low, i = low, j = mid + 1;
 
    while(i <= mid && j <= high){
        
		if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        
		else {
            aux[k++] = arr[j++];
        }
    }
 
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
 
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
    
	draw();
}
 
void mergesort(int aux[], int low, int high){
	
    if (high == low) {     
        return;
    }
 
    int mid = (low + ((high - low) >> 1));
 
    mergesort(aux, low, mid);          
    mergesort(aux, mid+1, high);     
 
    merge(aux, low, mid, high);       
}

void mergeSortStart(){
	int aux[n] = {0};
	
	for(int i=0;i<n;i++)
		aux[i] = arr[i]; 
	
	mergesort(aux,0,n-1);
	draw();
}

int partition(int start, int end){

    int pivot = arr[end];
 
	int pIndex = start;
 
    for(int i=start; i<end; i++){
        if(arr[i] <= pivot){
            swap(arr,i,pIndex);
            pIndex++;
        }
    }
 
    swap(arr,pIndex,end);
 
    return pIndex;
}
 
void quicksort(int start, int end){
    if (start >= end) {
        return;
    }
 
    int pivot = partition(start, end);
 
    quicksort(start,pivot-1);
    
	quicksort(pivot+1,end);
	draw();
}

void quicksortstart(){
	draw();
	quicksort(0,n-1);
}

void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if(left < n && arr[left] > arr[largest])
    	largest = left;
  
    if(right < n && arr[right] > arr[largest])
    	largest = right;
  
    if (largest != i) {
    	swap(arr,i,largest);
    	heapify(n, largest);
    }
}
  
void heapSort() {
	for(int i=n/2-1; i>=0; i--)
    	heapify(n,i);
  	
  	draw();
  	
    for(int i=n-1; i>=0; i--) {
    	swap(arr,0,i);
      	heapify(i,0);
    	draw();
	}
}

int main(){
	
	srand(time(0));
	
	initwindow(910,600,"Sorting Visualizer",15,15);
	
	randFill();
	draw();
	
	selectionSort();
	getchar();
	
	randFill();
	bubbleSort();
	getchar();
	
	randFill();
	insertionSort();
	getchar();
	

	randFill();
	mergeSortStart();
	getchar();

	randFill();
	quicksortstart();
	getchar();

	randFill();
	heapSort();
	getchar();
		
	closegraph();
	return 0;	
}
