#include<bits/stdc++.h>


using namespace std;

//假定输入的序列都是整数

//bucketsort
void bucketsort(vector<int>& arr){
    if(arr.empty()){
        return;
    }

    int bucketsortnum = arr.size();
    vector<int> buckets(bucketsortnum,0);

    auto iter = arr.begin();
    while(iter != arr.end()){
        int index = *iter;
        buckets[index]++;
        iter++;
    }
    cout << "Bucket-sorted long sequence: ";
    for(int i=0;i<bucketsortnum;i++){
        if(buckets[i]!=0){
            cout << i << " ";
        }
    }
    return;
}


//SelectionSort
void selectionsort(vector<int>& arr){
    int n = arr.size();

    for(int i=0;i<n;++i){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
    
        if(min_index!=i){
            swap(arr[i],arr[min_index]);
        }
    }
    

    // auto out_iter = arr.begin();
    // while(out_iter!=arr.end()){
    //     cout << *out_iter << " ";
    //     out_iter++;
    // }
}


//Bubblesort
void Bubblesort(vector<int>& arr){
    int n = arr.size();

    bool swapped = false;
    for(int i=0;i<n;++i){
        swapped = false;
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }
}


//insertionsort
void insertionsort(vector<int>& arr){
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; 
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key; // 插入 key
    }
}



//Shell Sort
void ShellSort(vector<int>& arr){
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}


void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0; 
    int j = 0; 
    int k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


