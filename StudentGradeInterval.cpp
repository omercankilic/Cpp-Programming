#include <iostream>
#include <queue>
using namespace std;

class grade_interval{
    public:
        int lower_bound;
        int higher_bound;
        grade_interval(int lower_bound,int higher_bound):lower_bound(lower_bound),higher_bound(higher_bound){}
};
bool operator<(const grade_interval& in1,const grade_interval& in2){
    return in1.lower_bound < in2.lower_bound; 
}

class student{
    public:
        int id;
        int point;
        student(int id, int point):id(id),point(point){}
};
bool operator<(const student& st1,const student& st2)
{
    return st1.point < st2.point;
}

void studentsInInterval(priority_queue<student> st,priority_queue<grade_interval> gr_int,int st_size,int gr_int_size){
    while(!gr_int.empty()){
        cout<<gr_int.top().lower_bound<<" "<<gr_int.top().higher_bound<<endl;
        if(gr_int.top().lower_bound<=st.top().point && st.top().point<=gr_int.top().higher_bound){
            while(gr_int.top().lower_bound<=st.top().point && st.top().point<=gr_int.top().higher_bound && !st.empty()){
                cout<<st.top().id<<endl;
                st.pop();
            }
            gr_int.pop();
        }else{
            st.pop();
        }
    }
}

int main(){

    priority_queue<grade_interval> intervals;
    priority_queue<student> students;
    int arr[2];
    int number_of_students;
    cin>>number_of_students;
    for(int i = 0; i<number_of_students; i++)
    {   cin>>arr[0];
        cin>>arr[1];
        students.push(student(arr[0],arr[1]));
    }
    int number_of_intervals;
    cin>>number_of_intervals;
    for(int i=0;i<number_of_intervals;i++){
        cin>>arr[0];
        cin>>arr[1];
        intervals.push(grade_interval(arr[0],arr[1]));
    }
    
    //cout<<endl;
    int size=students.size();
    int size2= intervals.size();
    
    studentsInInterval(students,intervals,size,size2);

    return 0;
}
