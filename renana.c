#include <stdio.h>
#include <stdlib.h>
struct Person{
    int id;
    char name[30];
};

void display(struct Person person){
    printf("name: %s\n", person.name);
    printf("id: %d\n", person.id);
}

void setId(int id1, struct Person* p){
    p ->id = id1;
}

int main()
{
    int num;
    if(scanf("%d", &num)==1){
        printf("1\n");
    }
    printf("%d", num);
    // struct Person *ptr, p1;
    // ptr = &p1;

    // p1.id = 207616830;
    // printf("p1 id: %d\n", p1.id);
    // // printf("p1 name: %s\n", p1.name);
    // ptr->id = 315848329;
    // printf("ptr id: %d\n", ptr->id);
    // printf("enter name: ");
    // scanf("%[^\n]%*c", p1.name);
    // display(p1);
    // setId(12345678, &p1);
    // display(p1);
    

    // person1->id = 
   
}
