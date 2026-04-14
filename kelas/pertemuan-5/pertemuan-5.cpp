#include <iostream>
#include <string>
using namespace std;

// ==================== BUBBLE SORT ====================

int arrBubble[] = {64, 34, 25, 12, 22, 11, 90};
int nBubble = sizeof(arrBubble) / sizeof(arrBubble[0]);

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void tampilkanArrayBubble(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==================== SELECTION SORT ====================

int arrSelection[] = {29, 10, 14, 37, 13};
int nSelection = sizeof(arrSelection) / sizeof(arrSelection[0]);

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indeksMin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indeksMin]) {
                indeksMin = j;
            }
        }
        if (indeksMin != i) {
            swap(arr[i], arr[indeksMin]);
        }
    }
}

void tampilkanArraySelection(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==================== MERGE SORT ====================

int arrMerge[] = {38, 27, 43, 3, 9, 82, 10, 55};
int nMerge = sizeof(arrMerge) / sizeof(arrMerge[0]);

void merge(int arr[], int l, int m, int r) {
    int temp[8];
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++) {
        arr[l + x] = temp[x];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ==================== QUICK SORT ====================

int arrQuick[] = {3, 4, 2, 9, 8, 6, 5, 7};
int nQuick = sizeof(arrQuick) / sizeof(arrQuick[0]);

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    int i = low, j = high;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j) {
        quickSort(arr, low, j);
    }
    if (i < high) {
        quickSort(arr, i, high);
    }
}

// ==================== INSERTION SORT ====================

struct Buku {
    int idBuku;
    string judul;
};

void insertionSort(Buku rak[], int n) {
    for (int i = 1; i < n; i++) {
        Buku key = rak[i];
        int j = i - 1;
        while (j >= 0 && rak[j].idBuku > key.idBuku) {
            rak[j + 1] = rak[j];
            j = j - 1;
        }
        rak[j + 1] = key;
    }
}

void tampilkanRak(Buku rak[], int n) {
    for (int i = 0; i < n; i++) {
        cout << rak[i].idBuku << " | " << rak[i].judul << endl;
    }
    cout << endl;
}

// ==================== MAIN ====================

int main() {
    cout << "===== BUBBLE SORT =====" << endl;
    cout << "Data Sebelum Bubble Sort: ";
    tampilkanArrayBubble(arrBubble, nBubble);
    bubbleSort(arrBubble, nBubble);
    cout << "Data Setelah Bubble Sort : ";
    tampilkanArrayBubble(arrBubble, nBubble);

    cout << "\n===== SELECTION SORT =====" << endl;
    cout << "Sebelum Selection Sort: ";
    tampilkanArraySelection(arrSelection, nSelection);
    selectionSort(arrSelection, nSelection);
    cout << "Sesudah Selection Sort : ";
    tampilkanArraySelection(arrSelection, nSelection);

    cout << "\n===== MERGE SORT =====" << endl;
    cout << "Sebelum sorting: ";
    for (int i = 0; i < nMerge; i++) cout << arrMerge[i] << " ";
    cout << endl;
    mergeSort(arrMerge, 0, nMerge - 1);
    cout << "Sesudah sorting: ";
    for (int i = 0; i < nMerge; i++) cout << arrMerge[i] << " ";
    cout << endl;

    cout << "\n===== QUICK SORT =====" << endl;
    cout << "Data Belum Terurut: ";
    for (int i = 0; i < nQuick; i++) cout << arrQuick[i] << " ";
    cout << endl;
    quickSort(arrQuick, 0, nQuick - 1);
    cout << "Hasil Quick Sort : ";
    for (int i = 0; i < nQuick; i++) cout << arrQuick[i] << " ";
    cout << endl;

    cout << "\n===== INSERTION SORT =====" << endl;
    int n = 5;

    Buku rakUrut[] = {
        {101, "Laskar Pelangi"}, {102, "Bumi Manusia"}, {103, "Negeri 5 Menara"},
        {104, "Filosofi Teras"}, {105, "Hujan"}
    };
    cout << "=== BEST CASE (Data Terurut) ===" << endl;
    insertionSort(rakUrut, n);
    tampilkanRak(rakUrut, n);

    Buku rakTerbalik[] = {
        {105, "Hujan"}, {104, "Filosofi Teras"}, {103, "Negeri 5 Menara"},
        {102, "Bumi Manusia"}, {101, "Laskar Pelangi"}
    };
    cout << "=== WORST CASE (Data Terbalik) ===" << endl;
    insertionSort(rakTerbalik, n);
    tampilkanRak(rakTerbalik, n);

    return 0;
}