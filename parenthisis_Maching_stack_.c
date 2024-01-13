#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
};
void push(struct stack *ptr, int val)
{
    if (isEmpty(ptr))
    {
        printf("Stack overflow! cannot push %d to the stack \n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d\n", val);
    }
};

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow! cannot pop from the Stack \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
};
int parenthsis(char * exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i]!= '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] != ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
}

int main()
{

    char exp = "8+(5)*))(_()()(()(()((_)()))((0980(4*)) ";
    if (parenthsis(exp))
    {
        printf("The parenthsis is Maching\n");
    }
    else
    {
        printf("The parenthsis is not Match \n");
    }
}