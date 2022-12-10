#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,string> api, users;
unordered_map<int,pair<int,int>> response_time_api;

void api_calls(){
    for(int i=0;i<1000000;i++){
        // getting random api calls using rand function
        int current_call=rand()%1000;
        if(current_call=0) current_call++;
        // getting random response time for the current api call
        int current_response_time=rand()%100;
        if(current_response_time==0) current_response_time++;
        response_time_api[current_call].first+=current_response_time;
        response_time_api[current_call].second++;
    }
}

int get_avg_response_time(){
    int api_id=-1;
    double max_avg=0.0;
    for(auto i:response_time_api){
        int id = i.first;
        //getting average time for each api
        double avg_api_response=(i.second.first/(i.second.second*1.0));
        if(max_avg<avg_api_response){
            max_avg=avg_api_response;
            api_id=api[i.first];
        }
    }
    return api_id;
}
int main() 
{
    for(int i=1;i<101;i++){
        //  100 apis - each id for each api
        api[i]="api"+(i+'0');
    }
    // there are 1000 users, each user has certain apis
    for(int i=1;i<1001;i++){
        users[i]="user"+(i+'0');
    }

    api_calls();
// Printing the API with maximum average response time across the users.
    cout<<get_avg_response_time();
    return 0;
}

