#include <iostream>
#include <vector>
using namespace std;
#define CARD_COUNT 12

struct CARD {
    int quanity;
    int type;
    int color;
    int filling;
};
vector < CARD > arr(CARD_COUNT);

void IN(int k) {
    if (k >= CARD_COUNT) return;
    cin >> arr[k].quanity >> arr[k].type >> arr[k].color >> arr[k].filling;
    k++;
    IN(k);
};

bool PROOF(CARD arr1, CARD arr2, CARD arr3) {
    return ((arr1.quanity == arr2.quanity && arr3.quanity == arr2.quanity || 
             arr1.quanity != arr2.quanity && arr3.quanity != arr2.quanity && arr1.quanity != arr3.quanity) &&

            (arr1.type == arr2.type && arr3.type == arr2.type ||
            arr1.type != arr2.type && arr3.type != arr2.type && arr1.type != arr3.type) &&

            (arr1.color == arr2.color && arr3.color == arr2.color ||
            arr1.color != arr2.color && arr3.color != arr2.color && arr1.color != arr3.color) &&

            (arr1.filling == arr2.filling && arr3.filling == arr2.filling ||
            arr1.filling != arr2.filling && arr3.filling != arr2.filling && arr1.filling != arr3.filling)) 
                ? true : false;
}


void SET(int i, int j, int l, int k) {//i j l для перебора k счетчик выведенных сетов
    
   
    if (i >= CARD_COUNT) {
        
        j++;
        i = j;
    }
    
    if (j >= CARD_COUNT) {
        l++;
        j = l;
    }
    

    if (l == CARD_COUNT) return;
    if (i != j && j != l && i != l)
        if(PROOF(arr[i], arr[j], arr[l])) {
            k++;
            cout << k << ": " << i+1 << " " << j+1 << " " << l+1 << endl;
        }
       

    return SET(i+1, j, l, k);
};


int main()
{
    IN(0);
    SET(2, 1, 0, 0);
}
