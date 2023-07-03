#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    ABS,
    FIB,
    INT
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

#define MAXN 100
int fib[MAXN];

Node* makeFunc(TypeTag type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* makeValue(int value) {
    Node *newNode = makeFunc(INT);
    newNode->value = value;
    return newNode;
}

// fibonacci function using dynamic programming
int fibonacci(int n) {
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

// function to calculate the value of a node
int calc(Node* node) {
    if (node->type == ADD) {
        return calc(node->left) + calc(node->right);
    }
    else if (node->type == SUB) {
        return calc(node->left) - calc(node->right);
    }
    else if (node->type == MUL) {
        return calc(node->left) * calc(node->right);
    }
    else if (node->type == DIV) {
        return calc(node->left) / calc(node->right);
    }
    else if (node->type == ABS) {
        return abs(calc(node->left));
    }
    else if (node->type == FIB) {
        return fibonacci(calc(node->left));
    }
    else if (node->type == INT) {
        return node->value;
    }
    printf("Invalid node type %d\n", node->type);
    exit(1);
}


int main() {
    for (int i = 0; i < MAXN; i++) {
        fib[i] = -1;
    }
    Node *add = makeFunc(ADD);
    add->left = makeValue(10);
    add->right = makeValue(6);
    Node *mul = makeFunc(MUL);
    mul->left = makeValue(5);
    mul->right = makeValue(4);
    Node *sub = makeFunc(SUB);
    sub->left = makeValue(calc(add));
    sub->right = makeValue(calc(mul));
    Node *fibo = makeFunc(FIB);
    fibo->left = makeValue(abs(calc(sub)));
    fibo->value = fibonacci(calc(fibo->left));

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));
}