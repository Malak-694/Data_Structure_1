#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
int compare = 0;
class Student {
    string id;
    string name;
    double gpa;

public:
    Student(string id, string name, double gpa) : id(id), name(name), gpa(gpa) {}
    string get_name() {
        return name;
    }
    string get_id() {
        return id;
    }
    double get_gpa() {
        return gpa;
    }
};

bool operator<(Student& student1, Student& student2) {
    return student1.get_name() < student2.get_name();}

bool operator>(Student& student1, Student& student2) {
    return student1.get_gpa() >student2.get_gpa();
}
template <class T>
vector <T> insertionSort_gpa(vector<T> students, int size) {
    int i, j;
    compare=0;
    for (i = size - 2; i >= 0; i--) {
        T tmp = students[i];
        for (j = i; j < size - 1; j++) {
            compare++;
            if (students[j + 1]>tmp) {
                students[j] = students[j + 1];
            } else {
                break;
            }
        }
        students[j] = tmp;
    }
    return students;
}

template <class T>
vector <T> insertionSort_name(vector<T> students, int size) {
    int i, j;
    compare=0;
    for (i = 1; i < size; i++) {
        T tmp = students[i];
        for (j = i; j > 0; j--) {
            compare++;
            if (tmp < students[j - 1]) {
                students[j] = students[j - 1];
            } else break;
        }
        students[j] = tmp;
    }

    return students;
}

template <class T>
vector<T> selectionSort_gpa(vector<T> students, int size) {
    int i, j, least;
    compare=0;
    for (i = size-1; i >= 0; i--) {
        least = i;
        for (j = i- 1; j >=0 ; j--) {
            compare++;
            if (students[least] > students[j]) {
                least = j;
            }
        }
        swap(students[least], students[i]);
    }

    return students;
}

template <class T>
vector<T> selectionSort_name(vector<T> students, int size) {
    int i, j, least;
    compare=0;
    for (i = 0; i < size - 1; i++) {
        least = i;
        for (j = i + 1; j < size; j++) {
            compare++;
            if (students[j] < students[least]) {
                least = j;
            }
        }
        swap(students[least], students[i]);
    }
    return students;
}

template<class QT>
int partition_name(vector<QT>& pstu, int l, int r) {
    QT pivot = pstu[l];
    int y = l;

    for (int i = l + 1; i <= r; ++i) {
        compare++;
        if (pstu[i] < pivot) {
            y++;
            swap(pstu[y], pstu[i]);
        }
    }

    swap(pstu[y], pstu[l]);
    return y;
}

template<typename QT>
vector<QT>  quicksort_name(vector<QT>& stu, int left, int right) {
    if (left >= right) {
        return stu;
    } else {
        int pivot = partition_name(stu, left, right);

        quicksort_name(stu, left, pivot - 1);
        quicksort_name(stu, pivot + 1, right);
    }
    return stu;
}

//_______________________________________________
template<class QT>
int partition_gpa(vector<QT>& pstu, int l, int r) {
    QT pivot = pstu[l];
    int y = l;

    for (int i = l + 1; i <= r; ++i) {
        compare++;
        if (pstu[i] > pivot) {
            y++;
            swap(pstu[y], pstu[i]);
        }
    }

    swap(pstu[y], pstu[l]);
    return y;
}

template<typename QT>
vector<QT> quicksort_gpa(vector<QT> stu, int left, int right) {
    if (left >= right) {
        return stu;
    } else {
        int pivot = partition_gpa(stu, left, right);

        quicksort_gpa(stu, left, pivot - 1);
        quicksort_gpa(stu, pivot + 1, right);
    }
    return stu;
}
//-----------------------------------

