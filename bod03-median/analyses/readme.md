# Бодлого 3 медиан 

### Хуваан эзлэх аргаар бодох нь 

Өгөгдсөн хүснэгтээс санамсаргүй байдлаар нэг тоо сугалж авъя. Авсан тоогоо хүснэгтийн бусад элементүүдтэй жишиж үзээд бага тоонуудийг санамсаргүйгээр сонгосон тооныхоо зүүн гар талд хадгалъя. Ингэвэл бид сонгож авсан тооныхоо зүүн гар талд уг тооноос бага, баруун гар талд уг тооноос их тоонууд орших ба сонгосон тооныхоо индексийг мэдэх боломжтой болно. Олсон индексээ хүснэгтийн голын элементтэй жишээд тэнцүү байвал голын элемент нь медиан болно. Харин бага байвал олсон индексээс голын элемент хооронд, харин их байвал голын элементээс олсон индекс хүртэлх дунд бидний хайж буй медиан  байгаа гэсэн үг юм.

### Хугацааны анализ
Бид медианаа хүснэгтээс хайхдаа хүснэгтээ 2 хэсэгт хувааж байгаа бөгөөд нэг хэсэгт нь бидний хайж байгаа медиан байгаа гэж үзээд нөгөө хэсэгт нь медиан байхгүй гэж үзээд байхгүй хэсгээ орхиод явж байгаа. Ингэснээр нэг санамсаргүй элемент сонгож хайхдаа нийт n-ээр гүйх үйлдлээ 2 хэсэгт хувааж зөвхөн нэг хэсгийг авч хайж байгаа болохоор ихдээ n, багадаа 1 болон дунджаар n/2 элементээр гүйж байгаа учир O(n*log(n)) хугацаанд алгоритм маань ажиллах юм.

### Бодолт 

Доор байгаа функц нь санамсаргүй сонгосон тоогоо функцын параметрээр дамжуулж өгсөн хүснэгтийн left-ээс right индексүүд дунд байгаа элементүүдтэй жишээд зөв байрлалд оруулж байгаа үйлдэл хийнэ.
``` 
int getCorrectIndexOfRandomValue(vector<int>& a, int left, int right, int pivot_index) {
    int pivot_value = a[pivot_index];
    swap(a[pivot_index], a[right]);
    int store_index = left;
    for(int i = left; i < right; i++) {
        if(a[i] < pivot_value) {
            swap(a[i], a[store_index]);
            store_index++;
        }
    }
    swap(a[store_index], a[right]);
    return store_index;
}
``` 
Харин доорх функц маань рекурсив функц бөгөөд санамсаргүй сонгосон элементийн индексийг голын элементийн индекстэй жишиж аль хэсгээ орхих, аль хэсгээс хайхаа сонгож рекурсив функц маань үргэлжлэх юм. 
``` 
int getTheMedian(vector<int>& a, int left, int right, int mid) {
    if(left == right) 
        return a[left];
    int pivot_index = left + rand() % (right - left + 1);
	pivot_index = getCorrectIndexOfRandomValue(a, left, right, pivot_index);
	if(mid == pivot_index) 
        return a[mid];
    else if(mid < pivot_index)
		return getTheMedian(a, left, pivot_index - 1, mid);
    else
		return getTheMedian(a, pivot_index + 1, right, mid);
} 
``` 
## Бодолт 

```
#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>

using namespace std;


int getCorrectIndexOfRandomValue(vector<int>& a, int left, int right, int pivot_index);
int getTheMedian(vector<int>& a, int left, int right, int mid);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int median;
    if(n % 2 == 0) { // Тэгш ширхэг тоо байвал
        int left = 0, right = n-1, mid = n/2-1;
        int median1 = getTheMedian(a, left, right, mid);
        int median2 = getTheMedian(a, left, right, mid + 1);
        median = (median1 + median2) / 2;
    }
    else { // Сондгой ширхэг тоо байвал
        int left = 0, right = n - 1, k = n / 2;
        median = getTheMedian(a, left, right, k);
    }
    cout << median << endl;
    return 0;
}

int getCorrectIndexOfRandomValue(vector<int>& a, int left, int right, int pivot_index) {
    int pivot_value = a[pivot_index];
    swap(a[pivot_index], a[right]);
    int store_index = left;
    for(int i = left; i < right; i++) {
        if(a[i] < pivot_value) {
            swap(a[i], a[store_index]);
            store_index++;
        }
    }
    swap(a[store_index], a[right]);
    return store_index;
}

int getTheMedian(vector<int>& a, int left, int right, int mid) {
    if(left == right) 
        return a[left];
    int pivot_index = left + rand() % (right - left + 1);
	pivot_index = getCorrectIndexOfRandomValue(a, left, right, pivot_index);
	if(mid == pivot_index) 
        return a[mid];
    else if(mid < pivot_index)
		return getTheMedian(a, left, pivot_index - 1, mid);
    else
		return getTheMedian(a, pivot_index + 1, right, mid);
}

``` 