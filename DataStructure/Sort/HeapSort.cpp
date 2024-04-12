#include <cstdio>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * 维护堆的性质
 * @param arr 存储堆的shuzu
 * @param n 数组的长度
 * @param i 待维护的节点的下标
 */
void heaptify(int arr[], int n, int i)
{
    int fa = i;
    int lson = 2 * i + 1;
    int rson = 2 * i + 2;
    if (lson < n && arr[fa] < arr[lson])
    {
        fa = lson;
    }
    if (rson < n && arr[fa] < arr[rson])
    {
        fa = rson;
    }
    if (fa != i)
    {
        swap(&arr[i], &arr[fa]);
        heaptify(arr, n, fa);
        // 一旦一个小堆被维护之后发生了父节点与子节点之间的数据交换，则会影响子节点一下的节点，需要递归维护
    }
}

/**
 * @author lgq007
 * @details -下标为i的节点的父节点下标: (i - 1)/2
 * @details -下标为i的节点的左孩子下标: 2 * i + 1
 * @details -下标为i的节点的右孩子下标: 2 * i + 2
 */
void heapSort(int arr[], int n)
{
    // 建堆
    for (int i = n / 2 - 1; i >= 0; i--) // 从最后一个非叶子节点开始(这个节点的下标一定是n - 1, 因此它的父节点坐标为 (n - 1 - 1)/2
    {
        heaptify(arr, n, i);
    }

    // 排序
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heaptify(arr, i, 0);
    }
}

int main()
{
    int arr[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}