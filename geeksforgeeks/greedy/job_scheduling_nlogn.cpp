////=========== Job Sequencing Problem | Set 1 (Greedy Algorithm)
/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. 
It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. 
How to maximize total profit if only one job can be scheduled at a time.

Input: Four Jobs with following deadlines and profits
  JobID    Deadline      Profit
    a        4            20   
    b        1            10
    c        1            40  
    d        1            30
Output: Following is maximum profit sequence of jobs
        c, a   


Input:  Five Jobs with following deadlines and profits
   JobID     Deadline     Profit
     a         2           100
     b         1           19
     c         2           27
     d         1           25
     e         3           15
Output: Following is maximum profit sequence of jobs
        c, a, e
		
Idea :
1) Sort all jobs in decreasing order of profit.
2) Initialize the result sequence as first job in sorted jobs.
3) Do following for remaining n-1 jobs
.......a) If the current job can fit in the current result sequence 
          without missing the deadline, add current job to the result.
          Else ignore the current job.

TC : O(nlogn)

*/

#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

typedef struct job_s
{
	char name;
	int deadline;
	int profit;
	
	job_s() {}
	
	job_s(char Name, int Deadline, int Profit)
	{
		name=Name;
		deadline = Deadline;
		profit = Profit;
	}
} Job;

bool compare(Job a, Job b)
{
	return a.profit > b.profit;
}

int getMaxProfit(Job *jobs, int n)
{
	sort(jobs,jobs+n,compare);
	
	int jobsIncluded=0;
	int deadLine=1;
	for(int i=0;i<n;i++)
	{
		Job currentJob = jobs[i];
		if(currentJob.deadline>=deadLine)
		{
			jobsIncluded++;
			deadLine++;
		}
	}
	
	return jobsIncluded;
}

int main()
{
    int n;
	cin >> n;
	
	Job *jobs = new Job[n];
	for(int i=0;i<n;i++)
	{
		cin >> jobs[i].name >> jobs[i].deadline >> jobs[i].profit;	
	}
	cout << getMaxProfit(jobs,n) << endl;	
    return 0;
}