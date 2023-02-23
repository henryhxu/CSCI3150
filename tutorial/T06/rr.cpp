 /*
    Time Complexity: O(N * log(N) + W / M)
    Space Complexity: O(N)

    Where ‘N’ is the total number of processes, and ‘W’ is the sum of burst times of the given process.
    And ‘M’ is the time quantum.
*/

#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// To sort the processes on the basis of their arrival time.
bool compare(vector<int> &a, vector<int> &b)
{
    if(a[1] != b[1])
        return a[1] < b[1];
    else 
        return a[0] < b[0];
}

vector<int> getCompletionTime(vector<int> &arrivalTime, vector<int> &burstTime, int n, int m)
{
    /*
        To store the information of processes. First element stores the process ID, 
        second element and third element stores arrival time and burst time respectively.
    */
    vector<vector<int>> process;
    process.resize(n);

    // To store the remaining burst time of ach process.
    vector<int> remTime(n);

    for (int i = 0; i < n; i++)
    {
        process[i].resize(3);

        process[i][0] = i;
        process[i][1] = arrivalTime[i];
        process[i][2] = burstTime[i];

        remTime[i] = burstTime[i];
    }

    // To store the completion time of each proces.
    vector<int> completionTime(n);

    // Sort the processes in increasing w.r.t arrival time.
    sort(process.begin(), process.end(), compare);

   
    // To keep track of the current time.
    int currentTime = 0;

    queue<int> readyQueue;

    // Push the first process in the ready queue.
    readyQueue.push(process[0][0]);

    currentTime = process[0][1];

    // To keep track of last index of process which is placed in the ready queue.
    int lastID = 1;

    // To keep the count of complete processes.
    int completed = 0;

    while (completed != n)
    {
        // Get the front element from the ready queue.
        int id = readyQueue.front();
        readyQueue.pop();

        if (remTime[id] > m)
        {
            // Execute the process for 1 time quantum.
            remTime[id] -= m;
            currentTime += m;
        }
        else
        {
            // Process can be executed completely.
            currentTime += remTime[id];
            completionTime[id] = currentTime;
            remTime[id] = 0;
            completed = completed + 1;
        }

        // Push all the processes in the readyTueue, for which the arrival time is less than the current time.
        while (lastID < n && process[lastID][1] <= currentTime)
        {
            readyQueue.push(process[lastID][0]);
            lastID = lastID + 1;
        }

        // Push the current process at the end of the queue if the remaining burst time is greater than zero.
        if (remTime[id] > 0)
        {
            readyQueue.push(id);
        }

        // Push the next process if ready queue is empty.
        if (readyQueue.empty())
        {
            if (lastID != n)
            {
                currentTime = process[lastID][1];
                readyQueue.push(process[lastID][0]);
                lastID = lastID + 1;
            }
        }
    }

    return completionTime;
} 

int main()
{
	vector<int> arrive_time={0,5,1,6,8};
	vector<int> burst_time={8,2,7,3,5};
	int quantum=3;
	int N=5;
	vector<int> complement_time=getCompletionTime(arrive_time,burst_time,N,quantum);
	for(int i=0;i<complement_time.size();i++)
		cout<<"process "<<i+1<<" complete time： "<<complement_time[i]<<endl;
}