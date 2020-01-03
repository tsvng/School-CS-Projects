
int A[10] = {5,3,-3,54,2,-56,7,9,11,11};
int N=10;
int (*funcptr)(int *, int *);

void swap(int *a, int *b) ;

bubblesort (int *A, int nelems, int (*compar)(int *, int *)) {
    int *outer,*inner,temp;
    int *last=&A[nelems];
    //for (outer=A; outer<last; outer++) {
    outer=A;
Louter:
    if (outer >= last) goto Louterdone;
        //for (inner=(outer+1);inner<last; inner++) {
        inner=(outer+1);
Linner:
        if (inner >= last) goto Linnerdone;
            //if ( ((*compar) (inner, outer)) > 0) {
            if ( ((*compar) (inner,outer)) <= 0) goto Linnerskip;
                swap(outer,inner);
            //}
Linnerskip:
        //}
        inner++;
        goto Linner;
Linnerdone:
    //}
    outer++;
    goto Louter;
Louterdone: ;
}

//return 1 if *first > *second. 0 otherwise
int compare_larger (int *first, int *second) ;

main() {
    int i;
    bubblesort(A,N,compare_larger);
    for (i=0;i<N;i++) printf("%d ",A[i]);
    putchar('\n');
}
