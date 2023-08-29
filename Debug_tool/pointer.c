#include <stdio.h>
#include <stdlib.h>
enum Color {RED, BLUE, GREEN};
struct Student{
    int age;
    int mark;
    int myColor;
    char *name;

};
int main(){
    struct Student *ptr = (struct Student *)malloc(sizeof(*ptr));
    if (NULL == ptr){
        printf("Allocated failed!\n");
    }
    else{
        ptr->age = 12;
        ptr->mark = 9;
        ptr->name = "ABC";
        ptr->myColor = RED;
    }
    return 0;
}