template<typename t>
vector<t> bubble_sort_gpa(vector<t> arr,int size){
    for(int i = 0 ; i<size ; i++ ){
        bool ischange=0;
        for(int j=0 ; j<size-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                ischange= 1;
                compare++;
            }
        }
        if(!ischange)break;
    }
    return arr;
}
//----------------------------------------//
template<typename t>
vector<t>  bubble_sort_name(vector<t> arr,int size){
    for(int i = 0 ; i<size ; i++ ){
        bool ischange=0;
        for(int j=0 ; j<size-i-1 ; j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j],arr[j+1]);
                ischange= 1;
                compare++;
            }
        }
        if(!ischange)break;
    }
    return arr;
}
//--------------------------------
template<typename T>
vector<T>  shell_sort_gpa(vector<T> arr,int size){
    int gap= size/2;
    while (gap>0){
        for(int i = gap;i<size;i++){
            T temp = arr[i];
            int j;
            for (j = i; j >= gap ; j -= gap) {
                if( arr[j - gap] > temp) {
                    compare++;
                    arr[j] = arr[j - gap];
                }
                else break;
            }
            arr[j]=temp;
        }
        gap=gap/2;
    }
    return arr;
}
//----------------------------------------//
template<typename T>
vector<T> shell_sort_name(vector<T> arr,int size){
    int gap= size/2;
    while (gap>0){
        for(int i = gap;i<size;i++){
            T temp = arr[i];
            int j;
            for (j = i; j >= gap ; j -= gap) {
                if( arr[j - gap] < temp) {
                    compare++;
                    arr[j] = arr[j - gap];
                }
                else break;
            }
            arr[j]=temp;
        }
        gap=gap/2;
    } return arr;
}

//--------------------//
template<typename T >
void mergeSortbyname(vector<T> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSortbyname(arr, left, mid);
    mergeSortbyname(arr, mid + 1, right);
    merge_n(arr, left, mid, right);
}


//_______________________________________________
template<typename T>
void merge_n(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L, R;

    for (int i = 0; i < n1; i++) {
        T x = arr[left + i];
        L.push_back(x);
    }
    for (int j = 0; j < n2; j++) {
        T x= arr[mid + 1 + j];
        R.push_back(x);
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
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
}

template<typename T>
void mergeSortbygpa(vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortbygpa(arr, left, mid);
        mergeSortbygpa(arr, mid + 1, right);
        merge_g(arr, left, mid, right);
    }
}

