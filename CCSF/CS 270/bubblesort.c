
int A[10] = {5,3,-3,54,2,-56,7,9,11,11};
int N=10;
int (*funcptr)(int *, int *);

// swap the values that a and b point to
void swap(int *a, int *b) ;

bubblesort (int *A, int nelems, int (*compar)(int *, int *)) {
    int *outer,*inner,temp;
    for (outer=A; outer<&A[nelems]; outer++) {
        for (inner=(outer+1);inner<&A[nelems]; inner++) {
            if ( ((*compar) (inner, outer)) > 0) {
                swap(outer,inner);
            }
        }
    }
}

//return 1 if *first > *second. 0 otherwise
int compare_larger (int *first, int *second) ;

main() {
    int i;
    bubblesort(A,N,compare_larger);
    for (i=0;i<N;i++) printf("%d ",A[i]);
    putchar('\n');
}
