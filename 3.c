#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int ary[256];
    int sum = 0;
    int max = 0;
    char *p = NULL;
    char *q = NULL;
    p = s;
    int tmp = 0;
    
	for(tmp=0;tmp<256;tmp++){
	    ary[tmp] = 0;
	}
	
    while(*p != '\0'){
        if(sum >= max){
            max = sum;
        }
        
        
        if (ary[(*p)] == 0){
            //printf("1 %c %d, sum %d max %d %d\n", *p, (*p)-'0', sum, max, ary[(*p)]);
            ary[(*p)] = 1;
			sum++;
            //printf("1 %c %d, sum %d max %d %d\n", *p, (*p)-'0', sum, max, ary[(*p)]);
            q = p;
        }else{
            //printf("2 %c %d, sum %d max %d %d\n", *p, (*p)-'0', sum, max, ary[(*p)]);
            sum = 0;
            for(tmp=0;tmp<256;tmp++){
	            ary[tmp] = 0;
	        }
            while(*q != *p){
                q--;
            }
            p = q;
            //printf("2 %c %d, sum %d max %d %d\n", *p, (*p)-'0', sum, max, ary[(*p)]);
        }
	
	    p++;
    }
    if(sum >= max){
        max = sum;
    }
    return max;
}