//_______________________________________________
template<typename T>
void merge_g(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L, R;

    for (int i = 0; i < n1; i++) {
        T x = arr[left + i];
        L.push_back(x);
    }
    for (int j = 0; j < n2; j++) {
        T x= arr[mid + 1 + j];
        R.push_back(x);
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
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
}

int main() {
    ifstream file("D:\\butterfly\\data_structure_assignment1\\example"); // Open the file "example.txt" for reading
    ofstream SortedByGPA("D:\\butterfly\\data_structure_assignment1\\SortedByGPA.txt");
    ofstream SortedByName("D:\\butterfly\\data_structure_assignment1\\SortedByName.txt");
    // Check if the file is opened successfully
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1; // Return error code
    }

    vector<Student> students;
    string id, name, s;
    double gpa;
    int size;
    getline(file, s);
    size = stoi(s);
    for (int i = 0; i < size; i++) {
        getline(file, name);
        getline(file, id);
        getline(file, s);
        gpa = stod(s);
        students.emplace_back(Student(id, name, gpa));
    }
    SortedByGPA<< "Algorithm: Insertion Sort\n";
    auto start = high_resolution_clock::now();

    vector<Student> gpa_insertion=insertionSort_gpa(students, size);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    SortedByGPA<< "Running Time:" << duration.count() << " nanoseconds\n";
    SortedByGPA<< compare << "\n";
    compare=0;
    for (int i = 0; i < size; i++) {
        SortedByGPA<< gpa_insertion[i].get_name() << "\n" << gpa_insertion[i].get_id() << "\n" << gpa_insertion[i].get_gpa();
        SortedByGPA<< "\n\n";
    }
    SortedByGPA<<"*************************\n";
    ////////////////////////////////////////

    SortedByName<< "Algorithm: Insertion Sort\n";
    auto start1 = high_resolution_clock::now();
    vector<Student> name_insertion=insertionSort_name(students, size);

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    SortedByName<< "Running Time:" << duration1.count() << " nanoseconds\n";
    SortedByName<< compare << "\n";
    compare=0;
    for (int i = 0; i < size; i++) {
        SortedByName<< name_insertion[i].get_name() << "\n" << name_insertion[i].get_id() << "\n" << name_insertion[i].get_gpa();
        SortedByName<< "\n\n";
    }
    SortedByName<<"\n***************************\n";
    /////////////////////////////////


    SortedByGPA<< "Algorithm: Selection Sort\n";
    start = high_resolution_clock::now();

    vector<Student> gpa_selection=selectionSort_gpa(students, size);

    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    SortedByGPA<< "Running Time:" << duration.count() << " nanoseconds\n";
    SortedByGPA<< compare << "\n";
    compare=0;
    for (int i = 0; i < size; i++) {
        SortedByGPA<< gpa_selection[i].get_name() << "\n" << gpa_selection[i].get_id() << "\n" << gpa_selection[i].get_gpa();
        SortedByGPA<< "\n\n";
    }
    SortedByGPA<<"\n****************\n";
    ////////////////////////////////////////

    SortedByName<< "Algorithm: Selection Sort\n";
    start1 = high_resolution_clock::now();
    vector<Student> name_selection=selectionSort_name(students, size);

    stop1 = high_resolution_clock::now();
    duration1 = duration_cast<nanoseconds>(stop1 - start1);
    SortedByName<< "Running Time:" << duration1.count() << " nanoseconds\n";
    SortedByName<< compare << "\n";
    compare=0;
    for (int i = 0; i < size; i++) {
        SortedByName<< name_selection[i].get_name() << "\n" << name_selection[i].get_id() << "\n" << name_selection[i].get_gpa();
        SortedByName<< "\n\n";
    }
    SortedByName<<"\n*******************\n";
    /////////////////////////////////


    SortedByGPA<< "Algorithm: Quick Sort\n";
    start = high_resolution_clock::now();

    vector<Student> gpa_quicksort = quicksort_gpa(students, 0, size - 1);

    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    SortedByGPA<< "Running Time:" << duration.count() << " nanoseconds\n";
    SortedByGPA<< compare << "\n";
    compare=0;
    for (int i = 0; i < size; i++) {
        SortedByGPA<< gpa_quicksort[i].get_name() << "\n" << gpa_quicksort[i].get_id() << "\n" << gpa_quicksort[i].get_gpa();
        SortedByGPA<< "\n\n";
    }
    SortedByGPA<<"\n****************\n";
    ////////////////////////////////////////

    SortedByName<< "Algorithm: Quick Sort\n";
    start1 = high_resolution_clock::now();
    vector<Student> name_quicksort = quicksort_name(students, 0, size - 1);

    stop1 = high_resolution_clock::now();
    duration1 = duration_cast<nanoseconds>(stop1 - start1);
    SortedByName<< "Running Time:" << duration1.count() << " nanoseconds\n";
    SortedByName<< compare << "\n";
    compare=0;
    for (int i = 0; i < size; i++) {
        SortedByName<< name_quicksort[i].get_name() << "\n" << name_quicksort[i].get_id() << "\n" << name_quicksort[i].get_gpa();
        SortedByName<< "\n\n";
    }
    SortedByName<<"\n*******************\n";

    /////////////////////////////////


    SortedByGPA<< "Algorithm: Bubble Sort\n";
    start = high_resolution_clock::now();

    vector<Student> gpa_bubble = bubble_sort_gpa(students, size );

    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    SortedByGPA<< "Running Time:" << duration.count() << " nanoseconds\n";
    SortedByGPA<< compare << "\n";
    compare=0;
    for (int i = size-1; i >=0; i--) {
        SortedByGPA<< gpa_bubble[i].get_name() << "\n" << gpa_bubble[i].get_id() << "\n" << gpa_bubble[i].get_gpa();
        SortedByGPA<< "\n\n";
    }
    SortedByGPA<<"\n****************\n";
    ////////////////////////////////////////

    SortedByName<< "Algorithm: Bubble Sort\n";
    start1 = high_resolution_clock::now();
    vector<Student> name_bubble = bubble_sort_name(students, size );

    stop1 = high_resolution_clock::now();
    duration1 = duration_cast<nanoseconds>(stop1 - start1);
    SortedByName<< "Running Time:" << duration1.count() << " nanoseconds\n";
    SortedByName<< compare << "\n";
    compare=0;
    for (int i = size-1; i >=0; i--) {
        SortedByName<< name_bubble[i].get_name() << "\n" << name_bubble[i].get_id() << "\n" << name_bubble[i].get_gpa();
        SortedByName<< "\n\n";
    }
    SortedByName<<"\n*******************\n";
    ////////////////////////////////
    SortedByGPA<< "Algorithm: Shell Sort\n";
    start = high_resolution_clock::now();

    vector<Student> gpa_shell= shell_sort_gpa(students, size);

    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    SortedByGPA<< "Running Time:" << duration.count() << " nanoseconds\n";
    SortedByGPA<< compare << "\n";
    compare=0;
    for (int i = size-1; i >=0; i--) {
        SortedByGPA<< gpa_shell[i].get_name() << "\n" << gpa_shell[i].get_id() << "\n" << gpa_shell[i].get_gpa();
        SortedByGPA<< "\n\n";
    }
    SortedByGPA<<"*************************\n";
    ////////////////////////////////////////

    SortedByName<< "Algorithm: Shell Sort\n";
    start1 = high_resolution_clock::now();
    vector<Student> name_shell=shell_sort_name(students, size);

    stop1 = high_resolution_clock::now();
    duration1 = duration_cast<nanoseconds>(stop1 - start1);
    SortedByName<< "Running Time:" << duration1.count() << " nanoseconds\n";
    SortedByName<< compare << "\n";
    compare=0;
    for (int i = size-1; i >=0; i--) {
        SortedByName<< name_shell[i].get_name() << "\n" << name_shell[i].get_id() << "\n" << name_shell[i].get_gpa();
        SortedByName<< "\n\n";
    }
    SortedByName<<"\n***************************\n";
    /////////////////////////////////
    ////////////////////////////////
    SortedByGPA<< "Algorithm: Merge Sort\n";
    start = high_resolution_clock::now();

    vector<Student> gpa_merge= students;
    mergeSortbygpa(gpa_merge,0,size-1);

    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    SortedByGPA<< "Running Time:" << duration.count() << " nanoseconds\n";
    SortedByGPA<< compare << "\n";
    compare=0;
    for (int i = 0; i <size ; i++) {
        SortedByGPA<< gpa_merge[i].get_name() << "\n" << gpa_merge[i].get_id() << "\n" << gpa_merge[i].get_gpa();
        SortedByGPA<< "\n\n";
    }
    SortedByGPA<<"*************************\n";
    ////////////////////////////////////////

    SortedByName<< "Algorithm: Merge Sort\n";
    start1 = high_resolution_clock::now();

    vector<Student> name_merge=students;
    mergeSortbyname(name_merge,0,size-1);

    stop1 = high_resolution_clock::now();
    duration1 = duration_cast<nanoseconds>(stop1 - start1);
    SortedByName<< "Running Time:" << duration1.count() << " nanoseconds\n";
    SortedByName<< compare << "\n";
    compare=0;
    for (int i = 0; i <size; i++) {
        SortedByName<< name_merge[i].get_name() << "\n" << name_merge[i].get_id() << "\n" << name_merge[i].get_gpa();
        SortedByName<< "\n\n";
    }
    SortedByName<<"\n***************************\n";
    /////////////////////////////////
    // Close the file
    // Close the file
    file.close();
    return 0;
}
