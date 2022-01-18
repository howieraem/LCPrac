import java.util.Comparator;


public class ArrayHeap<E> {
    private Object[] arr;
    private int curSZ;
    private final Comparator<? super E> comparator;

    private static final int INIT_SZ = 100;

    public ArrayHeap() {
        this(INIT_SZ, null);
    }

    public ArrayHeap(Comparator<? super E> comparator) {
        this(INIT_SZ, comparator);
    }

    public ArrayHeap(int cap, Comparator<? super E> comparator) {
        if (cap < 1)  throw new IllegalArgumentException();
        arr = new Object[cap];
        this.comparator = comparator;
    }

    public <? super E> ArrayHeap(E[] arr, Comparator<? super E> comparator) {
        this.arr = (Object[]) arr.clone();
        this.comparator = comparator;
        curSZ = arr.length;
        heapify(curSZ);
    }

    private void heapify(int n) {
        for (int i = (n >> 1) - 1; i >= 0; --i) {
            siftDown(n, i);
        }
    }

    public void add(E e) {
        arr[curSZ] = e;
        siftUp(curSZ);
        ++curSZ;
    }

    public E poll() {
        E e = peek();
        arr[0] = arr[--curSZ];
        siftDown(curSZ, 0);
        arr[curSZ] = null;
        return e;
    }

    public E peek() {
        if (curSZ > 0)  return (E) arr[0];
        throw new NullPointerException();
    }

    private int siftDown(int n, int i) {
        int j;
        while (i != (j = parent(n, i))) {
            swap(i, j);
            i = j;
        }
        return i;
    }

    private int siftUp(int i) {
        while (i > 0) {
            int j = ((i - 1) >> 1);
            if (comparator.compare(arr[i], arr[j]) < 0)  break;
            swap(i, j);
            i = j;
        }
        return i;
    }

    private int parent(int n, int i) {
        return isRightChildValid(n, i) ? compareElem(compareElem(i,  i * 2 + 1), i * 2 + 2) : 
            isLeftChildValid(n, i) ? compareElem(i, i * 2 + 1) : i;
    }

    private boolean isLeftChildValid(int n, int i) {
        return i * 2 + 1 < n;
    }

    private boolean isRightChildValid(int n, int i) {
        return i * 2 + 2 < n;
    }

    private int compareElem(int i, int j) {
        return j >= curSZ ? i : comparator.compare(arr[i], arr[j]) > 0 ? i : j;
    }

    private static final void swap(int i, int j) {
        Object tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}