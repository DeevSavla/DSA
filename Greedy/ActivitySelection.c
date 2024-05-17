#include <stdio.h>
# define SIZE 3
void main() {
    int start[SIZE];
    int finish[SIZE];
    int first,temp,count=1;
    int work[SIZE]={0};
    for(int i=0;i<SIZE;i++){
    printf("Enter start and finish time of the activity %d:",i);
    scanf("%d %d",&start[i],&finish[i]);
    }
    //ascending order of finish time
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(finish[j]>finish[j+1]){
                temp=finish[j];
                finish[j]=finish[j+1];
                finish[j+1]=temp;
                temp=start[j];
                start[j]=start[j+1];
                start[j+1]=temp;
            }
        }
    }
    first=finish[0];
    work[0]=0;
    for(int i=1;i<SIZE;i++){
        if(start[i]>=first){
            first=finish[i];
            work[count]=i;
            count++;
        }
    }
    printf("The maximum activities that can be done are %d\n",count);
    printf("The activities are :");
    int k=0;
    while(k<count){
        printf("%d ",work[k]);
        k++;
    }
}
