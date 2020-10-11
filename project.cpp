#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <map>

#define NIL -1 
#define GRADES 21

class Student{
    public:
        int id;
        int testGrade = NIL;
        int projectGrade = NIL;
        bool graded = false;

        std::vector<int> friends;

        void addFriend(int id) {friends.push_back(id);}

};

class Grades{
    public:
        std::vector<int> studs;

        void addStud(int id) {studs.push_back(id);}
};

class Graph{
    public:
        int nstudents;
        int id = 0;

        std::vector<Student> s_aux;
        std::vector<Grades> grades;

        Graph(int students, int relations){
            nstudents = students;
            int grade;

            for (int i = 0; i < GRADES; i++){
                Grades g;
                grades.push_back(g);
            }

            for(int i=0; i<students; i++){
                Student student;

                scanf("%d", &grade);

                student.id = id++;

                student.testGrade = grade;
                
                s_aux.push_back(student);

                grades[grade].addStud(student.id);
            }

            int friend1, friend2;
            for(int i = 0; i < relations; i++){

                scanf("%d %d",&friend1, &friend2);
                
                s_aux[friend2-1].addFriend(friend1-1);
            }
        }

        void visit(int id, int grade){

            if (s_aux[id].testGrade <= grade) s_aux[id].projectGrade = grade;
            else s_aux[id].projectGrade = s_aux[id].testGrade;

            s_aux[id].graded = true;

            for(unsigned long int i=0; i < s_aux[id].friends.size(); i++)
                if(!s_aux[s_aux[id].friends[i]].graded) {
                    visit(s_aux[s_aux[id].friends[i]].id, grade);
                }
        }

        void DFS(){

            for(int i = GRADES; i >= 0; i--)
                for(unsigned long int j = 0; j < grades[i].studs.size(); j++)
                    if(!s_aux[grades[i].studs[j]].graded)
                        visit(grades[i].studs[j], s_aux[grades[i].studs[j]].testGrade);
        }

        void printStudents(){
            for(int i=0; i < nstudents; i++)
                printf("%d\n", s_aux[i].projectGrade);
        }
};

int main(){

    int nstudents, nrelations;

    scanf("%d,%d",&nstudents,&nrelations);

    Graph g(nstudents,nrelations);

    g.DFS();

    g.printStudents();

    return 0;

}