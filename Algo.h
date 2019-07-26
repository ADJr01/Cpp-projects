//
// Created by adnan on ২৭/৭/১৯.
//

#ifndef HOME_ALGO_H
#define HOME_ALGO_H

template <class T>
void merge(T *ar, T *ar1, int len, int len1, T *final) {
    int i, j, k;
    i = j = k = 0;
    while (i < len && j < len1) {
        if (bool(ar[i] <= ar1[j])) {
            final[k++] = ar[i++];
        } else {
            final[k++] = ar1[j++];
        }
    }
    while (i < len) {
        final[k++] = ar[i++];
    }
    while (j < len1) {
        final[k++] = ar1[j++];
    }


}

template <class T>
void ms(T *Array, int low, int n) {
    if (n >= 2) {
        int mid = (low + n) / 2;
        T *left = new T[mid];
        for (int i = 0; i < mid; i++) {
            left[i] = Array[i];

        }

        T *right = new T[n - mid];
        for (int j = 0; j < (n - mid); j++) {
            right[j] = Array[j + mid];

        }
        ms(left, 0, mid);
        ms(right, mid, n - mid);
        merge(left, right, mid, n - mid, Array);
    }


}


#endif //HOME_ALGO_H
