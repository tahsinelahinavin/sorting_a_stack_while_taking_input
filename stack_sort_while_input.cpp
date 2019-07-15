#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = new Node;
struct Node *top2 = new Node;

void init_Stack(){
    top = NULL;
    top2 = NULL;
}

/*
bool isEmpty(){
    if (top = NULL) return true;
    return false;
}
*/

void push(int data, struct Node **top){

        struct Node *temp = new Node;
        temp->data = data;
        temp->next = *top;
        *top = temp;
        printf("Pushed data: %d\n", (*top)->data);




}

int pop(struct Node **top){
    struct Node *temp = new Node;
    int  top_data = (*top)->data;
    temp = *top;
    *top = (*top)->next;
    free(temp);
    return top_data;
}

int peek(){
    return top->data;
}

void sorted_push(int data){
     if(top == NULL || top->data < data){
            push(data, (&top));
            while(top2!=NULL){
                int a = pop(&top2);
                push(a, &top);
            }
    }
     else if(top->data>data){
            int data1 = pop(&top);
            push(data1, &top2);
            sorted_push(data);
            //push(data, &top);
            //int x = pop(&top2);
           // push(x, &top);
            }
     }




int main(){
    init_Stack();
    sorted_push(30);
    sorted_push(8);
    sorted_push(12);
    sorted_push(13);
    sorted_push(1);
    sorted_push(7);
    sorted_push(9);
    sorted_push(25);

    while(top!=NULL){
        cout<<top->data<<" ";
        top=top->next;
    }





}
