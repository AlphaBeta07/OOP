#include <iostream>
using namespace std;
class Job{
public:
    string name;
    int resources;
    int profit;
    double ratio;
    Job(string n, int r, int p) : name(n), resources(r), profit(p){
        ratio=static_cast<double>(profit)/resources;
    }
};
void sortJobs(Job jobs[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if(jobs[j].ratio<jobs[j+1].ratio){
                Job temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
            }
        }
    }
}
void allocate_resources(Job jobs[], int n, int total_resources){
    sortJobs(jobs, n);
    string allocated_jobs[10];
    int total_profit=0;
    int resources_used=0;
    int allocated_count=0;
    for(int i=0; i<n; i++){
        if(resources_used+jobs[i].resources<=total_resources){
            allocated_jobs[allocated_count++]=jobs[i].name;
            resources_used+=jobs[i].resources;
            total_profit+=jobs[i].profit;
        }
    }
    cout<<"Allocated Jobs: ";
    for (int i=0; i<allocated_count; i++){
        cout<<allocated_jobs[i]<<" ";
    }
    cout<<endl;
    cout<<"Total Profit:"<<total_profit<<endl;
}
int main(){
    Job jobs[]={
        Job("Job1", 2, 50),
        Job("Job2", 3, 60),
        Job("Job3", 4, 70),
        Job("Job4", 5, 100)
    };
    int total_resources=10;
    int n=sizeof(jobs)/sizeof(jobs[0]);
    allocate_resources(jobs,n,total_resources);
    return 0;
}
