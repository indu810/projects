#include <stdio.h>
// Function to find the waiting time for all processes
int waitingtime(int pro[], int n,int burst_time[], int wait_time[]) {
   // waiting time for first process is 0
   wait_time[0] = 0;
   int i;
   // calculating waiting time

   for (i = 1; i < n ; i++ )
       wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
   return 0;
}
// Function to calculate turn around time
int turnaroundtime( int proc[], int n,int burst_time[], int wait_time[], int tat[]) {
   // calculating turnaround time by adding
   // burst_time[i] + wait_time[i]
   int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}
//Function to calculate average time
int avgtime( int proc[], int n, int burst_time[]) {
   int wait_time[n], turn_a_time[n], total_wait = 0, total_tat = 0;
   int i;
   //Function to find waiting time of all processes
   waitingtime(proc, n, burst_time, wait_time);
   //Function to find turn around time for all processes
   turnaroundtime(proc, n, burst_time, wait_time, turn_a_time);
   //Display processes along with all details
   printf("Processes  Burst   Waiting Turn around \n");
   // Calculate total waiting time and total turn
   // around time
   for ( i=0; i<n; i++) {
      total_wait = total_wait + wait_time[i];
      total_tat = total_tat + turn_a_time[i];
      printf(" %d\t  %d\t\t %d \t%d\n", i+1, burst_time[i], wait_time[i], turn_a_time[i]);
   }
   printf("Average waiting time = %f\n", (float)total_wait / (float)n);
   printf("Average turn around time = %f\n", (float)total_tat / (float)n);
   gantt_chart(proc,n,burst_time,wait_time,turn_a_time);
   return 0;
}

void gantt_chart(int proc[], int n, int burst_time[],int waiting_time[],int turn_a_time[])
{


  int i=0;
   printf(" Process \t Burst Time \t Waiting Time \t Turn Around Time \n");
   for(i=0;i<n;i++){

       printf("%d\t\t %d\t\t %d\t\t %d\n",i+1,burst_time[i],waiting_time[i],turn_a_time[i]);
     }

}
// main function
int main() {
   //process id's
   int i;
   int proc[3];
   //int n = sizeof proc / sizeof proc[0];
   //Burst time of all processes
   int n=3;
   int burst_time[3] ;

   printf("Enter burst time :\n ");
   for(i=0;i<n;i++){
        printf("Process %d ",i+1);

        scanf("%d",&burst_time[i]);

        //fflush(stdin);
   }

   avgtime(proc, n, burst_time);

   return 0;
}
