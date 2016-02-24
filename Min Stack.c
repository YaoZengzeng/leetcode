typedef struct {
    int *stack;
    int sl;
    int *min;
    int ml;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->stack=(int*)malloc(maxSize*sizeof(int));
    stack->min=(int*)malloc(maxSize*sizeof(int));
    stack->sl=stack->ml=0;
    
    return;
}

void minStackPush(MinStack *stack, int element) {
    stack->stack[stack->sl]=element;
    (stack->sl)++;
    if(stack->ml==0 || element<=stack->min[stack->ml-1]){
        stack->min[stack->ml]=element;
        (stack->ml)++;
    }
    return;
}

void minStackPop(MinStack *stack) {
    if(stack->stack[stack->sl-1]==stack->min[stack->ml-1]){
        (stack->ml)--;
    }
    (stack->sl)--;
    return;
}

int minStackTop(MinStack *stack) {
    return stack->stack[stack->sl-1];
}

int minStackGetMin(MinStack *stack) {
    return stack->min[stack->ml-1];
}

void minStackDestroy(MinStack *stack) {
    free(stack->stack);
    free(stack->min);
    return;
}
