#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// dodatkowe metody
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void kopiec(int *t, int n, int i) {
    // init zmiennych
    int largest = i;
    int lewy = 2*i + 1;
    int prawy = 2*i + 2;

    // jesli lewy jest wiekszy niz korzen
    if (lewy < n && t[lewy] > t[largest])
        largest = lewy;

    // jesli prawy jest wiekszy od obecnego najwiekszego
    if (prawy < n && t[prawy] > t[largest])
        largest = prawy;

    // jesli najwiekszy nie jest korzeniem
    if (largest != i)
    {
        swap(&t[i], &t[largest]);

        // rekursywnie tworz kopiec
        kopiec(t, n, largest);
    }
}

// wielkosc instancji
unsigned int ns[] = { 1500, 15000, 15001, 15005, 30000, 35013, 60000, 75000, 90000, 150000 /* TODO: fill in "n" i.e. instance sizes */};


void fill_increasing(int *t, unsigned int n) {
    // TODO: implement
    int value = 10, counter = 0;
    for (counter; counter < n; counter++){
        t[counter] = value;
        value++;
    }
}

void fill_decreasing(int *t, unsigned int n) {
    // TODO: implement
    int value = 10, counter = 0;
    for (counter; counter < n; counter++){
        t[counter] = value;
        value--;
    }
}

void fill_vshape(int *t, unsigned int n) {
    // TODO: implement
    long int value = n;
    int counter = n;

    int *begin = t;
    int *end = t + n - 1;

    while (end - begin > 1) {
        *begin = value + counter;
        begin++;
        *end = value + counter;
        end--;
        counter--;
    }
    if(end - begin == 0) {
        *begin = value + counter;
    }
    /* STARA WERSJA Z SYMETRIA - kolejnosc na odwrot
    int symmetry = n/2;

    //wpisuj w array
    //jesli n jest parzyste

    //if(n % 2 == 0){

    for (counter = 0; counter <= n/2; counter++){
        t[symmetry + counter] = value + counter;
        t[symmetry - counter] = value + counter;
    }
    if (n%2 == 0){
        t[symmetry + counter] = value + counter;
    }
    */

    //}
    /*
    //jesli n jest NIEparzyste
    else if(n % 2 != 0){
        for (counter = 0; counter <= n/2; counter++){
            t[symmetry + counter] = value + counter;
            t[symmetry - counter] = value + counter;
        }
    }
    */

    /* WYPISYWANIE TABLICY
    printf("\nTABLICA fill v-shape: \n");
    for(int x = 0; x<n; x++){
        printf("%d\t", t[x]);
    };
    printf("\n");
    */

}

void selection_sort(int *t, unsigned int n) {
    // TODO: implement

    // init zmiennych
    int i, j, min_idx;
    // petla makro - przesuwanie po naszym array
    for (i = 0; i < n-1; i++){
        // porownywany arg to pierwszy arg w danym podarray
        min_idx = i;
        // petla mikro - porownywanie args w podarrays
        for(j = i+1; j < n; j++){
            if(t[j] < t[min_idx]){
                min_idx = j;
            }
        }
        // zamien najmniejsze z pierwszym
        swap(&t[min_idx], &t[i]);
    }
    /* WYPISYWANIE TABLICY
    printf("\nTABLICA selection sort: \n");
    for(int x = 0; x<n; x++){
        printf("%d\t", t[x]);
    };
    printf("\n");
    */
}

void insertion_sort(int *t, unsigned int n) {
    // TODO: implement
    int i, key, j;
        for (i = 1; i < n; i++) {
            key = t[i];
            j = i - 1;

            //przekladaj el do t[i-1] wieksze od klucza o 1 pozycje w prawo
            while (j >= 0 && t[j] > key) {
                t[j + 1] = t[j];
                j = j - 1;
            }
            // ustaw klucz na odpowiedniej pozycji
            t[j + 1] = key;
        }
    /* WYPISYWANIE TABLICY
    printf("\nTABLICA insertion sort: \n");
    for(int x = 0; x<n; x++){
        printf("%d\t", t[x]);
    };
    printf("\n");
    */
}

int podzial(int *t, int n, int l)
{
    int pivot = t[n];
    int i = l -1;
    for(int j= l;j<=n;j++ ){
        if(t[j]<pivot){
            i++;
            swap(&t[j],&t[i]);
        }
    }

    i= i+1;
    swap(&t[n], &t[i]);
    return i;
    }
void quick_sort_2(int *t, int n,  int l){
    int pi;
    if(l<n){
        pi = podzial(t,n,l);
        quick_sort_2(t,(pi-1),l);
        quick_sort_2(t,n,(pi+1));
    }
    /* WYPISYWANIE TABLICY
    printf("\nTABLICA quick sort: \n");
    for(int x = 0; x<n; x++){
        printf("%d\t", t[x]);
    };
    printf("\n");
    */
}

void quick_sort(int *t, int n) {
   quick_sort_2(t,(n-1),0);
}

void heap_sort(int *t, unsigned int n) {
    // TODO
    // stworz kopiec
    for (int i = n/2 - 1; i >= 0; i--)
        kopiec(t, n, i);

    // wyciagaj rzeczy z kopca po 1 el
    for (int i=n-1; i>=0; i--){
        // przeloz korzen drzewa na koniec
        swap(&t[0], &t[i]);

        // stworz ostateczny kopiec
        kopiec(t, i, 0);
    }
    /* WYPISYWANIE TABLICY
    printf("TABLICA heap sort: \n");
    for(int x = 0; x<n; x++){
        printf("%d\t", t[x]);
    };
    printf("\n");
    */
}

void fill_random(int *t, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        t[i] = rand();
    }
}

void is_random(int *t, unsigned int n) {
    return;
}

void is_increasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] > t[i - 1]);
    }
}

void is_decreasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] < t[i - 1]);
    }
}

void is_vshape(int *t, unsigned int n) {
    int *begin = t;
    int *end = t + n - 1;

    while (end - begin > 1) {
        assert(*begin >= *end);
        begin++;
        assert(*end >= *begin);
        end--;
    }
}

void is_sorted(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] >= t[i - 1]);
    }
}

void (*fill_functions[])(int *, unsigned int) = { fill_random, fill_increasing, fill_decreasing, fill_vshape };
void (*check_functions[])(int *, unsigned int) = { is_random, is_increasing, is_decreasing, is_vshape };
void (*sort_functions[])(int *, unsigned int) = { selection_sort, insertion_sort, quick_sort, heap_sort };

char *fill_names[] = { "Random", "Increasing", "Decreasing", "V-Shape" };
char *sort_names[] = { "SelectionSort", "InsertionSort", "QuickSort", "HeapSort" };

int main() {
    for (unsigned int i = 0; i < sizeof(sort_functions) / sizeof(*sort_functions); i++) {
        void (*sort)(int *, unsigned int) = sort_functions[i];

        for (unsigned int j = 0; j < sizeof(fill_functions) / sizeof(*fill_functions); j++) {
            void (*fill)(int *, unsigned int) = fill_functions[j];
            void (*check)(int *, unsigned int) = check_functions[j];

            for (unsigned int k = 0; k < sizeof(ns) / sizeof(*ns); k++) {
                unsigned int n = ns[k];
                int *t = malloc(n * sizeof(*t));

                fill(t, n);
                check(t, n);

                clock_t begin = clock();
                sort(t, n);
                clock_t end = clock();
                is_sorted(t, n);

                printf("%15s\t%15s\t%15u\t%15f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);
                free(t);
            }
        }
    }
    printf("\nZAKONCZONO POMYSLNIE!\n");
    return 0;
}
