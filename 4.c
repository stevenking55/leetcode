
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int i,j,k;
	int tag;
	int *p = NULL;
	int q;
	int odd;
	
    if((nums1Size + nums2Size)%2){
		tag = (nums1Size + nums2Size)/2 + 1;
		odd = 1;
	}else{
		tag = (nums1Size + nums2Size)/2;
		odd = 0;
	}
	
	i = 0;
	j = 0;
	k = 0;
	if(nums1Size){
		p = nums1;
	}else{
		p = nums2;
	}
	
	while(k < tag+1){
		q = *p;
		if((*(nums1+i) <= *(nums2+j)) && (i<nums1Size) && (j<nums2Size)){
			p = nums1+i;
			i++;
			k++;
		}else if((*(nums1+i) > *(nums2+j)) && (i<nums1Size) && (j<nums2Size)){
			p = nums2+j;
			j++;
			k++;
		}else if(i>=nums1Size){
			p = nums2+j;
			j++;
			k++;
		}else if(j>=nums2Size){
			p = nums1+i;
			i++;
			k++;
		}	
	}
	if(odd){
		return (double)q;
	}else{
		return (double)(*p+q)/2;
	}
}