//计数排序
void countingSort(vector<int>& arr, int exp) {
    int output[arr.size()];
    int count[10] = {0};

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// 基数排序
void radixSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// 用于划分的函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = (low - 1); // i 指向小于基准的最后一个元素

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            i++; // 增加 i
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// 快速排序的递归函数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi 是分区操作后的基准元素的索引
        int pi = partition(arr, low, high);

        // 单独对分区前后的子数组进行递归排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // 创建一个长序列
    const int long_seq_length = 100;
    vector<int> long_seq(long_seq_length);
    for (int i = 0; i < long_seq_length; ++i) {
        long_seq[i] = long_seq_length - i; // 初始化为逆序
    }

    // 创建一个短序列，取长序列的一部分
    const int short_seq_length = 10;
    vector<int> short_seq(long_seq.begin(), long_seq.begin() + short_seq_length);

    cout << "Original long sequence: ";
    for (int num : long_seq) {
       cout << num << " ";
    }
    cout << "\n";

    cout << "Original short sequence: ";
    for (int num : short_seq) {
       cout << num << " ";
    }
    cout << "\n";

    // 使用 <chrono> 库来测量排序算法的时间
    auto start = chrono::high_resolution_clock::now();

    // 桶排序
    {
        vector<int> bucketsorted_long_seq = long_seq;
        auto bucket_start = chrono::high_resolution_clock::now();
        bucketsort(bucketsorted_long_seq);
        // cout << "Bucket-sorted long sequence: ";
        // for (int num : bucketsorted_long_seq) {
        //     cout << num << " ";
        // }
        cout << "\n";
        auto bucket_end = chrono::high_resolution_clock::now();
        auto bucket_elapsed = chrono::duration_cast<chrono::microseconds>(bucket_end - bucket_start).count();
        cout << "Bucket-sort time for long sequence: " << bucket_elapsed << " microseconds\n";
    }

    {
        vector<int> bucketsorted_short_seq = short_seq;
        auto bucket_start = chrono::high_resolution_clock::now();
        bucketsort(bucketsorted_short_seq);
        cout << "Bucket-sorted short sequence: ";
        for (int num : bucketsorted_short_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto bucket_end = chrono::high_resolution_clock::now();
        auto bucket_elapsed = chrono::duration_cast<chrono::microseconds>(bucket_end - bucket_start).count();
        cout << "Bucket-sort time for short sequence: " << bucket_elapsed << " microseconds\n";
    }

    // 选择排序
    {
        vector<int> selectionsorted_long_seq = long_seq;
        auto selection_start = chrono::high_resolution_clock::now();
        selectionsort(selectionsorted_long_seq);
        cout << "Selection-sorted long sequence: ";
        for (int num : selectionsorted_long_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto selection_end = chrono::high_resolution_clock::now();
        auto selection_elapsed = chrono::duration_cast<chrono::microseconds>(selection_end - selection_start).count();
        cout << "Selection-sort time for long sequence: " << selection_elapsed << " microseconds\n";
    }

    {
        vector<int> selectionsorted_short_seq = short_seq;
        auto selection_start = chrono::high_resolution_clock::now();
        selectionsort(selectionsorted_short_seq);
        cout << "Selection-sorted short sequence: ";
        for (int num : selectionsorted_short_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto selection_end = chrono::high_resolution_clock::now();
        auto selection_elapsed = chrono::duration_cast<chrono::microseconds>(selection_end - selection_start).count();
        cout << "Selection-sort time for short sequence: " << selection_elapsed << " microseconds\n";
    }

    // 冒泡排序
    {
        vector<int> bubblesorted_long_seq = long_seq;
        auto bubble_start = chrono::high_resolution_clock::now();
        Bubblesort(bubblesorted_long_seq);
       cout << "Bubble-sorted long sequence: ";
        for (int num : bubblesorted_long_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto bubble_end = chrono::high_resolution_clock::now();
        auto bubble_elapsed = chrono::duration_cast<chrono::microseconds>(bubble_end - bubble_start).count();
        cout << "Bubble-sort time for long sequence: " << bubble_elapsed << " microseconds\n";
    }

    {
        vector<int> bubblesorted_short_seq = short_seq;
        auto bubble_start = chrono::high_resolution_clock::now();
        Bubblesort(bubblesorted_short_seq);
        cout << "Bubble-sorted short sequence: ";
        for (int num : bubblesorted_short_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto bubble_end = chrono::high_resolution_clock::now();
        auto bubble_elapsed = chrono::duration_cast<chrono::microseconds>(bubble_end - bubble_start).count();
        cout << "Bubble-sort time for short sequence: " << bubble_elapsed << " microseconds\n";
    }

    // 插入排序
    {
        vector<int> insertionsorted_long_seq = long_seq;
        auto insertion_start = chrono::high_resolution_clock::now();
        insertionsort(insertionsorted_long_seq);
        cout << "Insertion-sorted long sequence: ";
        for (int num : insertionsorted_long_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto insertion_end = chrono::high_resolution_clock::now();
        auto insertion_elapsed = chrono::duration_cast<chrono::microseconds>(insertion_end - insertion_start).count();
        cout << "Insertion-sort time for long sequence: " << insertion_elapsed << " microseconds\n";

    }

    {
        vector<int> insertionsorted_short_seq = short_seq;
        auto insertion_start = chrono::high_resolution_clock::now();
        insertionsort(insertionsorted_short_seq);
        cout << "Insertion-sorted short sequence: ";
        for (int num : insertionsorted_short_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto insertion_end = chrono::high_resolution_clock::now();
        auto insertion_elapsed = chrono::duration_cast<chrono::microseconds>(insertion_end - insertion_start).count();
        cout << "Insertion-sort time for short sequence: " << insertion_elapsed << " microseconds\n";
    }

    // 希尔排序
    {
        vector<int> shellsorted_long_seq = long_seq;
        auto shell_start = chrono::high_resolution_clock::now();
        ShellSort(shellsorted_long_seq);
        cout << "Shell-sorted long sequence: ";
        for (int num : shellsorted_long_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto shell_end = chrono::high_resolution_clock::now();
        auto shell_elapsed = chrono::duration_cast<chrono::microseconds>(shell_end - shell_start).count();
        cout << "Shell-sort time for long sequence: " << shell_elapsed << " microseconds\n";
    }

    {
        vector<int> shellsorted_short_seq = short_seq;
        auto shell_start = chrono::high_resolution_clock::now();
        ShellSort(shellsorted_short_seq);
        cout << "Shell-sorted short sequence: ";
        for (int num : shellsorted_short_seq) {
           cout << num << " ";
        }
        cout << "\n";
        auto shell_end = chrono::high_resolution_clock::now();
        auto shell_elapsed = chrono::duration_cast<chrono::microseconds>(shell_end - shell_start).count();
        cout << "Shell-sort time for short  sequence: " << shell_elapsed << " microseconds\n";
    }

    // 归并排序
    {
        vector<int> mergesorted_long_seq = long_seq;
        auto merge_start = chrono::high_resolution_clock::now();
        mergeSort(mergesorted_long_seq, 0, mergesorted_long_seq.size() - 1);
        cout << "Merge-sorted long sequence: ";
        for (int num : mergesorted_long_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto merge_end = chrono::high_resolution_clock::now();
        auto merge_elapsed = chrono::duration_cast<chrono::microseconds>(merge_end - merge_start).count();
        cout << "Merge-sort time for long sequence: " << merge_elapsed << " microseconds\n";
    }

    {
        vector<int> mergesorted_short_seq = short_seq;
        auto merge_start = chrono::high_resolution_clock::now();
        mergeSort(mergesorted_short_seq, 0, mergesorted_short_seq.size() - 1);
        cout << "Merge-sorted short sequence: ";
        for (int num : mergesorted_short_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto merge_end = chrono::high_resolution_clock::now();
        auto merge_elapsed = chrono::duration_cast<chrono::microseconds>(merge_end - merge_start).count();
        cout << "Merge-sort time for short sequence: " << merge_elapsed << " microseconds\n";
    }

    // 基数排序
    {
        vector<int> radixsorted_long_seq = long_seq;
         auto radix_start = chrono::high_resolution_clock::now();
        radixSort(radixsorted_long_seq);
        cout << "Radix-sorted long sequence: ";
        for (int num : radixsorted_long_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto radix_end = chrono::high_resolution_clock::now();
        auto radix_elapsed = chrono::duration_cast<chrono::microseconds>(radix_end - radix_start).count();
        cout << "Radix-sort time for long sequence: " << radix_elapsed << " microseconds\n";
    }

    {
       vector<int> radixsorted_short_seq = short_seq;
       auto radix_start = chrono::high_resolution_clock::now();
        radixSort(radixsorted_short_seq);
        cout << "Radix-sorted short sequence: ";
        for (int num : radixsorted_short_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto radix_end = chrono::high_resolution_clock::now();
        auto radix_elapsed = chrono::duration_cast<chrono::microseconds>(radix_end - radix_start).count();
        cout << "Radix-sort time for short sequence: " << radix_elapsed << " microseconds\n";
    }

    // 快速排序
    {
        vector<int> quicksorted_long_seq = long_seq;
        auto quick_start = chrono::high_resolution_clock::now();
        quickSort(quicksorted_long_seq, 0, quicksorted_long_seq.size() - 1);
        cout << "Quick-sorted long sequence: ";
        for (int num : quicksorted_long_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto quick_end = chrono::high_resolution_clock::now();
        auto quick_elapsed = chrono::duration_cast<chrono::microseconds>(quick_end - quick_start).count();
        cout << "Quick-sort time for long sequence: " << quick_elapsed << " microseconds\n";
    }

    {
        vector<int> quicksorted_short_seq = short_seq;
        auto quick_start = chrono::high_resolution_clock::now();
        quickSort(quicksorted_short_seq, 0, quicksorted_short_seq.size() - 1);
        cout << "Quick-sorted short sequence: ";
        for (int num : quicksorted_short_seq) {
            cout << num << " ";
        }
        cout << "\n";
        auto quick_end = chrono::high_resolution_clock::now();
        auto quick_elapsed = chrono::duration_cast<chrono::microseconds>(quick_end - quick_start).count();
        cout << "Quick-sort time for short sequence: " << quick_elapsed << " microseconds\n";
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Total time taken: " << elapsed << " microseconds\n";

    return 0;
}

